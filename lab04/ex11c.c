#include <stdlib.h>

struct vector {
    int x;
    int y;
};

typedef struct vector* Vector;




int main(int argc, char const *argv[])
{
    Vector v = malloc(sizeof(struct vector));


    return 0;
}
