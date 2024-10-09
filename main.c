#include <stdio.h>
//Name: Nicholas Wise
//Project Discription:
// Emulating Space invaders using the Intel 8080 microcomputer
/*
 *codebuffer is a valid pointer to 8080 assembly code
 pc is the current offset into the code

 returns the number of bytes of the op
 */
   int Disassemble8080Op(unsigned char *codebuffer, int pc) {
       unsigned char *code = &codebuffer[pc];
       int opbytes = 1;
       printf("%04x", pc);
       switch(*code) {
           /// // DATA TRANSFER // ///
           // SSS is source, and DDD is destination
           // We have 7 registers that use these ID's:
           // A 111
           // B 000
           // C 001
           // D 010
           // E 011
           // H 100
           // L 101
           // MOV is used to move data from Register to Register and is formated as follows:
               // 01 DDD SSS
               // As an example, if we wanted to move data from register C to register E The OP code would be 01 011 001
               // which can be written as 01011001 which equals 0x59 in hex format
           //For Data that is being moved from Memory to a register we use the format as follows:
               // Memory address is in registers H and L
               // 01 DDD 110 for r<-M
               // 01 110 SSS for M<-r
           case 0x40: printf("MOV B,B"); break;
           case 0x41: printf("MOV B,C"); break;
           case 0x42: printf("MOV B,D"); break;
           case 0x43: printf("MOV B,E"); break;
           case 0x44: printf("MOV B,H"); break;
           case 0x45: printf("MOV B,L"); break;
           case 0x46: printf("MOV B,M"); break;
           case 0x47: printf("MOV B,A"); break;
           case 0x48: printf("MOV C,B"); break;
           case 0x49: printf("MOV C,C"); break;
           case 0x4a: printf("MOV C,D"); break;
           case 0x4b: printf("MOV C,E"); break;
           case 0x4c: printf("MOV C,H"); break;
           case 0x4d: printf("MOV C,L"); break;
           case 0x4e: printf("MOV C,M"); break;   //C(001)<-M The OP code would be 01001110 (0x4e)
           case 0x4f: printf("MOV C,A"); break;
           case 0x50: printf("MOV D,B"); break;
           case 0x51: printf("MOV D,C"); break;
           case 0x52: printf("MOV D,D"); break;
           case 0x53: printf("MOV D,E"); break;
           case 0x54: printf("MOV D,H"); break;
           case 0x55: printf("MOV D,L"); break;
           case 0x56: printf("MOV D,M"); break;
           case 0x57: printf("MOV D,A"); break;
           case 0x58: printf("MOV E,B"); break;
           case 0x59: printf("MOV E,C"); break;   //E(011)<-C(001) The OP code would be 01011001 (0x59)
           case 0x5a: printf("MOV E,D"); break;
           case 0x5b: printf("MOV E,E"); break;
           case 0x5c: printf("MOV E,H"); break;
           case 0x5d: printf("MOV E,L"); break;
           case 0x5e: printf("MOV E,M"); break;
           case 0x5f: printf("MOV E,A"); break;
           case 0x60: printf("MOV H,B"); break;
           case 0x61: printf("MOV H,C"); break;
           case 0x62: printf("MOV H,D"); break;
           case 0x63: printf("MOV H,E"); break;
           case 0x64: printf("MOV H,H"); break;
           case 0x65: printf("MOV H,L"); break;
           case 0x66: printf("MOV H,M"); break;
           case 0x67: printf("MOV H,A"); break;
           case 0x68: printf("MOV L,B"); break;
           case 0x69: printf("MOV L,C"); break;
           case 0x6a: printf("MOV L,D"); break;
           case 0x6b: printf("MOV L,E"); break;
           case 0x6c: printf("MOV L,H"); break;
           case 0x6d: printf("MOV L,L"); break;
           case 0x6e: printf("MOV L,M"); break;
           case 0x6f: printf("MOV L,A"); break;
           case 0x70: printf("MOV M,B"); break;
           case 0x71: printf("MOV M,C"); break;
           case 0x72: printf("MOV M,D"); break;
           case 0x73: printf("MOV M,E"); break;
           case 0x74: printf("MOV M,H"); break;
           case 0x75: printf("MOV M,L"); break;   //M<-L(101) The OP code would be 01 110 101 (0x75)
           case 0x77: printf("MOV M,A"); break;
           case 0x78: printf("MOV A,B"); break;
           case 0x79: printf("MOV A,C"); break;
           case 0x7a: printf("MOV A,D"); break;
           case 0x7b: printf("MOV A,E"); break;
           case 0x7c: printf("MOV A,H"); break;
           case 0x7d: printf("MOV A,L"); break;   //A(111)<-L(101) The OP code would be 01 111 101
           case 0x7e: printf("MOV A,M"); break;
           case 0x7f: printf("MOV A,A"); break;

           // MVI is used to data in byte 2 into the target register as follows:
                // 00 DDD 110
           // MVI is used to move data in byte 2 into memory (address is stored in registers H and L)
                // 00110110
           case 0x06: printf("MVI B,D8"); break;   // B(000)<-Byte2 The OP code would be 00 000 110 (0x06)
           case 0x0e: printf("MVI C,D8 "); break;
           case 0x16: printf("MVI D,D8"); break;
           case 0x1e: printf("MVI E,D8 "); break;
           case 0x26: printf("MVI H,D8 "); break;
           case 0x2e: printf("MVI L,D8"); break;
           case 0x36: printf("MVI M,D8 "); break;
           case 0x3e: printf("MVI A,D8 "); break;

           // LXI is used to load Byte 3 into the high order pair and Byte 2 into the low order pair
           // Registers are paired and coded as follows:
           // B-C = 00
           // D-E = 01
           // H-L = 10
           // SP = 11 (SP is the 16-bit Pointer register)
           // The format for LXI is:
           // 00 RP 0001 (RP Stands for register pair)
           case 0x01: printf("LXI B,D16"); break;   // 00 B-C(00) 0001 = 0x01
           case 0x11: printf("LXI D,D16"); break;
           case 0x21: printf("LXI H,D16"); break;
           case 0x31: printf("LXI SP,D16"); break;

           // LDA (Load Accumulator Data)is used to load the contents of the memory location stored in byte 2 and 3
           // into register A. STA is the reverse (Store Accumulator Data)
           case 0x3a: printf("LDA adr"); break;
           case 0x32: printf("STA adr"); break;

           // LHLD (Load H and Load L Direct)
           // This is used to move the address stored in 2 bytes into the register pair HL
           case 0x2a: printf("LHLD adr"); break;

           //SHDL (Store H and L Direct)
           // This is used to move L into memory whose addres is in byte 2 an 3, H is stored in the next
           case 0x22: printf("SHDL adr"); break;

           // LDA X is just like previous LDA, but we are using other registers
           // format is 00 RP 1010
           case 0x0a: printf("LDAX B"); break;
           case 0x1a: printf("LDAX D"); break;

           // STA X (Store Accumulator indirect) is used to store data in register A, where ever
           // the address stored in provided RP is. Format is 00 RP 0010
           case 0x02: printf("STAX B"); break;
           case 0x12: printf("STAX D"); break;

           // XCHG The contents of registers H and L are exchanged with
           // the contents of registers D and E
           case 0xeb: printf("XCHG"); break;

           /// // ARITHMETIC // ///
           // Addition Operations
           // adds given register to the accumulator
           // format is 10000 SSS
           case 0x80: printf("ADD B"); break;
           case 0x81: printf("ADD C"); break;
           case 0x82: printf("ADD D"); break;   // add reg B to Acu. 10000 010
           case 0x83: printf("ADD E"); break;
           case 0x84: printf("ADD H"); break;
           case 0x85: printf("ADD L"); break;
           case 0x86: printf("ADD M"); break;   // adding memory uses address at HL
           case 0x87: printf("ADD A"); break;

           // Add data to the accumulator, contents of 2 byte
           case 0xc6: printf("ADI D8"); break;

           // ADC is just like regular additon but with carry
           case 0x88: printf("ADC B"); break;
           case 0x89: printf("ADC C"); break;
           case 0x8a: printf("ADC D"); break;
           case 0x8b: printf("ADC E"); break;
           case 0x8c: printf("ADC H"); break;
           case 0x8d: printf("ADC L"); break;
           case 0x8e: printf("ADC M"); break;
           case 0x8f: printf("ADC A"); break;

           // ACI (Add Carry Immediate) The content of the second byte of the instruction and
           // the content of the CY flag are added to the contents
           //of the accumulator. The result is placed in the accumulator
           case 0xce: printf("ACI D8"); break;

           // SUB (Subtract) contents of register are subtracted from contents of accumulator (A)
           case 0x90: printf("SUB B"); break;
           case 0x91: printf("SUB C"); break;
           case 0x92: printf("SUB D"); break;
           case 0x93: printf("SUB E"); break;
           case 0x94: printf("SUB H"); break;
           case 0x95: printf("SUB L"); break;
           case 0x96: printf("SUB M"); break;
           case 0x97: printf("SUB A"); break;

           // SUI The content of the second byte of the instruction is from the
           // content of the accumulator. The result is placed in the accumulator.
           case 0xd6: printf("SUI D8"); break;

           //



           //LOGICAL OPERATIONS
           //BRANCHING
           //STACK I/O and MACHINE CONTROL
           case 0x00: printf("NOP"); break;
       }
   }