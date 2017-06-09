
#include "msp430g2553.h"
#include "UART.h"

char rData;
void main()
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  UART_Init();
  P1DIR |= BIT0 + BIT6;
  while(1){
    rData = UART_Read_Char();	
    if(rData == '1'){
          P1OUT |= BIT0;
    }
      if(rData == '2'){
          P1OUT &=~ BIT0;
    }
      if(rData == '3'){
          P1OUT |= BIT6;
    }
      if(rData == '4'){
         P1OUT &=~ BIT6;
    }
    
  }
  
  
 
}
