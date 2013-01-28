
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

// Write the color to each pin using PWM and the value gathered above
  analogWrite(redPin, currentColorValueRed);
  analogWrite(bluePin, currentColorValueBlue);
  analogWrite(greenPin, currentColorValueGreen);
    delay(50); // wait a sec
  analogWrite(redPin,0); 
  analogWrite(bluePin,0); 
  analogWrite(greenPin,0); 
  
  Serial.print("values for are R, G, B: ");
  Serial.print(currentColorValueRed, DEC);    // print the acceleration in the X axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.print(currentColorValueBlue, DEC);    // print the acceleration in the Y axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.println(currentColorValueGreen, DEC);  // print the acceleration in the Z axis
  delay(100);              // wait 100ms for next reading

}
