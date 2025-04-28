<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/logo_ufsc1.png" alt="Rinha logo" width="30%" />
</p>


<p align = "center">
UNIVERSIDADE FEDERAL DE SANTA CATARINA
CENTRO DE CIÊNCIAS, TECNOLOGIA E SAÚDE - CAMPUS ARARANGUÁ
CURSO DE GRADUAÇÃO EM ENGENHARIA DE COMPUTAÇÃO
</p>

<p align = "center">
Miguel Garcia Silvestre
</p>

<p align = "center">
Estudo de Algoritmos de MPPT para Sistemas Solares Fotovoltaicos
baseados em Inteligência Artificial
</p>

---

## 1 Introdução
Este trabalho busca otimizar a eficiência energética, especialmente a potência em sistemas solares fotovoltaicos, usando técnicas de inteligência artificial (IA) para o rastreamento do ponto de máxima potência (MPPT) em condições de sombreamento parcial. Diante dos desafios causados pelos múltiplos picos locais na curva P-V, o estudo analisou referências e realizou simulações no software PLECS com o método de Otimização por Enxame de Partículas (PSO). Os resultados demonstraram que métodos de IA melhoram a identificação do ponto de máxima potência global (GMPP) sob sombreamento, aumentando a eficiência da geração fotovoltaica.

## 2 Motivação
Nas últimas décadas, fontes de energia renováveis vêm ganhando destaque devido ao aumento do consumo global de energia elétrica, associado principalmente ao crescimento populacional. O uso excessivo de combustíveis fósseis tem intensificado a poluição e o aquecimento global, impulsionando o interesse em alternativas renováveis, como a energia solar fotovoltaica (PV), favorecida por políticas públicas e redução de custos. Embora a geração PV seja confiável e sustentável, enfrenta desafios como o alto custo inicial, baixa eficiência sob certas condições e sua intermitência. Para melhorar a produção, pesquisadores têm investido no desenvolvimento de células mais eficientes e em dispositivos de rastreamento do ponto de máxima potência (MPPT) (HEGAZY; SHOKAIR; SAAD, 2023; JIN et al., 2017).

Os MPPTs, compostos por conversores CC-CC e sistemas de controle embarcados, utilizam algoritmos como Perturba e Observa (P&O), Condutância Incremental (INC) e Tensão Constante (CV) (VILLEGAS-MIER et al., 2021; GRUNER et al., 2023). Contudo, esses métodos tradicionais têm dificuldades em condições de sombreamento parcial (PSC), onde múltiplos pontos de máximo locais (LMPPs) surgem, dificultando a identificação do ponto de máxima potência global (GMPP) (YAP; SARIMUTHU; LIM, 2020).

Para superar essas limitações, técnicas de inteligência artificial (AI) como Enxame de Partículas (PSO), têm sido aplicados, proporcionando maior precisão e eficiência (YAP; SARIMUTHU; LIM, 2020). Diante disso, este trabalho propõe a aplicação do metodo (PSO) ao MPPT sob sombreamento parcial, com a implementação desta técnica, proponse um almento da eficiencia energetica

## 3 Descrição da Proposta
Serão desenvolvidos dois hardwares: um conversor CC-CC (Conversor Boost) e um controlador baseado no ESP8266 com sensor INA226. Esses dispositivos serão responsáveis por analisar e controlar o passo de cálculo no conversor CC-CC. Os resultados obtidos, influenciados pela aplicação do método PSO, afetarão o ajuste do passo de cálculo e serão enviados para a plataforma Zabbix.

## 4. Requisitos

## 4.1 REQUISITOS FUNCIONAIS
Os requisitos funcionais definem as principais funcionalidades que o protótipo do sistema deverá oferecer para garantir a integração eficaz entre o conversor Boost, o controlador baseado em ESP8266 e a plataforma de monitoramento Zabbix. As principais funcionalidades são:

