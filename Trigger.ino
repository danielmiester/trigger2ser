#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1,true);
volatile char flag = 0;


ISR(INT0_vect,ISR_NAKED){
  flag = 1;
  reti();
}

void setup() {
 // OSCCAL -=5;
  // put your setup code here, to run once:
  mySerial.begin(9600);
  MCUCR |= 2;//falling edge int0
  GIMSK |= 1<<6;//enable INT0
  delay(2);
  mySerial.print("OKOKOKOKOK\r");
  mySerial.print("* 0 IR 001\r");
  
}

void loop() {
  if(flag){
    mySerial.print("* 0 IR 002\r");
    flag = 0;
  }
}
