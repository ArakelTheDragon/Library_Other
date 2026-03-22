
/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

// Global vars initialized by compiler at start
double dSensorValue;

// Prototypes
bool bReadFromADC(); // bool returns 1 or 0

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // 9600 baud
}

// the loop routine runs over and over again forever:
void loop() {
  bReadFromADC();
}

bool bReadFromADC(){
  // print out the value you read:
  double dTmp = analogRead(A0);
  if (dSensorValue != dTmp){ // If different than previous value
    dSensorValue = dTmp;
    Serial.println("dSendorValue = ");
    Serial.println(dSensorValue);
    delay(1);        // delay in between reads for stability
    return 0;
  }
   else {
    return 1;
   }
}
