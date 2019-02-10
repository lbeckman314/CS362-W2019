#include "myAssert.h"
#include "color.h"
#include <stdio.h>
#include "dominion_helpers.h"

void passed(char *expression, int line, char *file)
{
    printf("%s%s%s:%d TEST SUCCESSFULLY COMPLETED -> %s%s%s\n", boldon, green, file, line, expression, normal, boldoff);
}

void failed(char *expression, int line, char *file)
{
    printf("%s%s%s:%d TEST FAILED: -> %s%s%s\n", boldon, red, file, line, expression, normal, boldoff);
}
