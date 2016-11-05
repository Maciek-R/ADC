#ifndef ADC_h
#define ADC_h

#include <avr/io.h>

void ADC_init();			//inicjalizacja modulu ADC
uint16_t pomiar(uint8_t kanal);	//zwraca pojedynczy pomiar	(od 0 do 1023 dla 10 bitowej rozdzielczoœci)
void napiecie(uint16_t pomia, uint8_t * cz_d, uint8_t * cz_u);	//zwraca pomiar napiecia //czesc dziesietna i ulamkowa // dwa miejsca po przecinku
char* int_to_string(int n);		//zamienia int na char *

#endif
