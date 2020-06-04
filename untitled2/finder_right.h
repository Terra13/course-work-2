#ifndef FINDER_RIGHT_H
#define FINDER_RIGHT_H
#include <iostream>
#include "base.h"

using namespace std;

class Finder_right: public Base
{
public:
    bool find_right(char arr[10][10], int &row, int &col, int &num);
    static void signal_1(char arr[10][10], int &row, int &col, int &num);
    static void signal_2(char arr[10][10], int &row, int &col, int &num);
};

#endif // FINDER_RIGHT_H
