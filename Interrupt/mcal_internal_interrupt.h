/* 
 * File:   mcal_internal_interrupt.h
 * Author: Abdallah Saad
 * Created on November 28, 2023, 8:43 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/

#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the ADC Module */
#define ADC_InterruptDisable()         (PIE1bits.ADIE = 0)
/* This routine sets the interrupt enable for the ADC Module */
#define ADC_InterruptEnable()          (PIE1bits.ADIE = 1)
/* This routine clears the interrupt flag for the ADC Module */
#define ADC_InterruptFlagClear()       (PIR1bits.ADIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the ADC Module Interrupt Priority to be High priority */
#define ADC_HighPrioritySet()          (IPR1bits.ADIP = 1)
/* This routine set the ADC Module Interrupt Priority to be Low priority */
#define ADC_LowPrioritySet()           (IPR1bits.ADIP = 0)
#endif
#endif

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the EUSART Module */
#define EUSART_TX_InterruptDisable()         (PIE1bits.TXIE = 0)
/* This routine sets the interrupt enable for the EUSART Module */
#define EUSART_TX_InterruptEnable()          (PIE1bits.TXIE = 1)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the EUSART Module Interrupt Priority to be High priority */
#define EUSART_TX_HighPrioritySet()          (IPR1bits.TXIP = 1)
/* This routine set the EUSART Module Interrupt Priority to be Low priority */
#define EUSART_TX_LowPrioritySet()           (IPR1bits.TXIP = 0)
#endif
#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the EUSART Module */
#define EUSART_RX_InterruptDisable()         (PIE1bits.RCIE = 0)
/* This routine sets the interrupt enable for the EUSART Module */
#define EUSART_RX_InterruptEnable()          (PIE1bits.RCIE = 1)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the EUSART Module Interrupt Priority to be High priority */
#define EUSART_RX_HighPrioritySet()          (IPR1bits.RCIP = 1)
/* This routine set the EUSART Module Interrupt Priority to be Low priority */
#define EUSART_RX_LowPrioritySet()           (IPR1bits.RCIP = 0)
#endif
#endif

#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptDisable()         (INTCONbits.TMR0IE = 0)
/* This routine sets the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptEnable()          (INTCONbits.TMR0IE = 1)
/* This routine clears the interrupt flag for the TIMER0 Module */
#define TIMER0_InterruptFlagClear()       (INTCONbits.TMR0IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the TIMER0 Module Interrupt Priority to be High priority */
#define TIMER0_HighPrioritySet()          (INTCON2bits.TMR0IP = 1)
/* This routine set the TIMER0 Module Interrupt Priority to be Low priority */
#define TIMER0_LowPrioritySet()           (INTCON2bits.TMR0IP = 0)
#endif
#endif

#if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the TIMER1 Module */
#define TIMER1_InterruptDisable()         (PIE1bits.TMR1IE = 0)
/* This routine sets the interrupt enable for the TIMER1 Module */
#define TIMER1_InterruptEnable()          (PIE1bits.TMR1IE = 1)
/* This routine clears the interrupt flag for the TIMER1 Module */
#define TIMER1_InterruptFlagClear()       (PIR1bits.TMR1IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the TIMER1 Module Interrupt Priority to be High priority */
#define TIMER1_HighPrioritySet()          (IPR1bits.TMR1IP = 1)
/* This routine set the TIMER1 Module Interrupt Priority to be Low priority */
#define TIMER1_LowPrioritySet()           (IPR1bits.TMR1IP = 0)
#endif
#endif

#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the TIMER2 Module */
#define TIMER2_InterruptDisable()         (PIE1bits.TMR2IE = 0)
/* This routine sets the interrupt enable for the TIMER2 Module */
#define TIMER2_InterruptEnable()          (PIE1bits.TMR2IE = 1)
/* This routine clears the interrupt flag for the TIMER2 Module */
#define TIMER2_InterruptFlagClear()       (PIR1bits.TMR2IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the TIMER2 Module Interrupt Priority to be High priority */
#define TIMER2_HighPrioritySet()          (IPR1bits.TMR2IP = 1)
/* This routine set the TIMER2 Module Interrupt Priority to be Low priority */
#define TIMER2_LowPrioritySet()           (IPR1bits.TMR2IP = 0)
#endif
#endif

