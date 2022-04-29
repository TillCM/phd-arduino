/*
  This a simple example of the aREST Library for the ESP8266 WiFi chip.
  See the README file for more details.
  Written in 2015 by Marco Schwartz under a GPL license.
*/

// Import required libraries

#include <aREST.h>

int touchPin =9;

// Create aREST instance
aREST rest = aREST();

// WiFi parameters
const char* ssid = "Till WiFi";
const char* password = "CID3208till";

// The port to listen for incoming TCP connections
#define LISTEN_PORT           80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// Variables to be exposed to the API
int touched;


// Declare functions to be exposed to the API

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Init variables and expose them to REST API

  int touched = 0;
 
  rest.variable("touvhed",&touched);





  // Give name & ID to the device (ID should be 6 characters long)
  rest.set_id("1");
  rest.set_name("esp8266");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);

}

// Custom function accessible by the API
int ledControl(String command) {

  // Get state from command
  int state = command.toInt();

  digitalWrite(6,state);
  return 1;
}

int getSensorData(){
   touched = digitalRead(touchPin); 
  if(touched ==1){
     return 1;
  }
}
