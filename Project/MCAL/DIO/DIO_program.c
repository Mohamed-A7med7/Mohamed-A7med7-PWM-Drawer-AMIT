/*
 * DIO_program.c
 *
 * Created: 2/07/2023 05:17:24 ã
 * Author : Mohamed Gwefel
 */ 



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                         */
/***************************************************************************************************/

#define NUMBER_OF_PORTS    (4)

/***************************************************************************************************/
/*                                        Important variables                                      */
/***************************************************************************************************/

/*DDRx array*/
static volatile u8_t* garr_ddrArray[NUMBER_OF_PORTS] = {MDIO_DDRA_ADDRESS, MDIO_DDRB_ADDRESS, MDIO_DDRC_ADDRESS, MDIO_DDRD_ADDRESS};

/*PORTx array*/
static volatile u8_t* garr_portArray[NUMBER_OF_PORTS] = {MDIO_PORTA_ADDRESS, MDIO_PORTB_ADDRESS, MDIO_PORTC_ADDRESS, MDIO_PORTD_ADDRESS};

/*PINx array*/
static volatile u8_t* garr_pinArray[NUMBER_OF_PORTS] = {MDIO_PINA_ADDRESS, MDIO_PINB_ADDRESS, MDIO_PINC_ADDRESS, MDIO_PIND_ADDRESS};

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status)
{
	/*Switching over pin status*/
	switch(au8_status)
	{
		/*In case of input float*/
		case INPUT_FLOAT:

		/*Clearing the specified pins in DDRx register*/
		*garr_ddrArray[au8_port] &= ~(au8_pin);

		/*Breaking from this case*/
		break;

		/*In case of input pull up*/
		case INPUT_PULLUP:

		/*Clearing the specified pins in DDRx register*/
		*garr_ddrArray[au8_port] &= ~(au8_pin);

		/*Setting the specified pins in PORTx register*/
		*garr_portArray[au8_port] |= (au8_pin);

		/*Break from this case*/
		break;

		/*In case of output*/
		case OUTPUT:

		/*Setting the specified pins in DDRx register*/
		*garr_ddrArray[au8_port] |= (au8_pin);

		/*Break from this case*/
		break;

		/*In case of default*/
		default:

		/*Break from this case*/
		break;
	}

	/*Return from this function*/
	return;
}

void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value)
{
	/*Switching over pin value*/
	switch(au8_value)
	{
		/*In case of LOW*/
		case LOW:

		/*Clearing the specified pins in PORTx register*/
		*garr_portArray[au8_port] &= ~(au8_pin);

		/*Breaking from this case*/
		break;

		/*In case of input HIGH*/
		case HIGH:

		/*Setting the specified pins in PORTx register*/
		*garr_portArray[au8_port] |= (au8_pin);

		/*Break from this case*/
		break;

		/*In case of default*/
		default:

		/*Break from this case*/
		break;
	}

	/*Return from this function*/
	return;
}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin)
{
	/*Toggling the specified pins in PORTx register*/
	*garr_portArray[au8_port] ^= (au8_pin);

	/*Return from this function*/
	return;
}

void mdio_getPinValue(u8_t au8_port, u8_t au8_pin, u8_t* pu8_pinValue)
{
	/*Checking the PINx value for a specified port pin if it's LOW or not*/
	if( (*garr_pinArray[au8_port] & au8_pin) == LOW )
	{
		/*Setting the pin value as LOW*/
		*pu8_pinValue = LOW;
	}
	else
	{
		/*Satting the pin value as HIGH*/
		*pu8_pinValue = HIGH;
	}

	/*Return from this function*/
	return;
}