#if TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the TIMER3 Module */
#define TIMER3_InterruptDisable()         (PIE2bits.TMR3IE = 0)
/* This routine sets the interrupt enable for the TIMER3 Module */
#define TIMER3_InterruptEnable()          (PIE2bits.TMR3IE = 1)
/* This routine clears the interrupt flag for the TIMER3 Module */
#define TIMER3_InterruptFlagClear()       (PIR2bits.TMR3IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the TIMER3 Module Interrupt Priority to be High priority */
#define TIMER3_HighPrioritySet()          (IPR2bits.TMR3IP = 1)
/* This routine set the TIMER3 Module Interrupt Priority to be Low priority */
#define TIMER3_LowPrioritySet()           (IPR2bits.TMR3IP = 0)
#endif
#endif

#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the MSSP I2C Module */
#define MSSP_I2C_InterruptDisable()         (PIE1bits.SSPIE = 0)
#define MSSP_I2C_BUS_COL_InterruptDisable() (PIE2bits.BCLIE = 0)
/* This routine sets the interrupt enable for the MSSP I2C Module */
#define MSSP_I2C_InterruptEnable()          (PIE1bits.SSPIE = 1)
#define MSSP_I2C_BUS_COL_InterruptEnable()  (PIE2bits.BCLIE = 1)
/* This routine clears the interrupt flag for the MSSP I2C Module */
#define MSSP_I2C_InterruptFlagClear()         (PIR1bits.SSPIF = 0)
#define MSSP_I2C_BUS_COL_InterruptFlagClear() (PIR2bits.BCLIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the MSSP I2C Module Interrupt Priority to be High priority */
#define MSSP_I2C_HighPrioritySet()          (IPR1bits.SSPIP = 1)
#define MSSP_I2C_BUS_COL_HighPrioritySet()  (IPR2bits.BCLIP = 1)
/* This routine set the MSSP I2C Module Interrupt Priority to be Low priority */
#define MSSP_I2C_LowPrioritySet()           (IPR1bits.SSPIP = 0)
#define MSSP_I2C_BUS_COL_LowPrioritySet()   (IPR2bits.BCLIP = 0)
#endif
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the CCP1 Module */
#define CCP1_InterruptDisable()         (PIE1bits.CCP1IE = 0)
/* This routine sets the interrupt enable for the CCP1 Module */
#define CCP1_InterruptEnable()          (PIE1bits.CCP1IE = 1)
/* This routine clears the interrupt flag for the CCP1 Module */
#define CCP1_InterruptFlagClear()       (PIR1bits.CCP1IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the CCP1 Module Interrupt Priority to be High priority */
#define CCP1_HighPrioritySet()          (IPR1bits.CCP1IP = 1)
/* This routine set the CCP1 Module Interrupt Priority to be Low priority */
#define CCP1_LowPrioritySet()           (IPR1bits.CCP1IP = 0)
#endif
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the CCP2 Module */
#define CCP2_InterruptDisable()         (PIE2bits.CCP2IE = 0)
/* This routine sets the interrupt enable for the CCP2 Module */
#define CCP2_InterruptEnable()          (PIE2bits.CCP2IE = 1)
/* This routine clears the interrupt flag for the CCP2 Module */
#define CCP2_InterruptFlagClear()       (PIR2bits.CCP2IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the CCP2 Module Interrupt Priority to be High priority */
#define CCP2_HighPrioritySet()          (IPR2bits.CCP2IP = 1)
/* This routine set the CCP2 Module Interrupt Priority to be Low priority */
#define CCP2_LowPrioritySet()           (IPR2bits.CCP2IP = 0)
#endif
#endif

#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the SPI Module */
#define MSSP_SPI_InterruptDisable()         (PIE1bits.SSPIE = 0)
/* This routine sets the interrupt enable for the SPI Module */
#define MSSP_SPI_InterruptEnable()          (PIE1bits.SSPIE = 1)
/* This routine clears the interrupt flag for the SPI Module */
#define MSSP_SPI_InterruptFlagClear()       (PIR1bits.SSPIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the SPI Module Interrupt Priority to be High priority */
#define MSSP_SPI_HighPrioritySet()          (IPR1bits.SSPIP = 1)
/* This routine set the SPI Module Interrupt Priority to be Low priority */
#define MSSP_SPI_LowPrioritySet()           (IPR1bits.SSPIP = 0)
#endif
#endif

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/

#endif	/* MCAL_INTERNAL_INTERRUPT_H */
