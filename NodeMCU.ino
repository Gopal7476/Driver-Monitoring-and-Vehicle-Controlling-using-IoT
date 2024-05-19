#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int a,b,c,d,e;
char f; String data;
HTTPClient http;

void setup() {
  WiFi.disconnect();
  delay(2000);
  WiFi.begin("project","12345678");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
  }
  Serial.begin(115200);
  Serial.println("Node MCU");
}

void loop() {
  while (Serial.available()) {
    delay(10);
    f = Serial.read();
    if (f == '@') { 
      a = data.toInt();
      data="";
    }
    else if (f == '*') {
      b = data.toInt();
      data="";
    }
    else if(f=='#') {
      c = data.toInt();
      break;
    }
    else {
      data +=f;
    }
  } 
  
  if (data.length() > 0) {
    Serial.println(a); // mq3
    Serial.println(b); // distance
    Serial.println(c); // acc
    Serial.println("");

    upload();
    data="";
  }
}

void upload() {
  String link="http://blynkcloud.com/5VDcelSeCNNRJ2qOa1UBOuJ9XxRgVOgZ/update/V8?value="; // TEMP
  link=String(link+a);
  http.begin(link);
  http.GET();
  http.end();
  delay(100); 
  link="http://blynkcloud.com/5VDcelSeCNNRJ2qOa1UBOuJ9XxRgVOgZ/update/V9?value="; // MOISTURE
  link=String(link+b);
  http.begin(link);
  http.GET();
  http.end();
  delay(100); 
  link="http://blynkcloud.com/5VDcelSeCNNRJ2qOa1UBOuJ9XxRgVOgZ/update/V10?value=";//LIGHT
  link=String(link+c);
  http.begin(link);
  http.GET();
  http.end();
  delay(100); 
}
