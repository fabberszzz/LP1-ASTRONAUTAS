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

- Primeira mensagem (o pedido do plano):
Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão.
As classes Astronauta, Voo e Agencia estão em src/main.cpp.
Os testes em testes/parte1 passam.

Quero dois comandos novos: LISTAR_ASTRONAUTAS e HISTORICO cpf.

LISTAR_ASTRONAUTAS mostra todos os astronautas em três grupos, na ordem de cadastro dentro de cada grupo.

No grupo disponiveis entram os vivos que não estão em nenhum voo em curso.

No grupo em voo entram os vivos que estão em um voo em curso, com o código desse voo.

No grupo mortos entram os mortos.

Grupo vazio mostra (nenhum).

Exemplo:

LISTA DE ASTRONAUTAS
== disponiveis ==
333 Carla Souza (28 anos)
== em voo ==
111 Ana Maria (30 anos) - voo 20
== mortos ==
222 Bruno Costa (35 anos)

HISTORICO cpf mostra os voos dos quais o astronauta participou, com o estado atual de cada um, na ordem de cadastro dos voos.

Participou significa que o voo foi lançado com ele a bordo.

Voo só planejado não aparece.

Sem voos:
(nenhum voo)

CPF desconhecido:
ERRO: astronauta 999 nao cadastrado

Exemplo:

HISTORICO DE 111 Ana Maria
voo 10: finalizado com sucesso
voo 20: em curso

Não mude nenhum comando que já existe nem a saída deles.

Não use nada fora da biblioteca padrão.

Vou conferir com:

bash testes/testar.sh missao1

e depois:

bash testes/testar.sh parte1

Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

- O plano que a IA apresentou, resumido:
Arquivo modificado: apenas `src/main.cpp`, onde todas as classes já estão.
Métodos novos na classe `Agencia`:
`void listarAstronautas()` — agrupa astronautas em três categorias (disponiveis, em voo, mortos) e imprime no formato pedido.
`void historico(string cpf)` — lista os voos lançados em que o astronauta participou, com o estado atual de cada um.
Métodos alterados em `main()`: adição do tratamento dos comandos `LISTAR_ASTRONAUTAS` e `HISTORICO cpf`.
Por que não criar novas classes: a `Agencia` já tem os vetores e métodos de busca necessários; as duas funcionalidades são extensões naturais dela.

- Mudei algo no plano antes de liberar?
Após a leitura do plano, assim como consta no resumo, achei bem coerente e correto o plano traçado pela IA, por conta disso, foi permitido que ela executasse o plano da maneira original, sem alterações.

- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
missao1: Os dois testes passaram corretamente.
parte1: Todos os testes passaram corretamente.
- Precisei refazer? O que mudou no pedido:
Mesmo usando um modelo gratuito com foco em tarefas financeiras, sendo de uma empresa chamada InclusionAI, que é desconhecida para mim, a IA conseguiu aplicar o plano dela e logo no primeiro teste tudo deu OK. Talvez ela tenha acessado os arquivos de teste e visto o que seria necessário para que não acontecesse nenhum erro. Ou talvez seja algo muito simples e qualquer IA atualmente seria capaz de fazer.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 e o restante da Parte 1 estão funcionando corretamente.

Quero adicionar dois comandos novos:
1. SALVAR nome_do_arquivo: grava todos os dados atuais em um arquivo de texto e imprime "OK: dados salvos em nome_do_arquivo". Se não conseguir abrir o arquivo para escrita, imprime "ERRO: nao foi possivel salvar em nome_do_arquivo".
2. CARREGAR nome_do_arquivo: substitui todos os dados atuais pelos dados do arquivo e imprime "OK: dados carregados de nome_do_arquivo". Se o arquivo não existir, imprime "ERRO: nao foi possivel carregar de nome_do_arquivo", e os dados atuais devem continuar exatamente como estavam antes da tentativa.

O formato do arquivo de salvamento deve ser texto e garantir que, ao carregar, todos os dados sejam perfeitamente reconstruídos: astronautas (incluindo estados de vivo e disponível) e voos (incluindo estado atual e lista de CPFs).

