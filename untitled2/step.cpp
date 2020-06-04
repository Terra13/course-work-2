#include "step.h"

void Step::handler_1(char arr[10][10], int &row, int &col, int &num){
    arr[row][col] = 'F';
    if(num == 1) {
        row += 1;
    }
    else if (num == 2) {
        col += 1;
    }
    else {
        row -= 1;
    }
}
void Step::handler_2(char arr[10][10], int &row, int &col, int &num){
    num = -1;
}
