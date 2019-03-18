#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_ChannelAFirCoefficients

/* Number of FIR filter taps are: 15 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0x8Du, 0xF6u, 0xFFu, 0x00u, /* Tap(0), -0.00028836727142334 */

 0x6Eu, 0x21u, 0x00u, 0x00u, /* Tap(1), 0.00102019309997559 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(2), 0 */

 0x02u, 0xBFu, 0xFEu, 0x00u, /* Tap(3), -0.0097959041595459 */

 0xF5u, 0xB4u, 0x04u, 0x00u, /* Tap(4), 0.0367723703384399 */

 0x0Bu, 0xBAu, 0xF5u, 0x00u, /* Tap(5), -0.0802599191665649 */

 0x40u, 0xC9u, 0x0Fu, 0x00u, /* Tap(6), 0.123329162597656 */

 0x5Bu, 0x7Eu, 0x48u, 0x00u, /* Tap(7), 0.566356062889099 */

 0x40u, 0xC9u, 0x0Fu, 0x00u, /* Tap(8), 0.123329162597656 */

 0x0Bu, 0xBAu, 0xF5u, 0x00u, /* Tap(9), -0.0802599191665649 */

 0xF5u, 0xB4u, 0x04u, 0x00u, /* Tap(10), 0.0367723703384399 */

 0x02u, 0xBFu, 0xFEu, 0x00u, /* Tap(11), -0.0097959041595459 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(12), 0 */

 0x6Eu, 0x21u, 0x00u, 0x00u, /* Tap(13), 0.00102019309997559 */

 0x8Du, 0xF6u, 0xFFu, 0x00u, /* Tap(14), -0.00028836727142334 */
};

