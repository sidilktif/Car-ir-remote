#include <IRremote.h>
int RECV_PIN = 11; // Declare variables to hold pin number
IRrecv irrecv(RECV_PIN); // Create irrecv object
decode_results results;
int yellowPin = 5;// declare variable to hold decoded IR receiver result
int yellowPin1 = 7;
 int yellowPin2 = 2;
 int yellowPin3 = 4;
 
// put your setup code here, to run once:
void setup(){
  pinMode(yellowPin, OUTPUT);  
    pinMode(yellowPin2, OUTPUT);
      pinMode(yellowPin3, OUTPUT);
  pinMode(yellowPin1, OUTPUT);// sets the digital pin as output
    digitalWrite(yellowPin2, LOW); 
           digitalWrite(yellowPin1, LOW); 
           digitalWrite(yellowPin3, LOW); 
            digitalWrite(yellowPin,LOW);
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
      case 3772778233: //when you press the 1 button
         digitalWrite(yellowPin,LOW); 
            digitalWrite(yellowPin1, HIGH); 
               digitalWrite(yellowPin2, HIGH); 
        digitalWrite(yellowPin3, LOW);
        break;   
      case 3772810873: //when you press the 4 button
     digitalWrite(yellowPin,HIGH); 
            digitalWrite(yellowPin3, HIGH); 
               digitalWrite(yellowPin1, LOW ); 
        digitalWrite(yellowPin2, LOW);
        break;
      case 3772794553: //when you press the 4 button
           digitalWrite(yellowPin3, LOW); 
            digitalWrite(yellowPin2, LOW); 
               digitalWrite(yellowPin, HIGH); 
        digitalWrite(yellowPin1, LOW);
        break;
         
           case 3772819033: //when you press the 4 button
           digitalWrite(yellowPin1, LOW); 
            digitalWrite(yellowPin, LOW); 
               digitalWrite(yellowPin3, HIGH); 
        digitalWrite(yellowPin2, LOW);
        break;
           case 3772782313    : //when you press the 4 button
           digitalWrite(yellowPin2, LOW); 
           digitalWrite(yellowPin1, LOW); 
           digitalWrite(yellowPin3, LOW); 
            digitalWrite(yellowPin,LOW);
        break;
          case 3772778743: //when you press the 4 button
           digitalWrite(yellowPin3, LOW); 
            digitalWrite(yellowPin2, HIGH); 
               digitalWrite(yellowPin, HIGH); 
        digitalWrite(yellowPin1, LOW);
        break;
          case 3772795063: //when you press the 4 button
           digitalWrite(yellowPin3,HIGH ); 
            digitalWrite(yellowPin2, LOW); 
               digitalWrite(yellowPin, LOW); 
        digitalWrite(yellowPin1,HIGH );
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