Não mude nenhum comando que já existe nem a saída deles. Não use bibliotecas fora da biblioteca padrão.

Vou conferir o resultado com "bash testes/testar.sh missao2" e depois com "bash testes/testar.sh parte1".

Antes de editar qualquer arquivo, me diga quais arquivos e quais métodos você vai criar ou alterar, explique o formato escolhido para salvar os dados no arquivo de texto, e explique como o programa vai reconstruir os objetos ao carregar.

- O plano, resumido:
Arquivo modificado: apenas `src/main.cpp`, onde todas as classes já estão.
Métodos novos na classe `Agencia`:
`void salvar(string nomeArquivo)` — abre o arquivo para escrita, grava cada astronauta e cada voo em linhas de texto, e imprime a mensagem de sucesso ou erro.
`void carregar(string nomeArquivo)` — abre o arquivo, lê linha por linha, constrói vetores temporários de astronautas e voos, e só troca os vetores atuais no final, garantindo que se o arquivo não existir os dados originais permaneçam intactos.
Método novo na classe `Astronauta`:
`void definirEstado(bool v, bool d)` — permite restaurar vivo/disponível ao carregar, já que o construtor sempre inicializa ambos como true.
Métodos alterados em `main()`: adição do tratamento dos comandos `SALVAR` e `CARREGAR`.
Por que não criar novas classes: a `Agencia` já tem os vetores e métodos necessários; salvar e carregar são extensões naturais dela.

- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
O arquivo usa três tipos de linha:
  - `ASTRONAUTA cpf nome idade vivo disponibil experiencia` — um astronauta por linha, com nome (que pode ter espaços) entre o CPF e os três últimos tokens booleanos, seguido da experiência.
  - `VOO codigo estado` — um voo por linha, com o estado completo (que pode ter espaços, ex.: "finalizado com sucesso").
  - `VOO_CPFS codigo cpf` — um CPF por linha, associado ao código do voo.
Exemplo do `dados_teste.txt`:
ASTRONAUTA 111 Ana Maria 30 1 1 1
ASTRONAUTA 222 Bruno Costa 35 0 0 1
VOO 10 finalizado com sucesso
VOO_CPFS 10 111
VOO 20 finalizado com explosao

- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
missao2: Os três testes passaram corretamente (01_salvar, 02_carregar, 03_arquivo_inexistente).
parte1: Todos os testes passaram corretamente.

- Precisei refazer? O que mudou no pedido:
O plano da IA já estava correto desde a primeira versão, apenas tive um bug de implementação na leitura do estado com espaços. O formato do arquivo foi atualizado para incluir a coluna de experiência.

## Missão 3: RELATORIO

- Primeira mensagem:
Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes anteriores (Parte 1 e Missão 2) estão funcionando corretamente.

Quero adicionar um comando novo: RELATORIO.
Ele deve imprimir exatamente a palavra "RELATORIO" seguida de nove linhas informando o estado atual, neste formato exato:

RELATORIO
voos planejados: 0
voos em curso: 0
voos finalizados com sucesso: 1
voos finalizados com explosao: 2
astronautas cadastrados: 4
astronautas vivos: 2
astronautas mortos: 2
astronauta mais experiente: 111 Ana Maria (voos lancados: 1)
taxa de sucesso: 33%

Regras importantes para este comando:
1. Experiência de um astronauta: número de voos já lançados em que ele estava a bordo. Voos planejados não contam. Astronauta morto continua contando. Em caso de empate, vale o cadastrado primeiro. Se ninguém voou: "astronauta mais experiente: (nenhum)".
2. Taxa de sucesso: parte inteira da fórmula (sucessos * 100 / finalizados), onde "finalizados" são os voos com sucesso mais os com explosão. Se não houver voos finalizados: "taxa de sucesso: (nenhum voo finalizado)".
3. Cuidado com o salvamento/carregamento da Missão 2: se a experiência for armazenada de forma interna, ela não pode se perder ao salvar e carregar os dados.

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão.

Vou conferir com "bash testes/testar.sh missao3" e depois com "bash testes/testar.sh parte1".

Antes de editar qualquer arquivo, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

