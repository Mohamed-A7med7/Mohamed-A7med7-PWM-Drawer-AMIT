/*
 * BIT_MATH.h
 *
 * Created: 9/05/2022 11:32:55 Õ
 * Author : Mohamed Gwefel
 */

#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/*Bit manipulation operations*/
#define SET_BIT(REG, BIT)        (REG |= (1 << BIT))
#define CLEAR_BIT(REG, BIT)      (REG &= ~(1 << BIT))
#define TOGGLE_BIT(REG, BIT)     (REG ^= (1 << BIT))
#define GET_BIT(REG, BIT)        ((REG >> BIT) & 0x1)

#endif