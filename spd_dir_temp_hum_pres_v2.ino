#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define RE_SPEED 8
#define DE_SPEED 7
SoftwareSerial modSpeed(2, 3);

#define RE_DIRECTION 10
#define DE_DIRECTION 9
SoftwareSerial modDirection(4, 5);

Adafruit_BME280 bme;

const byte O2[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B};
byte values[20];

void setup() {
  Serial.begin(4800);
  modSpeed.begin(4800);
  modDirection.begin(4800);
  pinMode(RE_SPEED, OUTPUT);
  pinMode(DE_SPEED, OUTPUT);
  pinMode(RE_DIRECTION, OUTPUT);
  pinMode(DE_DIRECTION, OUTPUT);

  if (!bme.begin(0x76)) {
    Serial.println("Could not find BME280 sensor! Check wiring.");
    while (1);
  }
}

void loop() {
  modSpeed.listen();
  int windSpeed = readSensor(modSpeed, RE_SPEED, DE_SPEED, values);
  Serial.print("Wind Speed: ");
  Serial.print(windSpeed);
  Serial.println(" m/s");

  delay(2000);

  modDirection.listen();
  int windDirection = readSensor(modDirection, RE_DIRECTION, DE_DIRECTION, values);
  Serial.print("Wind Direction: ");
  Serial.print(windDirection);
  Serial.print("° - ");
  Serial.println(getDirectionName(windDirection));

  delay(2000);

  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 2);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure, 2);
  Serial.println(" hPa");

  Serial.println();

  delay(2000);
}

int readSensor(SoftwareSerial &mod, int RE, int DE, byte *values) {
  int result = -1;
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);

  if (mod.write(O2, sizeof(O2)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    delay(100);

    for (byte i = 0; i < 11; i++) {
      if (mod.available()) {
        values[i] = mod.read();
      } else {
        values[i] = 0xFF;
      }
    }

    result = (values[5] * 256) + values[6];
  }
  return result;
}

String getDirectionName(int angle) {
  if (angle == 0) return "North";
  if (angle == 45) return "Northeast";
  if (angle == 90) return "East";
  if (angle == 135) return "Southeast";
  if (angle == 180) return "South";
  if (angle == 225) return "Southwest";
  if (angle == 270) return "West";
  if (angle == 315) return "Northwest";
  return "Unknown";
}
