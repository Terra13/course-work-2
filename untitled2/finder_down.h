#ifndef FINDER_DOWN_H
#define FINDER_DOWN_H
#include <iostream>
#include "base.h"

using namespace std;

class Finder_down: public Base{
public:
    bool find_down(char arr[10][10], int &row, int &col, int &num);
    static void signal_1(char arr[10][10], int &row, int &col, int &num);
    static void signal_2(char arr[10][10], int &row, int &col, int &num);
};

#endif // FINDER_DOWN_H
