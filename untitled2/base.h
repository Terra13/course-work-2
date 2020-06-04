#ifndef BASE_H
#define BASE_H

#define SIGNAL_D(signal_f) (TYPE_SIGNAL) (& signal_f)
#define HANDLER_D(handler_f) (TYPE_HANDLER)(&handler_f)

#include "input.h"
#include "output.h"
#include "finder_up.h"
#include "finder_down.h"
#include "finder_right.h"
#include "step.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Base;
typedef void (*TYPE_SIGNAL)(char arr[10][10], int &row, int &col, int &num);
typedef void (Base ::* TYPE_HANDLER)(char arr[10][10], int &row, int &col, int &num);

class Base{
public:
    char arr[10][10];
    int col, row, num;
    Input* in;
    Output* out;
    Finder_up* up;
    Finder_down* down;
    Finder_right* right;
    Step* one_step;
    static void signal_1(char arr[10][10], int &row, int &col, int &num){};
    static void signal_2(char arr[10][10], int &row, int &col, int &num){};
    int find_first(char arr[10][10]);
    void main_cycle();

    void set_connect(TYPE_SIGNAL p_signal, Base* p_object, TYPE_HANDLER p_ob_handler);
    void emit_signal(TYPE_SIGNAL p_signal, char arr[10][10], int &row, int &col, int &num);
    struct o_sh {
        Base* p_base;
        TYPE_HANDLER p_handler;
    };
    multimap <TYPE_SIGNAL, o_sh*> connects;
    multimap <TYPE_SIGNAL, o_sh*> ::iterator it_connects;
};

#endif // BASE_H
