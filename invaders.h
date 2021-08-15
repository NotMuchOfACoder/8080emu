   $ hexdump -v invaders.h    

   0000000 00 00 00 c3 d4 18 00 00 f5 c5 d5 e5 c3 8c 00 00    
   0000010 f5 c5 d5 e5 3e 80 32 72 20 21 c0 20 35 cd cd 17    
   0000020 db 01 0f da 67 00 3a ea 20 a7 ca 42 00 3a eb 20    
   0000030 fe 99 ca 3e 00 c6 01 27 32 eb 20 cd 47 19 af 32    
   0000040 ea 20 3a e9 20 a7 ca 82 00 3a ef 20 a7 c2 6f 00    
   0000050 3a eb 20 a7 c2 5d 00 cd bf 0a c3 82 00 3a 93 20    
   0000060 a7 c2 82 00 c3 65 07 3e 01 32 ea 20 c3 3f 00 cd    
   0000070 40 17 3a 32 20 32 80 20 cd 00 01 cd 48 02 cd 13    
   ...    
   0000 00       NOP    
   0001 00       NOP    
   0002 00       NOP    
   0003 c3 d4 18 JMP    $18d4    
   0006 00       NOP    
   0007 00       NOP    
   0008 f5       PUSH   PSW    
   0009 c5       PUSH   B    
   000a d5       PUSH   D    
   000b e5       PUSH   H    
   000c c3 8c 00 JMP    $008c    
   000f 00       NOP    
   0010 f5       PUSH   PSW    
   0011 c5       PUSH   B    
   0012 d5       PUSH   D    
   0013 e5       PUSH   H    
   0014 3e 80    MVI    A,#0x80    
   0016 32 72 20 STA    $2072    
   0000 NOP    
   0001 NOP    
   0002 NOP    
   0003 JMP    $18d4    
   0006 NOP    
   0007 NOP    
   0008 PUSH   PSW    
   0009 PUSH   B    
   000a PUSH   D    
   000b PUSH   H    
   000c JMP    $008c    
   000f NOP    
   0010 PUSH   PSW    
   0011 PUSH   B    
   0012 PUSH   D    
   0013 PUSH   H    
   0014 MVI    A,#$80    
   0016 STA    $2072    
   0019 LXI    H,#$20c0    
   001c DCR    M    
   001d CALL   $17cd    
   0020 IN     #$01    
   0022 RRC    
   0023 JC     $0067    
   0026 LDA    $20ea    
   0029 ANA    A    
   002a JZ     $0042    
   002d LDA    $20eb    
   0030 CPI    #$99    
   0032 JZ     $003e    
   0035 ADI    #$01    
   0037 DAA    
   0038 STA    $20eb    
   003b CALL   $1947    
   003e SRA    A    
   003f STA    $20ea    

   /*    
   0000000 00 00 00 c3 d4 18 00 00 f5 c5 d5 e5 c3 8c 00 00    
   0000010 f5 c5 d5 e5 3e 80 32 72 20 21 c0 20 35 cd cd 17    
   0000020 db 01 0f da 67 00 3a ea 20 a7 ca 42 00 3a eb 20    
   0000030 fe 99 ca 3e 00 c6 01 27 32 eb 20 cd 47 19 af 32    
   */    
cat invaders.h > invaders    
   cat invaders.g >> invaders    
   cat invaders.f >> invaders    
   cat invaders.e >> invaders    
      18d4 LXI    SP,#$2400    
   18d7 MVI    B,#$00    
   18d9 CALL   $01e6    
   01e6 LXI    D,#$1b00    
   01e9 LXI    H,#$2000    
   01ec JMP    $1a32    
   .....    
   1a32 LDAX   D    
   1a33 MOV    M,A    
   1a34 INX    H    
   1a35 INX    D    
   1a36 DCR    B    
   1a37 JNZ    $1a32    
   1a3a RET    
   18d4 LXI    SP,#$2400  ; SP=$2400 - Establish stack for whole program    
   18d7 MVI    B,#$00     ; B=0    
   18d9 CALL   $01e6    
   .....    
   01e6 LXI    D,#$1b00   ; DE=$1B00    
   01e9 LXI    H,#$2000   ; HL=$2000    
   01ec JMP    $1a32    
   .....    
   1a32 LDAX   D          ; A = (DE), so whatever was in memory at $1B00    
   1a33 MOV    M,A        ; Store A into (HL), so to $2000    
   1a34 INX    H          ; HL = HL + 1 (now $2001)    
   1a35 INX    D          ; DE = DE + 1 (now $1B01)    
   1a36 DCR    B          ; B = B - 1 (now 0xff because it wrapped around from 0)    
   1a37 JNZ    $1a32      ; loop, will be taken until b=0    
   1a3a RET   
   
