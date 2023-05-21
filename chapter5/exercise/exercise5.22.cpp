int get_size() {
    return 5;
}

int main(int argc, char const *argv[])
{   
    int sz;
    while ((sz = get_size()) <= 0)
        ;
    return 0;
}
