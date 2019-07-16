# ATmega238p to PC Serial Communication(RX/TX) using USART  

A collection of sample codes for communicating with Linux/Windows PC from an ATmega328p microcontroller using USART in asynchronous mode.

<img src = "https://www.xanthium.in/sites/default/files/site-images/atmega328p-usart-tutorial/atmega328p-pc-serial-communication-tutorial.jpg"/>

## Code

- Sourcecode written in **Embedded C**. 
- Compiled using **AVR-GCC** using **Make** utility.
- Code can be uploaded using AVRDUDE and any compatible programmer.

## Hardware setup

- Code tested on ATmega328p (32 pin TQFP).
- ATmega328p Clocked with a **11.0592MHz external crystal**.
- USB to Serial Converter used to connect ATmega328p with PC 

## ATmega328p Clocking (Fuse Bits)
- External 11.0592MHz Crystal
- *avrdude -c usbasp -p m328p -U lfuse:w:0xFF:m*

## Online Documentation

- <a href="https://www.xanthium.in/how-to-configuring-atmega328p-fuse-low-byte-embedded-design-use-external-crystal-fuse-settings">Configuring the ATmega328p Microcontroller to use external crystal</a>

- <a href ="https://www.xanthium.in/how-to-avr-atmega328p-microcontroller-usart-uart-embedded-programming-avrgcc">ATmega328p USART serial communication tutorial</a>
- www.xanthium.in
