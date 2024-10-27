/*
 * Autor: Hayann Goncalves Silva
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define DEFAULT_VALUE 50

#define INFO 0
#define ERROR 1
#define DEFAULT 2

typedef struct
{
    char type[DEFAULT_VALUE];
    char value[MAX_LINE_LENGTH];
} Token;

typedef struct
{
    char name[DEFAULT_VALUE];
    char value[DEFAULT_VALUE];
} Variable;

Variable variables[DEFAULT_VALUE];
int var_count = 0;

void LOGGER(int level, char* message, int code)
{
    switch (level)
    {
    case INFO:
        {
            printf("[INFO] %s\n", message);
        }
        break;
    case ERROR:
        {
            printf("[ERROR] %s\n", message);
            exit(code);
        }
    default:
        {
            printf("%s\n", message);
        }
    }
}

char* get_variable_value(const char* name)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0)
        {
            return variables[i].value;
        }
    }
    return "NULL";
}

void set_variable(const char* name, const char* value)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0)
        {
            strcpy(variables[i].value, value);
            return;
        }
    }
    strcpy(variables[var_count].name, name);
    strcpy(variables[var_count].value, value);
    var_count++;
}

int variable_exists(const char* name)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int is_variable(Token token)
{
    return token.type[0] == '$';
}

int is_echo(Token token)
{
    return strcmp(token.type, "echo") == 0;
}

void execute_echo()
{
    const char* full_echo_value = strtok(NULL, "\n");
    if (full_echo_value == NULL)
    {
        LOGGER(ERROR, "Invalid echo, message is empty", 1);
    }

    while (isspace(*full_echo_value)) full_echo_value++;

    char output[DEFAULT_VALUE] = "";

    while (*full_echo_value != '\0')
    {
        if (*full_echo_value == '$')
        {
            full_echo_value++;
            char var_name[DEFAULT_VALUE] = "$";
            int i = 1;
            while (isalnum(*full_echo_value) && i < DEFAULT_VALUE - 1)
            {
                var_name[i++] = *full_echo_value;
                full_echo_value++;
            }
            var_name[i] = '\0';

            strcat(output, get_variable_value(var_name));
        }
        else if (*full_echo_value == '"')
        {
            full_echo_value++;
            while (*full_echo_value != '"' && *full_echo_value != '\0')
            {
                strncat(output, full_echo_value, 1);
                full_echo_value++;
            }
            if (*full_echo_value == '"')
            {
                full_echo_value++;
            }
            else
            {
                LOGGER(ERROR, "Invalid echo, missing closing quote", 1);
            }
        }
        else
        {
            if (*full_echo_value == ' ')
            {
                full_echo_value++;
            }
            else
            {
                LOGGER(ERROR, "Invalid echo, missing quote", 1);
            }
        }
    }

    LOGGER(DEFAULT, output, 0);
}

void execute_variable(char* name)
{
    if (strlen(name) == 1 || (strlen(name) > 1 && !isalpha(name[1])))
    {
        LOGGER(ERROR, "Invalid variable name", 1);
    }

    const char* token = strtok(NULL, " ");

    if (token == NULL || *token != '=')
    {
        LOGGER(ERROR, "Invalid variable instanciation, missing \'=\'", 1);
    }

    token = strtok(NULL, " ");

    if (token == NULL)
    {
        LOGGER(ERROR, "Invalid variable assigment, missing value", 1);
    }

    set_variable(name, token);
}

void parse_and_execute(char* line)
{
    const char* token = strtok(line, " ");

    if (token == NULL)
    {
        LOGGER(INFO, "Empty command", 0);
        return;
    }

    Token currentToken;
    strcpy(currentToken.type, token);

    if (is_echo(currentToken))
    {
        execute_echo();
        return;
    }
    if (is_variable(currentToken))
    {
        execute_variable(currentToken.type);
        return;
    }
    LOGGER(INFO, "Invalid command", 0);
}

int main()
{
    char line[MAX_LINE_LENGTH];

    while (1)
    {
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0)
        {
            break;
        }

        parse_and_execute(line);
    }

    return 0;
}
