#include <PubSubClient.h>
#include <WiFi.h>

const char* ssid = "SSID";
const char* pass = "PASSWORD";
const char* mqtt_server = "MQTT.BROKER.IP.ADDRESS";


WiFiClient evilButton;
PubSubClient client(evilButton);
bool gate = false;

// for use with Sparkfun qwiic pocket ESP32-C6 board
// on the docket: implementing deep sleep function


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("evilButton", "mqtt_user","mqtt_user")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


int readDIP() {
  int result = (1 * !digitalRead(17)) + (2 * !digitalRead(4)) + (4 * !digitalRead(3)) + (8 * !digitalRead(2));
  return result;
}

void runFNC(int val) {
  client.publish("/evil-button/", String(val).c_str());
}

void setup() {
  Serial.begin(115200);
  Serial.println("setup beginning");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  client.setServer(mqtt_server, 1883);
  Serial.println("network established");

// note, there might be something wrong with using pin 17. it wasnt really working for me
  pinMode(2, INPUT_PULLUP);  // DIP switches
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  Serial.println("dip pins initialized");

  pinMode(19, INPUT_PULLUP);  // button for button input
  Serial.println("input button initialized");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(500);

  if (digitalRead(19) == false && gate == true) {
    int result = readDIP();
    runFNC(result);
    Serial.print("value: ");
    Serial.println(result);
    gate = false;
  }
  if (digitalRead(19) == true) {
    // button only fires on release
    gate = true;
  }
}
