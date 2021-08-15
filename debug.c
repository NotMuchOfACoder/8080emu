   $ gdb a.out    
   GNU gdb 6.3.50-20050815 (Apple version gdb-1708) (Mon Aug  8 20:32:45 UTC 2011)    
   Copyright 2004 Free Software Foundation, Inc.    
   GDB is free software, covered by the GNU General Public License, and you are    
   welcome to change it and/or distribute copies of it under certain conditions.    
   Type "show copying" to see the conditions.    
   There is absolutely no warranty for GDB.  Type "show warranty" for details.    
   This GDB was configured as "x86_64-apple-darwin"...Reading symbols for shared libraries .. done    

   #set a breakpoint so the program will stop at my routine    
   (gdb) b Disassemble8080Op    
   Breakpoint 1 at 0x1000012ef: file 8080dis.c, line 7.    

   #start the program with "invaders.h" as the argument    
   (gdb) run invaders.h    
   Starting program: /Users/bob/Desktop/invaders/a.out invaders.h    
   Reading symbols for shared libraries +........................ done    

   Breakpoint 1, Disassemble8080Op (codebuffer=0x100801000 "", pc=0) at 8080dis.c:7    
   7        unsigned char *code = &codebuffer[pc];    
   #gdb interprets n as "next".  You can also type "next"    
   (gdb) n    
   8        int opbytes = 1;    
   #p is short for "print", I want to see the value of *code    
   (gdb) p *code    
   $1 = 0 '\0'    
   (gdb) n    
   9        printf("%04x ", pc);    
   # If you just hit "return", gdb will do the same command again, in this case "next"    
   (gdb)    
   10       switch (*code)    
   (gdb) n    
   #opcode was zero, so it's going to go print "NOP"    
   12           case 0x00: printf("NOP"); break;    
   (gdb) n    
   285      printf("\n");    
   #c is "continue", so it will run until the next breakpoint    
   (gdb) c    
   Continuing.    
   0000 NOP    

   # It stopped at the top of Disassemble8080Op again.  I printed *opcode,    
   # saw it was going to be another NOP, so I just continued.    
   Breakpoint 1, Disassemble8080Op (codebuffer=0x100801000 "", pc=1) at 8080dis.c:7    
   7        unsigned char *code = &codebuffer[pc];    
   (gdb) c    
   Continuing.    
   0001 NOP    

   Breakpoint 1, Disassemble8080Op (codebuffer=0x100801000 "", pc=2) at 8080dis.c:7    
   7        unsigned char *code = &codebuffer[pc];    
   (gdb) n    
   8        int opbytes = 1;    
   (gdb) p *code    
   $2 = 0 '\0'    
   # The 3rd NOP, not interesting    
   (gdb) c    
   Continuing.    
   0002 NOP    

   Breakpoint 1, Disassemble8080Op (codebuffer=0x100801000 "", pc=3) at 8080dis.c:7    
   7        unsigned char *code = &codebuffer[pc];    
   (gdb) n    
   8        int opbytes = 1;    

   # Here's a new opcode!    
   (gdb) p *code    
   $3 = 195 '?'    
   # print gives decimal by default, but you can use /x to show hexadecimal numbers    
   (gdb) p /x *code    
   $4 = 0xc3    
   (gdb) n    
   9        printf("%04x ", pc);    
   (gdb)    
   10       switch (*code)    
   (gdb)    
   # C3 is a jump.  Neat.    
   219          case 0xc3: printf("JMP    $%02x%02x",code[2],code[1]); opbytes = 3; break;    
   (gdb)    
   285      printf("\n");    
