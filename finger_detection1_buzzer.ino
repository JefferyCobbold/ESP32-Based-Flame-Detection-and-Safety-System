#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FLAME_SENSOR_PIN 23
#define RELAY_PIN 22
#define BUZZER_PIN 12   // Buzzer pin (choose a free GPIO)

// Create LCD object with I2C address 0x27 and 16x2 size
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Initialize I2C on custom pins for ESP32
  Wire.begin(19, 21); // SDA = 19, SCL = 21
  
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);   // Relay off initially
  digitalWrite(BUZZER_PIN, LOW);  // Buzzer off initially

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Flame Detection");
  delay(2000);
  lcd.clear();
}

void loop() {
  int flameDetected = (digitalRead(FLAME_SENSOR_PIN) == LOW); // Active LOW

  if (flameDetected) {
    digitalWrite(RELAY_PIN, HIGH);   // Turn on pump
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer

    lcd.setCursor(0, 0);
    lcd.print("Flame Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Pumping Water   ");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn off pump
    digitalWrite(BUZZER_PIN, LOW);  // Turn off buzzer

    lcd.setCursor(0, 0);
    lcd.print("No Flame Found ");
    lcd.setCursor(0, 1);
    lcd.print("Pump OFF        ");
  }

  delay(500);
}
