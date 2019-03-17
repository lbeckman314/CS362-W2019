#include "myAssert.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // getCost function

    // false, should fail
    // myAssert(1 == 0);    

    // true, should pass
    // myAssert(1 == 1);    

    // curse
    myAssert(getCost(0) == 0);
    
    // estate
    myAssert(getCost(1) == 2);
    
    // duchy
    myAssert(getCost(2) == 5);
    
    // province
    myAssert(getCost(3) == 8);
    
    // copper
    myAssert(getCost(4) == 0);
}
