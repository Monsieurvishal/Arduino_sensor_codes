#define outputA 6
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState;  
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
}
void loop() {
  aState = digitalRead(outputA);
  
  if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       counter ++;
       angle ++;
       rotateCW();  
     }
     else {
       counter--;
       angle --;
       rotateCCW(); 
     }
     if (counter >=30 ) {
      counter =0;
     }
     
     lcd.clear();
     lcd.print("Position: ");
     lcd.print(int(angle*(-1.8)));
     lcd.print("deg"); 
     lcd.setCursor(0,0);
     
   }
  aLastState = aState;
}
void rotateCW() {
  digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(2000); 
}
void rotateCCW() {
  digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(2000);   
}