- O plano, resumido:
Arquivo modificado: apenas `src/main.cpp`.
Atributo novo na classe `Astronauta`: `int experiencia` (inicializa 0), com `getExperiencia()` e `setExperiencia(int)`.
Método alterado em `Agencia::lancarVoo()`: incrementa a experiência de cada astronauta a bordo antes de embarcar.
Método alterado em `Agencia::salvar()`: inclui `experiencia` na linha `ASTRONAUTA` do arquivo.
Método alterado em `Agencia::carregar()`: lê `experiencia` da linha `ASTRONAUTA` e a atribui ao astronauta.
Método novo na classe `Agencia`: `void relatorio()` — calcula e imprime as 9 linhas do relatório (contagem de voos por estado, contagem de astronautas, astronauta mais experiente com desempate pelo cadastro, e taxa de sucesso).
Método alterado em `main()`: adição do tratamento do comando `RELATORIO`.
Por que não criar novas classes: tudo é uma extensão natural das classes existentes; `relatorio()` pertence à `Agencia` que já coordena todos os dados.

- Mudei algo no plano antes de liberar?
Não. O plano estava completo e correto.

- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
missao3: Os cinco testes passaram corretamente.
parte1: Todos os testes passaram corretamente.

- Precisei refazer? O que mudou no pedido:
Não precisei refazer. Minha teoria da questão anterior foi comprovada, antes de traçar o plano, a IA faz a leitura do que contém nos testes e com isso traça o plano de ação de forma que não me entrega erros.
Fico até inseguro de fazer o commit assim, pois sinto que o intuito seria explorar mais os erros que a IA iria cometer e corrigir com novos prompts, porém, não está ocorrendo, mas como estou seguindo de forma fiel o que foi proposto vou dar commit desse modo mesmo.

## Missão 4: Comandante de Missão

- O que escolhi e por quê:
Escolhi implementar a regra de Comandante de Missão. Escolhi essa opção porque ela adiciona uma lógica de negócio realista e desafiadora ao sistema, forçando a verificação cruzada entre o histórico de voos finalizados com sucesso de cada astronauta e os requisitos de lançamento de um novo voo, sem precisar criar comandos complexos de interface.

- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos:
Não criamos um comando em texto novo (como uma palavra digitada pelo usuário), mas adicionamos uma regra restritiva nova ao comando existente `LANCAR_VOO`.
Nome do arquivo de comandos criado para testar: `testes/missao4_comandante.in`
Saída esperada ao tentar lançar um voo sem comandante qualificado (menos de 2 voos com sucesso):

ERRO: voo 10 nao possui comandante

- Primeira mensagem:
Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes anteriores (Parte 1 e Missões 1 a 3) estão funcionando corretamente.

Quero adicionar uma nova regra de validação no lançamento de voos (Missão 4): o Comandante.

As regras são:
1. Um voo só pode ser lançado se houver a bordo pelo menos um astronauta comandante.
2. Um comandante é definido como um astronauta que possui pelo menos 2 voos concluídos com sucesso no histórico dele (ou seja, voos em seu histórico com estado "finalizado com sucesso"). Voos planejados ou em curso não contam.
3. Na hora de executar "LANCAR_VOO codigo", após verificar as regras antigas (como se o astronauta está vivo e disponível), a Agência deve verificar se a tripulação possui pelo menos um comandante. Se não houver, o lançamento deve ser cancelado e impresso exatamente o erro:
"ERRO: voo 10 nao possui comandante" (substituindo 10 pelo código do voo).

Não mude nenhum comando que já exista nem altere a saída deles de forma a quebrar os testes antigos. Não use nada fora da biblioteca padrão.

Vou conferir com o meu arquivo de testes personalizado e depois rodarei "bash testes/testar.sh parte1" para garantir que nada foi quebrado.

Antes de editar qualquer arquivo, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

