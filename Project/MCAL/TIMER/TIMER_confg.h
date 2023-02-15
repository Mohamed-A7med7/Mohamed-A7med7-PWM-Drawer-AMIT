/*
 * TIMER_config.h
 *
 * Created: 2/09/2023 09:28:33 ã
 * Author : Mohamed Gwefel
 */


#ifndef __TIMER_CFG_H__
#define __TIMER_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*Custom prescalers choice*/
#define TIMER_OPERATION_STOP            (0xF8)
#define TIMER1_OPERATION_STOP           (0xFFF8)

/*ICU frequency value*/
#define TIMER_ICU_FREQ_4US_DIVIDER      (250000)

/*Clear to compare mode 1 ms delay*/
#define TIMER_1_MS_DELAY                (250)

#endif