#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std::chrono;
using namespace std;

struct Timer{
    double total;
    time_point<std::chrono::high_resolution_clock> last;
    string name;
};

class Time_counter {
    public:
        void tick(string name) {
            auto it = find_if(timer_list.begin(), timer_list.end(), [&name](const Timer& obj) {return obj.name == name;});
            int index = distance( timer_list.begin(), it );
            if (index >= timer_list.size())
            {
                Timer new_timer;
                auto this_time = std::chrono::high_resolution_clock::now();
                new_timer.name = name;
                timer_list.push_back(new_timer);
                timer_list[index].last = this_time;
            }  
            else{
                auto this_time = std::chrono::high_resolution_clock::now();
                auto int_ms = this_time - timer_list[index].last;
                timer_list[index].total += int_ms.count();
                timer_list[index].last = this_time;
            }
        }

        double tock(string name) {
            auto it = find_if(timer_list.begin(), timer_list.end(), [&name](const Timer& obj) {return obj.name == name;});
            int index = distance( timer_list.begin(), it );
            if (index >= timer_list.size()) throw "no timer with this name";
            else return timer_list[index].total;
        }

    private:
        vector<Timer> timer_list;

};