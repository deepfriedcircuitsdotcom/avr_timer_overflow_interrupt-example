#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_OVF_vect) {
    PORTB ^= (1<<0);      //toggle PORTB0
}

ISR(TIMER0_OVF_vect) {
    PORTB ^= (1<<1);      //toggle PORTB1
}

int main(void) {

    DDRB |= (1<<0);        //set PORTB0 as output
    PORTB &= ~(1<<0);      //clear PORTB0
    DDRB |= (1<<1);        //set PORTB1 as output
    PORTB &= ~(1<<1);      //clear PORTB0

    TCCR0B |= (1<<CS00);  //timer 0 no prescaler
    TIMSK0 |= (1<<TOIE0); //timer/counter 0 overflow interrupt enable

    TCCR1B |= (1<<CS10);  //timer 1 no prescaler
    TIMSK1 |= (1<<TOIE1); //timer/counter 0 overflow interrupt enable

    sei();                //set global interrupt

    while(1) 
    {

    }

}
