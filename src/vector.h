
#include <sys/types.h>

typedef struct vector {
    /* slots used so far */
    size_t size;
    /* total available slots */
    size_t cap;
    /* array of void * type data we're storing */
    void **data;
} vector;

#define VECTOR_SIZE(v) (v)->size
#define VECTOR_CAPACITY(v) (v)->cap
int vector_init(vector *v);
int vector_append(vector *v, void *data);
void *vector_get(vector *v, size_t index);
void vector_free(vector *v);
