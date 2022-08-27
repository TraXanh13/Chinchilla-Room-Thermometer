#include <Wire.h>

// LCD library
#include <LiquidCrystal_I2C.h>

// Library for the sensor
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Initializing LCD screen and size
// location, columns, rows
LiquidCrystal_I2C lcd(0x27,16,2);

// Sensor pin
const int DHT_SENSOR = 2;

// Setting the dht sensor
DHT dht(DHT_SENSOR, DHT11);

void setup() {  
  Serial.begin(9600);

  dht.begin();
  // Clearing everything on the LCD
  lcd.clear();
  lcd.init();
  lcd.begin(16,1);
  lcd.backlight();
}

void loop() {
  // Set the position of first char to col 0 and row 0 
  // setCursor([col], [row])
  printTemp();
  printHumid();
  delay(500);
}

// Prints the temperature contents of the package to the lcd
void printTemp(){
  float temp = dht.readTemperature();
  lcd.setCursor(0, 0);
  
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");
}

// Prints the humidity contents of the package to the lcd
void printHumid(){
  lcd.setCursor(0, 1);
  lcd.print("Humid:");
  float humid = dht.readHumidity();
  lcd.print(humid);
  lcd.print("%");
}
