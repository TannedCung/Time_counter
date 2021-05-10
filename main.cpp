// #include <math>
#include "include/Time_count.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

Time_counter test_timer;
float a, b, c;
// char add_char[8];
// strcpy(add_char, "add"); 
// char mul_char[8];
// strcpy(mul_char, "mul"); 
std::chrono::seconds sec(1);

int main(int argc, const char *argv[]) {
    for (int i = 0; i <=5; i++){
        a = i+i;
        test_timer.tick((string)("add"));
        b = i*i;
        sleep(0.5);
        test_timer.tick((string)("mul"));
    }
    for (int i = 0; i <=10; i++){
        sleep(1);
        test_timer.tick((string)("div"));
    }

    auto ret_add = test_timer.tock((string)("add"));
    auto ret_mul = test_timer.tock((string)("mul"));
    auto ret_div = test_timer.tock((string)("div"));

    cout << "ret_add: " << ret_add << endl;
    cout << "ret_mul: " << ret_mul << endl;
    cout << "ret_div: " << ret_div << endl;

}

