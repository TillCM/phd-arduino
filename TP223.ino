
int touchPin  = 9;
int val =0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
 pinMode(touchPin, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:


   val = digitalRead(touchPin); 
  if(val ==1){
     Serial.println("Touched");
  }

   delay(100);
  Serial.println();
 

}
