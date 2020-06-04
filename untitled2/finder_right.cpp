#include "finder_right.h"

bool Finder_right::find_right(char arr[10][10], int &col, int &row, int &num){
    if(arr[row][col + 1] == 1 && col != 9) {
        emit_signal(SIGNAL_D(signal_1), arr, row, col, 2);
    }
    else {
        emit_signal(SIGNAL_D(signal_2), arr, row, col, 2);
    }
}
