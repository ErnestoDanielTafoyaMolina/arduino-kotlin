#include "BluetoothSerial.h"

const char *pin = "1q2w3e4r"
String device_name = "NAME"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable. It is only available for the ESP32
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled
#endif
BluetoothSerial SerialBT;

String message="";
char inComingChar;
#define led 2
void setup(){
    pinMode(led,OUTPUT);
    Serial.begin(115200);
    SerialBt.begin(device_name);
    Serial.println("The device with name \"%s\" and MAC address %s is started. \nNow you can pair it with bluetooth!\n",device_name.c_str(),SerialBT.getMacString());

    #ifdef USE_PIN
        SerialBT.setPin(pin);
        Serial.println("Using PIN %s", pin);

}
void loop(){

    if(SerialBT.available()){
        inComingChar=SerialBT.read();
        if(inComingChar!='\n'){
            message+=String(inComingChar);
        }
    }
    Serial.println("message recived %s", message);
    if(message=="T"){
        bool led_state = digitalRead(led);
        digitalWrite(led,!led_state);
    }

}