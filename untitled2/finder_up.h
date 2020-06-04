#ifndef FINDER_UP_H
#define FINDER_UP_H
#include <iostream>
#include "base.h"

using namespace std;

class Finder_up: public Base
{
public:
    bool find_up(char arr[10][10], int &row, int &col, int &num);
    static void signal_1(char arr[10][10], int &row, int &col, int &num);
    static void signal_2(char arr[10][10], int &row, int &col, int &num);
};

#endif // FINDER_UP_H
