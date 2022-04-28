// 1.0 Version (mapping lamp modes) (Problem: Too slow!!)

const int button = 2;
int button_touches = 0;     // this variable = lamp mode

void setup(){
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop(){
    if (digitalRead(button) == HIGH and button_touches < 2)
    {
        delay(100);

        if (digitalRead(button) == LOW)
        {
            button_touches++;
            Serial.println(button_touches);
            delay(250);
        }
        
    }
    if (digitalRead(button) == HIGH and button_touches == 2)
    {   
        if (digitalRead(button) == LOW)
        {
        button_touches =0;
        Serial.println(button_touches);
        delay(100); 
        }
    }
    
}


// 1.1 Version (mapping lamp modes) (Problem: If you hold the button, arduino registers multiple interactions)

int button_touches = 0;

void setup(){
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop(){
    if (digitalRead(button) == HIGH and button_touches < 2)
    {
    	button_touches++;
        Serial.println(button_touches);
      	delay(250);
    }
        
    if (digitalRead(button) == HIGH and button_touches == 2)
    {
        button_touches =0;
        Serial.println(button_touches);
      	delay(250);
    }
    
}