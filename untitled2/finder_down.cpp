#include "finder_down.h"

bool Finder_down::find_down(char arr[10][10], int &col, int &row, int &num){
    if(arr[row + 1][col] == 1 && row != 9) {
        emit_signal(SIGNAL_D(signal_1), arr, row, col, 1);
    }
    else {
        emit_signal(SIGNAL_D(signal_2), arr, row, col, 1);
    }
}
