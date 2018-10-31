#include <stdio.h>
#include <stdlib.h>

struct Foo {
    int a;
    int b;
#ifndef __cplusplus
};
#endif

#ifdef __cplusplus

void test_func() 
#else
void test_func(struct Foo* this)
#endif
{
    this->a++;
    this->b += 2;
    printf("It works %d\n", this->a + this->b);
}

#ifdef __cplusplus
};
#endif


int main (int argc, char *argv[]) {
    struct Foo* test;
#ifdef __cplusplus
    printf("C++\n");
    test = new Foo();
    test->test_func();
    test->test_func();
    test->test_func();
#else
    test = malloc(sizeof(struct Foo));
    printf("C\n");
    test_func(test);
    test_func(test);
    test_func(test);
    free(test);
#endif
    return 0;
}
