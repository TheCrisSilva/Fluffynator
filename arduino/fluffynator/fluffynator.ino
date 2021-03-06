
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int count = 0; // initialize variable count
int state = 0;
int buttonPress;
long timeRef = 0;


LiquidCrystal_I2C lcd(0x27, 20, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:

  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT_PULLUP); // button pin
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  digitalWrite(7, LOW);
  digitalWrite(5, HIGH);
  dht.begin();

  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();





  Serial.begin(9600);

  Serial.print("The count is :");
  Serial.println(count);
  count = count + 1;

  Serial.println(state);
  lcd.print("Hey synch ");
  lcd.setCursor(0, 1);
  lcd.print("Fluffynator!");
  delay(2000);

  timeRef = millis(); // getting current time
  while (millis() < (timeRef + 20000)) {
    buttonPress = digitalRead(2);
    Serial.println(buttonPress);


    if (buttonPress == 0) {
      digitalWrite(12, LOW);
      delay(300);
      digitalWrite(12, HIGH);
      delay(300);
      while (buttonPress == 0) {
        buttonPress = digitalRead(2);


      }

    }
  }


}

void loop() {

  delay(3000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(count);
  Serial.print(",");
  Serial.print(h); // %humidity
  Serial.print(",");

  Serial.println();
  count = count + 1;

  //lcd.setCursor(0, 0);  // clear sets curser to (0,0)
  lcd.clear();
  lcd.print(h );
  lcd.print("%");
  lcd.print(",");
  lcd.print(t);
  lcd.print(" ");
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print(state);
  lcd.print(" ");
  lcd.print("state");
  delay(1500);


  if ((h < 70) && (state == 0)) {
    turnOn(); // turns on the Humidifier
    state = 1;
  }
  else if ((h > 70) && (state == 1)) {
    turnOff();
    state = 0;


  }
}

void turnOn()
{
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);


}

void turnOff()
{
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second\

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second


}
