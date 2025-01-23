#ifdef COMPILETIME  // 编译时打桩
#include <stdio.h>
#include <malloc.h>

// 包装函数wrapper functions
void *mymalloc(size_t size)
{
    void *ptr = malloc(size);
    printf("malloc(%d)=%p\n",
        (int)size, ptr);
    return ptr;
}

void myfree(void *ptr)
{
    free(ptr);
    printf("free(%p)\n", ptr);
}
#elif defined(LINKTIME)

#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

// 包装函数wrapper functions
void *__wrap_malloc(size_t size)
{
    void *ptr = __real_malloc(size);    /* Call libc malloc */
    printf("malloc(%d)= %p\n", (int)size, ptr);
    return ptr;
}

void __wrap_free(void *ptr)
{
    __real_free(ptr);   /* Call libc free */
    printf("free(%p)\n", ptr);
}

#endif
