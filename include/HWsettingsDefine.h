////////////////////////////////////////////////////////
// File per la configurazione delle opzioni hardware  //
////////////////////////////////////////////////////////
// Abilitazione spegnmento ampli audio con rele, se c'è
#define HWRCampli
// Alcune combinaziono cpu / relè funzionano al contrario
#ifdef HWRCampli
    #define MODEAMPON HIGH //
    #define MODEAMPOFF LOW //
#endif

// SELEZIONARE UN DISPLAY DA USARE <---------------------------------
#define SCREEN
// Oled display JMDO 96C-1 OLED SSD1306
// SCL G22
// SDA 21
// #define OLEDJMDO
// Display TFT 2.8" 320x240 ST7789
#define ST7789
// Gestione NEXTION
// Verificare la seriale e i pin da usare in NexHardware.cpp -> nexInit(void)
// #define NEXTOUCH

// Modello Telecomando <-----------------------------
//#define APPLE_IR
//#define ELEGO_IR
//#define SAMS_IR
//#define CARMP3
//#define PHILIPSRC5340
// #define KC808 // Bianco
//#define TANIX //SMART TV BOX TANIX TX5 MAX cucina
#define ZODIAC // MonCafe 

// Modulo radio FM se esistente <------------------------------ 
//#define FMMOD

// Pin usato nella mia radio cucina
//#define CUCINA