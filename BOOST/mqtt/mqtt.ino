#include <Wire.h>
#include <ESP8266WiFi.h>       // Para ESP8266; use <WiFi.h> se for ESP32
#include <PubSubClient.h>      // Biblioteca MQTT
#include <INA226_WE.h>         // Biblioteca do sensor INA226

#define I2C_ADDRESS 0x40
INA226_WE ina226 = INA226_WE(I2C_ADDRESS);

// ======== Configurações de WiFi ========
const char* ssid       = "Nelson 2G";
const char* password   = "nelson180599";

// ======== Configurações do MQTT ========
const char* mqtt_server = "127.0.0.1"; 
const int   mqtt_port   = 10050;
const char* mqtt_topic  = "tensao/tensao";

// ======== Objetos MQTT e WiFi ========
WiFiClient espClient;
PubSubClient client(espClient);

// ======== Setup ========
void setup() {
  Serial.begin(115200);
  while (!Serial);

  Wire.begin();
  ina226.init();

  // Conexão WiFi
  setup_wifi();

  // Conexão com servidor MQTT
  client.setServer(mqtt_server, mqtt_port);

  // Configuração do sensor INA226
  ina226.setResistorRange(0.1, 1.3);     // Resistor de 0.1Ω e até 1.3A
  ina226.setCorrectionFactor(0.93);      // Fator de correção baseado em calibração

  Serial.println("INA226 configurado - modo contínuo.");
  ina226.waitUntilConversionCompleted();
}

// ======== Loop principal ========
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Variáveis de medição
  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0;

  // Leitura do INA226
  ina226.readAndClearFlags();
  shuntVoltage_mV = ina226.getShuntVoltage_mV();
  busVoltage_V = ina226.getBusVoltage_V();
  current_mA = ina226.getCurrent_mA();
  power_mW = ina226.getBusPower();
  loadVoltage_V = busVoltage_V + (shuntVoltage_mV / 1000.0);

  // Exibe no monitor serial
  Serial.println("=== Leitura INA226 ===");
  Serial.print("Shunt Voltage [mV]: "); Serial.println(shuntVoltage_mV);
  Serial.print("Bus Voltage [V]: "); Serial.println(busVoltage_V);
  Serial.print("Load Voltage [V]: "); Serial.println(loadVoltage_V);
  Serial.print("Current [mA]: "); Serial.println(current_mA);
  Serial.print("Bus Power [mW]: "); Serial.println(power_mW);

  if (!ina226.overflow) {
    Serial.println("Leitura OK - Sem overflow");
  } else {
    Serial.println("Overflow! Escolha um range maior de corrente.");
  }
  Serial.println();

  // Publicação MQTT
  Serial.print("Publicando no tópico ");
  Serial.print(mqtt_topic);
  Serial.print(": ");
  Serial.println(power_mW);

  String payload = String(power_mW, 2);  // 2 casas decimais
  client.publish(mqtt_topic, payload.c_str());

  delay(3000);  // Espera 3 segundos para próxima leitura
}

// ======== Conexão WiFi ========
void setup_wifi() {
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// ======== Reconexão MQTT ========
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("INA226Client")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}
