#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf jmp_points[512];
int jmp_counter = 0;

#define cat_timp(cond, block) { \
    jmp_buf *buffer = &jmp_points[jmp_counter++]; \
    size_t _ = (size_t) setjmp(*buffer); \
    if (cond) { \
        block \
        longjmp(*buffer, 0); \
    } \
    jmp_counter--; \
    }


int main() {
    int i = 0;

    cat_timp(i < 10, {
        printf("%d\n", i);
        i++;        
    })

    i = 0;
    cat_timp(i < 10, {
        printf("%d\n", i);
        i++;        
    })

    i = 0;
    cat_timp(i < 10, {
        printf("%d\n", i);
        i++;        
    })

    return 0;
}
