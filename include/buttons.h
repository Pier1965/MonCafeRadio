// Gestione pulsanti e modalita clock <-> radio

void checkResetHw() {
    static int lastSteadyState = LOW;       // the previous steady state from the input pin
    static int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
    int currentState; 
    static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    currentState = digitalRead(RCSelector);
    // If the switch/button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > debT) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            #ifdef DEBUG
                DEBUG_PRINT("Btn - Modalita funzionamento: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("The button is released");
            #endif    
            // cambiare stato di funzionamento
            oldWMode = WMode;
            WMode = !WMode;
        }else if(lastSteadyState == LOW && currentState == HIGH){
            #ifdef DEBUG
                DEBUG_PRINT("Btn - Modalita funzionamento: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("The button Mode is pressed");
            #endif 
        }
        // save the the last steady state
        lastSteadyState = currentState;
    }   
}

// Gestione pulsanti cambio canale

void checkPreviousButton() {
    static int lastSteadyState = LOW;       // the previous steady state from the input pin
    static int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
    int currentState; 
    static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    currentState = digitalRead(previousButton);
    // If the previous channel button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > debT) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            DEBUG_PRINTLN("The button ch- is released");
            // cambiare stazione
            if(STATION>0)
                STATION--;
            else
                STATION = NR-1;
            nxtButton = 0;
            prvButton = 1;
            #ifdef DEBUG
                DEBUG_PRINT("Btn - CH-: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("Prev");
                DEBUG_PRINTDEC(STATION);
                DEBUG_PRINTLN("");
            #endif     
        }else if(lastSteadyState == LOW && currentState == HIGH){
            DEBUG_PRINTLN("The button ch- is pressed");
        }
        // save the the last steady state
        lastSteadyState = currentState;
    }      
}

void checkNextButton() {
    static int lastSteadyState = LOW;       // the previous steady state from the input pin
    static int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
    int currentState; 
    static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    currentState = digitalRead(nextButton);
    // If the next channel button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        DEBUG_PRINTLN("In checkNextButton");
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > debT) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            DEBUG_PRINTLN("The button ch+ is released");
            // cambiare stazione
            if(STATION<NR-1)
                STATION++;
            else
                STATION = 0;
            nxtButton = 1;
            prvButton = 0;
            #ifdef DEBUG
                DEBUG_PRINT("Btn - CH+: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("Next");
                DEBUG_PRINTDEC(STATION);
                DEBUG_PRINTLN("");
        #endif
        }else if(lastSteadyState == LOW && currentState == HIGH){
            DEBUG_PRINTLN("The button ch+ is pressed");
        }
        // save the the last steady state
        lastSteadyState = currentState;
    }       
}

// Gestione pulsanti regolazione volume

void checkvolumeDown() {
    static int lastSteadyState = LOW;       // the previous steady state from the input pin
    static int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
    int currentState; 
    static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    currentState = digitalRead(volumeDown);
    // If the  volume down button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > debT) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            DEBUG_PRINTLN("The button V- is released");
            // diminuire volume
            if(VOLUME > DVOL)
                VOLUME -= DVOL;
            else
                VOLUME = 0;
            #ifdef DEBUG
                DEBUG_PRINT("Btn - V-: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("Vdown");
                DEBUG_PRINTDEC(STATION);
                DEBUG_PRINTLN("");
            #endif   
        }else if(lastSteadyState == LOW && currentState == HIGH){
            DEBUG_PRINTLN("The button V- is pressed");
        }
        // save the the last steady state
        lastSteadyState = currentState;
    }  
}

void checkvolumeUp() {
    static int lastSteadyState = LOW;       // the previous steady state from the input pin
    static int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
    int currentState; 
    static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    currentState = digitalRead(volumeUp);
    // If the  volume down button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > debT) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            DEBUG_PRINTLN("The button V+ is released");
            // aumentare volume
            if(VOLUME < (100 - DVOL))
                VOLUME += DVOL;
            else
                VOLUME = 100;
            #ifdef DEBUG
                DEBUG_PRINT("Btn - V+: ");
                if (WMode)
                    DEBUG_PRINTLN("RADIO");
                else
                    DEBUG_PRINTLN("CLOCK");
                DEBUG_PRINTLN("Vup");
                DEBUG_PRINTDEC(STATION);
                DEBUG_PRINTLN("");
            #endif       
        }else if(lastSteadyState == LOW && currentState == HIGH){
            DEBUG_PRINTLN("The button V+ is pressed");
        }
        // save the the last steady state
        lastSteadyState = currentState;
    }    
}

// controllo di tutti i pulsanti

void checkHwBtns(){
    checkResetHw();
    checkPreviousButton();
    checkNextButton();
    checkvolumeDown();
    checkvolumeUp();
}

// impostazione modalita pulsanti
void setupBtn(){
    pinMode(previousButton, INPUT_PULLUP);
    pinMode(nextButton, INPUT_PULLUP);
    #ifdef HWRCampli
        pinMode(HWRC, OUTPUT);
        digitalWrite(HWRC, LOW);
    #endif

    pinMode(volumeUp, INPUT_PULLUP);
    pinMode(volumeDown, INPUT_PULLUP);

    pinMode(RCSelector, INPUT_PULLUP);
}