#include "myAssert.h"
#include "dominion.c"
#include <stdio.h>

int main(int argc, char* argv[])
{
    int test1 = 1;
    int test2 = 2;
    int *a = &test1;
    int *b = &test2;

    myAssert(compare(b, a) == 1);
    myAssert(compare(a, b) == -1);
    myAssert(compare(a, a) == 0);
    myAssert(compare(b, b) == 0);
}
