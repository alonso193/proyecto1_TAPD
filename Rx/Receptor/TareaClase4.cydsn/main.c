/*******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Project Defines */
#define FALSE  0
#define TRUE   1
#define TRANSMIT_BUFFER_SIZE  16
#define COUNT_OF_SAMPLES  2000

/* DMA Defines */
#define REQUEST_PER_BURST        (1u)
#define BYTES_PER_BURST          (1u)
#define UPPER_SRC_ADDRESS        CYDEV_PERIPH_BASE
#define UPPER_DEST_ADDRESS       CYDEV_PERIPH_BASE

    /* Flags used to store transmit data commands */
    uint8 Continuously;

    /* Transmit Buffer */
    char TransmitBuffer[TRANSMIT_BUFFER_SIZE];
    /* Variable used to send emulated data */
    uint8 EmulatedData;
    uint8 output;
    uint16 ADC_out;
    
    uint8 Buffer_sample_to_transmit[COUNT_OF_SAMPLES];
    int i = 0;
    unsigned int sample_counter = 0;
    
    char counter_char[10];

    void DMA_Config(void);
    float goertzel_mag(int numSamples,int TARGET_FREQUENCY,int SAMPLING_RATE, float data[]);

    float signal[COUNT_OF_SAMPLES];
    float MAG_ROW, MAG_COL;
    int mg;
    char test[32];


int sample;
float sample_f;
//UART transmit interrupt
CY_ISR_PROTO(Transmit);
CY_ISR(Transmit)
{   
    /* Send data based on last UART command */
    if(Continuously)
    {
        
        for( int j = 0; j < COUNT_OF_SAMPLES; j++ ){
            signal[j] = (float) Buffer_sample_to_transmit[j];
            sample = (int) signal[j];
            sprintf(TransmitBuffer,"%i\r\n", sample);
            //UART_1_PutString(TransmitBuffer);

        }
        
        MAG_ROW = goertzel_mag(2000,697,8000,signal);               
        MAG_COL = goertzel_mag(2000,1209,8000,signal);        

        sprintf(TransmitBuffer,"Row: %i\r\n", (int)MAG_ROW);
            UART_1_PutString(TransmitBuffer);
        sprintf(TransmitBuffer,"Col: %i\r\n", (int)MAG_COL);
            UART_1_PutString(TransmitBuffer);
            
        if (MAG_ROW >= 1 && MAG_COL >= 1) {
            UART_1_PutString("Num: 1\r\n");
        }
    }
        
}


/*******************************************************************************
* Interrupt
********************************************************************************
* Interrupt generated on Filter sample-ready. Interrupt handle:filterVDAC
*
* Summary:
*  The interrupt performs following functions:
*   1: Reads the left-justified register for Filter Channel A
*   2: Converts it into an unsigned value
*   3: Writes this value to VDAC
*
*******************************************************************************/
CY_ISR(filterVDAC)
{
    /* Convert the 2's complement value to an unsigned 8-bit value
     * The VDAC expects an unsigned 8-bit value as input.
     */
    output = Filter_Read8(Filter_CHANNEL_A)+32u;
	VDAC8_SetValue(output);
    
    if (i <= COUNT_OF_SAMPLES) {       
        Buffer_sample_to_transmit[i]= output;
        i++;
        if (i==COUNT_OF_SAMPLES) {
            i = 0;
        }
    }

}