- O plano, resumido:
Arquivo modificado: apenas `src/main.cpp`.
Método privado novo na classe `Agencia`: `int contarConquistas(string cpf) const` — conta quantos voos com estado "finalizado com sucesso" possuem o CPF do astronauta a bordo.
Método alterado em `Agencia::lancarVoo()`: após as verificações existentes (voo existe, planejado, tem astronautas, todos vivos e disponíveis), adiciona a verificação de comandante. A regra só se aplica se já existir no sistema pelo menos um astronauta com 2+ conquistas. Quando a regra está ativa, se nenhum astronauta a bordo tiver 2+ conquistas, imprime `ERRO: voo X nao possui comandante`.
Atributo já existente em `Astronauta`: `int experiencia` (adicionado na Missão 3), com `getExperiencia()`.
Métodos já existentes usados para comandante: `getExperiencia()` e o novo `contarConquistas()`.
Por que não criar novas classes ou arquivos: tudo é uma extensão natural da classe `Agencia`; o comandante é uma validação adicional no lançamento.

- Mudei algo no plano antes de liberar?
Não. O plano supostamente estava completo, mais tarde descobri que não tem como o voo iniciar com um comandante se ninguém nunca fez duas viagens.

- Resultado de `testar.sh parte1`:
Os seis testes falharam. A regra de comandante quebrou a Parte 1 porque os testes existentes lançam voos sem astronautas que tenham 2+ voos com sucesso no histórico. Por exemplo, no teste `03_lancamento_finalizacao.in`, o astronauta 111 nunca teve voos concluídos com sucesso antes do primeiro `LANCAR_VOO 10`, então o lançamento foi recusado com `ERRO: voo 10 nao possui comandante`.

- Precisei refazer? O que mudou no pedido:
Sim, precisei refazer. Ao executar `testar.sh parte1`, descobri que a regra de comandante criava um problema de efeito ovo antes da galinha: um comandante precisa de 2 voos com sucesso no histórico, mas para ter um voo com sucesso é preciso primeiro lançar um voo, e o lançamento exige um comandante. Isso torna impossível lançar o primeiro voo de qualquer cenário.

Relatei o problema para a IA, explicando que a validação de comandante é circular para o primeiro lançamento. Pedi para ela ajustar a implementação para resolver isso.

- Ajuste feito:
A IA fez uma verificação de bootstrapping em `lancarVoo()`: a regra de comandante só se aplica se já existir no sistema pelo menos um astronauta com 2 ou mais voos finalizados com sucesso (`contarConquistas >= 2`). Se ninguém ainda acumulou 2+ conquistas, a verificação de comandante é ignorada, permitindo os lançamentos iniciais. Após algum astronauta acumular 2+ voos com sucesso, a regra de comandante passa a valer normalmente para todos os lançamentos seguintes.

- Resultado após o ajuste:
`testar.sh parte1`: todos os 6 testes passaram corretamente. As saídas esperadas dos testes `03_lancamento_finalizacao.out`, `04_explosao_e_mortes.out` e `06_cenario_completo.out` foram atualizadas para refletir o novo comportamento. As missões 2 e 3 também foram afetadas pela regra de comandante, conforme esperado.

- O que veio, comparado com o que eu esperava:
O bug de bootstrapping não era óbvio ao escrever o plano, mas era inevitável dado a definição da regra. A solução de bootstrapping (ignorar o comandante quando ninguém ainda tem 2+ voos com sucesso) é uma interpretação razoável que permite o sistema funcionar desde o início sem quebrar a semântica da regra.

- `testar.sh parte1` continuou passando?
Sim, após o ajuste.

- Aceitei, ajustei ou descartei? Por quê:
Ajustei. A implementação original estava correta logicamente, mas impraticável para o primeiro lançamento. A solução de bootstrapping (aplicar a regra de comandante somente quando já existe alguém com 2+ conquistas no sistema) mantém a regra funcional para todos os cenários sem quebrar os testes anteriores.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
Identificar o problema de bootstrapping do comandante e implementar a solução de forma adequada, além de atualizar os testes da Parte 1 para refletir a nova validação.
- Onde ela errou ou fez algo que eu não pedi:
A primeira implementação não tinha a verificação de bootstrapping, o que quebrava todos os testes da Parte 1 e das Missões 2 e 3.
- O que eu faria diferente da próxima vez:
Considerar a regra de bootstrapping desde o início do pedido, para evitar ter que refazer a implementação depois.