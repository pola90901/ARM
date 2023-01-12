/*
 * RCC_Program.c
 *
 *  Created on: Dec 25, 2022
 *      Author: mohan
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_CALC.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


void MGPIO_SetPinSpeed(u8 A_u8PortID,u8 A_u8PinID,u8 A_u8Speed)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(3<<(2*A_u8PinID));
		GPIOA->OSPEEDR |= (A_u8Speed<<(2*A_u8PinID));
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(3<<(2*A_u8PinID));
		GPIOB->OSPEEDR |= (A_u8Speed<<(2*A_u8PinID));
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(3<<(2*A_u8PinID));
		GPIOC->OSPEEDR |= (A_u8Speed<<(2*A_u8PinID));
		break;
	}
}

void MGPIO_SetPinMode(u8 A_u8PortID,u8 A_u8PinID,u8 A_u8Mode)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(3<<(2*A_u8PinID));
		GPIOA->MODER |= (A_u8Mode<<(2*A_u8PinID));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(3<<(2*A_u8PinID));
		GPIOB->MODER |= (A_u8Mode<<(2*A_u8PinID));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(3<<(2*A_u8PinID));
		GPIOC->MODER |= (A_u8Mode<<(2*A_u8PinID));
		break;
	}
}

void MGPIO_SetOutputPinValue(u8 A_u8PortID,u8 A_u8PinID,u8 A_u8Value)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		switch(A_u8Value)
		{
		case OUTPUT: SetPin(GPIOA->ODR,A_u8PinID);		break;
		case INPUT : ClearPin(GPIOA->ODR,A_u8PinID);	break;
		}break;

	case GPIO_PORTB:
		switch(A_u8Value)
		{
		case OUTPUT: SetPin(GPIOB->ODR,A_u8PinID);		break;
		case INPUT : ClearPin(GPIOB->ODR,A_u8PinID);	break;
		}break;

	case GPIO_PORTC:
		switch(A_u8Value)
		{
		case OUTPUT: SetPin(GPIOC->ODR,A_u8PinID);		break;
		case INPUT : ClearPin(GPIOC->ODR,A_u8PinID);	break;
		}break;
	}
}

