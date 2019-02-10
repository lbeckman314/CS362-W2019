#ifndef MYASSERT_H
#define MYASSERT_H

#define myAssert(expression)                        \
    if (expression)                                 \
        (passed)(#expression, __LINE__, __FILE__ ); \
    else                                            \
        (failed)(#expression, __LINE__, __FILE__);  \

void failed(char *expression, int line, char *file);
void passed(char *expression, int line, char *file);

#endif
