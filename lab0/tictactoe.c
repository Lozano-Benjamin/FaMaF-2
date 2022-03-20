#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)


char f_elem_row (int col, char board[BOARD_SIZE][BOARD_SIZE]);
char f_elem_col (int row, char board[BOARD_SIZE][BOARD_SIZE]);

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE]){
    board = board;
    char winner = '-';
    // IMPLEMENTAR
    for(int r=0; r<BOARD_SIZE; r++){
            //Revision por filas
            if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != '-' ){
                winner = board[r][0];
            }
            //Revision por columnas
            if (board[0][r] == board[1][r] && board[0][r] == board[2][r] && board[0][r] != '-'  ){
             winner = board[0][r];
            }
        }

    //Revision por diagonal izq a derecha
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board [0][0] != '-'){
        winner = board[0][0];
        //Revision por diagonal de derecha a izquierda
    }else if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2] != '-'){
        winner=board[0][2];
    }
    
    return winner;
}



bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;
    bool bool_ = false;
    // IMPLEMENTAR
    //Revisa si existe un elemento con '-'. Recorre toda la matriz y compara
    for(int i=0;i<BOARD_SIZE; i++ ){
        for(int j=0; j<BOARD_SIZE; j++){
            bool_ = bool_ || (board[i][j] == '-');
        }
    }

    return bool_;
    
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
