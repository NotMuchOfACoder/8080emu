        case 0xc2:                      //JNZ address    
            if (0 == state->cc.z)    
                state->pc = (opcode[2] << 8) | opcode[1];    
            else    
                // branch not taken    
                state->pc += 2;    
            break;    

        case 0xc3:                      //JMP address    
            state->pc = (opcode[2] << 8) | opcode[1];    
            break;    
        case 0xcd:                      //CALL address    
            {    
            uint16_t    ret = state->pc+2;    
            state->memory[state->sp-1] = (ret >> 8) & 0xff;    
            state->memory[state->sp-2] = (ret & 0xff);    
            state->sp = state->sp - 2;    
            state->pc = (opcode[2] << 8) | opcode[1];    
            }    
                break;    

        case 0xc9:                      //RET    
            state->pc = state->memory[state->sp] | (state->memory[state->sp+1] << 8);    
            state->sp += 2;    
            break;    
