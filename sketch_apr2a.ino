#include <SPI.h>
#include <WiFiNINA.h>
#include <Servo.h>

#define led 9
#define servoPin 10

char ssid[] = "SoM BhArTi";
char userid[]= "15012003";
int keyIndex = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

Servo myservo;
String readString;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  myservo.attach(servoPin);

  while (status != WL_CONNECTED) {
    Serial.println(status);
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,userid);
    delay(10000);
  }
  server.begin();
  Serial.println(status);
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100)
        {
          readString += c;
          //Serial.print("Readstring:");
          //Serial.println(readString);
          Serial.write(c);
          
          if (c == '\n') {
            client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");
            client.println("<br />");
            client.println("<a href=\"/?servo\"\">Move Servo</a><br />");

            delay(1);
            
            if(readString.indexOf("ON") > 0)
            {
              digitalWrite(13, HIGH);
              delay(1);
              myservo.write(myservo.read() + 10);
              delay(1000);
            }
            else{
              if(readString.indexOf("OFF") > 0)
              {
                Serial.println("OFF Block");
                digitalWrite(13, LOW);    
                delay(1);
                myservo.write(myservo.read() - 10);
              delay(1000);
              }
              else{
                if(readString.indexOf("s1") > 0)
                {
                  Serial.println("help:" + readString);
                  Serial.println("help:" + readString.substring(4));
                  String thumbPosition = "";
                  Serial.println(readString);
                  for(int i = 0 ; i < readString.length(); i++){
                    char a  = readString.charAt(i);
                    if(a != '/')
                    {
                      thumbPosition = thumbPosition + a;
                    }
                  }
                  int sliderNo = thumbPosition.toInt();
                  Serial.println("servo motor 1");
                  myservo.write(myservo.read() + 10);
                  delay(1000); 
                }
              }
            }
            
            readString="";

            delay(1);
            client.stop();
            Serial.println("client disonnected");
          }
        }
      }
    }
  }
}
