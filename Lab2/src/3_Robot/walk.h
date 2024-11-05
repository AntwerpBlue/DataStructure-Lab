#include <iostream>
#include <math.h>

#include <map>
#include <algorithm>
#include "queue.h"
#include "unordered_set.h"

namespace DATA_STRUCTURE {

class walk {
    public:
        walk() = default;
        walk(int _steps, int _gold_num, int* _gold, int* _gold_value) {
            steps = _steps;
            gold_num = _gold_num;
            gold = _gold;
            gold_value = _gold_value;
        }
        ~walk() = default;

        void print_para();
        int get_value();
    private:
        int gold_num = 0;
        int* gold;
        int* gold_value;
        int steps = 0;


        int distances[100][100]= {0};
        void buildgraph();
        int get_subvalue(bool* visited, int stepleft, int cur);

        struct element {
            int steps;
            int value;
            int x, y;
            unordered_set<int> get_gold;
        };
        queue<struct element> q;

        int compute_distance(int x1, int y1, int x2, int y2);
};

}