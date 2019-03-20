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
 0x03u, 0x0Fu, 0x09u, 0x00u, /* Section(0)_A0, 0.141541242599487 */

 0x05u, 0x1Eu, 0x12u, 0x00u, /* Section(0)_A1, 0.283082246780396 */

 0x03u, 0x0Fu, 0x09u, 0x00u, /* Section(0)_A2, 0.141541242599487 */

 0xACu, 0x04u, 0xBFu, 0x00u, /* Section(0)_B1, 1.01533985137939 */

 0x18u, 0x1Au, 0xE4u, 0x00u, /* Section(0)_B2, 0.435907363891602 */

 /* Coefficients of Section 1 */
 0x62u, 0x3Cu, 0x25u, 0x00u, /* Section(1)_A0, 0.581810474395752 */

 0xC5u, 0x78u, 0x4Au, 0x00u, /* Section(1)_A1, 1.16362118721008 */

 0x62u, 0x3Cu, 0x25u, 0x00u, /* Section(1)_A2, 0.581810474395752 */

 0x73u, 0x00u, 0xC7u, 0x00u, /* Section(1)_B1, 0.890597581863403 */

 0x6Eu, 0x64u, 0xEFu, 0x00u, /* Section(1)_B2, 0.259495258331299 */

 /* Coefficients of Section 2 */
 0xBAu, 0x41u, 0x20u, 0x00u, /* Section(2)_A0, 0.504011631011963 */

 0x74u, 0x83u, 0x40u, 0x00u, /* Section(2)_A1, 1.00802326202393 */

 0xBAu, 0x41u, 0x20u, 0x00u, /* Section(2)_A2, 0.504011631011963 */

 0x27u, 0x8Eu, 0xCAu, 0x00u, /* Section(2)_B1, 0.835073709487915 */

 0xF3u, 0x6Au, 0xF4u, 0x00u, /* Section(2)_B2, 0.180972337722778 */

 /* Coefficients of Section 3 */
 0x2Au, 0xFCu, 0x21u, 0x00u, /* Section(3)_A0, 2.12406349182129 */

 0x54u, 0xF8u, 0x43u, 0x00u, /* Section(3)_A1, 4.24812698364258 */

 0x2Au, 0xFCu, 0x21u, 0x00u, /* Section(3)_A2, 2.12406349182129 */

 0x66u, 0x76u, 0xB0u, 0x00u, /* Section(3)_B1, 1.24277353286743 */

 0x5Au, 0x84u, 0xCFu, 0x00u, /* Section(3)_B2, 0.757546901702881 */
};

