   /* Example 1: read the control panel */    
   char *buttons_ptr = (char *)0x2043;    
   char buttons = *buttons_ptr;    
   if (buttons & 0x4)    
    HandleLeftButton();    

   /* Example 2: turn on one LED on the control panel */    
   char * LED_pointer = (char *) 0x2089;    
   char led = *LED_pointer;    
   led = led | 0x40; //set LED controlled by bit 6    
   *LED_pointer = led;    

   /* Example 3: turn off one LED */    
   char * LED_pointer = (char *) 0x2089;    
   char led = *LED_pointer;    
   led = led & 0xBF; //mask out bit 6    
   *LED_pointer = led;    
