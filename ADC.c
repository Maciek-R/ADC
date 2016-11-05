#include "ADC.h"

#include <avr/io.h>
#include <stdlib.h>

void ADC_init()
{
	ADMUX |= (1<<REFS0);		//napiecie odniesienia Vcc
	//ADMUX |= (1<<REFS0) | (1<<REFS1);	//napiecie odniesienia 2,56V
	ADCSRA |= (1<<ADEN);		//wlaczenie modulu ADC
	ADCSRA |= (1<<ADPS1)|(ADPS0);//preskaler 64
}

uint16_t pomiar(uint8_t kanal)		//PIN_ADC
{
	ADMUX |= (ADMUX & 0xF8) | kanal;	//ustawienie odpowiedniego kanalu

	ADCSRA |= (1<<ADSC);		//start pomiaru

	while (ADCSRA & (1<<ADSC));		//oczekiwanie na koniec pomiaru

	return ADCW;
}

char* int_to_string(int n)		//zamienia int na char *
{
     char bufor[50];			//musi byc wystarczajaco duzy
	 return itoa(n, bufor, 10);
}

void napiecie(uint16_t pomia, uint8_t * cz_d, uint8_t * cz_u)
{
	uint32_t wynik;
	uint16_t pm;

	pm = pomia;
	wynik = pm * 49 * 1;			//(5V/1024) = 0,0049 //*1 bo 5V/napiecie odniesienia=1
	*cz_d = wynik/10000;
	*cz_u = (wynik/100)%100;
}
