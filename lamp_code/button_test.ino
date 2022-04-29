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


// 1.2 Version (mapping lamp modes) (I'm using OneButton library: https://github.com/mathertel/OneButton)

#include "OneButton.h"
#define BUTTON 2
int button_touches = 0;

OneButton button(BUTTON, false);

void setup(){
    
    button.attachLongPressStart(WakeUp);
    
    button.attachClick(Co2Mode);

    button.attachDoubleClick(Co2Mode);
}