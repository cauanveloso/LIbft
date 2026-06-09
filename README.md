*This project has been created as part of the 42 curriculum by csilva-v*

# Description

Libft é uma biblioteca estática desenvolvida em C como parte do currículo da 42. O projeto consiste na recriação de diversas funções da biblioteca padrão da linguagem C, além da implementação de utilitários adicionais para manipulação de memória, strings, caracteres, conversão de tipos e listas encadeadas.

O principal objetivo da Libft é aprofundar o entendimento dos fundamentos da linguagem C através da implementação manual de funcionalidades amplamente utilizadas no desenvolvimento de software. Durante o projeto são explorados conceitos como ponteiros, alocação dinâmica de memória, estruturas de dados, modularização de código e gerenciamento de recursos.

Além de representar uma etapa importante do processo de aprendizagem, a Libft serve como base para diversos projetos futuros da 42, fornecendo um conjunto de funções reutilizáveis que auxiliam no desenvolvimento de aplicações mais complexas.

## Índice

* [Aprendizados](#aprendizados)
* [Funções Disponíveis](#funções-disponíveis)
* [Compilação e Estrutura do Projeto](#compilação-e-estrutura-do-projeto)
* [Manipulação de Caracteres](#manipulação-de-caracteres)
* [Manipulação de Memória](#manipulação-de-memória)
* [Manipulação de Strings](#manipulação-de-strings)
* [Conversão de Tipos](#conversão-de-tipos)
* [Manipulação de File Descriptors](#manipulação-de-file-descriptors)
* [Listas Encadeadas](#listas-encadeadas)

## Aprendizados

O desenvolvimento da Libft foi um dos primeiros grandes desafios da minha jornada na linguagem C. Durante a implementação de cada função, foi possível aprofundar conceitos fundamentais da programação de baixo nível e compreender melhor como diversas funções da biblioteca padrão funcionam internamente.

Ao longo deste projeto foram explorados conceitos como:

* Manipulação de ponteiros.
* Gerenciamento e alocação dinâmica de memória.
* Manipulação de strings e caracteres.
* Operações sobre regiões de memória.
* Conversão de tipos de dados.
* Modularização e reutilização de código.
* Criação e utilização de bibliotecas estáticas.
* Estruturas de dados dinâmicas.
* Listas encadeadas.
* Tratamento de erros e prevenção de vazamentos de memória.

Além do conhecimento técnico, o projeto contribuiu para o desenvolvimento de habilidades importantes de depuração, análise de problemas e escrita de código limpo, eficiente e reutilizável, que servirão como base para todos os projetos futuros desenvolvidos em C.

## Funções Disponíveis

A Libft é composta por funções organizadas nas seguintes categorias:

- Manipulação de Caracteres
- Manipulação de Memória
- Manipulação de Strings
- Conversão de Tipos
- Manipulação de File Descriptors
- Listas Encadeadas

Cada categoria é apresentada em detalhes nas seções seguintes.

## Instructions

A Libft é uma biblioteca estática desenvolvida em C e compilada através de um **Makefile**, responsável por automatizar todo o processo de construção do projeto.

Durante a compilação, cada arquivo-fonte (`.c`) é convertido em um arquivo objeto (`.o`). Em seguida, todos os arquivos objeto são agrupados para formar a biblioteca estática `libft.a`, que poderá ser utilizada em outros projetos através da inclusão do cabeçalho `libft.h`.

### Estrutura do Projeto

```text
libft/
├── Makefile
├── libft.h
├── README.md
├── ft_isalpha.c
├── ft_memset.c
├── ft_strlen.c
├── ft_atoi.c
├── ft_lstnew.c
└── ...
```

* **Makefile**: automatiza o processo de compilação.
* **libft.h**: contém os protótipos das funções e definições necessárias.
* **ft_*.c**: implementações das funções da biblioteca.
* **libft.a**: biblioteca estática gerada após a compilação.

### Comandos Disponíveis

Compilar a biblioteca:

```bash
make
```

Remove todos os arquivos objeto gerados durante a compilação:

```bash
make clean
```

Remove os arquivos objeto e a biblioteca estática gerada:

```bash
make fclean
```

Remove todos os arquivos gerados e recompila o projeto do zero:

```bash
make re
```

Após a compilação, a biblioteca poderá ser utilizada em outros projetos através do arquivo `libft.a` juntamente com o cabeçalho `libft.h`.


## Manipulação de Caracteres

Em C, os caracteres são representados por valores inteiros da tabela ASCII (American Standard Code for Information Interchange). Cada caractere possui um valor numérico associado.

Exemplos:

```c
'A' = 65
'B' = 66
'a' = 97
'b' = 98
'0' = 48
'1' = 49
```

Como os caracteres são armazenados como números, é possível compará-los e manipulá-los utilizando operações matemáticas e condicionais.

Exemplo:

```c
char c = 'A';

if (c >= 'A' && c <= 'Z')
{
    printf("É uma letra maiúscula\n");
}
```

A manipulação de caracteres é amplamente utilizada para:

- Validar entradas do usuário.
- Verificar se um caractere é letra ou número.
- Converter letras maiúsculas em minúsculas.
- Converter letras minúsculas em maiúsculas.
- Processar textos e strings.
- Criar funções de validação e parsing.

As funções a seguir fazem parte da categoria de manipulação e verificação de caracteres da Libft.

- [<u>**ft_isalpha**</u>](#ft_isalpha)
- [<u>**ft_isdigit**</u>](#ft_isdigit)
- [<u>**ft_isalnum**</u>](#ft_isalnum)
- [<u>**ft_isascii**</u>](#ft_isascii)
- [<u>**ft_isprint**</u>](#ft_isprint)
- [<u>**ft_tolower**</u>](#ft_tolower)
- [<u>**ft_toupper**</u>](#ft_toupper)

Estas funções são utilizadas para validação e conversão de caracteres ASCII.

## Manipulação de Memória

Em C, a memória é organizada como uma sequência contínua de bytes. Cada variável, array ou estrutura ocupa uma região específica da memória, podendo ser acessada e manipulada através de ponteiros.

A manipulação de memória permite copiar, mover, preencher, comparar e alocar blocos de memória de forma eficiente, sendo uma das características mais poderosas da linguagem C.

Exemplo:

```c
char buffer[10];

memset(buffer, 'A', 10);
```

Após a execução, todos os bytes do array conterão o caractere `'A'`.

Outro exemplo:

```c
char src[] = "Hello";
char dst[6];

memcpy(dst, src, 6);
```

Nesse caso, o conteúdo de `src` é copiado para `dst`.

A manipulação de memória é amplamente utilizada para:

* Inicializar estruturas e arrays.
* Copiar dados entre regiões de memória.
* Mover dados de forma segura entre áreas sobrepostas.
* Comparar blocos de memória.
* Buscar informações em regiões de memória.
* Realizar alocações dinâmicas.
* Construir estruturas de dados complexas.

As funções a seguir fazem parte da categoria de manipulação de memória da Libft.

* [<u>**ft_memset**</u>](#ft_memset)
* [<u>**ft_bzero**</u>](#ft_bzero)
* [<u>**ft_memcpy**</u>](#ft_memcpy)
* [<u>**ft_memmove**</u>](#ft_memmove)
* [<u>**ft_memchr**</u>](#ft_memchr)
* [<u>**ft_memcmp**</u>](#ft_memcmp)
* [<u>**ft_calloc**</u>](#ft_calloc)

Estas funções são utilizadas para manipular diretamente regiões de memória, oferecendo controle preciso sobre os dados armazenados e servindo como base para diversas operações internas da linguagem C.

## Manipulação de Strings

Em C, uma string é uma sequência de caracteres armazenados em um array e finalizada pelo caractere nulo (`'\0'`). Diferentemente de linguagens de mais alto nível, a linguagem C não possui um tipo nativo para strings, tornando necessária a utilização de funções específicas para manipulá-las.

A manipulação de strings permite criar, copiar, concatenar, comparar, buscar, dividir e modificar textos de forma eficiente, sendo uma das tarefas mais comuns no desenvolvimento de aplicações.

Exemplo:

```c
char str[] = "Hello";

printf("%zu\n", strlen(str));
```

Neste caso, a função retorna o tamanho da string sem contar o caractere nulo (`'\0'`).

Outro exemplo:

```c
char *name = "Cauan";
char *greeting;

greeting = ft_strjoin("Hello ", name);
```

Nesse caso, uma nova string é criada contendo a junção dos dois textos.

A manipulação de strings é amplamente utilizada para:

* Processar entradas do usuário.
* Manipular textos e arquivos.
* Buscar caracteres ou palavras.
* Comparar informações textuais.
* Dividir e concatenar strings.
* Converter valores entre diferentes formatos.
* Construir e formatar mensagens.

As funções a seguir fazem parte da categoria de manipulação de strings da Libft.

* [<u>**ft_strlen**</u>](#ft_strlen)
* [<u>**ft_strlcpy**</u>](#ft_strlcpy)
* [<u>**ft_strlcat**</u>](#ft_strlcat)
* [<u>**ft_strchr**</u>](#ft_strchr)
* [<u>**ft_strrchr**</u>](#ft_strrchr)
* [<u>**ft_strncmp**</u>](#ft_strncmp)
* [<u>**ft_strnstr**</u>](#ft_strnstr)
* [<u>**ft_strdup**</u>](#ft_strdup)
* [<u>**ft_substr**</u>](#ft_substr)
* [<u>**ft_strjoin**</u>](#ft_strjoin)
* [<u>**ft_strtrim**</u>](#ft_strtrim)
* [<u>**ft_split**</u>](#ft_split)
* [<u>**ft_itoa**</u>](#ft_itoa)
* [<u>**ft_strmapi**</u>](#ft_strmapi)
* [<u>**ft_striteri**</u>](#ft_striteri)

Estas funções são utilizadas para manipular e processar strings, fornecendo ferramentas essenciais para o tratamento de texto e servindo como base para diversas operações realizadas em programas escritos em C.

## Conversão de Tipos

Em programação, frequentemente é necessário converter dados entre diferentes representações. Uma informação pode estar armazenada como texto e precisar ser interpretada como um número, ou um valor numérico pode precisar ser convertido para uma string para exibição ao usuário.

As funções de conversão permitem realizar essas transformações de forma simples e eficiente, sendo amplamente utilizadas em validação de entradas, processamento de dados e formatação de informações.

Exemplo:

```c
int number;

number = ft_atoi("42");
```

Neste caso, a string `"42"` é convertida para o valor inteiro `42`.

Outro exemplo:

```c
char *str;

str = ft_itoa(42);
```

Neste caso, o valor inteiro `42` é convertido para a string `"42"`.

As funções de conversão são amplamente utilizadas para:

* Processar entradas do usuário.
* Interpretar dados vindos de arquivos.
* Converter números para exibição.
* Validar informações textuais.
* Formatar mensagens e relatórios.
* Facilitar a comunicação entre diferentes tipos de dados.

As funções a seguir fazem parte da categoria de conversão de tipos da Libft.

* [<u>**ft_atoi**</u>](#ft_atoi)
* [<u>**ft_itoa**</u>](#ft_itoa)

Estas funções permitem converter informações entre representações textuais e numéricas, servindo como ferramentas fundamentais para o processamento de dados em C.

## Manipulação de File Descriptors

Em sistemas Unix e Linux, um *file descriptor* (descritor de arquivo) é um identificador numérico utilizado pelo sistema operacional para acessar arquivos, terminais, pipes e outros recursos de entrada e saída.

Os descritores mais comuns são:

```c id="s4l1mv"
0 -> Entrada padrão (stdin)
1 -> Saída padrão (stdout)
2 -> Saída de erro (stderr)
```

As funções desta categoria permitem enviar caracteres, strings e números para qualquer descritor de arquivo, oferecendo maior flexibilidade para exibição de mensagens e escrita em arquivos.

Exemplo:

```c id="r0x0z7"
ft_putstr_fd("Hello World", 1);
```

Neste caso, a mensagem será exibida na saída padrão (`stdout`).

Outro exemplo:

```c id="e7n4aj"
ft_putnbr_fd(42, 1);
```

Neste caso, o número `42` será exibido no terminal.

As funções de file descriptors são amplamente utilizadas para:

* Exibir mensagens no terminal.
* Escrever dados em arquivos.
* Exibir mensagens de erro.
* Criar sistemas de logging.
* Facilitar a comunicação entre processos.
* Manipular diferentes fluxos de entrada e saída.

As funções a seguir fazem parte da categoria de manipulação de file descriptors da Libft.

* [<u>**ft_putchar_fd**</u>](#ft_putchar_fd)
* [<u>**ft_putstr_fd**</u>](#ft_putstr_fd)
* [<u>**ft_putendl_fd**</u>](#ft_putendl_fd)
* [<u>**ft_putnbr_fd**</u>](#ft_putnbr_fd)

Estas funções fornecem uma interface simples para escrita de dados em diferentes descritores de arquivo, permitindo maior controle sobre operações de entrada e saída em programas escritos em C.


## Listas Encadeadas

As listas encadeadas são estruturas de dados dinâmicas compostas por nós interligados através de ponteiros. Cada nó armazena um conteúdo e o endereço do próximo elemento da lista, permitindo que os dados sejam organizados de forma flexível na memória.

Diferentemente dos arrays, as listas encadeadas não precisam ocupar posições contíguas na memória, o que facilita a inserção e remoção de elementos sem a necessidade de mover grandes blocos de dados.

Exemplo:

```c
t_list *node1;
t_list *node2;

node1 = ft_lstnew("Hello");
node2 = ft_lstnew("World");

node1->next = node2;
```

Neste caso, `node1` aponta para `node2`, formando uma lista encadeada com dois elementos.

Outro exemplo:

```c
t_list *list;

list = NULL;
ft_lstadd_back(&list, ft_lstnew("First"));
ft_lstadd_back(&list, ft_lstnew("Second"));
```

Nesse caso, novos nós são adicionados ao final da lista.

As listas encadeadas são amplamente utilizadas para:

* Armazenar dados dinamicamente.
* Inserir e remover elementos com eficiência.
* Implementar filas e pilhas.
* Construir estruturas de dados mais complexas.
* Percorrer conjuntos de informações de forma sequencial.
* Gerenciar coleções de dados cujo tamanho pode variar durante a execução.

As funções a seguir fazem parte da categoria de listas encadeadas da Libft.

* [<u>**ft_lstnew**</u>](#ft_lstnew)
* [<u>**ft_lstadd_front**</u>](#ft_lstadd_front)
* [<u>**ft_lstsize**</u>](#ft_lstsize)
* [<u>**ft_lstlast**</u>](#ft_lstlast)
* [<u>**ft_lstadd_back**</u>](#ft_lstadd_back)
* [<u>**ft_lstdelone**</u>](#ft_lstdelone)
* [<u>**ft_lstclear**</u>](#ft_lstclear)
* [<u>**ft_lstiter**</u>](#ft_lstiter)
* [<u>**ft_lstmap**</u>](#ft_lstmap)

Estas funções permitem criar, percorrer, modificar, remover e transformar listas encadeadas, fornecendo uma base sólida para o desenvolvimento de estruturas de dados dinâmicas e algoritmos mais avançados em C.


<a id="ft_isalpha"></a>A função `ft_isalpha` verifica se um caractere é uma letra do alfabeto.

Ela retorna:
- Um valor diferente de `0` se o caractere for uma letra (`A-Z` ou `a-z`).
- `0` caso contrário.

Exemplo:

```c
ft_isalpha('A'); // retorna diferente de 0
ft_isalpha('z'); // retorna diferente de 0
ft_isalpha('5'); // retorna 0
ft_isalpha('@'); // retorna 0
```
---
<a id="ft_isdigit"></a>A função `ft_isdigit` verifica se um caractere é um dígito decimal.

Ela retorna:
- Um valor diferente de `0` se o caractere estiver entre `0` e `9`.
- `0` caso contrário.

Exemplo:

```c
ft_isdigit('5'); // retorna diferente de 0
ft_isdigit('0'); // retorna diferente de 0
ft_isdigit('A'); // retorna 0
ft_isdigit('@'); // retorna 0
```
---
<a id="ft_isalnum"></a>A função `ft_isalnum` verifica se um caractere é alfanumérico.

Ela retorna:
- Um valor diferente de `0` se o caractere for uma letra (`A-Z`, `a-z`) ou um dígito (`0-9`).
- `0` caso contrário.

Exemplo:

```c
ft_isalnum('A'); // retorna diferente de 0
ft_isalnum('7'); // retorna diferente de 0
ft_isalnum('z'); // retorna diferente de 0
ft_isalnum('#'); // retorna 0
```
---
<a id="ft_isascii"></a>A função `ft_isascii` verifica se um valor pertence à tabela ASCII.

Ela retorna:
- Um valor diferente de `0` se o valor estiver entre `0` e `127`.
- `0` caso contrário.

Exemplo:

```c
ft_isascii('A'); // retorna diferente de 0
ft_isascii(65);  // retorna diferente de 0
ft_isascii(128); // retorna 0
ft_isascii(200); // retorna 0
```
---
<a id="ft_isprint"></a>A função `ft_isprint` verifica se um caractere é imprimível.

Ela retorna:
- Um valor diferente de `0` se o caractere estiver entre `32` e `126` na tabela ASCII.
- `0` caso contrário.

Exemplo:

```c
ft_isprint('A'); // retorna diferente de 0
ft_isprint(' '); // retorna diferente de 0
ft_isprint('9'); // retorna diferente de 0
ft_isprint('\n'); // retorna 0
```
---
<a id="ft_tolower"></a>A função `ft_tolower` converte uma letra maiúscula para minúscula.

Ela retorna:
- A versão minúscula da letra, se ela estiver entre `A` e `Z`.
- O próprio caractere caso não seja uma letra maiúscula.

Exemplo:

```c
ft_tolower('A'); // retorna 'a'
ft_tolower('Z'); // retorna 'z'
ft_tolower('5'); // retorna '5'
ft_tolower('a'); // retorna 'a'
```
---
<a id="ft_toupper"></a>A função `ft_toupper` converte uma letra minúscula para maiúscula.

Ela retorna:
- A versão maiúscula da letra, se ela estiver entre `a` e `z`.
- O próprio caractere caso não seja uma letra minúscula.

Exemplo:

```c
ft_toupper('a'); // retorna 'A'
ft_toupper('z'); // retorna 'Z'
ft_toupper('5'); // retorna '5'
ft_toupper('A'); // retorna 'A'
```
---
<a id="ft_memset"></a>A função `ft_memset` preenche uma região de memória com um valor específico.

Ela retorna:

* Um ponteiro para a região de memória modificada.

Exemplo:

```c
char str[6] = "Hello";

ft_memset(str, 'A', 5);
// str = "AAAAA"
```
---
<a id="ft_bzero"></a>A função `ft_bzero` define todos os bytes de uma região de memória como `0`.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
char str[6] = "Hello";

ft_bzero(str, 5);
// str contém apenas bytes nulos
```
---
<a id="ft_memcpy"></a>A função `ft_memcpy` copia uma quantidade específica de bytes de uma região de memória para outra.

Ela retorna:

* Um ponteiro para o destino da cópia.

⚠️ Esta função não deve ser utilizada quando as regiões de memória se sobrepõem.

Exemplo:

```c
char src[] = "Hello";
char dst[6];

ft_memcpy(dst, src, 6);
// dst = "Hello"
```
---
<a id="ft_memmove"></a>A função `ft_memmove` copia bytes entre regiões de memória de forma segura, mesmo quando elas se sobrepõem.

Ela retorna:

* Um ponteiro para o destino da cópia.

Exemplo:

```c
char str[] = "abcdef";

ft_memmove(str + 2, str, 4);
// str = "ababcd"
```

__Diferentemente de ft_memcpy, esta função pode ser utilizada com regiões de memória sobrepostas.__

---

<a id="ft_memchr"></a>A função `ft_memchr` procura a primeira ocorrência de um byte específico em uma região de memória.

Ela retorna:

* Um ponteiro para o byte encontrado.
* `NULL` caso o byte não seja encontrado.

Exemplo:

```c
char str[] = "Hello";

ft_memchr(str, 'e', 5);
// retorna ponteiro para 'e'

ft_memchr(str, 'x', 5);
// retorna NULL
```
---
<a id="ft_memcmp"></a>A função `ft_memcmp` compara duas regiões de memória byte a byte.

Ela retorna:

* Um valor menor que `0` se a primeira região for menor que a segunda.
* `0` se ambas forem iguais.
* Um valor maior que `0` se a primeira região for maior que a segunda.

Exemplo:

```c
ft_memcmp("abc", "abc", 3);
// retorna 0

ft_memcmp("abc", "abd", 3);
// retorna valor negativo
```
---
<a id="ft_calloc"></a>A função `ft_calloc` aloca memória dinamicamente e inicializa todos os bytes com `0`.

Ela retorna:

* Um ponteiro para a memória alocada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
int *array;

array = ft_calloc(5, sizeof(int));

// array possui espaço para 5 inteiros
// todos inicializados com 0
```
---
<a id="ft_strlen"></a>A função `ft_strlen` calcula o tamanho de uma string.

Ela retorna:

* A quantidade de caracteres da string, sem contar o caractere nulo (`'\0'`).

Exemplo:

```c
ft_strlen("Hello");
// retorna 5
```
---
<a id="ft_strlcpy"></a>A função `ft_strlcpy` copia uma string para outra de forma segura, respeitando o tamanho do buffer de destino.

Ela retorna:

* O tamanho total da string de origem.

Exemplo:

```c
char dst[10];

ft_strlcpy(dst, "Hello", sizeof(dst));
// dst = "Hello"
```
---
<a id="ft_strlcat"></a>A função `ft_strlcat` concatena uma string ao final de outra de forma segura.

Ela retorna:

* O tamanho que a string resultante teria se houvesse espaço suficiente.

Exemplo:

```c
char dst[20] = "Hello ";

ft_strlcat(dst, "World", sizeof(dst));
// dst = "Hello World"
```
---
<a id="ft_strchr"></a>A função `ft_strchr` procura a primeira ocorrência de um caractere em uma string.

Ela retorna:

* Um ponteiro para a primeira ocorrência encontrada.
* `NULL` caso o caractere não seja encontrado.

Exemplo:

```c
ft_strchr("Hello", 'l');
// retorna ponteiro para o primeiro 'l'

ft_strchr("Hello", 'x');
// retorna NULL
```
---
<a id="ft_strrchr"></a>A função `ft_strrchr` procura a última ocorrência de um caractere em uma string.

Ela retorna:

* Um ponteiro para a última ocorrência encontrada.
* `NULL` caso o caractere não seja encontrado.

Exemplo:

```c
ft_strrchr("Hello", 'l');
// retorna ponteiro para o último 'l'
```
---
<a id="ft_strncmp"></a>A função `ft_strncmp` compara duas strings até uma quantidade específica de caracteres.

Ela retorna:

* Um valor menor que `0` se a primeira string for menor.
* `0` se ambas forem iguais.
* Um valor maior que `0` se a primeira string for maior.

Exemplo:

```c
ft_strncmp("abc", "abc", 3);
// retorna 0

ft_strncmp("abc", "abd", 3);
// retorna valor negativo
```
---
<a id="ft_strnstr"></a>A função `ft_strnstr` procura uma substring dentro de outra string, limitando a busca a um número máximo de caracteres.

Ela retorna:

* Um ponteiro para a primeira ocorrência encontrada.
* `NULL` caso a substring não seja encontrada.

Exemplo:

```c
ft_strnstr("Hello World", "World", 11);
// retorna ponteiro para "World"

ft_strnstr("Hello World", "42", 11);
// retorna NULL
```
---
<a id="ft_strdup"></a>A função `ft_strdup` cria uma cópia dinâmica de uma string.

Ela retorna:

* Um ponteiro para a nova string alocada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
char *copy;

copy = ft_strdup("Hello");
// copy contém uma cópia de "Hello"
```
---
<a id="ft_substr"></a>A função `ft_substr` cria uma nova string contendo uma parte de outra string.

Ela retorna:

* Um ponteiro para a substring criada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
ft_substr("Hello World", 6, 5);
// retorna "World"
```
---
<a id="ft_strjoin"></a>A função `ft_strjoin` cria uma nova string contendo a junção de duas strings.

Ela retorna:

* Um ponteiro para a nova string criada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
ft_strjoin("Hello ", "World");
// retorna "Hello World"
```
---
<a id="ft_strtrim"></a>A função `ft_strtrim` remove caracteres específicos do início e do final de uma string.

Ela retorna:

* Um ponteiro para a nova string criada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
ft_strtrim("###Hello###", "#");
// retorna "Hello"
```
---
<a id="ft_split"></a>A função `ft_split` divide uma string em várias substrings utilizando um delimitador.

Ela retorna:

* Um array de strings terminado por `NULL`.
* `NULL` caso a alocação falhe.

Exemplo:

```c
char **words;

words = ft_split("Hello World 42", ' ');

// words[0] = "Hello"
// words[1] = "World"
// words[2] = "42"
// words[3] = NULL
```
---
<a id="ft_atoi"></a>A função `ft_atoi` converte uma string contendo um número inteiro para o tipo `int`.

Ela ignora espaços em branco iniciais, reconhece sinais (`+` ou `-`) e converte os caracteres numéricos subsequentes para um valor inteiro.

Ela retorna:

* O valor inteiro representado pela string.

Exemplo:

```c
ft_atoi("42");
// retorna 42

ft_atoi("-42");
// retorna -42

ft_atoi("   +123");
// retorna 123

ft_atoi("abc");
// retorna 0
```
---
<a id="ft_itoa"></a>A função `ft_itoa` converte um número inteiro para uma string.

Ela retorna:

* Um ponteiro para a string criada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
ft_itoa(42);
// retorna "42"

ft_itoa(-42);
// retorna "-42"
```
---
<a id="ft_putchar_fd"></a>A função `ft_putchar_fd` escreve um único caractere em um descritor de arquivo.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
ft_putchar_fd('A', 1);
// Exibe: A
```
---
<a id="ft_putstr_fd"></a>A função `ft_putstr_fd` escreve uma string em um descritor de arquivo.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
ft_putstr_fd("Hello World", 1);
// Exibe: Hello World
```
---
<a id="ft_putendl_fd"></a>A função `ft_putendl_fd` escreve uma string seguida de uma quebra de linha em um descritor de arquivo.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
ft_putendl_fd("Hello World", 1);
// Exibe:
// Hello World
```
---
<a id="ft_putnbr_fd"></a>A função `ft_putnbr_fd` escreve um número inteiro em um descritor de arquivo.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
ft_putnbr_fd(42, 1);
// Exibe: 42

ft_putnbr_fd(-42, 1);
// Exibe: -42
```
---
<a id="ft_strmapi"></a>A função `ft_strmapi` cria uma nova string aplicando uma função a cada caractere da string original.

Ela retorna:

* Um ponteiro para a nova string criada.
* `NULL` caso a alocação falhe.

Exemplo:

```c
char add_index(unsigned int i, char c)
{
	return (c + i);
}

ft_strmapi("abc", add_index);
// retorna "ace"
```
---
<a id="ft_striteri"></a>A função `ft_striteri` percorre uma string aplicando uma função diretamente em cada caractere.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

char str[] = "hello";

ft_striteri(str, to_upper);
// str = "HELLO"
```
---
<a id="ft_lstnew"></a>A função `ft_lstnew` cria um novo nó para uma lista encadeada.

Ela retorna:

* Um ponteiro para o novo nó criado.
* `NULL` caso a alocação falhe.

Exemplo:

```c
t_list *node;

node = ft_lstnew("Hello");

// node->content = "Hello"
// node->next = NULL
```
---
<a id="ft_lstadd_front"></a>A função `ft_lstadd_front` adiciona um nó no início da lista.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
t_list *list;

list = ft_lstnew("World");
ft_lstadd_front(&list, ft_lstnew("Hello"));

// Hello -> World
```
---
<a id="ft_lstsize"></a>A função `ft_lstsize` calcula a quantidade de nós presentes na lista.

Ela retorna:

* O número de nós da lista.

Exemplo:

```c
ft_lstsize(list);
// retorna a quantidade de elementos da lista
```
---
<a id="ft_lstlast"></a>A função `ft_lstlast` retorna o último nó da lista.

Ela retorna:

* Um ponteiro para o último nó.
* `NULL` caso a lista esteja vazia.

Exemplo:

```c
t_list *last;

last = ft_lstlast(list);
```

<a id="ft_lstadd_back"></a>A função `ft_lstadd_back` adiciona um nó ao final da lista.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
t_list *list;

list = ft_lstnew("Hello");
ft_lstadd_back(&list, ft_lstnew("World"));

// Hello -> World
```
---
<a id="ft_lstdelone"></a>A função `ft_lstdelone` remove um único nó da lista, liberando sua memória.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
t_list *node;

node = ft_lstnew("Hello");
ft_lstdelone(node, del);
```

Neste caso, o conteúdo é liberado utilizando a função `del` e, em seguida, o nó é destruído.

---
<a id="ft_lstclear"></a>A função `ft_lstclear` remove todos os nós de uma lista, liberando toda a memória utilizada.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
ft_lstclear(&list, del);

// Toda a lista é destruída
```
---
<a id="ft_lstiter"></a>A função `ft_lstiter` percorre todos os nós da lista aplicando uma função ao conteúdo de cada elemento.

Ela retorna:

* Nada (`void`).

Exemplo:

```c
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

ft_lstiter(list, print_content);
```

Neste caso, o conteúdo de cada nó é exibido na tela.

---
<a id="ft_lstmap"></a>A função `ft_lstmap` cria uma nova lista aplicando uma transformação ao conteúdo de cada nó da lista original.

Ela retorna:

* Um ponteiro para a nova lista criada.
* `NULL` caso ocorra uma falha de alocação.

Exemplo:

```c
void	*duplicate_content(void *content)
{
	return (ft_strdup((char *)content));
}

t_list *new_list;

new_list = ft_lstmap(list, duplicate_content, del);
```

Neste caso, uma nova lista é criada contendo versões transformadas dos elementos da lista original, sem modificar a lista de origem.

## Resources

Durante o desenvolvimento deste projeto foram utilizadas diversas referências para consulta e aprofundamento dos conceitos da linguagem C e estruturas de dados.

### Documentação

* Linux Manual Pages (`man`)
* The Open Group Base Specifications
* GNU C Library Documentation
* C Reference

### Materiais de Estudo

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* Beej's Guide to C Programming
* Documentação oficial da 42 School

### Uso de Inteligência Artificial

Ferramentas de inteligência artificial foram utilizadas como apoio durante o processo de aprendizagem e desenvolvimento deste projeto para:

* Revisão de conceitos da linguagem C.
* Explicação de funções da biblioteca padrão.
* Esclarecimento de dúvidas sobre ponteiros e gerenciamento de memória.
* Compreensão de listas encadeadas.
* Revisão e melhoria da documentação presente neste README.

Todo o código foi implementado, testado e validado manualmente pelo autor do projeto.
