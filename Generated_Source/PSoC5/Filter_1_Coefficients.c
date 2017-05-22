#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_1_ChannelAFirCoefficients

/* Number of FIR filter taps are: 16 */

const uint8 CYCODE Filter_1_ChannelAFirCoefficients[Filter_1_FIR_A_SIZE] = 
{
 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(0), 0.00256860256195068 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(1), -0.00118374824523926 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(2), -0.0145359039306641 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(3), -0.0282543897628784 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(4), -0.00894057750701904 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(5), 0.0715601444244385 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(6), 0.193287491798401 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(7), 0.286455631256104 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(8), 0.286455631256104 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(9), 0.193287491798401 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(10), 0.0715601444244385 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(11), -0.00894057750701904 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(12), -0.0282543897628784 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(13), -0.0145359039306641 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(14), -0.00118374824523926 */

 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(15), 0.00256860256195068 */
};

