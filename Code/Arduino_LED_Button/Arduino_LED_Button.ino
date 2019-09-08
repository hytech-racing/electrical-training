/*
 * Code that demonstrates how to create a sticky pushbutton to control a LED.
 */
 
/*
 * Arduino Pin Definitions
 */
#define LED 13
#define BUTTON 12

/*
 * Variable Definitions
 */
int buttonState = LOW; // Way to store button state
int lastbuttonState = LOW; // Way to store previous button state from loop to loop

int ledState = LOW; // Way to store previous LED state from loop to loop

long lastDebounceTime = 0;  // The last time the button was pressed
long debounceDelay = 25;    // The time delay to block button bouncing

/*
 * Pin Setup
 */
void setup(){
  pinMode(LED, OUTPUT);
  pinMode (BUTTON, INPUT);
  digitalWrite(LED, ledState);
 }

/*
 * Main Loop
 */
void loop() {
  int buttonReading = digitalRead(BUTTON); // Reads button input
  if (buttonReading != lastbuttonState) {
    lastDebounceTime = millis(); // Gets current time
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) { // Waits until delay has passed 
    if (buttonReading != buttonState) { // Checks if the state still matches
      buttonState = buttonReading;
      
      if (buttonState == HIGH) { // Checks button was pushed
        ledState = !ledState; // Switches LED state
      }
    }
  }
  
  digitalWrite(LED, ledState); // Writes state change to the LED
  lastbuttonState = buttonReading; // Stores button state for next loop
}
