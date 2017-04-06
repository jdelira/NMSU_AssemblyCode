extern "C" 
{    

  byte tempV1;    

  byte tempV2;    

  void setupTherm();    

  void readTherm(); 

}  

 

void setup() 

{

  Serial.begin(9600);   // initialize serial window

  setupTherm();  // initialize thermometer (this calls your assembly code) 

}  

 

void loop() 

{

  //byte temp1;
  
  //byte temp2;
 
  //byte temp3;
  
  delay(2000);  // delay for two seconds    

  readTherm();  // read the thermometer (this calls your assembly code)       

  Serial.print("Integer degree part: ");    

  Serial.println(tempV1, DEC);  // print out first byte in decimal    

  Serial.print("Fractional degree part: ");    

  Serial.println(tempV2, HEX);  // print out second byte in hex 
  

  int temp1 = (int)tempV1;  //conver to fahrenheit
  //temp2 = tempV2 * 9/5 + 32;  //convert to fahrenheit
  int temp2 = (((int)tempV2) * 100)/256; //cuts number down to 10ths place 
  int temp3 = (temp1 * 100) + temp2;
  temp3 = temp3 * 9;
  temp3 = temp3 / 5;
  temp3 = temp3 + 3200;
  temp3 = temp3 / 10;
  
  Serial.println();
  Serial.print("Fahrenheit: ");
  //Serial.print(temp1, DEC);
  //Serial.print(temp2, HEX);
  Serial.println(temp3);
  
  Serial.println();
  

} 



