#include <WiFi.h>
#include <WiFiUdp.h>
const char *ssid = "soufuTitanic";
const char *password = "12345678";
WiFiUDP udp;
char controller;
char hexadecimal[] = {'1','2'};
int controll;
String str;
int LPWM;
int RPWM;
#define L1p 13
#define L1m 12
#define R1p 14
#define R1m 15
#define armp 26
#define armm 25
#define kagop 17
#define kagom 16

unsigned long armtime = 0;
unsigned long armdowntime = 0;

unsigned long kagotime = 0;
unsigned long kagodowntime = 0;

unsigned long armresettime = 0;
unsigned long kagoresettime = 0;

unsigned long armdownresettime = 0;
unsigned long kagodownresettime = 0;



void setup() {
  analogWriteResolution(L1p,10);
  analogWriteResolution(L1m,10);
  analogWriteResolution(R1p,10);
  analogWriteResolution(R1m,10);
  analogWriteResolution(armp,10);
  analogWriteResolution(armm,10);
  analogWriteResolution(kagop,10);
  analogWriteResolution(kagom,10);
  Serial.begin(115200);
  Serial.println("finish");
  WiFi.softAP(ssid, password);
  delay(500);
  pinMode(L1p, OUTPUT);
  pinMode(L1m, OUTPUT);
  pinMode(R1p, OUTPUT);
  pinMode(R1m, OUTPUT);
  pinMode(armp, OUTPUT);
  pinMode(armm, OUTPUT);
  pinMode(kagop, OUTPUT);
  pinMode(kagom, OUTPUT);
  IPAddress IP = WiFi.softAPIP();
  if (udp.begin(8000)) {

  } else {

  }
}

void loop() {
  unsigned long startfortime = millis();
  int packetSize = udp.parsePacket();
  if (packetSize) 
  {
    char packetBuffer[255];
    udp.read(packetBuffer, packetSize);
    packetBuffer[packetSize] = '\0';
    Serial.println(packetBuffer);
    int controller = atoi(packetBuffer);
    String strcontroller = String(packetBuffer);
    int controll = strcontroller.substring(0, 3).toInt();
    int LPWM = strcontroller.substring(4, 8).toInt();
    int RPWM = strcontroller.substring(9, 13).toInt();
    


    Serial.println(controll);

    if (controller >= 512) {
      analogWrite(L1p,LPWM);
      analogWrite(L1m,0);
      analogWrite(R1p,RPWM);
      analogWrite(L1m,0);
      controller = controller - 512;
      Serial.println("OK");
    }

    else if (controller >= 256) {
      analogWrite(L1p,0);
      analogWrite(L1m,LPWM);
      analogWrite(R1p,0);
      analogWrite(R1m,RPWM);
      Serial.println("OKB");

      controller = controller - 256;
    }

    else if (controller >= 128) {
      analogWrite(L1p,LPWM);
      analogWrite(L1m,0);
      analogWrite(R1p,0);
      analogWrite(R1m,RPWM);

      controller = controller - 128;
    }

    else if (controller >= 64) {
      analogWrite(L1p,0);
      analogWrite(L1m,LPWM);
      analogWrite(R1p,RPWM);
      analogWrite(R1m,0);

      controller = controller - 64;
    }
    else {
      analogWrite(L1p,0);
      analogWrite(L1m,0);
      analogWrite(R1p,0);
      analogWrite(R1m,0);
    }
    if (controller >= 32 && armtime <= startfortime && armdowntime <= startfortime) {
      armtime = startfortime + 1000;//1000 = 1s
      controller = controller - 32;
    }
    if (controller >= 16 && kagotime <= startfortime && kagodowntime <= startfortime) {
      kagotime = startfortime + 1000;
      controller = controller - 16;
    }

    if(armtime >= startfortime) {
      analogWrite(armp,1023);
      analogWrite(armm,LOW);
      armdowntime = startfortime + 1000; 
      Serial.println("UP");
    }
    else if(armdowntime >= startfortime){
      analogWrite(armp,LOW);
      analogWrite(armm,1023);
      Serial.println("DOWN");
    }
    else if (armtime <= startfortime && armdowntime <= startfortime && controller >= 4){
      analogWrite(armp,LOW);
      analogWrite(armm,LOW);
      Serial.println("STOP");
    }
    if (controller >= 8){
      analogWrite(armp,1023);
      analogWrite(armm,LOW);
      controller = controller - 8;
    }
    else if (controller >= 4){
      analogWrite(armp,LOW);
      analogWrite(armm,1023);
      controller = controller - 4;
    }
    else if(armtime <= startfortime && armdowntime <= startfortime){
      analogWrite(armp,LOW);
      analogWrite(armm,LOW);
    }

    if(kagotime >= startfortime) {
      analogWrite(kagop,1023);
      analogWrite(kagom,LOW);
      kagodowntime = startfortime + 1000;
    }
    else if(kagodowntime >= startfortime){
      analogWrite(kagop,LOW);
      analogWrite(kagom,1023);

    }
    else if (kagotime <= startfortime && kagodowntime <= startfortime && controller <=3 && !controller == 0){
      analogWrite(kagop,LOW);
      analogWrite(kagom,LOW);
    }
    if (controller >= 2){
      analogWrite(kagop,1023);
      analogWrite(kagom,LOW);
      controller = controller - 2;
    }
    else if (controller >= 1){
      analogWrite(kagop,LOW);
      analogWrite(kagom,1023);
      controller = controller - 1;
    }
    else if(kagotime <= startfortime && kagodowntime <= startfortime){
      analogWrite(kagop,LOW);
      analogWrite(kagom,LOW);
    }
    Serial.println(LPWM);
    Serial.println(RPWM);
    Serial.println(startfortime);
  }
}