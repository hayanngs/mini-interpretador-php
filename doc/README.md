# Documentação do Mini Interpretador de PHP

Este interpretador aceita comandos para definir e acessar variáveis e o comando `echo`.

## Comandos Suportados

### 1. `echo`

**Descrição**: Exibe uma mensagem no terminal. O comando `echo` aceita strings e variáveis definidas pelo usuário. Para imprimir variáveis, utilize o prefixo `$` seguido do nome da variável, fora dos parenteses.


**Sintaxe**:
```plaintext
echo "mensagem de exemplo" $variavel " mais texto"
```

### 2. Definir Variável

**Descrição**: Declara um variável atribuindo um valor à ela, a variável não possui tipos, apenas guarda seu valor. É possível também re-atribuir um valor à variável já existente.

**Sintaxe**:
```plaintext
$var = valor
```

## Como Executar

Para executar o interpretador, basta seguir os passos abaixo:

### 1. Compilar o Interpretador

```bash
make
```

### 2. Executar o Interpretador

```bash
./mini-interpretador-php
```

Então você irá acessar o shell do interpretador podendo executar os comando suportados.


# Mensagens

## Erros Gerais

### 1. Invalid command
Descrição: acontece quando o comando não é reconhecido pelo interpretador, aparece uma mensagem de aviso no terminal.

### 2. Empty command
Descrição: acontece quando o comando é vazio, aparece uma mensagem de aviso no terminal.


## Comando `echo`

### 1. Invalid echo, message is empty
Descrição: erro acontece quando o comando `echo` não possui uma mensagem para exibir, esse erro encerra o interpretador.

### 2. Invalid echo, missing quote
Descrição: erro acontece quando o comando `echo` não possui aspas de abertura, esse erro encerra o interpretador.

### 3. Invalid echo, missing closing quote
Descrição: erro acontece quando o comando `echo` não possui aspas de fechamento, esse erro encerra o interpretador.


## Comando para definir variável

### 1. Invalid variable instanciation, missing '='
Descrição: erro acontece quando o comando não possui o sinal de igualdade para atribuir um valor à variável, esse erro encerra o interpretador.

### 2. Invalid variable instanciation, missing value
Descrição: erro acontece quando o comando não possui um valor para atribuir à variável, esse erro encerra o interpretador.

### 3. Invalid variable name
Descrição: erro acontece quando o nome da variável é inválido, o nome da variável deve começar com `$` seguido de caracteres alfanuméricos, esse erro encerra o interpretador.


## Autor

### Aluno: Hayann Gonçalves Silva
