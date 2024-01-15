#include "fact.h"

int fact(int num) {
    int sum = 1;
    while (num > 1) {
        sum *= num--;
    }
    return sum;
}