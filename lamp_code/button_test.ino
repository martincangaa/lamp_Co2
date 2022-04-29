// 1.0 Version (mapping lamp modes) (Problem: Too slow!!)

const int BUTTON = 2;
int button_touches = 0;     // this variable = lamp mode

void setup(){
    pinMode(BUTTON, INPUT);
    Serial.begin(9600);
}

void loop(){
    if (digitalRead(BUTTON) == HIGH and button_touches < 2)
    {
        delay(100);

        if (digitalRead(BUTTON) == LOW)
        {
            button_touches++;
            Serial.println(button_touches);
            delay(250);
        }
        
    }
    if (digitalRead(BUTTON) == HIGH and button_touches == 2)
    {   
        if (digitalRead(BUTTON) == LOW)
        {
        button_touches =0;
        Serial.println(button_touches);
        delay(100); 
        }
    }
    
}


// 1.1 Version (mapping lamp modes) (Problem: If you hold the BUTTON, arduino registers multiple interactions)

int button_touches = 0;

void setup(){
    pinMode(BUTTON, INPUT);
    Serial.begin(9600);
}

void loop(){
    if (digitalRead(BUTTON) == HIGH and button_touches < 2)
    {
    	button_touches++;
        Serial.println(button_touches);
      	delay(250);
    }
        
    if (digitalRead(BUTTON) == HIGH and button_touches == 2)
    {
        button_touches =0;
        Serial.println(button_touches);
      	delay(250);
    }
    
}


// 1.2 Version (mapping lamp modes) (I'm using OneButton library: https://github.com/mathertel/OneButton) (I modified the library example "BlinkMachine" created by Matthias Hertel)

#include "OneButton.h"

typedef enum {
  LAMP_OFF,  // set lamp "OFF".
  LAMP_ON,   // set lamp "ON"
  MODE_CO2  // blink LED "FAST"
} 
MyActions;

#define PIN_INPUT 2
#define PIN_LED 13


OneButton button(PIN_INPUT, true);

MyActions nextAction = LAMP_OFF; // lamp off when starting


// setup code here, to run once.
void setup() {
  // enable the standard led on pin 13.
  pinMode(PIN_LED, OUTPUT);      // sets the digital pin as output

  // link the Press function to be called on a click event.   
  button.attachLongPressStart(PressFunction);

  // link the Click function to be called on a doubleclick event.   
  button.attachClick(ClickFunction);

  // set 80 msec. debouncing time. Default is 50 msec.
  button.setDebounceTicks(80);
} // setup


void loop() {
  unsigned long now = millis();

  // keep watching the push button:
  button.tick(); 

  if (nextAction == LAMP_OFF) {
    // turn lamp off
    GoBed();

  } else if (nextAction == LAMP_ON) {
    // turn lamp on
    WakeUp();

  } else if (nextAction == MODE_CO2) {
    // start mode CO2
    CO2Mode();

  } 
} 


// this function will be called when the button was held for 1 second.
void PressFunction() {
  if (nextAction == LAMP_OFF)
    nextAction = LAMP_ON;
  else
    nextAction = LAMP_OFF;
} // PressFunction


// this function will be called when the button was pressed 1 time.
void ClickFunction() {
  if (nextAction == LAMP_ON) {
    nextAction = MODE_CO2;

  } else if (nextAction == MODE_CO2) {
    nextAction = LAMP_ON;

  } 
} // ClickFunction