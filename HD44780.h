#ifndef LCD_LIBR
#define LCD_LIBR

#define PORT(x)   SPORT(x)
#define SPORT(x) (PORT##x)
#define PIN(x)    SPIN(x)
#define SPIN(x)  (PIN##x)
#define DDR(x)    SDDR(x)
#define SDDR(x)  (DDR##x)

#define LCD_X 16
#define LCD_Y 2

#define USE_RW 1

#define LCD_D7PORT C
#define LCD_D7 0
#define LCD_D6PORT C
#define LCD_D6 1
#define LCD_D5PORT C
#define LCD_D5 2
#define LCD_D4PORT C
#define LCD_D4 3

#define LCD_RSPORT C
#define LCD_RS 4

#define LCD_RWPORT C
#define LCD_RW 5

#define LCD_EPORT C
#define LCD_E 6

#define SET_RS PORT(LCD_RSPORT) |= (1<<LCD_RS)
#define CLR_RS PORT(LCD_RSPORT) &= ~(1<<LCD_RS)

#define SET_RW PORT(LCD_RWPORT) |= (1<<LCD_RW)
#define CLR_RW PORT(LCD_RWPORT) &= ~(1<<LCD_RW)

#define SET_E PORT(LCD_EPORT) |= (1<<LCD_E)
#define CLR_E PORT(LCD_EPORT) &= ~(1<<LCD_E)

#if ((LCD_Y==4) && (LCD_X==20))
#define LCD_LINE1 0x00
#define LCD_LINE2 0x28
#define LCD_LINE3 0x14
#define LCD_LINE4 0x54
#else
#define LCD_LINE1 0x00
#define LCD_LINE2 0x40
#define LCD_LINE3 0x10
#define LCD_LINE4 0x50
#endif

#define LCDC_CLS       0b00000001		//czyszczenie wysw
#define LCDC_FUNC      0b00100000
#define LCDC_FUNC2L    0b00101000
#define LCDC_FUNC5x7   0b00100000
#define LCDC_FUNC4B	   0b00100000     //wyswietlacz 4bitowy
#define LCDC_FUNC8B	   0b00110000     //wyswietlacz 8bitowy
#define LCDC_ON        0b00001000		//wlaczenie wyswietlacza, kursor off
#define LCDC_ENTRY     0b00000100		//przesuwanie kursora w prawo
#define LCDC_ENTRYR    0b00000110
#define LCDC_ONOFF     0b00001000
#define LCDC_CURSOROFF 0b00001000
#define LCDC_DISPLAYON 0b00001100


void lcd_init(void);
void lcd_cls(void);
void lcd_str(char *);	//wyswietlenie napisu
void lcd_int(uint16_t val);	//wyswietlenie liczby
void lcd_locate(uint8_t x, uint8_t y);	//lokalizuje kursor w danym miejscu

//void _lcd_write_byte(unsigned char _data);



#endif



