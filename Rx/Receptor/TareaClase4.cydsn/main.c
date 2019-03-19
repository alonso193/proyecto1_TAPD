
#include <project.h>
#include <stdio.h>
#include <device.h>

#define TONE_DURATION_MS 80 /* Duration of tone in mSec */
#define TONE_SPACE_MS 50 /* Duration of space between tones in mSec */
#define TONE_PAUSE_MS 100 /* Pause caused by invalid code */
/* Function prototypes */
void DialNumber( char * number );
void PlayTones( char key );
int8 KeyIndex(char * keyString, char key);
char keyCodes[] = "123A456B789C*0#D"; /* Valid character array */
/* The tables below store the dividers loaded into */
/* the counter period register to generate the row */
/* and column tones. */
/* Row Tones (Hz) 697 770 852 941 */
uint8 rowDiv[] = {214, 194, 175, 158};
/* Col Tones (Hz) 1209 1336 1477 1633 */
uint8 colDiv[] = { 198, 179, 161, 146};


    /* Flags used to store transmit data commands */
    uint8 ContinuouslySendData;
    uint8 SendSingleByte;
    uint8 SendEmulatedData;


    char counter_char[10];



int main()
{
 /* Initialize all components */
 ToneClock_Stop();
 Row_Divider_Start();
 Col_Divider_Start();
 Row_Tone_Start();
 Col_Tone_Start();
 DTMF_Buffer_Start();


  UART_1_Start();

  char Ch;

  UART_1_PutString("Digite el numero: \n");



for(;;)
    {
        /* data recieved  */
        Ch = (char)UART_1_GetChar();
        
        char * ch_string = &Ch;
        UART_1_PutString(ch_string);
        
        /* Send tone */
       DialNumber(ch_string);
        
    }

return 0;
}

/*******************************************************************************
* Function Name: DialNumber( char * number )
********************************************************************************
*
* Summary:
* This function dials the number passed to it in a character string. After
* the number has been dialed the funtions returns.
*
* Parameters:
* char * number: Pointer to phone number string.
*
* Return:
* void
*
*******************************************************************************/
void DialNumber( char * number )
{
 uint8 c = 0;
 while( number[c] != 0 ) /* Step through the dial string */
     {
        PlayTones( number[c] ); /* Play tone for each digit */
        CyDelay(TONE_SPACE_MS); /* Wait minimum space between tones */
        c++;
     }
}

/*******************************************************************************
* Function Name: PlayTones( )
********************************************************************************
*
* Summary:
* Generates the two tones required to dial the given key code. The valid
* dial characters are "1 2 3 4 5 6 7 8 9 0 A B C D * #". Any invalid
* character will generate a pause.
*
* Parameters:
* char key: Keypad character to be dialed.
*
* Return:
* void
*
*******************************************************************************/
void PlayTones( char key )
{
 int8 idx;
 uint8 row_div, col_div;

 idx = KeyIndex(keyCodes, key); /* Convert key to "keyCodes" array index */
 if (idx >= 0 ) /* Is key valid */
     { /* Valid Key */
        col_div = colDiv[(uint8)(idx & 0x03)]; /* Get divider for column tone */
        row_div = rowDiv[(uint8)((idx >> 2)& 0x03)];/* Get divider for row tone */
        Row_Divider_WritePeriod(row_div); /* Set both dividers */
         Col_Divider_WritePeriod(col_div);

        ToneClock_Start(); /* Turn on clock */
        CyDelay(TONE_DURATION_MS); /* Wait for the tone duration */
        ToneClock_Stop(); /* Turn off clock */
 } else /* Invalid key, just pause for set period of time. */
     {
        CyDelay(TONE_PAUSE_MS);
     }
}
/*******************************************************************************
* Function Name: KeyIndex( )
********************************************************************************
*
* Summary:
* This function finds the location of a character in a string and returns
* the index. If the character is not found a -1 is returned.
*
* Parameters:
* char * keyString: String to search through. This strings should be null
* terminated and less than 255 characters in lenth.
* char key: Character to find in "String".
*
* Return:
* int8: Index of "key" in "keyString". If not found, return -1.
*
*******************************************************************************/
int8 KeyIndex(char * keyString, char key)
{
 int8 i; /* String index */
 int8 charLoc = -1; /* Location of character in string */

 /* Search through string for character match */
 for(i=0; (keyString[i] != 0); i++)
 {
 /* If character is found return index in string */
     if (key == keyString[i])
    {
         charLoc = i;
        break;
    }
 }
 return charLoc;
}
/* [] END OF FILE */