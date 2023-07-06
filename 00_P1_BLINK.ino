#define led2
#define periodo 1000

unsigned long t_ant=0;

void setup(){
    pinMode(led,OUTPUT);
}

void loop(){
    if((millis())-t_ant>=1000){
        bool led_state=digitalRead(led);
        digitalWrite(led,!led_state);
        t_ant=millis()
    }
}