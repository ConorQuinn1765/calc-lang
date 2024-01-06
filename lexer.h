#ifndef LEXER_H
#define LEXER_H
#include <stddef.h>

enum token_t {TOKEN_NUM, TOKEN_ADD, TOKEN_SUB, TOKEN_MUL, TOKEN_DIV,
                TOKEN_EXP, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_END};

enum token_t* lex(const char* input, size_t size);

#endif
