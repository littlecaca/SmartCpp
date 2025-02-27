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
#elif defined(LINKTIME) // 链接时打桩

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

#elif defined(RUNTIME)  // 运行时打桩

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// 包装函数wrapper functions
void *malloc(size_t size)   
{
    void *(*mallocp)(size_t size);
    char *error;

    mallocp = dlsym(RTLD_NEXT, "malloc"); /* Get the address of libc malloc */
    if ((error = dlerror()) != NULL)
    {
        fputs(error, stderr);
        exit(1);
    }
    char *ptr = mallocp(size);  /* Call libc malloc */
    printf("malloc(%d) = %p\n", (int)size, ptr);
    return ptr;
}

void free(void *ptr)
{
    void (*freep)(void *) = NULL;
    char *error;

    if (!ptr)
        return;

    freep = dlsym(RTLD_NEXT, "free");   /* Get the address of libc free */
    if ((error = dlerror()) != NULL)
    {
        fputs(error, stderr);   
        exit(1);
    }

    freep(ptr); /* Call libc free */
    printf("free(%p)\n", ptr);
}

#endif
