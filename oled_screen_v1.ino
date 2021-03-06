

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define HONDA_2HEIGHT 31
#define HONDA_2WIDTH 128


const unsigned char PROGMEM Honda_2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x07, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xC3, 0xFF, 0x7F, 0xE3, 0xFF, 0xC7, 0xFE, 0x7F, 0xFF, 0xFF, 0x83, 0xFF, 0x00,
0x03, 0xFF, 0xFF, 0xC3, 0xFF, 0x7F, 0xEF, 0xFF, 0xF7, 0xFE, 0x7F, 0xFF, 0xFF, 0xC3, 0xFF, 0x80,
0x1F, 0xFF, 0xFF, 0x80, 0xFC, 0x0F, 0x9F, 0xC7, 0xF9, 0xFF, 0x1E, 0x1F, 0xFF, 0xE0, 0xFF, 0xC0,
0x7F, 0xFF, 0xFF, 0x80, 0x7C, 0x0F, 0x9F, 0x81, 0xF9, 0xFF, 0x8E, 0x1F, 0x03, 0xF0, 0xFF, 0xC0,
0x7F, 0xFF, 0xFC, 0x00, 0x7F, 0xFF, 0x9F, 0x80, 0xF9, 0xFF, 0xCE, 0x1F, 0x03, 0xF1, 0xE7, 0xE0,
0x7F, 0xFF, 0xFE, 0x00, 0x7F, 0xFF, 0x9F, 0x00, 0xF9, 0xEF, 0xCE, 0x1F, 0x03, 0xF1, 0xFF, 0xF0,
0x7F, 0xFF, 0xFC, 0x00, 0x7F, 0xFF, 0x9F, 0x80, 0xF9, 0xE7, 0xEE, 0x1F, 0x03, 0xF3, 0xFF, 0xF0,
0x3F, 0xFF, 0xF0, 0x00, 0x7C, 0x0F, 0x9F, 0x81, 0xF9, 0xE7, 0xFE, 0x1F, 0x03, 0xF7, 0xFF, 0xF8,
0x1F, 0xFF, 0x80, 0x00, 0xFC, 0x0F, 0x9F, 0xC3, 0xF9, 0xE3, 0xFE, 0x1F, 0x0F, 0xE7, 0x81, 0xFC,
0x0F, 0xFF, 0xC0, 0x03, 0xFF, 0x7F, 0xEF, 0xFF, 0xF7, 0xF9, 0xFE, 0x7F, 0xFF, 0xFF, 0xC3, 0xFF,
0x07, 0xFF, 0xF0, 0x03, 0xFF, 0x7F, 0xE7, 0xFF, 0xE7, 0xF9, 0xFE, 0x7F, 0xFF, 0xBF, 0xC3, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



#define DS3231_I2C_ADDRESS 0x68
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

const int buttonPin1 = 8;
int buttonState1 = 0;
const int buttonPin2 = 10;
int buttonState2 = 0;
//const int buttonPin3 = 9;
//int buttonState3 = 0;

float volt;
int voltPin = A2;
int DST;
void setup()   {                
  
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP); 
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  
  display.clearDisplay();
  display.drawBitmap(0, 0, Honda_2, 128, 31, WHITE);
  display.display();
  delay(5000);
  // Clear the buffer.
  display.clearDisplay();

  displayTime();
  display.display();
  display.clearDisplay();



 Wire.begin();
 
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  //setDS3231time(20,35,19,7,23,9,17);



}
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  
}
void readDS3231time(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
  
  }

void displayTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  // send it to the serial monitor
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.print(" Day of week: ");
  switch(dayOfWeek){
  case 1:
    Serial.println("Sunday");
    break;
  case 2:
    Serial.println("Monday");
    break;
  case 3:
    Serial.println("Tuesday");
    break;
  case 4:
    Serial.println("Wednesday");
    break;
  case 5:
    Serial.println("Thursday");
    break;
  case 6:
    Serial.println("Friday");
    break;
  case 7:
    Serial.println("Saturday");
    break;
  }    
 
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,2);
  display.print(hour, DEC);
  display.print(":");
  if (minute<10)
  {
   display.print("0");
  }
  
 
  display.print(minute, DEC);
  //display.print(":");
  //display.print(second, DEC);
  display.display();
  display.clearDisplay();
  
  if (dayOfWeek == 1 && month == 10 && dayOfMonth >= 25 && hour == 3 && second == 1 && minute == 0)
    { setDS3231time(1,0,2,1,dayOfMonth,10,year);
    
    DST=DST+1;
    Serial.println("DST OCT");
    Serial.println(DST);   
      
     } 
  if (dayOfWeek == 1 && month == 3 && dayOfMonth >= 25 && hour == 2 && second == 0 && minute == 0)
    { setDS3231time(1,0,3,1,dayOfMonth,3,year);
    
    DST=DST+1;
    Serial.println("DST MAR");
    Serial.println(DST);   
      
     } 
   //  if (buttonState2 ==LOW) {
   //  setDS3231time(second,minute,hour +1,dayOfWeek,dayOfMonth,month,year);
   //  Serial.println("Hour +");
   //  }  
     
}
void loop() {

 buttonState1=digitalRead(buttonPin1);
 //Serial.println("test");
 
 displayTime(); 


  
  if (buttonState1 ==LOW) {

    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,5);
    display.print("Voltage");
    display.display();
    delay(2000);
    display.clearDisplay();
  
      for (int i=0; i<=120; i++) {

        float volt = analogRead(voltPin);
        volt = volt * (5.00 / 1023.00) * 4;
        display.setTextSize(3);
        display.setTextColor(WHITE);
        display.setCursor(4,5);
        display.print(volt);
        display.print("V");
        display.display();
        delay(500);
        display.clearDisplay(); 

    }
  }
}




   
   





