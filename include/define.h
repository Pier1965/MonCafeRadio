///////////////////////////////////////////////////
// Rilascio versione software
#define RelDate "Novembre 2024"
#define Autore "Pierpaolo Garofalo"
#define eMailAutore "ing.pierpaolo.garofalo@gmail.com"
#define buildFor "Moncafe Bar Lanciano"
// incremento volume click
#define DVOL 5
// Valori ritornati da cambio stazione o volume
#define STNCH 1
#define VOLCH 2
// gestione valori in flash eeprom
// memorizziamo STATION e VOLUME
#define EEPROM_SIZE 2
// Tempo attesa riaccensione dopo spegnimento per evitare bump casse
#define Tdebump 10000
#ifdef SCREEN
	#ifdef OLEDJMDO
		#define SCREEN_WIDTH 128 // OLED display width, in pixels
		#define SCREEN_HEIGHT 64 // OLED display height, in pixels
		// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
		// The pins for I2C are defined by the Wire-library.
		// On an arduino UNO:       A4(SDA), A5(SCL)
		// On an arduino MEGA 2560: 20(SDA), 21(SCL)
		// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
		// Esp32:   SDA -> G21, SCL -> G22
		#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
		#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
	#endif	
	#ifdef ST7789
		#define SCREEN_WIDTH 320 // OLED display width, in pixels
		#define SCREEN_HEIGHT 240 // OLED display height, in pixels
	#endif
#endif
// Upate time screen in modalità clock
#define UPDATETMRSCR 5000
// Timeout access point e connessione
#define TIMEOUT1 10
#define TIMEOUT 180
// Codifica tasti di telecomandi a infrarossi
#include "ir_butt.h"
// Campi del file info radio
#define POS1 "pos" 		// "field1"
#define POS2 "stream" 	// "field2" // <------------------ Se FM allora frequenza
#define POS3 "nome" 	// "field3"
#define POS4 "genere"	// "field4" // <------------------ Uso questo campo per individuare radio WEB o FM

// Gestione modulo radio FM
#ifdef FMMOD
	#define RADIOMODE // <--------------- WEB o FM modalità di funzionamento
#endif