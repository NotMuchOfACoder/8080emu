   /*    
    *codebuffer is a valid pointer to 8080 assembly code    
    pc is the current offset into the code    

    returns the number of bytes of the op    
   */    

   int Disassemble8080Op(unsigned char *codebuffer, int pc)    
   {    
    unsigned char *code = &codebuffer[pc];    
    int opbytes = 1;    
    printf ("%04x ", pc);    
    switch (*code)    
    {    
        case 0x00: printf("NOP"); break;    
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;    
        case 0x02: printf("STAX   B"); break;    
        case 0x03: printf("INX    B"); break;    
        case 0x04: printf("INR    B"); break;    
        case 0x05: printf("DCR    B"); break;    
        case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes=2; break;    
        case 0x07: printf("RLC"); break;    
        case 0x08: printf("NOP"); break;    
        /* ........ */    
        case 0x3e: printf("MVI    A,#0x%02x", code[1]); opbytes = 2; break;    
        /* ........ */    
        case 0xc3: printf("JMP    $%02x%02x",code[2],code[1]); opbytes = 3; break;    
        /* ........ */    
    }    

    printf("\n");    

    return opbytes;    
   }    
   int main (int argc, char**argv)    
   {    
    FILE *f= fopen(argv[1], "rb");    
    if (f==NULL)    
    {    
        printf("error: Couldn't open %s\n", argv[1]);    
        exit(1);    
    }    

    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);    
    int fsize = ftell(f);    
    fseek(f, 0L, SEEK_SET);    

    unsigned char *buffer=malloc(fsize);    

    fread(buffer, fsize, 1, f);    
    fclose(f);    

    int pc = 0;    

    while (pc < fsize)    
    {    
        pc += Disassemble8080Op(buffer, pc);    
    }    
    return 0;    
   }    
   int Emulate8080Op(State8080* state)    
   {    
       unsigned char *opcode = &state->memory[state->pc];    
       Disassemble8080Op(state->memory, state->pc);    
       switch (*opcode)    
       {    
           case 0x00:   //NOP    
           /* ... */    
       }    
       /* print out processor state */    
       printf("\tC=%d,P=%d,S=%d,Z=%d\n", state->cc.cy, state->cc.p,    
           state->cc.s, state->cc.z);    
       printf("\tA $%02x B $%02x C $%02x D $%02x E $%02x H $%02x L $%02x SP %04x\n",    
           state->a, state->b, state->c, state->d,    
           state->e, state->h, state->l, state->sp);    
   }    
