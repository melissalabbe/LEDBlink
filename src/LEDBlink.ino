/*
 * Project LEDBlink
 * Description: Blinks an LED when Twitter user is mentioned
 * Author: Melissa Labbe
 * Date: 09/19/17
 */

 /* led1 is D0, led2 is D7 */

 int led1 = D0;
 int led2 = D7;

 // Declare pins and register Particle function

 void setup()
 {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    // We are also going to declare a Particle.function that will blink LED on request
    Particle.function("led", ledBlink);

    // Make sure both LEDs are off when we start:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

 }

 void loop()
 {
    // No Op
 }

 // Blink LED when API request is sent

 int ledBlink(String command) {

   if (command=="blink") {

       // Turn LED on
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);

       // Leave on for 800 milliseconds
        delay(800);

        // Turn LED off
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        return 1;

     } else {
        return -1;
     }
 }
