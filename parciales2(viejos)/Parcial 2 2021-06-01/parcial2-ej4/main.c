#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "queue.h"

static bool is_left_delimiter(char c) {
    return (c == '(' || c == '[' || c == '{' || c == '<');
}

static bool is_right_delimiter(char c) {
    return (c == ')' || c == ']' || c == '}' || c == '>');
}

static bool is_delimeter(char c) {
    return is_left_delimiter(c) || is_right_delimiter(c);
}

static char match(char c) {
    char m;
    if (c == '(') {
        m = ')';
    } else if (c == '[') {
        m = ']';
    } else if (c == '{') {
        m = '}';
    } else if (c == '<') {
        m = '>';
    }
    return (m);
}

// static void print_help(char *program_name) {
//     /* Print the usage help of this program. */
//     printf("Usage: %s <expression-to-check>\n\n"
//            "Check if the expression has balanced delimeters (parenthesis, brackets, braces and <>).\n",
//            program_name);
// }

// static char* parse_expression(int argc, char *argv[]) {
//     /* Parse the expression given by command line argument. */
//     char *result=NULL;
//     /* Program takes exactly one argument */
//     if (argc != 2) {
//         print_help(argv[0]);
//         exit(EXIT_FAILURE);
//     }
//     /* Use the first argument ass the expression */
//     result = argv[1];
//     /* return expression */
//     return result;
// }

int main() { //int argc, char *argv[]
    stack s;
    bool balanced = true;
    char *expression=NULL;

    // Parse arguments and get the expression to be analysed
    expression= "{[(2 * 3) + 4] - (7* 8)} / 2";
    //parse_expression(argc, argv);

    queue delim_fifo = queue_empty(); // Cola de delimitadores
    /*
     * Completar: Crear una cola con todos los delimitadores de `expression`
     *
     */
    for (size_t i = 0; i < strlen(expression); i++) {
        if (is_delimeter(expression[i]))  {
            delim_fifo = queue_enqueue(delim_fifo, expression[i]);
        }
    }
    s = stack_empty();
    while (!queue_is_empty(delim_fifo) && balanced) {
        char delim ;
        delim =  queue_first(delim_fifo);
        delim_fifo = queue_dequeue(delim_fifo);
        /*
         * Completar: en `delim` debe estar el primer delimitador
         * de la cola. Luego de procesarlo se lo debe quitar de
         * `delim_fifo`.
         *
         */
        
        if (is_left_delimiter(delim)) {
            s = stack_push(s, match(delim));
        } else {
            assert(is_right_delimiter(delim));
            if (!stack_is_empty(s) && delim == stack_top(s)) {
                s = stack_pop(s);
            } else {
                balanced = false;
            }
        }
    }
    balanced = balanced && stack_is_empty(s);
    printf(balanced ? "la expresi??n est?? balanceada\n":"la expresi??n NO esta balanceada\n");
    s= stack_destroy(s);

    return 0;
}

