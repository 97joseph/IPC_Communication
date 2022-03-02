# IPC_Communication
 Interprocess Communication Lines
 Purpose
The goal of this exercise is to review the fundamental components of data communication.

What to Do
You are to write two C programs: (1) a synchronous producer, and (2) a synchronous consumer. Both programs will assume the use of ASCII codes with odd bit parity. The producer and consumer communication to be implemented makes use of a set of files. Details regarding such files are provided by the table below.

File Characteristics

Naming	Contents	Created by	Accessed by-

filename.inpf	any ASCII character	user	producer

filename.binf	(0 and 1) ASCII characters	producer	consumer

filename.outf	any ASCII character	consumer	user


1. The Synchronous Producer
Creates files of bits (‘0’ and ‘1’ characters) from the input files. All valid input files contain data made up of ASCII characters and have the .inpf file extension. The data to be transmitted must be structured as a set of blocks. Each block will consist of 2 SYN characters, ASCII 22, one control character to indicate the length of data block followed by a maximum of 64 data characters. Assume that there are no trailing control characters. Every block transmitted must contain 64 data characters except possibly the case where the remainder of the file cannot fill the buffer. Each character will consist of 7 information bits and a parity bit. The two tables below illustrate the structure of a block created to transmit the “BCCA” character string. The top table shows the frame contents in decimal and in the bottom table the actual contents of the frame have been encoded with characters ‘0’ and ‘1’ to simulate the binary representation of the characters used.

2222	4	BCCA

0001011000010110	00000100	11000010010000110100001111000001 

2. The Synchronous Consumer
This program reads the files created by the Producer (.binf) as input, checks for transmission errors, decodes stream of bits, and stores the resulting information in a file (.outf).Both programs should have three distinct layers: physical, data link and application. The physical layer should contain routines to handle tasks such as converting a character into a binary bit pattern, calculating and including a parity bit, and writing bits into an output file (i.e., transmission of bits). It should also include routines for reading bits from a file (i.e., reception of bits) and converting bits into characters. The data link layer should contain routines for framing (putting two SYN characters, a LENGTH character, and data into a frame) and deframing (separating those control characters from data characters). The application layer should contain routines to handle tasks such as reading data to be transmitted from input data file in the Producer and writing received data into display (or output data file) in the Consumer, as well as any other routines that you feel necessary.  Your solution must also include a module to simulate transmission errors. 

3. Details
The following are the tasks to be done for this project:
a.	Create a simple consumer/producer (transmitter/receiver; client/server) application as discussed in this document that uses a simple odd parity bit and a file for "data transmission". 
b.	Design and implement the Error Creation module. This component must, in a random way, change a single bit as well as more than one bit in the message. Your function must have the number of bits that are to be modified as an input parameter. It must also inform the user the frame, byte and bit locations of the errors introduced. The receiver must be able to report the location of errors introduced during transmission.

