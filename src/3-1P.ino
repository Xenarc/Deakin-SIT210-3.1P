#include "..\lib\BH1750\src\BH1750.h"
#include <Wire.h>
BH1750 lightMeter;

// Wait for Network to become live before sending
// SYSTEM_THREAD(ENABLED);

void setup(){

  Serial.begin(9600);
  Serial.println(F("Ready"));

  Wire.begin();

  lightMeter.begin();
  lightMeter.switch_power_on();
  Serial.println(F("BH1750 Setup"));
}

void loop() {

  float lux = lightMeter.get_light_level();
  Serial.print("Light: ");
  Serial.print(std::to_string(lux).c_str());
  Serial.print(" lx\t");
  bool status = Particle.publish("MBlashkiArgon_LightMeter", std::to_string(lux).c_str(), PRIVATE);
  Serial.print("Status: ");
  Serial.println(status);
  delay(30000);
}
