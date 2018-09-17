/*
  Example for receiving
  
  https://github.com/sui77/rc-switch/
  
  If you want to visualize a telegram copy the raw data and 
  paste it into http://test.sui.li/oszi/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

RCSwitch mySwitch1 = RCSwitch();int state = 0;

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(13, OUTPUT);      
  mySwitch1.enableTransmit(10);
}

void siren() {
  if(state==1){
  //Serial.println("outside");
  mySwitch1.send("000100010001001100000010");
  delayMicroseconds(364);
  mySwitch1.send("000100010001001100000010");
  delayMicroseconds(364);  
  }
  /*else{
    state = 0;   
  }*/
  
}

void loop() {
    
    //Serial.println(Serial.parseInt());    
     if (mySwitch.available()) {
      //Serial.println("inside");
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }

  if(Serial.available()){
    state = Serial.parseInt();
    digitalWrite(13, state);
  

 }

     siren();  
     //Serial.println(state); 
 

   

delay(1000);
}
