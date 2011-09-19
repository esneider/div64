/**
 * @file div64.h
 *
 * non-standard
 *
 * functions to replace __umoddi3 __udivdi3 gcc builtins
 * (actually they are in gcc's c standard library so we can't use them)
 *
 * we use the old trick of dividing using shifts (a.k.a binary long division)
 *
 * @author Dario Sneidermanis
 */

#ifndef _DIV64_H_
#define _DIV64_H_

/* replace this by whatever your fixed-size integer header is */
#include "smdint.h"


/**
 * Using "long division" to divide uint64_ts
 *
 * @param dividend
 * @param divisor
 *
 * @return the quotient
 */
inline
static uint32_t uint64_div32 ( uint64_t dividend, uint32_t divisor ) {

	uint32_t low      = 0xFFFF & (uint32_t)dividend;
	uint32_t mid_low  = 0xFFFF & (uint32_t)(dividend >>= 16);
	uint32_t mid_high = 0xFFFF & (uint32_t)(dividend >>= 16);
	uint32_t high     =          (uint32_t)(dividend >> 16);

	dividend  = high / divisor;
	mid_high += (high % divisor) << 16;
	dividend  = (dividend << 16) + mid_high / divisor;
	mid_low  += (mid_high % divisor) << 16;
	dividend  = (dividend << 16) + mid_low / divisor;
	low      += (mid_low % divisor) << 16;

	return (dividend << 16) + low / divisor;
}


/**
 * Using "long division" to modulo uint64_ts
 *
 * @param dividend
 * @param divisor
 *
 * @return the remainder
 */
inline
static uint32_t uint64_mod32 ( uint64_t dividend, uint32_t divisor ) {

	uint32_t low      = 0xFFFF & (uint32_t)dividend;
	uint32_t mid_low  = 0xFFFF & (uint32_t)(dividend >>= 16);
	uint32_t mid_high = 0xFFFF & (uint32_t)(dividend >>= 16);
	uint32_t high     =          (uint32_t)(dividend >> 16);

	dividend  = high / divisor;
	mid_high += (high % divisor) << 16;
	dividend  = (dividend << 16) + mid_high / divisor;
	mid_low  += (mid_high % divisor) << 16;
	dividend  = (dividend << 16) + mid_low / divisor;
	low      += (mid_low % divisor) << 16;

	return low % divisor;
}


/**
 * Using "long division" to divide uint64_ts
 *
 * @param dividend
 * @param divisor
 *
 * @return the quotient
 */
inline
static uint64_t uint64_div64 ( uint64_t dividend, uint64_t divisor ) {

	uint64_t shift = divisor;
	uint64_t aux   = divisor;

	while ( shift < dividend && (aux <<= 1) > shift )
		shift = aux;

	for ( aux = 0; shift >= divisor; shift >>= 1 ) {
		aux <<= 1;
		if ( shift <= dividend ) {
			aux++;
			dividend -= shift;
		}
	}
	return aux;
}


/**
 * Using "long division" to modulo uint64_ts
 *
 * @param dividend
 * @param divisor
 *
 * @return the remainder
 */
inline
static uint64_t uint64_mod64 ( uint64_t dividend, uint64_t divisor ) {

	uint64_t shift = divisor;
	uint64_t aux   = divisor;

	while ( shift < dividend && (aux <<= 1) > shift )
		shift = aux;

	for ( aux = 0; shift >= divisor; shift >>= 1 ) {
		aux <<= 1;
		if ( shift <= dividend ) {
			aux++;
			dividend -= shift;
		}
	}
	return dividend;
}


#endif /* _DIV64_H_ */
