#include "finder_up.h"

bool Finder_up::find_up(char arr[10][10], int &row, int &col, int &num){
    if(arr[row - 1][col] == 1 && row != 0) {
        emit_signal(SIGNAL_D(signal_1), arr, row, col, 3);
    }
    else {
        emit_signal(SIGNAL_D(signal_2), arr, row, col, 3);
    }
}
