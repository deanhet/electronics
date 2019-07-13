#include <MicroView.h>    // include MicroView library

int RED = 6;      // declare RED LED pin 6
int GREEN = 5;      // declare GREEN LED pin 5
int BLUE = 3;     // declare BLUE LED pin 3
int buttonPin = A0;       // push button pin
int buttonState = 0;// variable to store the pushbutton status
int buttonSwitch = 1;

void setup() {
  uView.begin();      // start MicroView
  uView.clear(PAGE);    // clear page
  pinMode(RED, OUTPUT);             // set RED LED pin as OUTPUT
  pinMode(GREEN, OUTPUT);             // set GREEN LED pin as OUTPUT
  pinMode(BLUE, OUTPUT);
  pinMode(buttonPin, INPUT);    // initialize the pushbutton pin as an input
  digitalWrite(buttonPin,HIGH);   // set Internal pull-up
}

void loop() {
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

  // check if the pushbutton is pressed.
  // if it is not pressed, the buttonState is HIGH:
  if (buttonState == LOW && buttonSwitch == 1){
    analogWrite(BLUE,0);
    analogWrite(RED,255);
    uView.clear(PAGE);    // clear page
    uView.setCursor(0,0);
    uView.print("RED");
    uView.display();
    buttonSwitch = 2;
    delay(500);
  } else if (buttonSwitch == 2 && buttonState == LOW){
      analogWrite(RED,0);
      analogWrite(GREEN,255);
      uView.clear(PAGE);    // clear page
      uView.setCursor(0,0);
    buttonSwitch = 3;
    uView.print("GREEN");
    uView.display();
    delay(500);
  } else if (buttonSwitch == 3 && buttonState == LOW){
        analogWrite(GREEN,0);
        analogWrite(BLUE,255);
        uView.clear(PAGE);    // clear page
      uView.setCursor(0,0);
    buttonSwitch = 1;
    uView.print("BLUE");
    uView.display();
    delay(500);
  }
}
