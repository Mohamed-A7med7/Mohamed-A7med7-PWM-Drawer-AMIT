/*
 * LCD_confg.h
 *
 * Created: 2/08/2023 08:13:34 ã
 * Author : Mohamed Gwefel
 */ 


#ifndef __LCD_CFG_H__
#define __LCD_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*LCD Control lines configurations*/
#define LCD_CONTROL_LINES_PORT      (PORTB)
#define LCD_RS_PIN                  (PIN1)
#define LCD_RW_PIN                  (PIN2)
#define LCD_EN_PIN                  (PIN3)

/*LCD Data lines configurations*/
#define LCD_DATA_LINES_PORT         (PORTA)
#define LCD_D4_PIN                  (PIN4)
#define LCD_D5_PIN                  (PIN5)
#define LCD_D6_PIN                  (PIN6)
#define LCD_D7_PIN                  (PIN7)

/*LCD Instructions*/
#define LCD_FUNCTION_SET            (0x2C)
#define LCD_DISP_ON_OFF_CTRL        (0x0F)
#define LCD_CLEAR                   (0x01)
#define LCD_ENTRY_MODE_SET          (0x06)

#endif