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