- **Controle dinâmico do conversor Boost:** O protótipo deverá permitir o ajuste automático do duty cycle do conversor CC-CC (Boost), com base nas leituras de corrente, tensão e potência fornecidas pelo sensor INA226, em tempo real.

- **Aplicação do algoritmo PSO:** O sistema deverá implementar o método de Otimização por Enxame de Partículas (PSO) para ajustar o passo de cálculo e maximizar a eficiência energética do conversor.

- **Envio de dados para o Zabbix:** O controlador ESP8266 deverá enviar continuamente os dados de operação (tensão, corrente, potência e duty cycle) para a plataforma Zabbix, em formato adequado (como JSON via MQTT ou HTTP).

- **Monitoramento remoto:** O sistema deverá possibilitar o monitoramento remoto dos parâmetros do conversor Boost através de dashboards configurados no Zabbix, permitindo a análise e registro de desempenho.

- **Ajuste automático baseado em monitoramento:** Com base nos dados monitorados pelo Zabbix, o sistema deverá permitir ajustes automáticos de parâmetros de operação, caso sejam detectados desvios de desempenho ou falhas.

## 4.2 REQUISITOS NÃO FUNCIONAIS

- **Desempenho:** O protótipo deverá garantir tempos de resposta baixos para leitura dos sensores, aplicação do algoritmo PSO e envio dos dados ao Zabbix, assegurando uma operação em tempo real.

- **Escalabilidade:** O sistema deverá ser capaz de integrar múltiplos conversores Boost monitorados simultaneamente, com cada um enviando dados a uma única instância do Zabbix, conforme a necessidade de expansão.

- **Confiabilidade:** A solução deverá assegurar alta disponibilidade dos dados enviados ao Zabbix, com estratégias de reconexão automática do ESP8266 em caso de falhas de rede.

- **Manutenibilidade:** O código do controlador deverá ser modular, facilitando atualizações futuras no algoritmo de controle, integração com novos sensores ou mudanças na estrutura de comunicação com o Zabbix.

- **Portabilidade:** O sistema deverá ser capaz de ser facilmente adaptado para operar com outros microcontroladores similares ao ESP8266 ou para comunicação com diferentes servidores de monitoramento, além do Zabbix.

- **Eficiência no uso de recursos:** O firmware do ESP8266 deverá otimizar o uso de memória e processamento, assegurando um consumo energético reduzido, ideal para aplicações em ambientes com restrições de energia.

## 5. Diagrama de Comunicação

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

### 1. Módulo Fotovoltaico
O sistema inicia no **Módulo Fotovoltaico**, que é responsável pela geração de energia elétrica a partir da radiação solar. A saída de energia gerada é enviada diretamente para o sistema MPPT.

### 2. Sistema MPPT (Boost + ESP)

- **Conversor CC-CC (Boost)**:  
  O conversor Boost atua para ajustar dinamicamente a tensão e a corrente vindas do módulo fotovoltaico, buscando o ponto de máxima potência (MPPT). Ele é controlado de forma inteligente pelo microcontrolador.

- **ESP8266**:  
  O ESP é o microcontrolador responsável por:
  - Ler as informações de tensão, corrente e potência (por meio do sensor INA226, embutido no sistema);
  - Aplicar o algoritmo de controle MPPT;
  - Controlar o duty cycle do conversor Boost para otimizar a extração de energia;
  - Comunicar os dados de monitoramento para o serviço de dados externo.

### 3. Data Services (Zabbix + Banco de Dados)

- **Storage Management**:  
  O ESP publica as informações de desempenho (como tensão, corrente, potência e estado do sistema) em um banco de dados que integra o Zabbix e o MySQL. Esses dados são armazenados de forma estruturada para posterior análise.

- **Zabbix Web**:  
  O Zabbix Web é a interface de visualização e monitoramento. Através dele, os dados capturados pelo ESP são acessados por meio de gráficos, alertas e dashboards, permitindo o acompanhamento em tempo real do comportamento do sistema fotovoltaico.

