/*
*************************************************
*           Medidor de vazão pulmonar           *                                   
*                                               *
*       Desenvolvido por Bruno Castanho         *
*                                               *
*                              26/07/2021,BVA   *
*************************************************
*/
//incluindo bibliotecas
#include <math.h>
//BMP280
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <IOXhop_FirebaseESP32.h>
#include <ArduinoJson.h> 
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#define BME280_ADD1 0x76  //os 2 BME280 compartilham o mesmo barramento I2C 
#define BME280_ADD2 0x77

//declaração de varíaveis
float rawPressure1 = 0;
float rawPressure2 = 0;
float delta=0;
float zeroPressure1;
float zeroPressure2;
float volumetricFlowRate = 0;
float volume = 0;
float acul = 0;
float pres_m = 0;

// iniciando sensores
Adafruit_BME280 bme1;
Adafruit_BME280 bme2;

void setup()
{
  Serial.begin(9600);

  SerialBT.begin("Spiromed v1");  //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  bool status;

  status = bme1.begin(BME280_ADD1);
  if (!status)
  {
    while (1);
  }

  status = bme2.begin(BME280_ADD2);
  if (!status)
  {
    while (1) delay(10);
  }

  //calibrando sensor conforme pressão atmosferica    
  zeroPressure1 = bme1.readPressure();
  zeroPressure2 = bme2.readPressure();

}
void loop()
{
  //bluetooth
  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
  }

  //leitura e calculo da pressão diferencial
  for (int i = 0; i < 15; i++)
  {
    rawPressure1 = bme1.readPressure() - zeroPressure1;
    rawPressure2 = bme2.readPressure() - zeroPressure2;

    if (rawPressure2 > rawPressure1)
    {
      delta = rawPressure2 - rawPressure1;
    }
    else
    {
      delta = rawPressure1 - rawPressure2;
    }

    //calculo da vazão
    volumetricFlowRate = 0.0016619011 *(sqrt((2 / 1.225) *(delta) / (sq(0.0016619011 / 0.0003801324))));
    volume = ((volumetricFlowRate *1000));

    acul = acul + volume;

  }

  pres_m = acul / 15;
  // enviando byte para o aplicativo via bluetooth
  SerialBT.write(volume);
  acul = 0;

}

//******FIM*******
