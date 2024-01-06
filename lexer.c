#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "lexer.h"

#define TOKEN_BUF_LEN 512

bool iswhitespace(char c);

enum token_t* lex(const char* input, size_t size)
{
    enum token_t* tokens = calloc(sizeof(enum token_t), TOKEN_BUF_LEN);
    if(!tokens)
        return NULL;

    unsigned int tokenCount = 0;
    for(int i = 0; i < size; i++) {
        switch(input[i]) {
        case '+':
            tokens[tokenCount++] = TOKEN_ADD;
            break;
        case '-':
            tokens[tokenCount++] = TOKEN_SUB;
            break;
        case '*':
            tokens[tokenCount++] = TOKEN_MUL;
            break;
        case '/':
            tokens[tokenCount++] = TOKEN_DIV;
            break;
        case '^':
            tokens[tokenCount++] = TOKEN_EXP;
            break;
        case '(':
            tokens[tokenCount++] = TOKEN_LPAREN;
            break;
        case ')':
            tokens[tokenCount++] = TOKEN_RPAREN;
            break;
        case '\n':
            tokens[tokenCount++] = TOKEN_END;
            break;
        default:
            if(!isdigit(input[i])) {
                if(!iswhitespace(input[i])) {
                    free(tokens);
                    return NULL;
                }
            } else {
                while(isdigit(input[i++]));
                i -= 2;
                tokens[tokenCount++] = TOKEN_NUM;
            }
            break;
        }
    }

    tokens[tokenCount] = TOKEN_END;
    return tokens;
}

bool iswhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\0';
}
