#include <stdio.h>
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
           // DATA TRANSFER
           case 0x40: printf("MOV"); break;
           //ARITHMETIC
           //LOGICAL OPERATIONS
           //BRANCHING
           //STACK I/O and MACHINE CONTROL
           case 0x00: printf("NOP"); break;
       }
   }