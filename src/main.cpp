#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

void setup()
{
    Serial.begin(115200);

    // GPS RX=16 TX=17
    gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

    Serial.println("GPS Tracker Started");
}

void loop()
{
    while (gpsSerial.available())
    {
        gps.encode(gpsSerial.read());
    }

    if (gps.location.isUpdated())
    {
        float lat = gps.location.lat();
        float lon = gps.location.lng();

        Serial.print("Latitude: ");
        Serial.println(lat,6);

        Serial.print("Longitude: ");
        Serial.println(lon,6);

        Serial.print("Google Maps: ");
        Serial.print("https://maps.google.com/?q=");
        Serial.print(lat,6);
        Serial.print(",");
        Serial.println(lon,6);

        Serial.println("----------------------");
    }
}