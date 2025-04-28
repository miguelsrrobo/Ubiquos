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
Este trabalho busca otimizar a eficácia energetica especialemente a potencia em sistemas solare fotovoltaicos (PV), atraves de técnicas de inteligência artificial (AI) aplicadas ao rastreamento do ponto de máxima potência (MPPT), com foco específico em condições de sombreamento parcial. O sombreamento parcial representa um desafio significativo, pois gera múltiplos picos locais na curva característica P-V, dificultando a identificação do ponto de máxima potência global (GMPP) por métodos tradicionais. Para isso, foram consultadas referências bibliográficas e artigos de revisão, nos quais os autores destacam que a geração de energia fotovoltaica enfrenta desafios significativos, com a sua natureza intermitente e o baixo desempenho em determinadas situações de sombreamento. No que diz respeito aos métodos de AI aplicados a MPPTs, buscamos tecer considerações sobre as melhores abordagens para resolver o problema do sombreamento parcial, que impacta negativamente a geração de energia. A questão central da nossa investigação é: como os métodos de inteligência artificial lidam com o sombreamento parcial? Para responder a essa indagação, realizamos testes simulando condições adversas, utilizando o software PLECS. Foram realizadas simulações com um método de MPPT baseado em Otimização por Enxame de Partículas (PSO) em diferentes cenários de teste. Os resultados obtidos nas simulações permitiram uma compreensão mais aprofundada da eficiência dos métodos de Inteligência Artificial em relação ao problema do sombreamento parcial. Sendo assim, a presença dos métodos de Inteligência Artificial tem impacto positivo na captura do GMPP.

## 2 Motivação
as últimas décadas, as fontes de energia renováveis vêm recebendo muita atenção
devido ao crescimento do consumo de energia elétrica mundial, o qual está relacionado,
especialmente, ao crescimento populacional. O uso exacerbado de geração de energia por
meio de combustíveis fósseis tem resultado em um aumento da poluição atmosférica e da
temperatura média global. Dessa forma, o interesse em energias renováveis está progredindo
rapidamente para enfrentar esse desafio. Nesse âmbito, a energia solar fotovoltaica, do
inglês photovoltaic (PV), se destaca como uma opção promissora de produção de energia
e, graças a políticas governamentais favoráveis e redução de custos, vêm tomando cada
vez mais espaço na matriz energética mundial. A geração PV é confiável, amplamente
disponível e pode contribuir significativamente para a produção global de eletricidade de
forma sustentável, reduzindo as emissões de dióxido de carbono.
Contudo, a geração de energia fotovoltaica também apresenta desafios notáveis, a
exemplo do alto custo inicial de instalação, do baixo desempenho na produção de energia
em determinadas situações e da sua natureza intermitente. Assim sendo, pesquisadores têm
investigado abordagens que possibilitem aumentar a quantidade total de energia elétrica
produzida, tal como o desenvolvimento de células fotovoltaicas mais eficientes ou o uso
de dispositivos que consigam garantir sua operação no ponto de potência máxima, do
inglês Maximum Power Point (MPP) (HEGAZY; SHOKAIR; SAAD, 2023). Por realizar o
rastreamento do ponto de máxima potência Maximum Power Point Tracking (MPPT), tais
dispositivos são elementos centrais de um sistema fotovoltaico e, por conseguente, serão
objeto de estudo deste trabalho (JIN et al., 2017).
Os MPPTs consistem em duas partes: um conversor CC-CC e um sistema eletrônico
embarcado com um algoritmo de controle, possibilitando uma maximização da potência
extraída pelo sistema (VILLEGAS-MIER et al., 2021). Os algoritmos de controle mais
populares são denominados Perturba e Observa, do inglês Perturb and Observe (P&O),
Condutância Incremental, do inglês Incremental Conductance (INC), e Tensão Constante,
do inglês Constant Voltage (CV) (GRUNER et al., 2023). No entanto, esses métodos têm
limitações na adaptação a mudanças ambientais e não possuem capacidade de determinar
o MPP global (GMPP) em condições de sombreamento parcial, do inglês Partial Shading
Conditions (PSC), as quais podem gerar inúmeros pontos de máximo locais (LMPPs), tal
como ilustra a Figura 1 .
Fonte: (YAP; SARIMUTHU; LIM, 2020).
Figura 1 – Curva de potência em função da tensão de um gerador PV sob PSC, com um
GMPP e diversos LMPP.
3
Para contornar essas limitações, técnicas de inteligência artificial, do inglês Artificial
Intelligence (AI), e algoritmos metaheurísticos, como Ant Colony (ACO), Cuckoo Search
(CS) e Firefly Algorithm (FF), têm sido explorados, oferecendo maior precisão na detecção
do GMPP (YAP; SARIMUTHU; LIM, 2020). Redes Neurais Artificiais (ANNs) também
são aplicadas para prever saídas de tensão e otimizar o desempenho dos controladores. Em
condições de sombreamento parcial, onde múltiplos picos locais podem ocorrer, métodos
evolutivos e heurísticos como a Otimização por Enxame de Partículas (PSO) e Algoritmos
Genéticos (GA) têm mostrado eficiência superior. Além disso, controladores como o de
Lógica Fuzzy (FLC) vêm sendo aprimorados com essas abordagens híbridas, que combinam
técnicas de AI para alcançar maior eficiência e resposta rápida em sistemas fotovoltaicos
complexos.
Diante do exposto, este trabalho tem por objetivo realizar um estudo abrangente
sobre técnicas de AI utilizadas em algoritmos de MPPT, capazes de operar sob o efeito de
sombreamento parcial. Uma das técnicas será então selecionada para implementação, a fim
de identificar a sua eficácia no rastreamento do GMPP quando o sistema é submetido a
condições adversas de sombreamento e mudanças abruptas de irradiância.
Estruturalmente, este documento está organizado em cinco capítulos, incluindo
este, introdutório. Inicialmente, no capítulo 2, é apresentado o referencial teórico utilizado
para o desenvolvimento do trabalho. Em seguida, no capítulo 3, discute-se o método de
MPPT baseado em AI desenvolvido. A validação é realizada no capítulo 4, por meio de
resultados de simulação. Por fim, o capítulo 5 apresenta as considerações finais dos estudos
realizados neste trabalho de conclusão de curso.

