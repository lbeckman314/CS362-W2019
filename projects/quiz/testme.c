#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    int random;
    char character;

    random = rand() % 127;
    character = (char) random;

    return character;
}

char *inputString()
{
    // TODO: rewrite this function
    int random;
    char *string;
    int size = 6;
    string = malloc(size * sizeof(char));
    //printf("size: %d\n", size);

    int pool[27];
    pool[0] = 0;

    int i;

    for (i = 1; i < 27; i++)
    {
        pool[i] = i + 96;

        //printf("adding %d to pool\n", i);
        //printf("pool: %d\n", pool[i]);
    }

    for (i = 0; i < size; i++)
    {
        /*
        random = rand() % size;
        switch (random)
        {
            case 0:
                string[i] = 'r';
                break;
            case 1:
                string[i] = 'e';
                break;
            case 2:
                string[i] = 's';
                break;
            case 3:
                string[i] = 'e';
                break;
            case 4:
                string[i] = 't';
                break;
            case 5:
                string[i] = '\0';
                break;
        }
        */
        string[i] = (char) pool[rand() % 27];
        //printf("pool: %d\n", pool[2]);
        //printf("string[i]: %c\n", string[i]);
    }

    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
