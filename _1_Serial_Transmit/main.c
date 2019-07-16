


// AVR Send Character  string "Hello from ATmega328p" Continously to the PC using Serial port.
// PC receives the data and displays on terminal.
// External Oscillator = 11.0592MHz

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
	int i = 0;
	unsigned int ubrr = BAUD_RATE_230400_BPS;
	
	unsigned char data[] = "Hello from ATmega328p  ";
	
	/* Set Baudrate  */
	UBRR0H = (ubrr>>8); // Shift the 16bit value ubrr 8 times to the right and transfer the upper 8 bits to UBBR0H register.
	UBRR0L = (ubrr);    // Copy the 16 bit value ubrr to the 8 bit UBBR0L register,Upper 8 bits are truncated while lower 8 bits are copied
	
	

	UCSR0C = 0x06;       /* Set frame format: 8data, 1stop bit  */
	UCSR0B = (1<<TXEN0); /* Enable  transmitter                 */
	
	while(1) /* Loop the messsage continously */
	{ 
	    i = 0;
		while(data[i] != 0) /* print the String  "Hello from ATmega328p" */
		{
			while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer       */
			
											 /* When UDRE0 = 0,data transmisson ongoing.                         */
											 /* So NOT{[UCSR0A & (1<<UDRE0)] = 0} = 1 ,While(1) loop stays there */
											 
											 /* When UDRE0 = 1,data transmisson completed.                       */
											 /* So NOT{[UCSR0A & (1<<UDRE0)] = 1} = 0 ,While(0) loop fails       */
											 
			UDR0 = data[i];					 /* Put data into buffer, sends the data */
			i++;                             /* increment counter                    */
		}
		
		
		/* Sending '\n'  '\r' Character pair helps to format the output properly on console putty Screen */
		/*************************************************************************************************/
		/* Send "\n" Character */
		 while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
		 UDR0 = '\n';					    /* Put data into buffer, sends the data */
		
		/* Send "\r" Character */
		 while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
		 UDR0 = '\r';					    /* Put data into buffer, sends the data */
		/*------------------------------------------------------------------------------------------------*/
		
		_delay_ms(100);
		
		
	}	
		
}//end of main























