#include <avr/io.h>
#include <util/delay.h>

#include "HD44780.h"	//dolaczenie wyswietlacza LCD
#include "ADC.h"		//modul ADC do pomiaru napiecia

uint16_t single_pomiar;
uint16_t poprzedni_pomiar = 0;
uint8_t  cale;
uint8_t  ulamek;

uint8_t epsilon = 10;	//dopuszczalny blad pomiaru
int16_t roznica;

int main()
{
	lcd_init();
	ADC_init();	

	lcd_cls();
	while(1)
	{	
		//lcd_cls();
		single_pomiar = pomiar(7);
		napiecie(single_pomiar, &cale, &ulamek);

		if (single_pomiar > poprzedni_pomiar)
			roznica = single_pomiar - poprzedni_pomiar;
		else roznica = poprzedni_pomiar - single_pomiar;

		if (roznica>epsilon )
		{
			lcd_cls();
			lcd_locate(0, 0);
			lcd_int(single_pomiar);

			lcd_locate(0, 1);
			lcd_int(cale);
			lcd_str(".");
			if (ulamek<10) lcd_int(0);
			lcd_int(ulamek);
			lcd_str("V");

			poprzedni_pomiar = single_pomiar;
		}

	}

	return 0;
}
