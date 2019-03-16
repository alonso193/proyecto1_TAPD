#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_ChannelABiquadCoefficients

/* Number of Biquad sections are: 4 */

const uint8 CYCODE Filter_ChannelABiquadCoefficients[Filter_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0x58u, 0xC0u, 0x04u, 0x00u, /* Section(0)_A0, 0.0742397308349609 */

 0xAFu, 0x80u, 0x09u, 0x00u, /* Section(0)_A1, 0.148479223251343 */

 0x58u, 0xC0u, 0x04u, 0x00u, /* Section(0)_A2, 0.0742397308349609 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(0)_B1, 0 */

 0x0Eu, 0xB7u, 0xEDu, 0x00u, /* Section(0)_B2, 0.285702228546143 */

 /* Coefficients of Section 1 */
 0x71u, 0xE9u, 0x12u, 0x00u, /* Section(1)_A0, 0.295498132705688 */

 0xE2u, 0xD2u, 0x25u, 0x00u, /* Section(1)_A1, 0.590996265411377 */

 0x71u, 0xE9u, 0x12u, 0x00u, /* Section(1)_A2, 0.295498132705688 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(1)_B1, 0 */

 0x5Bu, 0x1Cu, 0xFAu, 0x00u, /* Section(1)_B2, 0.0920193195343018 */

 /* Coefficients of Section 2 */
 0xBEu, 0x27u, 0x10u, 0x00u, /* Section(2)_A0, 0.252425670623779 */

 0x7Cu, 0x4Fu, 0x20u, 0x00u, /* Section(2)_A1, 0.504851341247559 */

 0xBEu, 0x27u, 0x10u, 0x00u, /* Section(2)_A2, 0.252425670623779 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(2)_B1, 0 */

 0x11u, 0x61u, 0xFFu, 0x00u, /* Section(2)_B2, 0.00970053672790527 */

 /* Coefficients of Section 3 */
 0x82u, 0xE9u, 0x25u, 0x00u, /* Section(3)_A0, 1.18475437164307 */

 0x04u, 0xD3u, 0x4Bu, 0x00u, /* Section(3)_A1, 2.36950874328613 */

 0x82u, 0xE9u, 0x25u, 0x00u, /* Section(3)_A2, 1.18475437164307 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Section(3)_B1, 0 */

 0x26u, 0xE5u, 0xD4u, 0x00u, /* Section(3)_B2, 0.673513889312744 */
};

