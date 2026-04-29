/*
 * peripherals.c
 *
 *  Created on: Apr 7, 2026
 *      Author: Pedro
 */

/*
 * PA5 Built in LED
 * PC13 Built in Button
 *
 */

#include "stm32l4xx_hal.h"

void init_GPIO_SETUP(void) {

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	GPIOA->MODER &= ~(0b11 << (5*2));       //Reset PA5 mode
	GPIOA->MODER |= (0b01 << (5*2));        //Set PA5 to output
	GPIOC->MODER &= ~(0b11 << (13*2));      //Reset PC13 mode to input

	GPIOA->OSPEEDR &= ~(0b11 << (5*2));     //Reset PA5 speed to low speed
	GPIOC->OSPEEDR &= ~(0b11 << (13*2));    //Reset PA13 speed to low speed

	GPIOA->PUPDR &= ~(0b11 << (5*2));       //Reset PA5 PUPD to default
	GPIOC->PUPDR &= ~(0b11 << (13*2));      //Reset PA13 PUPD to default
	GPIOC->PUPDR |= (0b10 << (13*2));       //Set PA13 to PD

}

