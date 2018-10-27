#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""


double vol;
int itemp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
     delay(400);
  }
  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  itemp = 0;
}


void loop() {
  // put your main code here, to run repeatedly:
  while(itemp <= 50){
    vol = analogRead(A0);
    Serial.println(vol);
    Firebase.setFloat("/TempReport/"+String(itemp), vol);
    delay(500);
    itemp++;
    }
  itemp = 0;
}
