# Diário da atividade

Escreva com as suas palavras.
Frases curtas bastam.
Não cole a conversa inteira com a IA.
Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode: 1.18.31
- Modelo usado: Ling 3.0 Flash Fin

## Parte 1: antes de programar

![alt text](desenho.png)

Fiz o desenho no paint.

- O que cada classe guarda: Está no desenho
- O que acontece em `LANCAR_VOO 10`, em palavras: A agência procura o voo de código 10. Após isso, verifica se o voo está no estado planejado e se possui pelo menos um astronauta a bordo. Para cada CPF que consta no voo, a Agencia procura o astronauta correspondente e verifica se ele está vivo e disponível para o voo. Após todas as verificações serem aprovadas a agencia manda cada astronauta embarcar e manda o voo alterar seu estado para em curso.
- Uma dúvida que eu tinha antes de começar: Como organizar toda a estrutura do projeto, mas após ver que tinha um esqueleto no PDF disponibilizado pelo professor, ficou mais claro o que eu deveria fazer.

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): Perguntei para a IA como compilar usando powershell pois não estava conseguindo usar o Git Push, mas posteriormente consegui usar o Git Push normalmente.
- O que aprendi: Os comandos do Git Push no PowerShell.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
1. Getters sem const - todos os métodos que só leem o objeto deveriam ser marcados como const;
2. Duplicação de lógica entre lancarVoo, explodirVoo e finalizarVoo;
3. Using namespace std; no arquivo de cabeçalho;
- A que escolhi e por quê: Escolhi a primeira porque era a mais simples de fazer. É só colocar a palavra const no final dos métodos que só leem dados, sem mudar nada mais. Depois fiz a segunda também, porque percebi que lancarVoo, explodirVoo e finalizarVoo faziam a mesma coisa: um loop para olhar cada astronauta do voo e fazer alguma ação. Então criei três métodos privados novos — embarcarAstronautasDoVoo, morrerAstronautasDoVoo e desembarcarAstronautasDoVoo — cada um com um loop que faz uma ação específica. Os três métodos principais (lancarVoo, explodirVoo e finalizarVoo) chamam o método certo em vez de repetir o loop. A terceira sugestão não fiz porque trocar o using namespace std mexeria em tudo e tinha medo de quebrar.
- O que mudou no código, e se os seis testes continuaram passando: Coloquei const nos 13 métodos que só leem dados (5 da Astronauta, 5 da Voo e 2 buscadores privados da Agencia). Depois criei três métodos privados simples: embarcarAstronautasDoVoo, morrerAstronautasDoVoo e desembarcarAstronautasDoVoo, cada um com um loop que itera pelos astronautas do voo e faz uma ação. O lancarVoo chama o primeiro, o explodirVoo chama o segundo, e o finalizarVoo chama o terceiro. Isso tirou o loop repetido de lancarVoo, explodirVoo e finalizarVoo. O programa continuou compilando sem erros e os seis testes passaram igual antes.
- O que entendi que não sabia antes: Antes não fazia ideia do que const fazia nos métodos. Agora sei que const significa "este método não vai mudar nada no objeto". É como uma promessa pro compilador: "eu só leio, não mexo". Isso é bom porque se alguém tentar usar o método num objeto que não pode mudar, o compilador já avisa. Também aprendi que quando vários métodos fazem a mesma coisa com mudanças só no fim, é melhor criar métodos separados com nomes claros que descrevem o que fazem, em vez de repetir o mesmo loop. Assim fica mais fácil de ler e de manter.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
