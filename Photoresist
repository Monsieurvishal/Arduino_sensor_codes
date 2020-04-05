int sensorPin = A0;  
int threshold = 300;  
int sensorValue = 0;  

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  if (analogRead(sensorPin) < threshold)
  {
    // low light, so switch the light (LED) on
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else 
  {
    // light level high enough, so switch the light (LED) off
    digitalWrite(LED_BUILTIN, LOW);
  }
  // wait for ADC to settle before next reading
  delay(20);
}
