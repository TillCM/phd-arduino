  int LED1 =13;
 

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1,HIGH); //turn on LED
delay(200); //delay LED for ms
digitalWrite(LED1,LOW);
delay(300);
}
