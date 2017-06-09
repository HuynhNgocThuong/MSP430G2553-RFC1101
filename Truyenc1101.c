
#include "msp430g2553.h"
#include "UART.h"
void main()
{
  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  UART_Init();
  while(1){
      UART_Write_Char('A');
        __delay_cycles(5000000);
    
  }
}
