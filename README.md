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
- Citação das fontes utilizadas para revisão da literatura e pesquisa geral.
