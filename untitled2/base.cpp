#include "base.h"

int Base::find_first(char arr[10][10]){
    int begin = 0, end = 0, flag = 0;
    for (int i = 0; i < 10; i++){
        if(arr[i][0] == 1){
            if(flag != -1) {
                begin = i;
                flag = -1;
            }
            end = i;
        }
    }
    if(arr[end][1] == 1 || end == begin) return begin;
    else return end;
}

void Base::main_cycle(){
    in = new Input();
    out = new Output();
    up = new Finder_up();
    down = new Finder_down();
    right = new Finder_right();
    one_step = new Step();
    in->input(arr);
    row = find_first(arr);

    set_connect(SIGNAL_D(signal_1), up, HANDLER_D(Finder_up::find_up));
    set_connect(SIGNAL_D(signal_1), down, HANDLER_D(Finder_down::find_down));
    set_connect(SIGNAL_D(signal_1), right, HANDLER_D(Finder_right::find_right));

    up->set_connect(SIGNAL_D(signal_1), one_step, HANDLER_D(Step::handler_1));
    up->set_connect(SIGNAL_D(signal_2), one_step, HANDLER_D(Step::handler_2));
    down->set_connect(SIGNAL_D(signal_1), one_step, HANDLER_D(Step::handler_1));
    down->set_connect(SIGNAL_D(signal_2), one_step, HANDLER_D(Step::handler_2));
    right->set_connect(SIGNAL_D(signal_1), one_step, HANDLER_D(Step::handler_1));
    right->set_connect(SIGNAL_D(signal_2), one_step, HANDLER_D(Step::handler_2));

    while(1){
        emit_signal(SIGNAL_D(signal_1), arr, col, row, num);
    }

    out->output(arr);
}
void Base::set_connect(TYPE_SIGNAL p_signal, Base* p_object,
    TYPE_HANDLER p_ob_handler)
{
    TYPE_SIGNAL p_key;
    o_sh* p_value;
    if (connects.size() > 0)
    {
        it_connects = connects.begin();
        while (it_connects != connects.end())
        {
            p_key = it_connects->first;
            p_value = it_connects->second;
            if ((p_key) == p_signal && (p_value->p_base) ==
                p_object && (p_value->p_handler) == p_ob_handler)
                return;
            it_connects++;
        }
    }
    p_value = new o_sh();
    p_value->p_base = p_object;
    p_value->p_handler = p_ob_handler;
    connects.insert({ p_signal, p_value });
}

void Base::emit_signal(TYPE_SIGNAL p_signal, char arr[10][10], int &row, int &col, int &num)
{
    TYPE_HANDLER p_handler;
    if (connects.empty()) return;
    if (connects.count(p_signal) == 0) return;
    (p_signal)(arr, row, col, num);
    it_connects = connects.begin();
    while (it_connects != connects.end())
    {
        if ((it_connects->first) == p_signal)
        {
            p_handler = it_connects->second->p_handler;
            Base* obj = it_connects->second ->p_base;
            (obj->*p_handler) (arr, row, col, num);
        }
        it_connects++;
    }
}
