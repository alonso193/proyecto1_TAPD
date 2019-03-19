/*******************************************************************************
* File Name: Row_Tone.c
* Version 2.10
*
* Description:
*  This file provides the source code for the 8-bit Waveform DAC 
*  (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Row_Tone.h"

uint8  Row_Tone_initVar = 0u;

const uint8 CYCODE Row_Tone_wave1[Row_Tone_WAVE1_LENGTH] = { 128u,137u,147u,157u,166u,175u,184u,193u,201u,209u,216u,223u,229u,234u,239u,243u,246u,249u,251u,252u,252u,252u,251u,249u,246u,243u,239u,234u,229u,223u,216u,209u,201u,193u,184u,175u,166u,157u,147u,137u,128u,118u,108u,98u,89u,80u,71u,62u,54u,46u,39u,32u,26u,21u,16u,12u,9u,6u,4u,3u,3u,3u,4u,6u,9u,12u,16u,21u,26u,32u,39u,46u,54u,62u,71u,80u,89u,98u,108u,118u };
const uint8 CYCODE Row_Tone_wave2[Row_Tone_WAVE2_LENGTH] = { 128u,135u,143u,151u,159u,166u,174u,181u,188u,194u,201u,207u,213u,219u,224u,229u,233u,237u,241u,244u,246u,249u,250u,252u,252u,252u,252u,252u,250u,249u,246u,244u,241u,237u,233u,229u,224u,219u,213u,207u,201u,194u,188u,181u,174u,166u,159u,151u,143u,135u,128u,120u,112u,104u,96u,89u,81u,74u,67u,61u,54u,48u,42u,36u,31u,26u,22u,18u,14u,11u,9u,6u,5u,3u,3u,3u,3u,3u,5u,6u,9u,11u,14u,18u,22u,26u,31u,36u,42u,48u,54u,61u,67u,74u,81u,89u,96u,104u,112u,120u };

static uint8  Row_Tone_Wave1Chan;
static uint8  Row_Tone_Wave2Chan;
static uint8  Row_Tone_Wave1TD;
static uint8  Row_Tone_Wave2TD;


/*******************************************************************************
* Function Name: Row_Tone_Init
********************************************************************************
*
* Summary:
*  Initializes component with parameters set in the customizer.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void Row_Tone_Init(void) 
{
	Row_Tone_VDAC8_Init();
	Row_Tone_VDAC8_SetSpeed(Row_Tone_HIGHSPEED);
	Row_Tone_VDAC8_SetRange(Row_Tone_DAC_RANGE);

	#if(Row_Tone_DAC_MODE == Row_Tone_CURRENT_MODE)
		Row_Tone_IDAC8_SetPolarity(Row_Tone_DAC_POL);
	#endif /* Row_Tone_DAC_MODE == Row_Tone_CURRENT_MODE */

	#if(Row_Tone_OUT_MODE == Row_Tone_BUFFER_MODE)
	   Row_Tone_BuffAmp_Init();
	#endif /* Row_Tone_OUT_MODE == Row_Tone_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	Row_Tone_Wave1TD = CyDmaTdAllocate();
	Row_Tone_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	Row_Tone_Wave1Setup(Row_Tone_wave1, Row_Tone_WAVE1_LENGTH) ;
	Row_Tone_Wave2Setup(Row_Tone_wave2, Row_Tone_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(Row_Tone_DacClk_PHASE)
	   Row_Tone_DacClk_SetPhase(Row_Tone_CLK_PHASE_0nS);
	#endif /* defined(Row_Tone_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: Row_Tone_Enable
********************************************************************************
*  
* Summary: 
*  Enables the DAC block and DMA operation.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void Row_Tone_Enable(void) 
{
	Row_Tone_VDAC8_Enable();

	#if(Row_Tone_OUT_MODE == Row_Tone_BUFFER_MODE)
	   Row_Tone_BuffAmp_Enable();
	#endif /* Row_Tone_OUT_MODE == Row_Tone_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(Row_Tone_Wave1Chan, 1u);
	(void)CyDmaChEnable(Row_Tone_Wave2Chan, 1u);
	
	/* set the initial value */
	Row_Tone_SetValue(0u);
	
	#if(Row_Tone_CLOCK_SRC == Row_Tone_CLOCK_INT)  	
	   Row_Tone_DacClk_Start();
	#endif /* Row_Tone_CLOCK_SRC == Row_Tone_CLOCK_INT */
}


/*******************************************************************************
* Function Name: Row_Tone_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as 
*  executing the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void Row_Tone_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(Row_Tone_initVar == 0u)
	{
		Row_Tone_Init();
		Row_Tone_initVar = 1u;
	}
	
	Row_Tone_Enable();
}


/*******************************************************************************
* Function Name: Row_Tone_StartEx
********************************************************************************
*
* Summary:
*  The StartEx function sets pointers and sizes for both waveforms
*  and then starts the component.
*
* Parameters:  
*   uint8 * wavePtr1:     Pointer to the waveform 1 array.
*   uint16  sampleSize1:  The amount of samples in the waveform 1.
*   uint8 * wavePtr2:     Pointer to the waveform 2 array.
*   uint16  sampleSize2:  The amount of samples in the waveform 2.
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void Row_Tone_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	Row_Tone_Wave1Setup(wavePtr1, sampleSize1);
	Row_Tone_Wave2Setup(wavePtr2, sampleSize2);
	Row_Tone_Start();
}


/*******************************************************************************
* Function Name: Row_Tone_Stop
********************************************************************************
*
* Summary:
*  Stops the clock (if internal), disables the DMA channels
*  and powers down the DAC.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
*******************************************************************************/
void Row_Tone_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(Row_Tone_CLOCK_SRC == Row_Tone_CLOCK_INT)  	
	   Row_Tone_DacClk_Stop();
	#endif /* Row_Tone_CLOCK_SRC == Row_Tone_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(Row_Tone_Wave1Chan);
	(void)CyDmaChDisable(Row_Tone_Wave2Chan);

	/* Disable power to DAC */
	Row_Tone_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: Row_Tone_Wave1Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 1.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None 
*
*******************************************************************************/
void Row_Tone_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (Row_Tone_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		Row_Tone_Wave1Chan = Row_Tone_Wave1_DMA_DmaInitialize(
		Row_Tone_Wave1_DMA_BYTES_PER_BURST, Row_Tone_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		Row_Tone_Wave1Chan = Row_Tone_Wave1_DMA_DmaInitialize(
		Row_Tone_Wave1_DMA_BYTES_PER_BURST, Row_Tone_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(Row_Tone_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(Row_Tone_Wave1TD, sampleSize, Row_Tone_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)Row_Tone_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(Row_Tone_Wave1TD, LO16((uint32)wavePtr), LO16(Row_Tone_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(Row_Tone_Wave1Chan, Row_Tone_Wave1TD);
}


/*******************************************************************************
* Function Name: Row_Tone_Wave2Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 2.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None
*
*******************************************************************************/
void Row_Tone_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (Row_Tone_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		Row_Tone_Wave2Chan = Row_Tone_Wave2_DMA_DmaInitialize(
		Row_Tone_Wave2_DMA_BYTES_PER_BURST, Row_Tone_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		Row_Tone_Wave2Chan = Row_Tone_Wave2_DMA_DmaInitialize(
		Row_Tone_Wave2_DMA_BYTES_PER_BURST, Row_Tone_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(Row_Tone_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(Row_Tone_Wave2TD, sampleSize, Row_Tone_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)Row_Tone_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(Row_Tone_Wave2TD, LO16((uint32)wavePtr), LO16(Row_Tone_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(Row_Tone_Wave2Chan, Row_Tone_Wave2TD);
}


/* [] END OF FILE */
