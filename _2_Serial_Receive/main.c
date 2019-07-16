// AVR Serial Reception @ 230.4k bps
// AVR Receives character 'A' Blinks the LED  on PC4
//                        'B' Beeps  the Buzzer on PC5
// External Oscillator = 11.0592MHz
// Controller ATmega328p


//+------------------------------------------------------------------------------------------------+
//| Compiler           : AVR GCC (WinAVR)                                                          |
//| Microcontroller    : ATmega328p                                                                |
//| Programmer         : Rahul.Sreedharan                                                          |
//| Date               : 16-July-2019                                                              |
//+------------------------------------------------------------------------------------------------+

//(C) www.xanthium.in 
// Visit to Learn More 


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

// +-----------------------------------------------------------------------+ //
// | ATmega328p Baudrate values for UBRRn for external crystal 11.0592MHz  | //
// +-----------------------------------------------------------------------+ //

#define BAUD_RATE_4800_BPS  143 // 4800bps
#define BAUD_RATE_9600_BPS  71  // 9600bps

#define BAUD_RATE_14400_BPS  47 // 14.4k bps
#define BAUD_RATE_19200_BPS  35 // 19.2k bps  
#define BAUD_RATE_28800_BPS  23 // 28.8k bps
#define BAUD_RATE_38400_BPS  17 // 38.4k bps
#define BAUD_RATE_57600_BPS  11 // 57.6k bps
#define BAUD_RATE_76800_BPS   8 // 76.8k bps

#define BAUD_RATE_115200_BPS  5 // 115.2k bps
#define BAUD_RATE_230400_BPS  2 // 230.4k bps

// +-----------------------------------------------------------------------+ //


int main()
{
	
	unsigned int ubrr = BAUD_RATE_230400_BPS; 
	
	PORTC = 0x00; //All LED's OFF
	PORTD = 0x00;
	
	/* Set Baudrate @ 230.4k bps */
	UBRR0H = (ubrr>>8);
	UBRR0L = (ubrr);
	
	/*Enable receiver  */
	UCSR0B = (1<<RXEN0);
	
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = 0x06;
	
	while(1)
	{
		while ( !(UCSR0A & (1<<RXC0)) ); /* Wait for data to be received */
	
		switch(UDR0) // using the switch() statement to  control the LED and Buzzer		
		{
			case 'A' : 	DDRC  |= (1<<PC4); // Blinks LED
						PORTC |= (1<<PC4);
						_delay_ms(500);
						PORTC &= ~(1<<PC4);
						break;
				
            case 'B' : 	DDRC  |= (1<<PC5); // Beeps Buzzer
						PORTC |= (1<<PC5);
						_delay_ms(500);
						PORTC &= ~(1<<PC5);
						break;			
						
			default  :
						break;
		}//end of Switch()
	}//end of While(1)
}//end of main
	
	
	
	
	






















