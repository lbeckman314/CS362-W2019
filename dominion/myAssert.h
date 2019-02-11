#ifndef MYASSERT_H
#define MYASSERT_H

#define myAssert(expression)                          \
    if (expression)                                   \
        (passed)(#expression, __LINE__, __FILE__, 0); \
    else                                              \
        (failed)(#expression, __LINE__, __FILE__, 0); \

void failed(char *expression, int line, char *file, int color);
void passed(char *expression, int line, char *file, int color);

#endif
