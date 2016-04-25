//
// Created by Daniel DeJager on 4/24/16.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Button.h" //https://github.com/JChristensen/Button

const int txpin = 2;
const int rxpin = 3;
const int trigpin = 4;

SoftwareSerial ss(rxpin, txpin);
Button button(trigpin,0,0,50);

void setup(void){
    ss.begin(9600);
}


void powerOn(void){
    ss.print(F("OKOKOKOKOK"));
}
void powerOff(void){
    ss.print(F("* 0 IR 002\r"));
}

void loop(void){
    static boolean onOff = false;
    static uint32_t ms = millis() + 1000;
    button.read();
    if(ss.available()){
        ss.read();
    }

    if(ms < millis()){
        ms = millis() + 1000;
        if(button.isPressed()){
            powerOn();
        } else {
            powerOff();
        }
    }
}