CY_ISR(get_from_ADC)
{
    /* Convert the 2's complement value to an unsigned 8-bit value
     * The VDAC expects an unsigned 8-bit value as input.
     */

    if (i <= COUNT_OF_SAMPLES) {       
        Buffer_sample_to_transmit[i]= ADC_DelSig_GetResult16();
        i++;
        if (i==COUNT_OF_SAMPLES) {
            i = 0;
        }
    }

}
/*******************************************************************************

* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1: Enables global interrupts
*   2: Start all components on the schematic
*   3: Calls a function to configure DMA

* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/


int main()
{
  
    /* Variable to store UART received character */
    uint8 Ch;

    /* Start all components used on schematic */
    ADC_DelSig_IRQ_Start();
    isr_StartEx(filterVDAC);
    isrTimer_StartEx(Transmit);
    
    isrTimer_1_StartEx(get_from_ADC);
    
    ADC_DelSig_Start();
    ADC_DelSig_StartConvert();
    VDAC8_Start();
    WaveDAC8_Start();
    Filter_Start();
    Timer_Start();
    Timer_1_Start();
    UART_1_Start();

    /* Initialize Variables */
    Continuously = FALSE;
    EmulatedData = 0;
    
    
    /* Send message to verify COM port is connected properly */
    UART_1_PutString("COM Port Open");
    
    /* User-implemented function to set-up DMA */
    DMA_Config();

    /* Enable Global Interrupts */
    CYGlobalIntEnable;

    for(;;)
    {
        /* Non-blocking call to get the latest data recieved  */
        Ch = UART_1_GetChar();
        
        /* Set flags based on UART command */
        switch(Ch)
        {
            case 0:
                /* No new data was recieved */
                break;
            case 'C':
            case 'c':
                sample_counter = 0;
                
                break;
            case 'S':
            case 's':
                sample_counter = 0;
                Continuously = TRUE;                
                break;
            
            default:
                /* Place error handling code here */
                break;    
        }
        
    }
} /* End of main */


/*******************************************************************************
* Function Name: DMA_Config
********************************************************************************
*
* Summary:
*  Initializes and sets up DMA for use (generated by DMA Wizard)
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DMA_Config(void)
{
    /* Declare variable to hold the handle for DMA channel */
    uint8 channelHandle;

    /* Declare DMA Transaction Descriptor for memory transfer into
     * Filter Channel.
     */
    uint8 tdChanA;

    /* Configure the DMA to Transfer the data in 1 burst with individual trigger
     * for each burst.
     */
    channelHandle = DMA_DmaInitialize(BYTES_PER_BURST, REQUEST_PER_BURST,
                                        HI16(UPPER_SRC_ADDRESS), HI16(UPPER_DEST_ADDRESS));

    /* This function allocates a TD for use with an initialized DMA channel */
    tdChanA = CyDmaTdAllocate();

    /* Configure the tdChanA to transfer 1 byte with no next TD */
    CyDmaTdSetConfiguration(tdChanA, 1u, DMA_INVALID_TD, 0u);

    /* Set the source address as ADC_DelSig and the destination as
     * Filter Channel A.
     */
    CyDmaTdSetAddress(tdChanA, LO16((uint32)ADC_DelSig_DEC_SAMP_PTR), LO16((uint32)Filter_STAGEAH_PTR));

    /* Set tdChanA to be the initial TD associated with channelHandle */
    CyDmaChSetInitialTd(channelHandle, tdChanA);

    /* Enable the DMA channel represented by channelHandle and preserve the TD */
    CyDmaChEnable(channelHandle, 1u);
}

float goertzel_mag(int numSamples,int TARGET_FREQUENCY,int SAMPLING_RATE, float data[])
{
    int     k,i;
    float   floatnumSamples;
    float   omega,sine,cosine,coeff,q0,q1,q2,magnitude,real,imag;

    float   scalingFactor = numSamples / 2.0;

    floatnumSamples = (float) numSamples;
    k = (int) (0.5 + ((floatnumSamples * TARGET_FREQUENCY) / SAMPLING_RATE));
    omega = (2.0 * 3.1416 * k) / floatnumSamples;
    
    sine = sin(omega);
    cosine = cos(omega);
    coeff = 2.0 * cosine;
    q0=0;
    q1=0;
    q2=0;

    for(i=0; i<numSamples; i++)
    {
        q2 = q1;
        q1 = q0;
        q0 = coeff * q1 - q2 + data[i];
    }

    // calculate the real and imaginary results
    // scaling appropriately
    real = (q0 - q1 * cosine) / scalingFactor;
    imag = (-q1 * sine) / scalingFactor;

    magnitude = sqrtf(real*real + imag*imag);
    

    return magnitude;
}


/* [] END OF FILE */
