#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Token {
    int row;
    int col;
    char type[20];
    char value[100];
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '>' || c == '<' || c == '=' || c == '&' || c == '|');
}

int isSpecialSymbol(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',' || c == '[' || c == ']');
}

int isKeyword(char *word) {
    char keywords[][10] = {"int", "float", "if", "else", "while", "for", "do", "switch", "case"};
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isNumber(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isdigit(word[i]) && word[i] != '.') {
            return 0;
        }
    }
    return 1;
}

int isStringLiteral(char *word) {
    if (word[0] == '"' && word[strlen(word) - 1] == '"') {
        return 1;
    }
    return 0;
}

int isIdentifier(char *word) {
    if (isalpha(word[0]) || word[0] == '_') {
        for (int i = 1; word[i] != '\0'; i++) {
            if (!isalnum(word[i]) && word[i] != '_') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

struct Token getNextToken(FILE *fp, int *row, int *col) {
    char c;
    char buffer[100];
    struct Token token;

    token.row = *row;
    token.col = *col;

    c = fgetc(fp);
    while (isspace(c)) {
        if (c == '\n') {
            (*row)++;
            *col = 1;
        } else {
            (*col)++;
        }
        c = fgetc(fp);
    }

    if (c == EOF) {
        strcpy(token.type, "EOF");
        strcpy(token.value, "");
        return token;
    }

    buffer[0] = c;
    buffer[1] = '\0';

    if (isOperator(c)) {
        strcpy(token.type, "Operator");
    } else if (isSpecialSymbol(c)) {
        strcpy(token.type, "Special Symbol");
    } else {
        while (!isspace(c) && !isOperator(c) && !isSpecialSymbol(c) && c != EOF) {
            c = fgetc(fp);
            (*col)++;
            if (!isspace(c) && !isOperator(c) && !isSpecialSymbol(c) && c != EOF) {
                strncat(buffer, &c, 1);
            }
        }

        if (isKeyword(buffer)) {
            strcpy(token.type, "Keyword");
        } else if (isNumber(buffer)) {
            strcpy(token.type, "Number");
        } else if (isStringLiteral(buffer)) {
            strcpy(token.type, "String Literal");
        } else if (isIdentifier(buffer)) {
            strcpy(token.type, "Identifier");
        } else {
            strcpy(token.type, "Invalid");
        }
    }

    strcpy(token.value, buffer);

    return token;
}

int main() {
    FILE *fp = fopen("test.c", "r");
    
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(0);
    }

    int row = 1;
    int col = 1;
    
    while (!feof(fp)) {
        struct Token token = getNextToken(fp, &row, &col);
        printf("Row: %d, Col: %d, Type: %s, Value: %s\n", token.row, token.col, token.type, token.value);
    }

    fclose(fp);
    return 0;
}
