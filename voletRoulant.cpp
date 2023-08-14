#include <Arduino.h>
#include "voletRoulant.h"

VoletRoulant::VoletRoulant(int pinUp,int pinDown){
    _pinUp = pinUp;
    _pinDown=pinDown;
    //_desactive = HIGH;
    //_active = LOW;

}

void VoletRoulant::init(){
    pinMode(_pinUp, OUTPUT);
    digitalWrite(_pinUp,_desactive);
    pinMode(_pinDown, OUTPUT);
    digitalWrite(_pinDown,_desactive);
}

void VoletRoulant::monte(){
    Serial.println("monte");
    digitalWrite(_pinDown,_desactive);
    digitalWrite(_pinUp,_active);
    startTimer();
}

void VoletRoulant::descend(){
    Serial.println("descend");
    digitalWrite(_pinUp,_desactive);
    digitalWrite(_pinDown,_active);
    startTimer();
}

void VoletRoulant::stop(){
    Serial.println("stop");
    digitalWrite(_pinDown,_desactive);
    digitalWrite(_pinUp,_desactive);
}

void VoletRoulant::startTimer(){
    _time=millis();
}

void VoletRoulant::testTimer(){
    if(!_active)return;
    long duree=millis()-_time;
    if(duree>_dureeTimer)stop();
}