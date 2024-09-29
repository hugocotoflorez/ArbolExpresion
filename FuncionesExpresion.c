#include "abin.h"
#include "pilaOperadores.h"
#include "pilaOperandos.h"

// Devuelve la prioridad del operador dentro de la pila.
// Prioridad('(')=0
int
prioridadDentro(char op)
{
    int prior;
    switch (op)
    {
        case '^':
            prior = 3;
            break;
        case '*':
        case '/':
            prior = 2;
            break;
        case '+':
        case '-':
            prior = 1;
            break;
        case '(':
            prior = 0; // nunca va a entrar en la pila, provoca vaciado
            break;
    }
    return prior;
}

// Devuelve la prioridad del operador fuera de la pila.
// Prioridad('(')=4
int
prioridadFuera(char op)
{
    int prior;
    switch (op)
    {
        case '^':
            prior = 3;
            break;
        case '*':
        case '/':
            prior = 2;
            break;
        case '+':
        case '-':
            prior = 1;
            break;
        case '(':
            prior = 4; // para que SIEMPRE entre en la pila
            break;
    }
    return prior;
}

// Devuelve 1 si c es un operador: +, -, /, *, ^, ()
unsigned
esOperador(char c)
{
    switch (c)
    {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
            return 1;
            break;
        default:
            return 0;
    }
}

// Devuelve 1 si c es un operando: mayúsculas y minúsculas
// completar para caracteres 0 a 9
unsigned
esOperando(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void
insertar_subarbol(pilaOperadores *operadores, pilaOperandos *operandos)
{
    abin aux;
    crear(&aux);
    insder(&aux, topeOperadores(*operadores));
    popOperadores(operadores);
    insArbolder(&aux, topeOperandos(*operandos));
    popOperandos(operandos);
    insArbolizq(&aux, topeOperandos(*operandos));
    popOperandos(operandos);
    pushOperandos(operandos, aux);
}


// Recibe una cadena de caracteres y devuelve el arbol de expresion
// DEBES ESCRIBIR ESTA FUNCIÓN
abin
arbolExpresion(char *expr_infija)
{
    pilaOperandos  operandos;
    pilaOperadores operadores;
    abin           arbol;
    char          *c;

    crearPilaOperandos(&operandos);
    crearPilaOperadores(&operadores);

    c = expr_infija;

    while (*c)
    {
        if (esOperando(*c)) // es un numero
        {
            crear(&arbol);
            insder(&arbol, *c);
            pushOperandos(&operandos, arbol);
        }

        else if (esOperador(*c)) // es un operador
        {
            while (!esVaciaPilaOperadores(operadores) &&
                   prioridadFuera(*c) <= prioridadDentro(topeOperadores(operadores)))
            {
                insertar_subarbol(&operadores, &operandos);
            }
            pushOperadores(&operadores, *c);
        }

        else if (*c == ')')
        {
            while (topeOperadores(operadores) != '(')
            {
                insertar_subarbol(&operadores, &operandos);
            }
            popOperadores(&operadores);
        }
        ++c;
    }

    while (!esVaciaPilaOperadores(operadores))
    {
        insertar_subarbol(&operadores, &operandos);
    }

    destruirPilaOperadores(&operadores);
    arbol = topeOperandos(operandos);
    destruirPilaOperandos(&operandos);

    return arbol;
}
