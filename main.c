#include "FuncionesExpresion.h"
#include "abin.h"
#include "recorridos.h"
#include <stdio.h>
#include <stdlib.h>

#define EXPR_MAXLEN 100

int
main(int argc, char *argv[])
{
    char *expr;
    char  buff[EXPR_MAXLEN];

    if (argc == 2)
        expr = argv[1];

    else
    {
        expr = buff;
        printf("Expr >> ");
        scanf("%s", buff);
    }

    abin arbol = arbolExpresion(expr);
    preorden(arbol);
    putchar('\n');
    postorden(arbol);
    putchar('\n');

    return EXIT_SUCCESS;
}
