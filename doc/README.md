# Documenta��o do Mini Interpretador de PHP

Este interpretador aceita comandos para definir e acessar vari�veis e o comando `echo`.

## Comandos Suportados

### 1. `echo`

**Descri��o**: Exibe uma mensagem no terminal. O comando `echo` aceita strings e vari�veis definidas pelo usu�rio. Para imprimir vari�veis, utilize o prefixo `$` seguido do nome da vari�vel, fora dos parenteses.


**Sintaxe**:
```plaintext
echo "mensagem de exemplo" $variavel " mais texto"
```

### 2. Definir Vari�vel

**Descri��o**: Declara um vari�vel atribuindo um valor � ela, a vari�vel n�o possui tipos, apenas guarda seu valor. � poss�vel tamb�m re-atribuir um valor � vari�vel j� existente.

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

Ent�o voc� ir� acessar o shell do interpretador podendo executar os comando suportados.


# Mensagens

## Erros Gerais

### 1. Invalid command
Descri��o: acontece quando o comando n�o � reconhecido pelo interpretador, aparece uma mensagem de aviso no terminal.

### 2. Empty command
Descri��o: acontece quando o comando � vazio, aparece uma mensagem de aviso no terminal.


## Comando `echo`

### 1. Invalid echo, message is empty
Descri��o: erro acontece quando o comando `echo` n�o possui uma mensagem para exibir, esse erro encerra o interpretador.

### 2. Invalid echo, missing quote
Descri��o: erro acontece quando o comando `echo` n�o possui aspas de abertura, esse erro encerra o interpretador.

### 3. Invalid echo, missing closing quote
Descri��o: erro acontece quando o comando `echo` n�o possui aspas de fechamento, esse erro encerra o interpretador.


## Comando para definir vari�vel

### 1. Invalid variable instanciation, missing '='
Descri��o: erro acontece quando o comando n�o possui o sinal de igualdade para atribuir um valor � vari�vel, esse erro encerra o interpretador.

### 2. Invalid variable instanciation, missing value
Descri��o: erro acontece quando o comando n�o possui um valor para atribuir � vari�vel, esse erro encerra o interpretador.

### 3. Invalid variable name
Descri��o: erro acontece quando o nome da vari�vel � inv�lido, o nome da vari�vel deve come�ar com `$` seguido de caracteres alfanum�ricos, esse erro encerra o interpretador.


## Autor

### Aluno: Hayann Gon�alves Silva
