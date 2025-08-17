/*
Wiring:
  ---------------------
  | VS1053  |  ESP32  |
  ---------------------
  |   SCK   |  IO18   |
  |   MISO  |  IO19   |
  |   MOSI  |  IO23   |
  |   XRST  |  EN/5V  |
  |   CS    |  IO5    |
  |   DCS   |  IO0    |
  |   DREQ  |  IO4    |
  |   5V    |  5V     |
  |   GND   |  GND    |
  ---------------------

  ---------------------------
  | JMDO 96C-1 OLED | ESP32 |
  ---------------------------
  | SDA             | 21    |
  | SCL             | 22    |
  | GND             | GND   |
  | 5V              | 5V    |
  ---------------------------

  ------------------------------------
  | TFT 2.8 ST7789  | Wroom/Wrover-b |
  ------------------------------------
  | SDA             | 21    | 
  | SCL             | 22    |
  | RST             | 15    |
  | DC              | 27    |
  | CS              | 16/2  |
  | BL              | 14    |
  | GND             | GND   |
  | VCC             | 3.3V  |
  ---------------------------


  ---------------------------
  | IR module elegoo | ESP32 |
  ---------------------------
  | G                | GND   |
  | R                | 5V    |
  | Y                | G26/13|  wroom/wrover - B ttgo
  ----------------------------

  -----------------------------
  | Pulsanti         | ESP32  |
  -----------------------------
  | Vol UP           | G32    |
  | Vol Down         | G33    |
  | Next Station     | G13/34 | wroom/wrover - B ttgo
  | Prv Station      | G12    |
  | Radio-Clock Sel  | G36/35 | wroom/wrover - B ttgo
  ----------------------------

  ------------------------------
  | Rele comando amplificatore |
  ------------------------------
  | G14/26                     |
  ------------------------------

  Il file NexHardware.cpp va modificato per l'uso con seriale 2 del WROVER 

  // Modifica per usare la seriale 2 su wrover-b TTGO
    	#define RXD2 25
		  #define TXD2 26
*/

const int previousButton  	= 12;
#ifdef CUCINA
  const int nextButton        = 13; // radio cucina
#else
  const int nextButton        = 34; 
#endif

const int volumeUp        	= 32;
const int volumeDown      	= 33;
#ifdef WROVER
  const int RCSelector   		  = 35; // Selettore modalità radio o clock Wrover
  #ifdef HWRCampli
    const int HWRC              = 26; // Output comando relè spegnimento ampli audio
  #endif
#endif
#ifdef WROOM
  const int RCSelector   		  = 36; // Selettore modalità radio o clock Wroom
  #ifdef HWRCampli
    const int HWRC              = 17; // Output comando relè spegnimento ampli audio
  #endif
#endif
//IR sensor
//Infrarosso collegato a Pin Esp32
#ifdef WROVER
  const unsigned int kRecvPin		= 13; //26;
#endif
#ifdef WROOM
  const unsigned int kRecvPin		= 26;
#endif
// Pin decodificatore mp3 VS1053
#ifdef ARDUINO_ARCH_ESP32
	#define VS1053_CS     5
	#define VS1053_DCS    0
	#define VS1053_DREQ   4
	#define SPI_CLK_PIN 18
	#define SPI_MISO_PIN 19
	#define SPI_MOSI_PIN 23
#endif

// Pin ST7789
#ifdef ST7789
  #define TFT_SDA 21
  #define TFT_SCL 22
  #define TFT_RST 15
  #define  TFT_DC 27
  #ifdef WROVER
    #define  TFT_CS 2
  #endif
  #ifdef WROOM
    #define  TFT_CS 16
  #endif
  #define  TFT_BL 14
#endif
/*
 ---------------------------
  | TFT 2.8 ST7789  | ESP32 | wroom / wrover
  ---------------------------
  | SDA             | 21    |
  | SCL             | 22    |
  | RST             | 15    |
  | DC              | 27    |
  | CS              | 16/2  |
  | BL              | 14    | back light pin
  | GND             | GND   |
  | VCC             | 3.3V  |
  ---------------------------
*/

// Modulo radio FM
#ifdef FMMOD // Verificare con Wrover B se questi pin sono ok
  #define PIN_FMWEB 13
  #define PIN_SDAFM 03
  #define PIN_SLCFM 01
#endif
