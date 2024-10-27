# Exemplos

## Casos de Sucesso

### Exibir uma Mensagem com echo

```plaintext
> echo "Hello, world!"
Hello, world!
```


### Exibir uma Mensagem com Vari�vel

```plaintext
> $name = "Maria"
> echo "Hello, " $name "!"
Hello, Maria!
```


### Definir e Redefinir uma Vari�vel

```plaintext
> $age = 30
> echo "Idade inicial: " $age
Idade inicial: 30

> $age = 31
> echo "Nova idade: " $age
Nova idade: 31
```

## Casos de Erro

### Comando Inv�lido

```plaintext
> eho "Hello, world!"
[INFO] Invalid command
```

### Comando Vazio

```plaintext
> 
[INFO] Empty command
```


### Comando `echo` com mensagem vazia

```plaintext
> echo
[ERROR] Invalid echo, message is empty
```

### Comando `echo` sem Aspas de Abertura

```plaintext
> echo Hello, world!"
[ERROR] Invalid echo, missing quote
```

### Comando `echo` sem Aspas de Fechamento

```plaintext
> echo "Hello, world!
[ERROR] Invalid echo, missing closing quote
```

### Comando para Definir Vari�vel sem `=`

```plaintext
> $name "Maria"
[ERROR] Invalid variable instantiation, missing '='
```

### Comando para Definir Vari�vel sem Valor

```plaintext
> $name = 
[ERROR] Invalid variable instantiation, missing value
```

### Comando para Definir Vari�vel com Nome Inv�lido

```plaintext
> $1
[ERROR] Invalid variable name
```

```plaintext
> $
[ERROR] Invalid variable name
```
