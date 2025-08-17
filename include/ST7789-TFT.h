// funzione che pulisce lo schermo per aggirare i problemi di memoria che si hanno 
// con il NodeMcu WROOM e la funzione display->fillScreen
void clearScreen(uint16_t colore);
void clearScreen(uint16_t x0, uint16_t y0, uint16_t xw, uint16_t yh, uint16_t colore);
void initSCR() {
  DEBUG_PRINTLN("Inizializzo TFT ST7789");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display->begin()) {
    DEBUG_PRINTLN(F("ST7789 allocation failed... System locked"));
    for(;;); // Don't proceed, loop forever
  }
  #ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
  #endif
  //
  clearScreen(BLACK);
  display->setTextSize(1);
  display->setTextColor(YELLOW);
  display->setCursor(0, 0);
  // Display static text
  display->println("WR PPPC65");
  display->println(Autore);
  display->println(eMailAutore);
  display->println(buildFor);
   //display.setCursor(0, 1);
  display->print(RelDate);
  //display->display();
  delay(1000);
}
//
void updateSCR(){
  const char *nomeradio;
  uint8_t fontSize = 1;
  int16_t x1, y1;
  uint16_t w, h;
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->setFont(&FreeSans12pt7b);
  display->setTextSize(1);
  record = radioRecords[STATION].as<JsonObject>();
    if(record.containsKey(POS3)){
      nomeradio = record[POS3];
    }
  display->setTextColor(YELLOW);
  display->getTextBounds(nomeradio, 0, 0, &x1, &y1, &w, &h); //calc width of new string
  display->setCursor(0, h);
  display->setTextSize(1);
  display->println(nomeradio);
  display->print("Vol: ");
  display->print(VOLUME);
  display->print("% ");
  display->setTextColor(RED);
  for(int i=0;i<10;i++){
    if(i>VOLUME/10)
      display->setTextColor(YELLOW);
    display->print("O");
  }
  display->println("");
  display->setTextColor(YELLOW);
  display->print("Stazione: ");
  display->println(STATION);
  display->setTextColor(RGB565_BLUE);
  display->print("SSID: ");
  display->println(WiFi.SSID());
  display->print("IP: ");
  display->println(WiFi.localIP());
  display->print("Segnale: ");
  display->println(WiFi.RSSI());
  //display.println("");
  display->setTextColor(GREEN);
  display->print(Data);
  display->print(" ");
  display->println(Ora);
  display->setTextColor(ORANGE);
  display->print(buildFor);
  display->setTextColor(YELLOW);
  display->setCursor(210, 150);
  display->setTextSize(3);
  display->print(STATION);
  //String myString = String(STATION);
  //display->getTextBounds(myString, 0, 0, &x1, &y1, &w, &h); //calc width of new string
  //display->drawRect(210, 150 - h, w, h, RED);
  display->setFont();
}
void updateTimeScr(){
  clearScreen(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
  display->setFont();
  
  //
  uint8_t fontSize = 1;
  display->setCursor(0, 0);
  display->setFont(&FreeSans12pt7b);
  //display->fillScreen(BLACK);
  display->setTextColor(YELLOW);
  //display->setCursor(0, 0);
  //display->setTextSize(4); // carattere STD alto 7 pixel ursorSize 2 -> 14 pixel
  //display->println("");
  int16_t x1, y1;
  uint16_t w, h;
  display->setTextSize(2* fontSize);
  display->getTextBounds(Data, 0, 0, &x1, &y1, &w, &h); //calc width of new string
  display->setCursor(SCREEN_WIDTH /2 - w / 2, h+2);
  display->println(Data);
  display->setTextColor(GREEN);
  display->setTextSize(3*fontSize);
  display->getTextBounds(Ora, 0, 0, &x1, &y1, &w, &h);
  display->setCursor(SCREEN_WIDTH / 2 - w / 2, 4*(h + 2));
  display->println(Ora);
  display->setTextColor(RED);
  display->setTextSize(fontSize);
  display->getTextBounds(buildFor, 0, 0, &x1, &y1, &w, &h);
  display->setCursor(SCREEN_WIDTH / 2 - w / 2, SCREEN_HEIGHT/2 + fontSize /2);
  display->println(buildFor);
  //display->display();
}
void printSCR_notavail(){
  display->setFont();
  display->setTextColor(YELLOW);
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->println("Canale non disponibile...");
  //lcd.setCursor(0, 1);
  display->print("Riconnessione...");
  //display->display();
  //delay(1000);
}

void printSCR_yesnet(){
  display->setFont();
  display->setTextColor(YELLOW);
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->println("Canale non disponibile...");
  //lcd.setCursor(0, 1);
  display->print("Riconnessione...");
  //display->display();
  //delay(1000);
  display->setCursor(0, 0);
  display->println("Internet OK");
  display->print("SSID: ");
  display->println(WiFi.SSID());
  display->print("IP: ");
  display->println(WiFi.localIP());
  //display->display();
}
void printSCR_nonet(){
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->print("No Internet");
  //display->display();
}
void printSCR_nomp3(){
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->print("No mp3 module");
  //display->display();
}
void printSCR_attesaWL(){
  uint8_t fontSize = 1;
  display->setFont();
  display->setTextSize(2* fontSize);
  display->setTextColor(YELLOW);
  clearScreen(BLACK);
  display->setCursor(0, 0);
  display->println("Attesa WIFI!");
  //lcd.setCursor(0, 1);
  display->setTextColor(RED);
  display->setCursor(0, 30);
  display->setTextSize(fontSize);
  display->print("Connessione...");
  display->println("AP Mode");
  display->setTextSize(1);
  display->print("AP: ");
  display->println((String)APEsp32);
  display->println("IP: 192.168.4.1");
  display->print("Timeout: ");
  display->print(TIMEOUT);
  display->print("sec");
  //display->display();
}

void clearScreen(uint16_t colore){
  DEBUG_PRINTLN("IN CLEARSCREEN");
  for(uint16_t j = 0; j < uint16_t(SCREEN_HEIGHT / 25)+1; j++){
    for(uint16_t i=0; i<SCREEN_WIDTH; i++){
      display->drawFastVLine(i, j*25, 25, colore);
      //delay(10);
    }
  }
}
void clearScreen(uint16_t x0, uint16_t y0, uint16_t xw, uint16_t yh, uint16_t colore){
DEBUG_PRINTLN("IN CLEARSCREEN square");
// con 25 lunghezza massima non ho problemi grafici...
  uint16_t nc = xw;
  uint16_t nr = uint16_t(yh/25);
  for(uint16_t r = 0; r<nr; r++)
    for(uint16_t j=0; j<nc; j++)
        display->drawFastVLine(x0+j, y0+r*25, 25, colore);
  uint16_t remain = yh - nr*25;
  if(remain > 0)
    for(uint16_t j=0; j<nc; j++)
        display->drawFastVLine(x0+j, y0+nr*25, remain, colore);
}

void updateAPSCR(unsigned int utimeout){
  display->setFont();
  display->setTextColor(YELLOW);
  clearScreen(BLUE);
  display->setCursor(0, 0);
  #ifdef OLEDJMDO
  display->setTextSize(2);
  #endif
  display->println("AP Mode");
  display->setTextSize(1);
  display->print("AP: ");
  display->println((String)APEsp32);
  display->println("IP: 192.168.4.1");
  display->print("Timeout: ");
  display->print(utimeout);
  display->print("sec");
  //display->display();
}