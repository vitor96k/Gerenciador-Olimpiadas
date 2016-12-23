# Gerenciador Jogos Olimpicos 2016

Dsenvolvimento de um programa que gerencia as Olímpiads 2016 para a disciplina de Estrutura de Dados - 2º Ano Ciência da Computação.

<h2> Processos: </h2>

1) A pessoa candidata-se aos eventos a que deseja assistir, informando, também o número de ingressos que deseja para cada evento. <br />

2) A atribuição dos ingressos é feita por sorteio. Se a pessoa for sorteada, ser-lhe-á enviado um boleto para que pague pelos ingressos. Se a pessoa não for sorteada, receberá uma carta informando com pesar a noticía de sua pouca sorte. <br />

3) Os espectadores que receberam o boleto deverão quitá-lo até a data definida (1 o prazo). <br />

4) Caso o sorteado não quite o boleto, terá uma segunda chance de fazê-lo, porém, a um preço maior. Para tal, o próprio boleto já contém a informação sobre o segundo prazo e a multa a ser aplicada. <br />

5) Finalmente, os ingressos (para cada um dos eventos) referentes ao boleto quitado são enviados pelo correio. <br />

<h2> Especificações: </h2>

Os arquivos executáveis deverão ter os nomes riose, riosd, riode, riodd. O primeiro usará a implementação da lista com encadeamento simples e alocação estática; o segundo, a implementação com encadeamento simples e alocação dinâmica; o terceiro, encadeamento duplo e alocação estática; por fim, encadeamento duplo e alocação dinâmica.

<h2> Execução e Parâmetros: </h2>

```diff
+ make
+ riodd "parametros"
```


![Alt text](parametros.png?raw=true "exec")
