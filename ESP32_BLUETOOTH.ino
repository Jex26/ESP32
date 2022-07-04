#include "BluetoothSerial.h"

#define PILOTO 2

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("ESP32-Jeison"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(PILOTO,OUTPUT);
}

void loop(){
  char Comando;
  
  if(SerialBT.available()){
      Comando = SerialBT.read();
      if(Comando == 'A') {
        digitalWrite(PILOTO,HIGH);
        SerialBT.println("Led encendido");
        }
      else if(Comando == 'B'){
        digitalWrite(PILOTO,LOW);
        SerialBT.println("Led apagado");
      }
  }
  delay(20);
}
