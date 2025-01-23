#include <stdio.h>


struct _hdr
{
    unsigned char opcode : 4,
                  rsv3 : 1,
                  rsv2 : 1,
                  rsv1 : 1,
                  fin : 1;

    unsigned char load : 7,
                  mask : 1;
};

typedef struct _hdr hdr;



int main(int argc, char const *argv[])
{

    hdr data;
    data.fin = 1;
    data.rsv3 = 1;
    data.load = 126;
    printf("%2x\t", data.opcode);
    printf("%2x\t", data.rsv3);
    printf("%2x\t", data.rsv2);
    printf("%2x\t", data.rsv1);
    printf("%2x\t", data.fin);
    printf("%2x\t", data.load & 0x7F);
    printf("%2x\t", data.mask & 0x7F);
    fflush(stdout);
    return 0;
}
