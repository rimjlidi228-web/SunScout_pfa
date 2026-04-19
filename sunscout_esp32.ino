#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>

// ================= WIFI =================
const char* ssid = "Aouni";
const char* password = "hhhhhhhh";

// ================= SERVER =================
WebServer server(80);

// ================= PINS =================
#define LDR_LEFT 34
#define LDR_RIGHT 35
#define SERVO_PIN 13
#define LED_PIN 4

Servo myServo;

// ================= VARIABLES =================
int position = 90;
int threshold = 200;     // sensibilité servo
int speedStep = 2;

// LDR values
int left = 0;
int right = 0;

// LED state
bool ledState = false;

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(position);

  // ================= WIFI =================
  WiFi.begin(ssid, password);
  Serial.print("Connexion WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnecté !");
  Serial.print("IP ESP32: ");
  Serial.println(WiFi.localIP());

  // ================= API =================
  server.on("/data", []() {
      server.sendHeader("Access-Control-Allow-Origin", "*");
    String json = "{";
    json += "\"left\":" + String(left) + ",";
    json += "\"right\":" + String(right) + ",";
    json += "\"angle\":" + String(position) + ",";
    json += "\"led\":" + String(ledState ? "true" : "false");
    json += "}";

    server.send(200, "application/json", json);
  });

  server.begin();
}

void loop() {
  server.handleClient();

  // ================= LDR READ =================
  left = analogRead(LDR_LEFT);
  right = analogRead(LDR_RIGHT);

  Serial.print("LDR Left: ");
  Serial.print(left);
  Serial.print(" | LDR Right: ");
  Serial.print(right);
  Serial.print(" | Position: ");
  Serial.println(position);

  // ================= SERVO CONTROL =================
  int diff = left - right;

  if (abs(diff) > threshold) {
    if (diff > 0) {
      position -= speedStep;
    } else {
      position += speedStep;
    }

    position = constrain(position, 0, 180);
    myServo.write(position);
  }

  // ================= LED CONTROL =================
  // 👉 LED ON si lumière détectée forte sur au moins un capteur
  if (left < 2000 || right < 2000) {
    digitalWrite(LED_PIN, HIGH);
    ledState = true;
  } else {
    digitalWrite(LED_PIN, LOW);
    ledState = false;
  }

  delay(80);
}