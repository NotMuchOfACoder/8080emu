   typedef struct ConditionCodes {    
    uint8_t    z:1;    
    uint8_t    s:1;    
    uint8_t    p:1;    
    uint8_t    cy:1;    
    uint8_t    ac:1;    
    uint8_t    pad:3;    
   } ConditionCodes;    

   typedef struct State8080 {    
    uint8_t    a;    
    uint8_t    b;    
    uint8_t    c;    
    uint8_t    d;    
    uint8_t    e;    
    uint8_t    h;    
    uint8_t    l;    
    uint16_t    sp;    
    uint16_t    pc;    
    uint8_t     *memory;    
    struct      ConditionCodes      cc;    
    uint8_t     int_enable;    
   } State8080;    
   void UnimplementedInstruction(State8080* state)    
   {    
    //pc will have advanced one, so undo that    
    printf ("Error: Unimplemented instruction\n");    
    exit(1);    
   }    

   int Emulate8080Op(State8080* state)    
   {    
    unsigned char *opcode = &state->memory[state->pc];    

    switch(*opcode)    
    {    
        case 0x00: UnimplementedInstruction(state); break;    
        case 0x01: UnimplementedInstruction(state); break;    
        case 0x02: UnimplementedInstruction(state); break;    
        case 0x03: UnimplementedInstruction(state); break;    
        case 0x04: UnimplementedInstruction(state); break;    
        /*....*/    
        case 0xfe: UnimplementedInstruction(state); break;    
        case 0xff: UnimplementedInstruction(state); break;    
    }    
    state->pc+=1;  //for the opcode    
   }    
   void Emulate8080Op(State8080* state)    
   {    
    unsigned char *opcode = &state->memory[state->pc];    

    switch(*opcode)    
    {    
        case 0x00: break;                   //NOP is easy!    
        case 0x01:                          //LXI   B,word    
            state->c = opcode[1];    
            state->b = opcode[2];    
            state->pc += 2;                  //Advance 2 more bytes    
            break;    
        /*....*/    
        case 0x41: state->b = state->c; break;    //MOV B,C    
        case 0x42: state->b = state->d; break;    //MOV B,D    
        case 0x43: state->b = state->e; break;    //MOV B,E    
    }    
    state->pc+=1;    
   }    
