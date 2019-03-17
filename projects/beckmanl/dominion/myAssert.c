#include "myAssert.h"
#include "color.h"
#include <stdio.h>
#include "dominion_helpers.h"

void passed(char *expression, int line, char *file, int color)
{
    if (color)
        printf("%s%s", boldon, green);

    printf("%s:%d TEST SUCCESSFULLY COMPLETED -> %s\n", file, line, expression);

    if (color)
        printf("%s%s", normal, boldoff);
}

void failed(char *expression, int line, char *file, int color)
{
    if (color)
        printf("%s%s", boldon, red);

    printf("%s:%d TEST FAILED: -> %s\n", file, line, expression);

    if (color)
        printf("%s%s", normal, boldoff);
}
