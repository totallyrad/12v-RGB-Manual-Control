                                                    // Init the Pins used for PWM
int redPin = 3;
int greenPin = 5;
int bluePin = 6;


                                                    // Init the Pins used for 10K pots
const int redPotPin = 0;
const int greenPotPin = 1;
const int bluePotPin = 2;

                                                    // Init our Vars
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;

void setup()
{
  Serial.begin(9600);  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
                                                    // Read the voltage on each analog pin then scale down to 0-255 and inverting the value for common anode
  currentColorValueRed = (254 - map( analogRead(redPotPin), 0, 1024, 0, 255 ) ); 
  currentColorValueBlue = (254 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ) );
  currentColorValueGreen = (254 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ) );


  analogWrite(redPin, currentColorValueRed);        // Write the color to each pin using PWM and the value gathered above
  analogWrite(bluePin, currentColorValueBlue);
  analogWrite(greenPin, currentColorValueGreen);
    delay(50);                                      // wait a little bit. I considered adding in another variable here so a 4th pot could be used to control rate
  analogWrite(redPin,0);                            // Turn off all pins
  analogWrite(bluePin,0); 
  analogWrite(greenPin,0); 
  
  Serial.print("values for R, G, B: ");
  Serial.print(currentColorValueRed, DEC);          // print the acceleration in the R axis
  Serial.print(" ");                                // prints a space between the numbers
  Serial.print(currentColorValueBlue, DEC);         // print the acceleration in the G axis
  Serial.print(" ");                                // prints a space between the numbers
  Serial.println(currentColorValueGreen, DEC);      // print the acceleration in the B axis
  delay(100);                                       // wait 100ms for next reading

}
