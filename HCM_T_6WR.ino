const uint8_t PIN_BTN     = 2;    // fog button (active-low)
const uint8_t PIN_LED     = 6;    // button backlight LED
const uint8_t PIN_DIAL    = A0;   // dial analog

const uint8_t RELAYS[6]  = {3,4,5,6,7,8};
bool modeState[6]        = {0};

unsigned long downTime, lastDebounce;
const uint16_t DB_MS=50, LONG_MS=2000;
bool lastBtn=HIGH;

void setup(){
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  for(auto p:RELAYS){ pinMode(p,OUTPUT); digitalWrite(p,LOW); }
}

void loop(){
  bool btn=digitalRead(PIN_BTN);
  if(btn!=lastBtn){ lastDebounce=millis(); lastBtn=btn; }
  if(millis()-lastDebounce>DB_MS){
    if(btn==LOW){
      downTime=millis();
      while(digitalRead(PIN_BTN)==LOW){}
      auto held=millis()-downTime;
      if(held>=LONG_MS){
        // long-press: reset all
        for(int i=0;i<6;i++){ modeState[i]=0; digitalWrite(RELAYS[i],LOW); }
        for(int i=0;i<3;i++){
          digitalWrite(PIN_LED,HIGH); delay(200);
          digitalWrite(PIN_LED,LOW);  delay(200);
        }
      } else {
        // short-press: toggle current mode
        uint8_t mode=constrain(map(analogRead(PIN_DIAL),0,1023,0,6),0,5);
        modeState[mode]=!modeState[mode];
        digitalWrite(RELAYS[mode],modeState[mode]);
        digitalWrite(PIN_LED,modeState[mode]);
      }
    }
  }
}
