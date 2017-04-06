
//
// Declare the things that exist in our assembly code
//
extern "C" { 
  byte val1;
  byte val2;
  void compute();
}

//
// function to read a 2-digit decimal value from user
//
byte read2DigitValue()
{
  byte inch; int val;
  Serial.println("Enter a 2-digit decimal value:");
  while (!Serial.available()) delay(100);
  inch = Serial.read();
  val = (inch - '0') * 10;
  while (!Serial.available()) delay(100);
  inch = Serial.read();
  val += (inch - '0');
  Serial.print("The value entered is ");
  Serial.println(val,DEC);
  return (byte) val;
}

//
// Arduino-required setup function (called once)
//
void setup()
{
  //
  // Initialize serial communications
  //
  Serial.begin(9600);
  //
  // Read 2 values from user, store in global vars
  //
  val1 = read2DigitValue();
  val2 = read2DigitValue();
  //
  // Call our assembly code
  //
  compute();
  //
  // print out value of val1 variable
  Serial.println("After compute()");
  Serial.print("The value is ");
  Serial.println((int)val1,DEC);
}

//
// Arduino-required loop function (called infinitely)
//
void loop()
{
  delay(20000); // 20,000 millisecs == 20 seconds
  Serial.println("*");
}

