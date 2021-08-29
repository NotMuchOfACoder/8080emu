    case 0x2F:                    //CMA (not)    
        state->a = ~state->a    
        //Data book says CMA doesn't effect the flags    
        break;    

    case 0xe6:                    //ANI    byte    
        {    
        uint8_t x = state->a & opcode[1];    
        state->cc.z = (x == 0);    
        state->cc.s = (0x80 == (x & 0x80));    
        state->cc.p = parity(x, 8);    
        state->cc.cy = 0;           //Data book says ANI clears CY    
        state->a = x;    
        state->pc++;                //for the data byte    
        }    
        break;    
Shift Right(0b00010000) = 0b00001000

Shift Left (0b00000001) = 0b00000010
      case 0x0f:                    //RRC    
        {    
            uint8_t x = state->a;    
            state->a = ((x & 1) << 7) | (x >> 1);    
            state->cc.cy = (1 == (x&1));    
        }    
        break;    

    case 0x1f:                    //RAR    
        {    
            uint8_t x = state->a;    
            state->a = (state->cc.cy << 7) | (x >> 1);    
            state->cc.cy = (1 == (x&1));    
        }    
        break;    
    case 0xfe:                      //CPI  byte    
        {    
        uint8_t x = state->a - opcode[1];    
        state->cc.z = (x == 0);    
        state->cc.s = (0x80 == (x & 0x80));    
        //It isn't clear in the data book what to do with p - had to pick    
        state->cc.p = parity(x, 8);    
        state->cc.cy = (state->a < opcode[1]);    
        state->pc++;    
        }    
        break;    
