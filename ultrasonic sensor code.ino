

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <GSM.h>

#define trig 3
#define echo 2
#define buzz 7
long dur;
int dis;
 void setup()
 {
   pinMode(trig,OUTPUT);
   pinMode(echo, INPUT);
   Serial.begin(9600);
 }

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW)
  //travel time of wave extraction
  dur=pulseIn(echo, HIGH);
  //distance calculation
  dis=dur/2*0.034;
  Serial.print("distance");
  Serial.print(dis);
  if(dis>0 && dis<50)
  { 
    digitalWrite(buzz,HIGH);
  }
  else
  {
    digitalWrite(buzz,LOW);
  }
}


//code block for signal sent by the user
const int BUTTON = 4;
const int sms = 5;
int BUTTONstate = 0;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(sms, OUTPUT);
}

void loop()
{
  BUTTONstate = digitalRead(BUTTON);
  if (BUTTONstate == HIGH)
  {
    digitalWrite(sms, HIGH);
  } 
  else{
    digitalWrite(sms, LOW);
  }

  static const int RXP=11 TXP=12;
  static const uint32_t GPSBaud=8600;
  
  TinyGPSPlus gps;

  //Serial connection to our device
  
  
  SoftwareSerial GPS(RXP,TXP);

  void setup()
  {  
  Serial.begin(9600);
  GPS.begin(GPSbaud);
  }
 
  char lati;
  char longi;
  void loop()
  {
    while (GPS.available()>0)
    { 
      gps.encode(GPS.read())
    
      if (gps.location.isUpdated())
      {
        lati=gps.location.lat();
        longi=gps.location.lng();
        SoftwareSerial mySerial(9, 10);

        if (Serial.available()>0)
        switch(Serial.read())
        
        SoftwareSerial mySerial(9, 10);//RX,TX Pins

        void setup()

        { 

        mySerial.begin(9600);   //  baud rate of GSM Module 

        Serial.begin(9600);    // baud rate of Arduino

        delay(100);

      }

      void loop()

      {

       if (Serial.available()>0)

         switch(Serial.read())

        {

         case 1:

         SendMessage();

        break;
        }




      if (mySerial.available()>0)
      {
         Serial.write(mySerial.read());
      }
      void SendMessage()
      {
        mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
        delay(1000);  // Delay of 1 second
        mySerial.println("AT+CMGS=\"+918777213291\"\r"); 
        delay(1000);
        mySerial.println(lati,longi);// The SMS text 
        delay(100);
        mySerial.println((char)26);// ASCII code of CTRL+Z
        delay(1000);
      }



