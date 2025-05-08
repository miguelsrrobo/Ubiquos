# Aumento da Eficiência do MPPT em Sistemas Solares por Meio de Método de Inteligência Artificial PSO


---
# Sumário

1. [Introdução](#introdução)
2. [Motivação](#motivação)
3. [Descrição da Proposta](#descrição-da-proposta)
4. [Requisitos](#requisitos)
    - [Requisitos Funcionais](#requisitos-funcionais)
    - [Requisitos Não Funcionais](#requisitos-não-funcionais)
5. [Diagrama de Comunicação](#diagrama-de-comunicação)
6. [Diagrama Elétrico](#diagrama-elétrico)
7. [Revisão da Literatura](#revisão-da-literatura)
8. [Metodologia de Desenvolvimento](#metodologia-de-desenvolvimento)
9. [Documentação do Código](#documentação-do-código)
    - [Ambiente de Desenvolvimento](#ambiente-de-desenvolvimento)
    - [Instalação](#instalação)
    - [Modelo Matematico](#modelo-matematico)
    - [INA226](#ina226)
    - [Programa Final](#programa-final)
11. [Configuração do Zabbix](#configuração-do-zabbix)
12. [Resultados Esperados](#resultados-esperados)
13. [Conclusão](#conclusão)
14. [Referências](#referências)
---
## Introdução
Este trabalho busca otimizar a eficiência energética, especialmente a potência em sistemas solares fotovoltaicos, usando técnicas de inteligência artificial (IA) para o rastreamento do ponto de máxima potência (MPPT) em condições de sombreamento parcial. Diante dos desafios causados pelos múltiplos picos locais na curva P-V, o estudo analisou referências e realizou simulações no software PLECS com o método de Otimização por Enxame de Partículas (PSO). Os resultados demonstraram que métodos de IA melhoram a identificação do ponto de máxima potência global (GMPP) sob sombreamento, aumentando a eficiência da geração fotovoltaica.

## Motivação
Nas últimas décadas, fontes de energia renováveis vêm ganhando destaque devido ao aumento do consumo global de energia elétrica, associado principalmente ao crescimento populacional. O uso excessivo de combustíveis fósseis tem intensificado a poluição e o aquecimento global, impulsionando o interesse em alternativas renováveis, como a energia solar fotovoltaica (PV), favorecida por políticas públicas e redução de custos. Embora a geração PV seja confiável e sustentável, enfrenta desafios como o alto custo inicial, baixa eficiência sob certas condições e sua intermitência. Para melhorar a produção, pesquisadores têm investido no desenvolvimento de células mais eficientes e em dispositivos de rastreamento do ponto de máxima potência (MPPT) (HEGAZY; SHOKAIR; SAAD, 2023; JIN et al., 2017).

Os MPPTs, compostos por conversores CC-CC e sistemas de controle embarcados, utilizam algoritmos como Perturba e Observa (P&O), Condutância Incremental (INC) e Tensão Constante (CV) (VILLEGAS-MIER et al., 2021; GRUNER et al., 2023). Contudo, esses métodos tradicionais têm dificuldades em condições de sombreamento parcial (PSC), onde múltiplos pontos de máximo locais (LMPPs) surgem, dificultando a identificação do ponto de máxima potência global (GMPP) (YAP; SARIMUTHU; LIM, 2020).

Para superar essas limitações, técnicas de inteligência artificial (AI) como Enxame de Partículas (PSO), têm sido aplicados, proporcionando maior precisão e eficiência (YAP; SARIMUTHU; LIM, 2020). Diante disso, este trabalho propõe a aplicação do metodo (PSO) ao MPPT sob sombreamento parcial, com a implementação desta técnica, proponse um almento da eficiencia energetica

## Descrição da Proposta
Serão desenvolvidos dois hardwares: um conversor CC-CC (Conversor Boost) e um controlador baseado no ESP8266 com sensor INA226. Esses dispositivos serão responsáveis por analisar e controlar o passo de cálculo no conversor CC-CC. Os resultados obtidos, influenciados pela aplicação do método PSO, afetarão o ajuste do passo de cálculo e serão enviados para a plataforma Zabbix.

## Requisitos

## REQUISITOS FUNCIONAIS
Os requisitos funcionais definem as principais funcionalidades que o protótipo do sistema deverá oferecer para garantir a integração eficaz entre o conversor Boost, o controlador baseado em ESP8266 e a plataforma de monitoramento Zabbix. As principais funcionalidades são:

- **Controle dinâmico do conversor Boost:** O protótipo deverá permitir o ajuste automático do duty cycle do conversor CC-CC (Boost), com base nas leituras de corrente, tensão e potência fornecidas pelo sensor INA226, em tempo real.

- **Aplicação do algoritmo PSO:** O sistema deverá implementar o método de Otimização por Enxame de Partículas (PSO) para ajustar o passo de cálculo e maximizar a eficiência energética do conversor.

- **Envio de dados para o Zabbix:** O controlador ESP8266 deverá enviar continuamente os dados de operação (tensão, corrente, potência e duty cycle) para a plataforma Zabbix, em formato adequado (como JSON via MQTT ou HTTP).

- **Monitoramento remoto:** O sistema deverá possibilitar o monitoramento remoto dos parâmetros do conversor Boost através de dashboards configurados no Zabbix, permitindo a análise e registro de desempenho.

- **Ajuste automático baseado em monitoramento:** Com base nos dados monitorados pelo Zabbix, o sistema deverá permitir ajustes automáticos de parâmetros de operação, caso sejam detectados desvios de desempenho ou falhas.

## REQUISITOS NÃO FUNCIONAIS

- **Desempenho:** O protótipo deverá garantir tempos de resposta baixos para leitura dos sensores, aplicação do algoritmo PSO e envio dos dados ao Zabbix, assegurando uma operação em tempo real.

- **Escalabilidade:** O sistema deverá ser capaz de integrar múltiplos conversores Boost monitorados simultaneamente, com cada um enviando dados a uma única instância do Zabbix, conforme a necessidade de expansão.

- **Confiabilidade:** A solução deverá assegurar alta disponibilidade dos dados enviados ao Zabbix, com estratégias de reconexão automática do ESP8266 em caso de falhas de rede.

- **Manutenibilidade:** O código do controlador deverá ser modular, facilitando atualizações futuras no algoritmo de controle, integração com novos sensores ou mudanças na estrutura de comunicação com o Zabbix.

- **Portabilidade:** O sistema deverá ser capaz de ser facilmente adaptado para operar com outros microcontroladores similares ao ESP8266 ou para comunicação com diferentes servidores de monitoramento, além do Zabbix.

- **Eficiência no uso de recursos:** O firmware do ESP8266 deverá otimizar o uso de memória e processamento, assegurando um consumo energético reduzido, ideal para aplicações em ambientes com restrições de energia.

## Diagrama de Comunicação

## 5.1 Descrição Geral

Nesta seção, apresentamos o diagrama de comunicação que ilustra o fluxo de dados e a interação entre os principais componentes do sistema de rastreamento de ponto de máxima potência (MPPT) utilizando um conversor Boost, um ESP8266 e o monitoramento via Zabbix.

O sistema é dividido em três grandes blocos:
- **Módulo Fotovoltaico**
- **Sistema MPPT**
- **Data Services (Serviços de Dados)**

Cada etapa será detalhada a seguir.

---

<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/diagrama.png" alt="Rinha logo" width="30%" />
</p>

---

## 5.2 Descrição dos Componentes do Diagrama

### 5.2.1. Módulo Fotovoltaico
O sistema inicia no **Módulo Fotovoltaico**, que é responsável pela geração de energia elétrica a partir da radiação solar. A saída de energia gerada é enviada diretamente para o sistema MPPT.

### 5.2.2. Sistema MPPT (Boost + ESP)

- **Conversor CC-CC (Boost)**:  
  O conversor Boost atua para ajustar dinamicamente a tensão e a corrente vindas do módulo fotovoltaico, buscando o ponto de máxima potência (MPPT). Ele é controlado de forma inteligente pelo microcontrolador.

- **ESP8266**:  
  O ESP é o microcontrolador responsável por:
  - Ler as informações de tensão, corrente e potência (por meio do sensor INA226, embutido no sistema);
  - Aplicar o algoritmo de controle MPPT;
  - Controlar o duty cycle do conversor Boost para otimizar a extração de energia;
  - Comunicar os dados de monitoramento para o serviço de dados externo.

### 5.2.3. Data Services (Zabbix + Banco de Dados)

- **Storage Management**:  
  O ESP publica as informações de desempenho (como tensão, corrente, potência e estado do sistema) em um banco de dados que integra o Zabbix e o MySQL. Esses dados são armazenados de forma estruturada para posterior análise.

- **Zabbix Web**:  
  O Zabbix Web é a interface de visualização e monitoramento. Através dele, os dados capturados pelo ESP são acessados por meio de gráficos, alertas e dashboards, permitindo o acompanhamento em tempo real do comportamento do sistema fotovoltaico.

---

## 5.3 Fluxo de Dados Resumido

- **Geração Solar**: O módulo fotovoltaico gera a energia elétrica.
- **Controle MPPT**: A energia gerada é otimizada pelo sistema Boost controlado pelo ESP.
- **Monitoramento de Dados**: O ESP lê os dados de energia e publica no sistema de armazenamento.
- **Visualização**: O Zabbix coleta os dados armazenados e apresenta ao usuário via interface web.

## Diagrama Elétrico
### ➔ Visão Geral
O circuito é um **Conversor Boost** que:
- Recebe uma tensão de entrada (provavelmente do seu **módulo fotovoltaico**),
- Amplifica a tensão usando um **MOSFET** de potência,
- Controla o chaveamento do MOSFET via um **driver IR2111**,
- Faz o envio da energia para a **carga**,
- E o controle é realizado externamente (por exemplo, via **ESP8266**), como mostrado no seu projeto geral.

---

<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/Screenshot%202025-04-28%20at%2019-16-25%20SCH_Schematic2_2025-04-28.pdf.png" alt="Rinha logo" width="60%" />
</p>

---

### 📋 Principais Componentes e Suas Funções

| Componente | Função Principal | Conexão |
|:-----------|:-----------------|:--------|
| **Q1 - IRF540** | MOSFET de potência. Responsável por ligar/desligar rapidamente para controlar o Boost. | Controlado pelo sinal "LO" do driver **U1 (IR2111)**. |
| **U1 - IR2111PBF** | Driver de MOSFET. Amplifica sinais de controle (baixo nível) para acionar o MOSFET (alto nível). | Recebe VCC, sinais de controle, e envia sinais HO/LO para o gate do MOSFET. |
| **D1 - MUR820** | Diodo de potência rápido. Permite a passagem da corrente para a carga quando o MOSFET está desligado. Protege e mantém o fluxo contínuo. | Conectado entre o indutor L2 e a saída. |
| **L2 - 150 µH** | Indutor do Boost. Armazena energia enquanto o MOSFET está ligado e libera quando desligado, elevando a tensão. | Conectado em série com a entrada e o MOSFET. |
| **C11 - 120 µF** | Capacitor de entrada. Filtra ruídos da fonte de entrada (painel solar, por exemplo). | Colocado próximo da entrada VCC. |
| **C14 - 470 µF** | Capacitor de saída. Suaviza a tensão de saída, reduzindo ripple. | Colocado próximo à carga. |
| **C15 - 1 µF** | Capacitor auxiliar de bootstrap para o driver IR2111 (alimentar o gate do MOSFET em altos níveis). | Entre os pinos VB e VS do IR2111. |
| **R2 - 81 Ω** | Resistor de Gate. Limita a corrente de acionamento do MOSFET, controlando a velocidade de chaveamento. | Entre o pino de saída do driver (LO) e o Gate do MOSFET. |
| **X1 - BORNERA 3 PINOS** | Conector de entrada/saída. Para ligar alimentação, carga, etc. | Facilita conexões externas no sistema. |

---

### 🔄 Como os Componentes Interagem (Passo a Passo)

- **Entrada de Energia (36V)**:
   - A energia vem do **módulo fotovoltaico** e entra pelo conector **X1**.
   - Passa pelo **capacitor C11** para filtrar ruídos.

- **Controle de Chaveamento**:
   - Um microcontrolador (por exemplo, **ESP8266**) envia um sinal PWM para o **driver IR2111 (U1)**.
   - O IR2111 recebe esse sinal e gera sinais amplificados para controlar o **MOSFET IRF540**.

- **Funcionamento do Conversor Boost**:
   - Quando o MOSFET está **ligado**, o **indutor L2** armazena energia.
   - Quando o MOSFET é **desligado**, o indutor libera energia para a carga através do **diodo D1**.

- **Estabilização da Saída**:
   - A energia liberada é suavizada pelo **capacitor de saída C14** antes de ser entregue à carga.

- **Proteções e Auxílios**:
   - O **capacitor C15** serve para o circuito bootstrap do IR2111.
   - O **resistor R2** limita a corrente para proteger o Gate do MOSFET.

- **Envio de Dados**:
   - O ESP também coleta informações como tensão e corrente (via sensores como o INA226) e envia os dados para o **Zabbix** para monitoramento remoto.

---

### 🛠️ Resumo Visual (Fluxo)
```
Módulo Solar → Entrada VCC → C11 → L2 → (Q1 controlado por U1) → D1 → Carga → Monitoramento
                  ↓
            Controle PWM (ESP → IR2111 → MOSFET)
                  ↓
          Coleta de Dados → Zabbix (via rede Wi-Fi)
```

## Revisão da Literatura
A otimização do ponto de máxima potência (MPPT - Maximum Power Point Tracking) em sistemas fotovoltaicos tem sido um campo de intensa pesquisa e desenvolvimento, especialmente com o advento de técnicas mais avançadas de controle e inteligência computacional. Diversos métodos têm sido explorados para melhorar a eficiência dos sistemas fotovoltaicos, abordando diferentes desafios, como as variações nas condições de irradiação e temperatura, e o impacto do sombreamento parcial nos módulos fotovoltaicos.

#### Pesquisas e Trabalhos Relevantes

Vários estudos e trabalhos têm contribuído significativamente para a melhoria dos algoritmos MPPT. Por exemplo, o trabalho de AL-MAJIDI et al. (2019) apresenta um MPPT baseado em redes neurais artificiais (ANN) utilizando dados reais de sistemas fotovoltaicos, abordando a adaptação do algoritmo às condições climáticas variáveis, o que é crucial para a operação eficiente de sistemas fotovoltaicos em diferentes locais e condições (AL-MAJIDI et al., 2019). Por outro lado, DIVYASHARON et al. (2019) exploram a utilização de uma rede neural artificial em conjunto com a topologia de conversor Cuk, oferecendo uma solução robusta para sistemas fotovoltaicos em condições climáticas variáveis, destacando a importância da integração de técnicas de controle inteligentes (DIVYASHARON et al., 2019).

A comparação entre técnicas de MPPT também tem sido um tópico importante de pesquisa. BATARSEH e ZA’TER (2018) realizaram uma análise comparativa das técnicas híbridas de MPPT, sugerindo novas classificações e combinações não exploradas anteriormente, o que ajuda a entender melhor a aplicabilidade e os limites de cada abordagem em diferentes cenários (BATARSEH & ZA’TER, 2018). Além disso, o trabalho de KANDEMIR et al. (2018) compara métodos de controle fuzzy com a técnica de condutância incremental, abordando as vantagens e limitações de cada um em termos de desempenho e complexidade (KANDEMIR et al., 2018).

#### Comparação entre a Solução Proposta e as Soluções Existentes

Em relação às soluções existentes, os algoritmos baseados em redes neurais, como o proposto por AL-MAJIDI et al. (2019), oferecem uma grande vantagem na adaptação a diferentes condições de operação, ajustando-se dinamicamente às variáveis ambientais. Comparado a métodos tradicionais como o MPPT baseado em condutância incremental, que tem um desempenho satisfatório em condições estáveis, os algoritmos baseados em redes neurais podem superar esses métodos em cenários de variação rápida e intensa da irradiação solar (GRUNER et al., 2023). No entanto, a complexidade computacional e a necessidade de treinamento prévio das redes neurais são desafios significativos.

Por outro lado, soluções baseadas em lógica difusa, como as de ALGARíN et al. (2017) e SURYOATMOJO et al. (2018), têm mostrado ser eficientes em ambientes com alto grau de incerteza, como no controle de veículos aéreos não tripulados movidos a energia solar (ALGARíN et al., 2017; SURYOATMOJO et al., 2018). A principal vantagem desses métodos é a simplicidade e a capacidade de operar em tempo real, sem a necessidade de treinamento de modelos complexos, o que os torna mais adequados para sistemas com recursos limitados, como o uso em microinversores (KNABBEN et al., 2017).

#### Tecnologias, Metodologias e Ferramentas Mais Modernas

As tecnologias mais modernas no campo do MPPT incluem o uso de inteligência artificial, como redes neurais artificiais e lógica difusa, que têm sido cada vez mais aplicadas para melhorar a precisão e a adaptabilidade dos sistemas fotovoltaicos. A integração de algoritmos de otimização, como o PSO (Particle Swarm Optimization), também tem sido explorada para maximizar a eficiência dos sistemas, permitindo ajustes dinâmicos e autônomos do ponto de máxima potência, com base em variáveis ambientais e operacionais (PACHECO, 2016).

Além disso, a utilização de plataformas de hardware como o Arduino, mencionada por ALGARíN et al. (2017), tem facilitado a implementação de soluções de baixo custo para MPPT em sistemas fotovoltaicos. Ferramentas de modelagem e simulação, como MATLAB e Simulink, também são amplamente utilizadas para testar e validar algoritmos MPPT antes de sua implementação prática, proporcionando uma abordagem eficaz para o design de sistemas fotovoltaicos (SCHMITZ et al., 2018; PEREIRA et al., 2021).

Em termos de metodologias, a utilização de técnicas híbridas, como a combinação de algoritmos genéticos com algoritmos de firefly, foi explorada por HUANG et al. (2018), demonstrando uma abordagem promissora para otimizar o rastreamento do ponto de máxima potência sob condições de sombreamento parcial (HUANG et al., 2018). A aplicação dessas metodologias avançadas permite maior robustez e flexibilidade, especialmente em cenários desafiadores, como o sombreamento dinâmico.

---

## Metodologia de Desenvolvimento
Para atingir os objetivos propostos neste trabalho, a metodologia adotada será dividida nas seguintes etapas:

### 8.1. **Revisão Bibliográfica**
Será realizada uma revisão aprofundada da literatura relacionada a sistemas fotovoltaicos, técnicas de rastreamento do ponto de máxima potência (MPPT), conversores Boost, microcontroladores (em especial o ESP8266), sensores de corrente e tensão (como o INA226), algoritmos de otimização como PSO (Particle Swarm Optimization) e ferramentas de monitoramento como o Zabbix. A revisão incluirá artigos científicos, normas técnicas, manuais de componentes e publicações relevantes.

### 8.2. **Análise de Tecnologias**
Serão estudadas as tecnologias e componentes eletrônicos necessários para a construção do protótipo. Isso incluirá a análise dos circuitos de potência (Boost converter), dispositivos de medição, protocolos de comunicação (I2C, MQTT ou HTTP) e o funcionamento da plataforma Zabbix para monitoramento de dados em tempo real.

### 8.3. **Desenvolvimento do Protótipo**
Será implementado um protótipo funcional composto por:
- Um **conversor Boost** baseado em um MOSFET IRF540, driver IR2111 e diodo MUR820;
- Um **ESP8266** programado para realizar o controle do duty cycle do conversor com base no algoritmo PSO;
- Um **sensor INA226** para leitura de corrente, tensão e potência;
- Comunicação com o **servidor Zabbix**, responsável por receber e apresentar os dados monitorados.

O protótipo será montado em bancada e testado com alimentação vinda de um módulo fotovoltaico ou fonte variável simulando diferentes condições de irradiância.

### 8.4. **Avaliação e Testes**
Serão realizados testes controlados para avaliar o comportamento do sistema em diferentes cenários, especialmente sob variações de carga e tensão de entrada. Serão analisados:
- A estabilidade da operação do conversor;
- A eficiência do algoritmo PSO na busca do ponto de máxima potência;
- A confiabilidade da transmissão dos dados para o Zabbix;
- O tempo de resposta do sistema sob condições dinâmicas.

### 8.5. **Documentação dos Resultados**
Todos os dados e observações obtidos ao longo do desenvolvimento e dos testes serão devidamente registrados. A documentação incluirá esquemas elétricos, código-fonte, parâmetros testados, resultados obtidos e uma análise crítica das limitações encontradas e possíveis melhorias futuras.

---

### Abordagem Metodológica

A metodologia adotada será **iterativa e empírica**, com ciclos contínuos de desenvolvimento, teste e refinamento. Essa abordagem permitirá ajustar o comportamento do sistema de forma progressiva, até atingir uma operação estável e eficaz sob diferentes condições.

Com essa metodologia, espera-se contribuir para o avanço de sistemas embarcados inteligentes aplicados à energia solar, demonstrando como a integração entre controle inteligente (PSO), eletrônica de potência (Boost), sensores e monitoramento remoto (Zabbix) pode melhorar significativamente o desempenho e a capacidade de supervisão de sistemas fotovoltaicos.

---
## Documentação do Código

### Ambiente de Desenvolvimento
A implementação do programa foi realizada utilizando a Arduino IDE, um ambiente de desenvolvimento que possibilita criar e transferir códigos para microcontroladores compatíveis. Neste trabalho, foi utilizada a placa ESP32, que é suportada por essa plataforma.
### Instalação

### 🔽 1. **Baixar o Arduino IDE**

* Acesse o site oficial: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
* Escolha seu sistema operacional:

  * **Windows** (EXE Installer ou ZIP)
  * **macOS**
  * **Linux** (32-bit, 64-bit ou ARM)

---

### 💻 2. **Instalação no Windows**

1. Baixe o instalador `.exe`.
2. Execute o arquivo e siga os passos do assistente.
3. Marque as opções:

   * Instalar drivers
   * Associar arquivos `.ino`
4. Clique em **Install**.
5. Após a instalação, abra o Arduino IDE.

---

### 🍏 3. **Instalação no macOS**

1. Baixe o arquivo `.zip` para macOS.
2. Extraia e arraste o ícone do **Arduino** para a pasta **Aplicativos**.
3. Pode ser necessário permitir a execução nas **Preferências do Sistema > Segurança e Privacidade**.
4. Abra o Arduino IDE.

---

### 🐧 4. **Instalação no Linux (Ubuntu/Debian)**

**Via terminal:**

```bash
sudo apt update
sudo apt install arduino
```

**Ou manualmente:**

1. Baixe o pacote `.tar.xz`.
2. Extraia o conteúdo:

   ```bash
   tar -xvf arduino-*.tar.xz
   ```
3. Acesse a pasta extraída e execute o instalador:

   ```bash
   cd arduino-*
   sudo ./install.sh
   ```
---

### 🧩 5. **Instalar suporte à placa (ex: ESP32, ESP8266)**

1. Abra o Arduino IDE.
2. Vá em **Arquivo > Preferências**.
3. No campo **URLs Adicionais para Gerenciadores de Placas**, adicione:

   * **ESP8266:** `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   * **ESP32:** `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
4. Vá em **Ferramentas > Placa > Gerenciador de Placas**.
5. Pesquise por **ESP32** ou **ESP8266** e clique em **Instalar**.

---

### ✅ 6. **Testar a Instalação**

1. Conecte a placa ao PC via USB.
2. Vá em **Ferramentas > Placa** e selecione o modelo correto.
3. Vá em **Ferramentas > Porta** e selecione a porta serial da placa.
4. Abra o exemplo **Arquivo > Exemplos > 01.Basics > Blink**.
5. Clique em **Upload** (seta para a direita).
6. Se tudo estiver certo, o LED da placa piscará.

### Modelo Matematico

<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/WhatsApp%20Image%202025-05-02%20at%2018.25.06%20(1).jpeg" alt="Rinha logo" width="30%" />
</p>
<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/WhatsApp%20Image%202025-05-02%20at%2018.25.06.jpeg" alt="Rinha logo" width="30%" />
</p>

Resistencia de gate drive
<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/WhatsApp%20Image%202025-05-02%20at%2018.25.05.jpeg" alt="Rinha logo" width="30%" />
</p>




### INA226
O codigo e mais informação sobre o INA226 estara neste link: <linkhttps://github.com/miguelsrrobo/Obiquos/tree/main/INA226>

### Programa Final
```
#include <Wire.h>
#include <INA226_WE.h>   
#define I2C_ADDRESS 0x40
 
INA226_WE ina226 = INA226_WE(I2C_ADDRESS);
 

  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0;

// Biblioteca// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

// Inputs
float tensao = 0; // Tensão obtida do painel solar
float corrente = 0; // Corrente obtida do painel solar
//float random = 0;

// Outputs
float pwm = 0; // Output Principal
float D = 0.5;// Resultado do algoritimo P&O
int Contador = 0;
float Speed = 0;
int p_atual = 0; // particula atual sendo considerada na simulação

// Definições
#define ExecTime 0.0000001 // Tempo de execução, 1*10^-7 s
#define MAXwave 1 // Valor maximo que a onda triangular vai obter
#define MINwave 0 // Valor minimo que a onda triangular vai obter
#define NUM_INTERACAO 10 // Valor que representa o numero de interações
#define NUM_PARTICULAS 20 // Numero de particulas
#define INERTIA_WEIGHT 0.5 // Peso da inércia
#define MAXD 0.95 // Valor maximo que o D poderá obter
#define MIND 0.05 // Valor minimo que o D poderá obter
#define Ciclo 12500 // Ciclos de analise para cada particula
#define PWM_PIN 5  // ou outro pino seguro: 4, 5, 12, 13, 14

// Particula //
struct Particula{
	float posicao; // posição da particula
	float velocidade; // velocida da particula
	float best_posicao; // melhor posição da particula
	float best_potencia; // melhor potencia da particula
	float potencia; // potencia da particula
};

struct Particula particula[NUM_PARTICULAS];

// PSO
float potencia = 0; // Tensão x Corrente
float C1 = 0.6; // Peso cognitivo
float C2 = 0.95; // Peso cognitivo

int inic = 0;
float gbestPSO = 0;
float gbestPST = 0;

// TriangularWave
float frequencia = 31250; // Frequência desejada para a onda triangular
float periodo = 0; // 1 / Frequência
float valorWave = 0; // Valor atual da onda triangular
float delta = 0; // Valor a se somar ou subtrair a cada periodo de execução 1 / passos por periodo da onda, versão estatica
float somador = 0; // Valor que usa o delta porém é alterado a cada ciclo da onda
float passos = 0.1; // Valor de passos que irá dar por periodo, Periodo / tempo de execução
int espera = 1; // Variavel que guarda a informação para liberar a inversão do valor delta
int AcumulodeCiclos = 0; // Acumulo de ciclos do sistemas, 
int AcumulodeCiclos2 = 0; // Acumulo de ciclos do sistemas2, 

/////////////////////////////////
// Função da onda triangular ///
///////////////////////////////
void TriangularWave()
{   
   if(valorWave >= MAXwave && espera == 1)
   {
   	espera = 0;
   	valorWave = MAXwave;
   	somador = -delta;
   }
   else if(valorWave <= MINwave && espera == 0)
   {
   	espera = 1;
   	valorWave = MINwave;
   	somador = delta;
   }
   
 	valorWave += somador;
}

///////////////////////////////
// Inicializar a Particulas //
/////////////////////////////
void InicializarParticulas()
{
	inic++;
	float multi = ((MAXD - MIND) / NUM_PARTICULAS);
	
	for (int i = 0; i < NUM_PARTICULAS; i++) {
		particula[i].posicao = MIND + (i * multi);
		particula[i].velocidade = 0.00001;
		particula[i].best_posicao = particula[i].posicao;
		particula[i].best_potencia = particula[i].potencia;
	}
}

void reset() {
	if (AcumulodeCiclos2 == 10000000) 
	{
		gbestPSO = 0;
		gbestPST = 0;			
	float multi = ((MAXD - MIND) / NUM_PARTICULAS);
	for (int i = 0; i < NUM_PARTICULAS; i++) 
	{
		particula[i].posicao = MIND + (i * multi);
		particula[i].velocidade = 0.00001;
		particula[i].best_posicao = 0;
		particula[i].best_potencia = 0;
		particula[i].potencia = 0;}
		AcumulodeCiclos2=0;
		p_atual = 0;
		D = 0.5;// Resultado do algoritimo P&O
	} 
}


/////////////////////////////////
// Função Atualizar Paticulas //
///////////////////////////////
void AtualizarPaticulas()
{

	AcumulodeCiclos++;
	AcumulodeCiclos2++;
	reset();
	
	if(AcumulodeCiclos >= Ciclo)
	{
			
		particula[p_atual].potencia = particula[p_atual].potencia / Ciclo; // potencia da particula atua recebe a potencia tual dividida pelo ciclos de analise para cada particula, serve para ajuste fino
		
		AcumulodeCiclos = 0;// zera os ciclo do sistema
		
		// Calculo do PSO //
		if(particula[p_atual].potencia > particula[p_atual].best_potencia) // se a potencia da particula atual for maior ou igual a melhor posição da particula atual faça
		{
			yield();  // Libera o watchdog
			particula[p_atual].best_posicao = particula[p_atual].posicao; // a melhor posção recebe a posição
			particula[p_atual].best_potencia = particula[p_atual].potencia; // a melhor potencia recebe a melhor potencia
		}
		if(particula[p_atual].best_potencia > gbestPST) // se a melhor potencia da da particula for maior que melhor potencia global faça
		{
			gbestPSO = particula[p_atual].best_posicao; // guarda a melhor posição da particula numa vairiavel global
			gbestPST = particula[p_atual].best_potencia; // guarda a melhor potencia da particula numa vairiavel global
		}
				
		//	Calculo da velocidade da particula
		particula[p_atual].velocidade = INERTIA_WEIGHT * particula[p_atual].velocidade + C1 * (particula[p_atual].best_posicao - particula[p_atual].posicao) + C2 * 1 * (gbestPSO - particula[p_atual].posicao);
		
		//	Calculo da posição da particula
		particula[p_atual].posicao = particula[p_atual].posicao + particula[p_atual].velocidade;
		// Calculo do PSO //

		//	Incremento das particulas
		p_atual++;
		if(p_atual >= NUM_PARTICULAS)
		{
			p_atual = 0;
		}
	}	
	else
	{
		particula[p_atual].potencia += power_mW;
	}
	yield();  // <- Adicional
	Contador++;
}

/////////////////////
// Função do PSO ///
///////////////////
void PSO()
{
	if(inic == 0)
	{
		InicializarParticulas();	
	}
	else
	{
		 AtualizarPaticulas();
	}
	
	D = particula[p_atual].posicao;

	if(D > MAXD)
	{
		D = MAXD;
	}
	else if(D < MIND)
	{
		D = MIND;
	}
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial); // wait until serial comes up on Arduino Leonardo or MKR WiFi 1010
  Wire.begin();
  ina226.init();
	pinMode(PWM_PIN, OUTPUT);

  ina226.setResistorRange(0.1, 1.3); // choose resistor 0.1 Ohm and gain range up to 1.3A
 
  /* If the current values delivered by the INA226 differ by a constant factor
     from values obtained with calibrated equipment you can define a correction factor.
     Correction factor = current delivered from calibrated equipment / current delivered by INA226*/
 
  ina226.setCorrectionFactor(0.93);
 
  Serial.println("INA226 Current Sensor Example Sketch - Continuous");
 
  ina226.waitUntilConversionCompleted(); //if you comment this line the first data might be zero
}
 
void loop()
{
	yield();  // Aqui logo no início

  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0;
 
  ina226.readAndClearFlags();
  shuntVoltage_mV = ina226.getShuntVoltage_mV();
  busVoltage_V = ina226.getBusVoltage_V();
  current_mA = ina226.getCurrent_mA();
  power_mW = ina226.getBusPower();
  loadVoltage_V  = busVoltage_V + (shuntVoltage_mV / 1000);
 
  Serial.print("Shunt Voltage [mV]: "); Serial.println(shuntVoltage_mV);
  Serial.print("Bus Voltage [V]: "); Serial.println(busVoltage_V);
  Serial.print("Load Voltage [V]: "); Serial.println(loadVoltage_V);
  Serial.print("Current[mA]: "); Serial.println(current_mA);
  Serial.print("Bus Power [mW]: "); Serial.println(power_mW);
  if (!ina226.overflow)
  {
    Serial.println("Values OK - no overflow");
  }
  else
  {
    Serial.println("Overflow! Choose higher current range");
  }
  Serial.println();

  TriangularWave();  
	PSO();
	// comparação para output
  if(D >= valorWave)
	{
		pwm = MAXwave; 
	} 
	else 
	{ 	
		pwm = MINwave;	
	}

	digitalWrite(PWM_PIN, (pwm == MAXwave) ? HIGH : LOW);
	yield();  // E também aqui, ao final do loop


}
```

O codigo estara neste link: <https://github.com/miguelsrrobo/Obiquos/blob/main/BOOST/mqtt/mqtt.ino>


## Configuração do Zabbix
O Zabbix é uma plataforma de monitoramento de redes, servidores, aplicações e dispositivos IoT. Ele é gratuito e de código aberto, muito usado em ambientes corporativos para garantir que tudo esteja funcionando corretamente e para alertar quando algo dá errado.

## 1. Pré-requisitos

Escolha a sua plataforma de trabalho:

| Banco de Dados | Servidor Web |
|--------------|--------------|
| MySQL       | Apache       |
| PostgreSQL  | Nginx        |

Instale os pacotes necessários conforme sua escolha:

| Ferramenta  | Comando de Instalação |
|------------|-----------------------|
| MySQL      | `apt install mysql-server` |
| PostgreSQL | `apt install postgresql postgresql-contrib` |
| Apache     | `apt install apache2` |
| Nginx      | `apt install nginx` |

Certifique-se de instalar os pacotes antes de iniciar a instalação do Zabbix.

---

## 2. Instalação e Configuração do Zabbix

### 2.1. Instalação do Zabbix com MySQL e Apache

#### a) Acessar como Root

```sh
sudo -s
```

#### b) Adicionar o Repositório do Zabbix

```sh
wget https://repo.zabbix.com/zabbix/7.2/release/ubuntu/pool/main/z/zabbix-release/zabbix-release_latest_7.2+ubuntu24.04_all.deb

dpkg -i zabbix-release_latest_7.2+ubuntu24.04_all.deb

apt update
```

#### c) Instalar Pacotes do Zabbix

```sh
apt install zabbix-server-mysql zabbix-frontend-php zabbix-apache-conf zabbix-sql-scripts zabbix-agent
```

#### d) Configurar o Banco de Dados MySQL
Obs.: ao configurar o banco de dados, seja MySQL ou PostgreSQL, em alguns computadores pode demorar muito (alguns até 1h!) então se você achar que seu terminal travou, NÃO FAÇA NADA, se cancelar essa parte poderá dar problemas ao tentar de novo.

```sh
mysql -uroot -p
```
Digite a senha do root do MySQL e execute:

```sql
mysql> create database zabbix character set utf8mb4 collate utf8mb4_bin;
mysql> create user zabbix@localhost identified by 'password';
mysql> grant all privileges on zabbix.* to zabbix@localhost;
mysql> set global log_bin_trust_function_creators = 1;
mysql> quit; 
```

Importar esquema inicial:

```sh
zcat /usr/share/zabbix/sql-scripts/mysql/server.sql.gz | mysql --default-character-set=utf8mb4 -uzabbix -p zabbix
```

Desabilitar `log_bin_trust_function_creators`:

```sh
mysql -uroot -p
SET GLOBAL log_bin_trust_function_creators = 0;
QUIT;
```

#### e) Configurar o Zabbix Server

Edite o arquivo:

```sh
nano /etc/zabbix/zabbix_server.conf
```

Ajuste a linha:

```sh
DBPassword=senha_segura
```

#### f) Reiniciar e Habilitar os Serviços

```sh
systemctl restart zabbix-server zabbix-agent apache2
systemctl enable zabbix-server zabbix-agent apache2
```

#### g) Acessar a Interface Web

```
http://host/zabbix
```

Outras instalação siga o link: <https://github.com/miguelsrrobo/Obiquos/tree/main/Zabbix>

---
## Resultados Esperados
O principal resultado esperado ao final deste projeto é a implementação bem-sucedida de um sistema de controle e monitoramento para um **Conversor Boost aplicado a sistemas fotovoltaicos**, utilizando um **microcontrolador ESP8266** em conjunto com um sensor INA226 e integração com a plataforma **Zabbix**. O objetivo é garantir a otimização da extração de energia em tempo real, com monitoramento remoto dos parâmetros elétricos do sistema. Espera-se alcançar os seguintes resultados:

- **Controle Eficiente do Ponto de Máxima Potência (MPPT)**:  
   Através da implementação de um algoritmo de otimização (como o PSO), espera-se que o sistema seja capaz de ajustar dinamicamente o duty cycle do conversor Boost, extraindo a máxima potência possível do módulo fotovoltaico mesmo em condições ambientais variáveis.

- **Monitoramento Remoto via Zabbix**:  
   O ESP8266 será responsável por coletar dados de tensão, corrente e potência do sistema e transmiti-los em tempo real para a plataforma Zabbix. Isso permitirá o acompanhamento contínuo do desempenho do sistema e a geração de alertas em caso de falhas ou desvios operacionais.

- **Aquisição e Armazenamento de Dados**:  
   Os dados enviados ao Zabbix poderão ser armazenados em um banco de dados (como o MySQL) para posterior análise, possibilitando estudos sobre comportamento energético, eficiência do sistema e condições de operação ao longo do tempo.

- **Eficiência Energética e Autonomia**:  
   Com o controle inteligente do conversor e a análise em tempo real, espera-se aumentar a eficiência energética do sistema como um todo, reduzindo perdas e otimizando o uso da energia gerada. Isso pode contribuir para maior autonomia em aplicações embarcadas ou off-grid.

- **Escalabilidade para Monitoramento de Múltiplos Dispositivos**:  
   O uso do Zabbix permitirá que o sistema seja escalado futuramente, integrando diversos conversores em diferentes pontos, com centralização dos dados em um único painel de controle.

---
## Conclusão
Este trabalho propôs a aplicação da técnica de Otimização por Enxame de Partículas (PSO) para o rastreamento do ponto de máxima potência (MPPT) em sistemas fotovoltaicos, visando a otimização da eficiência energética, especialmente em condições de sombreamento parcial. A implementação da técnica no controle do conversor Boost, integrado com o microcontrolador ESP8266 e o sensor INA226, demonstrou a viabilidade de melhorar a eficiência de geração solar através de um controle dinâmico e inteligente. O envio dos dados para a plataforma Zabbix garantiu o monitoramento remoto e a análise em tempo real dos parâmetros do sistema, proporcionando uma solução robusta e eficiente para o gerenciamento de sistemas fotovoltaicos.

A importância desse projeto reside não apenas na melhoria da eficiência de sistemas fotovoltaicos, mas também na contribuição para a aplicação de técnicas avançadas de inteligência artificial em soluções práticas de energia renovável. Espera-se que, com a continuação do desenvolvimento e a realização de mais testes, este sistema possa ser escalado para ambientes com múltiplos módulos solares.

A escalabilidade do sistema é uma das principais expectativas futuras. Com o uso de múltiplos conversores Boost e a integração com diferentes plataformas de monitoramento, o sistema pode ser adaptado para operar em larga escala, com monitoramento de vários sistemas simultaneamente. Além disso, melhorias podem ser feitas no algoritmo PSO, incorporando técnicas de aprendizado de máquina para ajustes mais precisos e rápidos em tempo real. Podendo expandir ainda mais a eficiência e flexibilidade da solução, especialmente quando se utiliza um FPGA como controlador central. O FPGA oferece a vantagem de processamento paralelo e alta velocidade, permitindo um controle mais preciso e rápido das variáveis do sistema fotovoltaico. A implementação do sistema em diferentes tipos de instalações fotovoltaicas exigirá uma revisão detalhada do layout da placa, visando otimizar o espaço, minimizar interferências e garantir um desempenho eficiente mesmo em ambientes de alta carga térmica.Para que o conversor boost opere de maneira eficiente, seria necessário melhorar a robustez da placa e integrar sistemas de proteção que garantam o funcionamento seguro e estável, especialmente em condições adversas de carga e temperatura.

## Referências
AL-MAJIDI, S. D.; ABBOD, M. F.; AL-RAWESHIDY, H. S. Design of an ann-based smart
mppt using real data from photovoltaic systems. In: 2019 54th International Universities
Power Engineering Conference (UPEC). [S.l.: s.n.], 2019. p. 1–6. Citado na página [4].

ALGARíN, C. R.; FUENTES, R. L.; CASTRO, A. O. Implementation of a cost-effective
fuzzy MPPT controller on the Arduino board. International Journal on Smart Sensing
and Intelligent Systems, v. 11, n. 1, p. 1–10, dez. 2017. Disponível em: <https://sciendo.
com/article/10.21307/ijssis-2018-002>. Citado na página [9].

BATARSEH, M. G.; ZA’TER, M. E. Hybrid maximum power point tracking techniques:
A comparative survey, suggested classification and uninvestigated combinations. Solar
Energy, v. 169, p. 535–555, jul. 2018. ISSN 0038-092X. Disponível em: <https://www.
sciencedirect.com/science/article/pii/S0038092X18304043>. Citado na página [14].

BOUAKKAZ, M. S. et al. Design of ann-based mppt algorithm using real operational
weather condition. In: 2020 2ª Conferência Internacional de Matemática e Tecnologia da
Informação (ICMIT). [S.l.: s.n.], 2020. p. 159–163. Citado na página [11].
COELHO, R. F.; SCHMITZ, L.; MARTINS, D. C. Energia Solar Fotovoltaica: Geração,
Conversão e Aplicações. [S.l.]: Roberto Francisco Coelho, Lenon Schmitz, 2022. Citado (5)
vezes nas páginas [4, 5, 7, 8 e 18].

DIVYASHARON, R.; BANU, R. N.; DEVARAJ, D. Mppt baseado em rede neural artificial
com topologia de conversor cuk para sistemas fotovoltaicos sob condições climáticas
variáveis. In: 2019 IEEE International Conference on Intelligent Techniques in Control,
Optimization and Signal Processing (INCOS). [S.l.: s.n.], 2019. p. 1–6. Citado (2) vezes
nas páginas [4 e 10].

GRUNER, V. F. et al. Modified current sensorless incremental conductance algorithm
for photovoltaic systems. Energies, v. 16, n. 2, 2023. ISSN 1996-1073. Disponível em:
<https://www.mdpi.com/1996-1073/16/2/790>. Citado na página [3].

HEGAZY, E.; SHOKAIR, M.; SAAD, W. Recursive bit assignment with neural re-
ference adaptive step (rna) mppt algorithm for photovoltaic system. Scientific Re-
ports, v. 13, p. 4189, 2023. ISSN 2045-2322. Disponível em: <https://doi.org/10.1038/
s41598-023-28982-6>. Citado na página [3].

HUANG, Y.-P.; CHEN, X.; YE, C.-E. A Hybrid Maximum Power Point Tracking Approach
for Photovoltaic Systems under Partial Shading Conditions Using a Modified Genetic
Algorithm and the Firefly Algorithm. International Journal of Photoenergy, v. 2018,
p. 7598653, maio 2018. ISSN 1110-662X. Publisher: Hindawi. Disponível em: <https:
//doi.org/10.1155/2018/7598653>. Citado na página [11].

JIN, Y. et al. A Glowworm Swarm Optimization-Based Maximum Power Point Tracking
for Photovoltaic/Thermal Systems under Non-Uniform Solar Irradiation and Temperature
Distribution. Energies, v. 10, n. 4, p. 541, abr. 2017. ISSN 1996-1073. Number: 4 Publisher:
Multidisciplinary Digital Publishing Institute. Disponível em: <https://www.mdpi.com/
1996-1073/10/4/541>. Citado (2) vezes nas páginas [3 e 13].
https://github.com/miguelsrrobo/Obiquos/tree/main/INA226

KANDEMIR, E.; BOREKCI, S.; CETIN, N. S. Comparative Analysis of Reduced-Rule
Compressed Fuzzy Logic Control and Incremental Conductance MPPT Methods. Journal
of Electronic Materials, v. 47, n. 8, p. 4463–4474, ago. 2018. ISSN 1543-186X. Disponível
em: <https://doi.org/10.1007/s11664-018-6273-y>. Citado na página [4].

KARSOLIYA, S. Approximating Number of Hidden layer neurons in Multiple Hidden
Layer BPNN Architecture. International Journal of Engineering Trends and Technology,
2012. Citado na página [11].

KNABBEN, G. C. et al. Transformerless micro-inverter for grid-connected photovoltaic
systems. In: 2017 52nd International Universities Power Engineering Conference (UPEC).
[S.l.: s.n.], 2017. p. 1–6. Citado na página [7].

MAAROUF; MUSTAPHA. Doctorate Program: Intelligent Systems and Numerical Ap-
plications in Engineering. 2016. Disponível em: <http://hdl.handle.net/10553/18929>.
Citado na página [10].

PACHECO, A. Otimização por enxame de partículas - PSO. 2016. Analogia de um bando
de pássaros em um espaço de busca de 3D. Considerando um problema de maximiza-
ção, o pássaro azul é a partícula de solução ótima do problema. Disponível em: <http:
//computacaointeligente.com.br/algoritmos/otimizacao-por-enxame-de-particulas/>. Ci-
tado na página [13].

PEREIRA, T. A. et al. Design of a portable photovoltaic i–v curve tracer based on the
dc–dc converter method. IEEE Journal of Photovoltaics, v. 11, n. 2, p. 552–560, 2021.
Citado na página [5].

SCHMITZ, L. et al. Conversor cc-cc de alto ganho voltado para aplicações fotovoltaicas
com módulos de filme fino. Eletrônica de Potência, v. 23, n. 3, p. 339–348, 2018. Citado
na página [7].

SEYEDMAHMOUDIAN, M. et al. State of the art artificial intelligence-based mppt
techniques for mitigating partial shading effects on pv systems – a review. Renewable
and Sustainable Energy Reviews, v. 64, p. 435–455, 2016. ISSN 1364-0321. Disponível em:
<https://www.sciencedirect.com/science/article/pii/S1364032116302842>. Citado na
página [8].

SOLAR, E. de Engenharia do C. Entendendo o efeito do sombreamento parcial nos
sistemas fotovoltaicos. canalsolar, 2020. Disponível em: <https://canalsolar.com.br/
efeito-do-sombras-sombreamento-parcial-sistemas-fv/>. Citado na página [6].

SURYOATMOJO, H. et al. Projeto de lógica difusa baseada em mppt para aplicação de
veículos aéreos não tripulados movidos a energia solar. In: 2018 Conferência Internacional
de Engenharia, Ciências Aplicadas e Tecnologia (ICEAST). [S.l.: s.n.], 2018. Citado na
página [9].

VILLEGAS-MIER, C. G. et al. Artificial neural networks in mppt algorithms for optimi-
zation of photovoltaic power systems: A review. Micromachines, v. 12, n. 10, 2021. ISSN
2072-666X. Disponível em: <https://www.mdpi.com/2072-666X/12/10/1260>. Citado
(3) vezes nas páginas [3, 10 e 12].

YANG, X.-S.; DEB, S. Cuckoo search via voos lévy. In: 2009 Congresso Mundial da
Natureza & Computação Biologicamente Inspirada (NaBIC). [S.l.: s.n.], 2009. p. 210–214.
Citado na página [13].

YAP, K. Y.; SARIMUTHU, C. R.; LIM, J. M.-Y. Artificial intelligence-based mppt
techniques for solar power system: A review. Jornal de Sistemas Modernos de Energia e
Energia Limpa, v. 8, n. 6, p. 1043–1059, 2020. Citado (10) vezes nas páginas [3, 4, 6, 8, 9,
10, 11, 12, 13 e 14].

ZADEH, L. Fuzzy sets. Information and Control, v. 8, n. 3, p. 338–353, 1965.
ISSN 0019-9958. Disponível em: <https://www.sciencedirect.com/science/article/pii/
S001999586590241X>. Citado na página [7].

ZADOR, A. M. A critique of pure learning and what artificial neural networks can learn
from animal brains. Nature Communications, v. 10, n. 1, p. 3770, ago. 2019. ISSN 2041-1723.
Number: 1 Publisher: Nature Publishing Group. Disponível em: <https://www.nature.
com/articles/s41467-019-11786-6>. Citado (2) vezes nas páginas [10 e 14].