## 3 Descrição da Proposta
- Detalhamento da solução proposta (hardware, software ou ambos).
- Principais funcionalidades que serão desenvolvidas.
- Abordagem utilizada para implementação (ferramentas, plataformas, metodologias).
5. Requisitos
- Requisitos Funcionais:
- Lista das funcionalidades essenciais que o sistema deverá oferecer.
- Requisitos Não Funcionais:
- Critérios de qualidade como desempenho, segurança, confiabilidade, manutenibilidade, etc.
6. Diagrama de Comunicação
- Representação gráfica do fluxo de dados e da comunicação entre os componentes do sistema
(ex.: sensores, atuadores, servidores, dispositivos móveis).
- Descrição breve de cada elemento e sua função.
7. Diagrama Elétrico (se houver)
- Diagrama esquemático detalhado dos componentes eletrônicos utilizados no hardware.
- Explicação de como cada componente se conecta e interage no sistema.
8. Revisão da Literatura
- Pesquisas e trabalhos relevantes já realizados sobre o tema.
- Comparação entre a solução proposta e as soluções existentes.
- Tecnologias, metodologias e ferramentas mais modernas utilizadas na área.
9. Metodologia de Desenvolvimento
- Detalhamento das etapas de desenvolvimento.
- Ferramentas e tecnologias que serão utilizadas para implementação e testes.
10. Resultados Esperados
- Descrição dos principais resultados esperados ao final do projeto.
- Impacto no monitoramento, automação ou coleta de dados, caso seja relevante.
- Possíveis melhorias ou benefícios proporcionados pela solução.
11. Conclusão
- Resumo da proposta e considerações sobre a importância do projeto.
- Expectativas futuras em relação à escalabilidade, melhorias ou aplicações futuras do projeto.
12. Referências
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
