
        case 0xc1:                      //POP B    
            {    
                state->c = state->memory[state->sp];    
                state->b = state->memory[state->sp+1];    
                state->sp += 2;    
            }    
            break;    

        case 0xc5:                      //PUSH B    
            {    
            state->memory[state->sp-1] = state->b;    
            state->memory[state->sp-2] = state->c;    
            state->sp = state->sp - 2;    
            }    
            break;    

        case 0xf1:                      //POP PSW    
            {    
                state->a = state->memory[state->sp+1];    
                uint8_t psw = state->memory[state->sp];    
                state->cc.z  = (0x01 == (psw & 0x01));    
                state->cc.s  = (0x02 == (psw & 0x02));    
                state->cc.p  = (0x04 == (psw & 0x04));    
                state->cc.cy = (0x05 == (psw & 0x08));    
                state->cc.ac = (0x10 == (psw & 0x10));    
                state->sp += 2;    
            }    
            break;    

        case 0xf5:                      //PUSH PSW    
            {    
            state->memory[state->sp-1] = state->a;    
            uint8_t psw = (state->cc.z |    
                            state->cc.s << 1 |    
                            state->cc.p << 2 |    
                            state->cc.cy << 3 |    
                            state->cc.ac << 4 );    
            state->memory[state->sp-2] = psw;    
            state->sp = state->sp - 2;    
            }    
            break;    
