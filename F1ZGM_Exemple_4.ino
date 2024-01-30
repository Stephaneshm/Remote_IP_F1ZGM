/* ------------------------------------------------------------------------- *
 * Name   : F1ZGM Remote IP -> Serial
 * Author : Stéphane HELAIEM - F4IRX
 * Date   : January 26, 2024
 * Purpose: Remote IP For Kramr switch Video Matrix
 * Versions:
 *    0.1  : Initial code base, test IP/Serial
 *    0.1b : Update Web Page
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     http://192.168.1.127/update?output=OUT1&value=81 lien direct 
 * ------------------------------------------------------------------------- */
#define progVersion "0.1b"          

/* ------------------------------------------------------------------------- *
 *       Debug
 * ------------------------------------------------------------------------- */
#define DEBUG 1
#if DEBUG == 1
  #define debugstart(x) Serial.begin(x)
  #define debug(x) Serial.print(x)
  #define debugln(x) Serial.println(x)
#else
  #define debugstart(x)
  #define debug(x)
  #define debugln(x)
#endif

/* ------------------------------------------------------------------------- *
 *       Include libraries 
 * ------------------------------------------------------------------------- */
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "index.h"              //HTML webpage 
#include <SoftwareSerial.h>


/* ------------------------------------------------------------------------- *
 *       Other definitions
 * ------------------------------------------------------------------------- */
const char* ssid = "DC_Atelier";
const char* password = "delta_2019";

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "value";


String ValueIN="81";
String ValueOUT="81";


/* ------------------------------------------------------------------------- *
 *       Create Object
 * ------------------------------------------------------------------------- */
AsyncWebServer server(80);
SoftwareSerial VS162Serial(D5, D6); // RX, TX

/* ------------------------------------------------------------------------- *
 *       Setup
 * ------------------------------------------------------------------------- */
void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  VS162Serial.begin(9600);//9600);
  delay(2000);
  debugln(F("F1ZGM telecommande IP : " __VERSION__)); 
  debugln(F("Built on " __DATE__ " at " __TIME__));  
  debug("RemoteIP version :");
  debugln(progVersion);

  VS162Serial.println("Serial test - VS162 Serial at 9600 ");


  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
   debugln("Connecting to WiFi..");
  }
  #ifdef DEBUG
      debugln(F("DEBUG ON"));                      // Debug - Serial
  #endif
  // Print ESP Local IP Address
  debugln(WiFi.localIP());

  // Route for root / web page

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", MAIN_page);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&value=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    //uint8_t Value_In  = 0x81;
    //uint8_t Value_Out = 0x81;
    String inputMessage1;
    String inputMessage2;
   
   
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
   
      // envoi code suivant table Kramer VS162AV
      // IN_1 -> OUT_1 = 01818181 01+
      // IN_1 -< OUT_2 = 01818281

      if (inputMessage1.substring(0, 2)=="IN") {ValueIN=inputMessage2;} else  {ValueOUT=inputMessage2;}
      debug("Message RS232 : ");
      debug("01");
      debug(ValueIN);
      debug(ValueOUT);
      debugln("81");



      VS162Serial.print("01");
      VS162Serial.print(ValueIN);
      VS162Serial.print(ValueOUT);
      VS162Serial.print("81");
    }

    request->send(200, "text/plain", "OK");
  });

  // Start server
  server.begin();
}

/* ------------------------------------------------------------------------- *
 *       Loop
 * ------------------------------------------------------------------------- */
void loop() {

}