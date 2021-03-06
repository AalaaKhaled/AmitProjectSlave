/*
 * AmitProject.c
 *
 * Created: 3/3/2021 8:53:45 PM
 * Author : Alaa
 */ 


#include "LED.h"
#include "SPI.h"
#include "LCD.h"

int main(void)
{
	LED0_Init();
	LED1_Init();
	LED2_Init();
	SPI_Init();
	LCD_Init();
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

ISR(SPI_STC_vect){
	 Uint8t ReceivedData = SPDR ;
		switch (ReceivedData)
		{
			case 'a' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 1 OPEN");
			_delay_ms(150);
			LED0_ON();
			break;
			case 'b' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 1 CLOSE");
			_delay_ms(150);
			LED0_OFF();
			break;
			case 'c' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 2 OPEN");
			_delay_ms(150);
			LED1_ON();
			break;
			case 'd' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 2 CLOSE");
			_delay_ms(150);
			LED1_OFF();
			break;
			case 'e' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 3 OPEN");
			_delay_ms(150);
			LED2_ON();
			break;
			case 'f' :
			LCD_CLEAR();
			LCD_WRITE_STR("LED 3 CLOSE");
			_delay_ms(150);
			LED2_OFF();
			break;
			default:
			LCD_CLEAR();
			LCD_WRITE_STR("Wrong Input !!");
			_delay_ms(150);
			LED0_ON();
			_delay_ms(150);
			LED0_OFF();
			LED1_ON();
			_delay_ms(150);
			LED1_OFF();
			LED2_ON();
			_delay_ms(150);
			LED2_OFF();
			break;
		}
}