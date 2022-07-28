#include "Director.c"
#include "Data.c"

struct Movie {
    char name[50];
    int length;
    char style[50];
    struct Director *director;
    struct Data *data;
};