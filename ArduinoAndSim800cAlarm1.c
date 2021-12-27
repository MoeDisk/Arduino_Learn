#define sms_content "I am SMS from GSM Module"
#define phone_num1 "AT+CMGS=\"10086\"\r"
#define phone_num2 "ATD10086;"
#define power_key 12       //power key is connected to digital pin 12
#include <avr/wdt.h>

void(* resetFunc) (void) = 0;

int ledPin = 13;
int inputPin = 2;
int val = 0; 
int inPin = 7;
void inint();
void power_on();
void setup(){
  inint();
}

void loop(){
  val = digitalRead(inPin);
  digitalWrite(ledPin, val); 
  int val = digitalRead(inputPin);
  while(val == HIGH){
    Serial.println("Warning");
    Serial.println(phone_num2);
    delay(100);
    Serial.println("AT+CMGF=1\r");
    delay(1000);
    Serial.println(phone_num1);
    delay(1000);
    Serial.println(sms_content);
    delay(100);
    Serial.println((char)26);
    delay(300000);
    Serial.println("Restart");
    break;
  }
}

void inint(){
  pinMode(inputPin, INPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(power_key, OUTPUT);
  Serial.begin(115200);
  power_on();
  delay(500);
}

void power_on(){
  digitalWrite(power_key,HIGH);
  delay(1500);
  digitalWrite(power_key, LOW);
  Serial.println("AT");
  delay(300);
  Serial.println("AT");
  delay(8000);
}

//MoeDisk
