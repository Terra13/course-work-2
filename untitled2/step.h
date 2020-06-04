#ifndef STEP_H
#define STEP_H
#include <iostream>
#include "base.h"

using namespace std;

class Step:public Base
{
    bool is_step = false;
public:
    void handler_1(char arr[10][10], int &row, int &col, int &num);
    void handler_2(char arr[10][10], int &row, int &col, int &num);
};

#endif // STEP_H
