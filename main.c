#include <stdio.h>
#include "lexer.h"

int main(void) {
    char buf[] = "1 + 22 - 333 * 4444 / 55555 ^ 666666 ( 7777777 )";
    enum token_t* tokens = lex(buf, sizeof(buf));

    char* tokenNames[] = {"TOKEN_NUM", "TOKEN_ADD", "TOKEN_SUB", "TOKEN_MUL", "TOKEN_DIV",
                "TOKEN_EXP", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_END"};

    int i = 0;
    while(tokens[i] != TOKEN_END) {
        printf("%s\n", tokenNames[tokens[i]]);
        i++;
    }

    return 0;
}