---

## 5.3 Fluxo de Dados Resumido

1. **Geração Solar**: O módulo fotovoltaico gera a energia elétrica.
2. **Controle MPPT**: A energia gerada é otimizada pelo sistema Boost controlado pelo ESP.
3. **Monitoramento de Dados**: O ESP lê os dados de energia e publica no sistema de armazenamento.
4. **Visualização**: O Zabbix coleta os dados armazenados e apresenta ao usuário via interface web.

## 6. Diagrama Elétrico (se houver)

### ➔ Visão Geral
O circuito é um **Conversor Boost** que:
- Recebe uma tensão de entrada (provavelmente do seu **módulo fotovoltaico**),
- Amplifica a tensão usando um **MOSFET** de potência,
- Controla o chaveamento do MOSFET via um **driver IR2111**,
- Faz o envio da energia para a **carga**,
- E o controle é realizado externamente (por exemplo, via **ESP8266**), como mostrado no seu projeto geral.

---

<p align = "center">
  <img src="https://github.com/miguelsrrobo/Obiquos/blob/main/Imagens/diagrama.png" alt="Rinha logo" width="30%" />
</p>

---

# 📋 Principais Componentes e Suas Funções

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

# 🔄 Como os Componentes Interagem (Passo a Passo)

1. **Entrada de Energia (36V)**:
   - A energia vem do **módulo fotovoltaico** e entra pelo conector **X1**.
   - Passa pelo **capacitor C11** para filtrar ruídos.

2. **Controle de Chaveamento**:
   - Um microcontrolador (por exemplo, **ESP8266**) envia um sinal PWM para o **driver IR2111 (U1)**.
   - O IR2111 recebe esse sinal e gera sinais amplificados para controlar o **MOSFET IRF540**.

3. **Funcionamento do Conversor Boost**:
   - Quando o MOSFET está **ligado**, o **indutor L2** armazena energia.
   - Quando o MOSFET é **desligado**, o indutor libera energia para a carga através do **diodo D1**.

4. **Estabilização da Saída**:
   - A energia liberada é suavizada pelo **capacitor de saída C14** antes de ser entregue à carga.

5. **Proteções e Auxílios**:
   - O **capacitor C15** serve para o circuito bootstrap do IR2111.
   - O **resistor R2** limita a corrente para proteger o Gate do MOSFET.

6. **Envio de Dados**:
   - O ESP também coleta informações como tensão e corrente (via sensores como o INA226) e envia os dados para o **Zabbix** para monitoramento remoto.

---

# 🛠️ Resumo Visual (Fluxo)
```
Módulo Solar → Entrada VCC → C11 → L2 → (Q1 controlado por U1) → D1 → Carga → Monitoramento
                  ↓
            Controle PWM (ESP → IR2111 → MOSFET)
                  ↓
          Coleta de Dados → Zabbix (via rede Wi-Fi)
```

## 7. Revisão da Literatura
- Pesquisas e trabalhos relevantes já realizados sobre o tema.
- Comparação entre a solução proposta e as soluções existentes.
- Tecnologias, metodologias e ferramentas mais modernas utilizadas na área.
## 8. Metodologia de Desenvolvimento
- Detalhamento das etapas de desenvolvimento.
- Ferramentas e tecnologias que serão utilizadas para implementação e testes.
## 9. Resultados Esperados
- Descrição dos principais resultados esperados ao final do projeto.
- Impacto no monitoramento, automação ou coleta de dados, caso seja relevante.
- Possíveis melhorias ou benefícios proporcionados pela solução.
## 10. Conclusão
- Resumo da proposta e considerações sobre a importância do projeto.
- Expectativas futuras em relação à escalabilidade, melhorias ou aplicações futuras do projeto.
## 11. Referências
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
