/*****************************************************************************
* Product: DPP on MSP-EXP430G2 board, cooperative QV kernel
* Last updated for version 6.9.1
* Last updated on  2020-09-22
*
*                    Q u a n t u m  L e a P s
*                    ------------------------
*                    Modern Embedded Software
*
* Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Alternatively, this program may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GNU General Public License and are specifically designed for
* licensees interested in retaining the proprietary status of their code.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <www.gnu.org/licenses/>.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*****************************************************************************/
#include "qpc.h"
#include "dpp.h"
#include "bsp.h"

#include <msp430g2553.h>  /* MSP430 variant used */
/* add other drivers if necessary... */

//Q_DEFINE_THIS_FILE

/* random seed */
static uint32_t l_rnd;

/* Local-scope objects -----------------------------------------------------*/
/* 1MHz clock setting, see BSP_init() */
#define BSP_MCK     1000000U
#define BSP_SMCLK   1000000U

/* LEDs on the MSP-EXP430G2 board */
#define LED1        (1U << 0)
#define LED2        (1U << 6)

/* Buttons on the MSP-EXP430G2 board */
#define BTN1        (1U << 3)


/* ISRs used in this project ===============================================*/
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
    __interrupt void TIMER0_A0_ISR(void); /* prototype */
    #pragma vector=TIMER0_A0_VECTOR
    __interrupt void TIMER0_A0_ISR(void)
#elif defined(__GNUC__)
    __attribute__ ((interrupt(TIMER0_A0_VECTOR)))
    void TIMER0_A0_ISR(void)
#else
    #error MSP430 compiler not supported!
#endif
{
    /* state of the button debouncing, see below */
    static struct ButtonsDebouncing {
        uint8_t depressed;
        uint8_t previous;
    } buttons = { (uint8_t)~0U, (uint8_t)~0U };
    uint8_t current;
    uint8_t tmp;

#ifdef NDEBUG
    __low_power_mode_off_on_exit(); /* see NOTE1 */
#endif

    TACTL &= ~TAIFG;   /* clear the interrupt pending flag */

    QTIMEEVT_TICK_X(0U, (void *)0);  /* process all time events at rate 0 */

    /* Perform the debouncing of buttons. The algorithm for debouncing
    * adapted from the book "Embedded Systems Dictionary" by Jack Ganssle
    * and Michael Barr, page 71.
    */
    current = ~P1IN; /* read P1 port with the state of BTN1 */
    tmp = buttons.depressed; /* save the debounced depressed buttons */
    buttons.depressed |= (buttons.previous & current); /* set depressed */
    buttons.depressed &= (buttons.previous | current); /* clear released */
    buttons.previous   = current; /* update the history */
    tmp ^= buttons.depressed;     /* changed debounced depressed */
    if ((tmp & BTN1) != 0U) {     /* debounced BTN1 state changed? */
        if ((buttons.depressed & BTN1) != 0U) { /* is BTN1 depressed? */
            QACTIVE_POST(AO_Table, &pauseEvt, 0U);
        }
        else {            /* the button is released */
            QACTIVE_POST(AO_Table, &serveEvt, 0U);
        }
    }
}

/* BSP functions ===========================================================*/
void BSP_init(void) {
    WDTCTL = WDTPW | WDTHOLD; /* stop watchdog timer */

    /* configure the Basic Clock Module */
    DCOCTL = 0;             /* Select lowest DCOx and MODx settings */
    BCSCTL1 = CALBC1_1MHZ;  /* Set DCO */
    DCOCTL = CALDCO_1MHZ;

    /* configure pins for LEDs */
    P1DIR |= (LED1 | LED2); /* set LED1 and LED2 pins to output */

    /* configure pin for Button */
    P1DIR &= ~BTN1;   /* set BTN1 pin as input */
    P1OUT |= BTN1;    /* drive output to hi */
    P1REN |= BTN1;    /* enable internal pull up register */
}
/*..........................................................................*/
void BSP_displayPhilStat(uint8_t n, char const *stat) {
    if (stat[0] == 'h') { /* is Philo hungry? */
        P1OUT |=  LED1;  /* turn LED1 on */
    }
    else {
        P1OUT &= ~LED1;  /* turn LED1 off */
    }
}
/*..........................................................................*/
void BSP_displayPaused(uint8_t paused) {
    /* not enough LEDs to implement this feature */
    if (paused != 0U) {
        //P1OUT |=  LED1;
    }
    else {
        //P1OUT &= ~LED1;
    }
}
/*..........................................................................*/
uint32_t BSP_random(void) { /* a very cheap pseudo-random-number generator */
    /* "Super-Duper" Linear Congruential Generator (LCG)
    * LCG(2^32, 3*7*11*13*23, 0, seed)
    */
    l_rnd = l_rnd * ((uint32_t)3U*7U*11U*13U*23U);

    return l_rnd >> 8;
}
/*..........................................................................*/
void BSP_randomSeed(uint32_t seed) {
    l_rnd = seed;
}
/*..........................................................................*/
void BSP_terminate(int16_t result) {
    (void)result;
}


/* QF callbacks ============================================================*/
void QF_onStartup(void) {
    TACTL  = (ID_3 | TASSEL_2 | MC_1);  /* SMCLK, /8 divider, upmode */
    TACCR0 = (((BSP_SMCLK / 8U) + BSP_TICKS_PER_SEC/2U) / BSP_TICKS_PER_SEC);
    CCTL0 = CCIE;  /* CCR0 interrupt enabled */
}
/*..........................................................................*/
void QF_onCleanup(void) {
}
/*..........................................................................*/
void QV_onIdle(void) { /* NOTE: called with interrutps DISABLED, see NOTE1 */
    /* toggle LED2 on and then off, see NOTE2 */

    P1OUT |=  LED2;  /* turn LED2 on */
    P1OUT &= ~LED2;  /* turn LED2 off */

#ifdef NDEBUG
    /* Put the CPU and peripherals to the low-power mode.
    * you might need to customize the clock management for your application,
    * see the datasheet for your particular MSP430 MCU.
    */
    __low_power_mode_1(); /* enter LPM1; also ENABLES interrupts */
#else
    QF_INT_ENABLE(); /* just enable interrupts */
#endif
}

/*..........................................................................*/
Q_NORETURN Q_onAssert(char const * const module, int_t const loc) {
    /*
    * NOTE: add here your application-specific error handling
    */
    /* write invalid password to WDT: cause a password-validation RESET */
    WDTCTL = 0xDEAD;
}

/*****************************************************************************
* NOTE1:
* With the cooperative QV kernel for MSP430, it is necessary to explicitly
* turn the low-power mode OFF in the interrupt, because the return
* from the interrupt will restore the CPU status register, which will
* re-enter the low-power mode. This, in turn, will prevent the QV event-loop
* from running.
*
* NOTE2:
* One of the LEDs is used to visualize the idle loop activity. The brightness
* of the LED is proportional to the frequency of invocations of the idle loop.
* Please note that the LED is toggled with interrupts disabled, so no
* interrupt execution time contributes to the brightness of the User LED.
*/

