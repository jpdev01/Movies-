#include "Director.c"
#include "Data.c"

struct Movie {
    char *name;
    int length;
    char *style;
    struct Director director;
    struct Data data;
};