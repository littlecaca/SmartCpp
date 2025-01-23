#include <stdio.h>
#include <stdint.h>

struct __attribute__ ((__packed__)) sdshdr32 {
    uint32_t len; /* used */
    uint32_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};

struct sdshdr32_no_packed {
    uint32_t len; /* used */
    uint32_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};

int main()
{
    // sizeof sdshdr32:9
    printf("sizeof sdshdr32:%lld\n", sizeof (struct sdshdr32));
    // sizeof sdshdr32_no_packed:12
    printf("sizeof sdshdr32_no_packed:%lld\n", sizeof (struct sdshdr32_no_packed));

    return 0;
}
