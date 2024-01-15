
int main() {
    int fact(int);
    fact(10);
    return 0;
}


int fact(int m) {
    int sum = 1;
    while (m > 1)
        sum *= m--;
    return sum;
}