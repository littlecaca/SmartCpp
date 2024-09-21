#include <stdio.h>

int test(int mat[10][10])
{
    mat[2][2] = 2;

    *(&mat[0] + 1)[0] = 3;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%d, ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int mat[10][10] = { 0 };
    test(mat);
    return 0;
}
