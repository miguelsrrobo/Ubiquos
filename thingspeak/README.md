## ✅ **1. Pré-requisitos**

### ⚙️ Hardware necessário:

* ESP8266 (ex: NodeMCU ou Wemos D1 Mini)
* Sensor de corrente/tensão **INA226**
* Display **LCD 16x2 com interface I2C**
* Resistores de shunt (conforme necessário para o INA226)
* Fonte de alimentação
* Fios jumpers

---

## 📦 **2. Instalar as bibliotecas necessárias**

No **Arduino IDE**, vá em:
`Sketch > Incluir Biblioteca > Gerenciar Bibliotecas`
Procure e instale:

* `INA226_WE`
* `LiquidCrystal_I2C`
* `ESP8266WiFi`

---

## 🌐 **3. Criar conta no ThingSpeak**

1. Acesse: [https://thingspeak.com](https://thingspeak.com)

2. Crie uma conta gratuita

3. Vá em **Channels > New Channel**

4. Configure os campos:

   * Field 1: Tensão
   * Field 2: Tensão com carga
   * Field 3: Corrente (mA)
   * Field 4: Potência (mW)

5. Após criar, vá em **API Keys**

   * Copie a **Write API Key** (você usará no código)

---

## 📄 **4. Configurar o código**

### ⚙️ Altere as seguintes variáveis no código:

```cpp
const char* ssid     = "SUA_REDE_WIFI";
const char* pass     = "SUA_SENHA_WIFI";
String apiKey        = "SUA_WRITE_API_KEY_DO_THINGSPEAK";
```

Essas informações conectam seu ESP8266 à internet e enviam os dados para seu canal no ThingSpeak.

---

## 🔌 **5. Conexões**

| Componente       | ESP8266                          |
| ---------------- | -------------------------------- |
| INA226 SDA       | D2 (GPIO4)                       |
| INA226 SCL       | D1 (GPIO5)                       |
| LCD SDA          | D2 (GPIO4)                       |
| LCD SCL          | D1 (GPIO5)                       |
| VCC              | 3.3V ou 5V (conforme componente) |
| GND              | GND                              |
| PWM OUT (GPIO12) | Dispositivo de controle PWM      |

---

## 🧠 **6. Como funciona o código**

### Leitura de dados:

* O sensor **INA226** mede tensão e corrente
* Calcula a potência (P = V × I)

### Controle fuzzy:

* Define o valor do PWM baseado na potência usando lógica fuzzy
* Controle proporcional entre 0–255

### Exibição:

* Mostra os dados no **LCD 16x2** com backlight

### Envio para o ThingSpeak:

* Usa uma conexão HTTP padrão (porta 80)
* Envia os dados via método POST a cada 15 segundos
* Campos:

  * field1 = tensão (V)
  * field2 = tensão com carga (V)
  * field3 = corrente (mA)
  * field4 = potência (mW)

---

## 📈 **7. Visualizar os dados**

Após fazer upload do código para seu ESP8266 e aguardar a conexão, acesse seu canal no ThingSpeak e veja os gráficos sendo atualizados com:

* **Tensão**
* **Tensão com carga**
* **Corrente**
* **Potência**

---

## 🛠️ **8. Dicas úteis**

* Certifique-se de que o intervalo entre envios é de **15 segundos** (mínimo exigido pela plataforma gratuita do ThingSpeak).
* Verifique se o **shunt resistor** no INA226 é compatível com a corrente medida.
* Se o LCD não mostrar nada, teste outros endereços como `0x3F` ao invés de `0x27`.
