#include <IRremote.h>
int RECV_PIN = 11; // Declare variables to hold pin number
IRrecv irrecv(RECV_PIN); // Create irrecv object
decode_results results;
int yellowPin = 8;// declare variable to hold decoded IR receiver result
int yellowPin1 = 9;
 
// put your setup code here, to run once:
void setup(){
  pinMode(yellowPin, OUTPUT);  
  pinMode(yellowPin1, OUTPUT);// sets the digital pin as output
Serial.begin(9600); //Initialize serial monitor
Serial.println("Enabling IR Receiver"); // Print text on serial monitor
irrecv.enableIRIn(); // Start the IR receiver
Serial.println("Enabled IR Receiver"); // Print text on serial monitor
}

void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 3772819033: //when you press the 1 button
        digitalWrite(yellowPin, HIGH);
        break;   
      case 3772810873: //when you press the 4 button
        digitalWrite(yellowPin, LOW); 
            digitalWrite(yellowPin1, LOW); 
        break;
      case 3772794553: //when you press the 4 button
            digitalWrite(yellowPin1, HIGH); 
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(2);
}
