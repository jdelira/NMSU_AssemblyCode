extern "C" 
{    

  byte tempV1;    

  byte tempV2;    

  void setupTherm();    

  void readTherm();    

  void displayTemp();  /** NEW **/ 

}  

 

void setup() 
{    

  Serial.begin(9600);   // initialize serial window

  //setupTherm();  // initialize thermometer (this calls your assembly code)

}

 

void loop() 
{    

  delay(2000);  // delay for two seconds    

  //readTherm();  // read the thermometer (this calls your assembly code)    

  Serial.print("Integer degree part: ");    

  Serial.println(tempV1, DEC);  // print out first byte in decimal    

  Serial.print("Fractional degree part: ");    

  Serial.println(tempV2, HEX);  // print out second byte in hex 
  


  displayTemp(); /** NEW, this also calls your assembly code **/ 

} 


