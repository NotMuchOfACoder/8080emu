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
    case 0xC6:      //ADI byte    
        {    
            uint16_t answer = (uint16_t) state->a + (uint16_t) opcode[1];    
            state->cc.z = ((answer & 0xff) == 0);    
            state->cc.s = ((answer & 0x80) != 0);    
            state->cc.cy = (answer > 0xff);    
            state->cc.p = Parity(answer&0xff);    
            state->a = answer & 0xff;    
        }    
    case 0x86:      //ADD M    
        {    
            uint16_t offset = (state->h<<8) | (state->l);    
            uint16_t answer = (uint16_t) state->a + state->memory[offset];    
            state->cc.z = ((answer & 0xff) == 0);    
            state->cc.s = ((answer & 0x80) != 0);    
            state->cc.cy = (answer > 0xff);    
            state->cc.p = Parity(answer&0xff);    
            state->a = answer & 0xff;    
        }    
