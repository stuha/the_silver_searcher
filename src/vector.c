
/* vector (dynamic array) */
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

static int vector_resize(vector *v, size_t new_size)
{
    void **new_data;
    size_t new_allocated;
    size_t allocated = v->cap;

    /* inspired by python */
    if (new_size <= allocated && new_size >= (allocated >> 1))
        return 0;

    new_allocated = (new_size >> 3) + (new_size < 9 ? 3 : 6);
    new_allocated += new_size;
    new_data = realloc(v->data, sizeof(void *) * new_allocated);
    if (!new_data) {
        /* do something here if needed */
        perror("realloc");
        return -1;
    }
    v->cap = new_allocated;
    v->data = new_data;
    return 0;
}

int vector_init(vector *v)
{
    v->size = 0;
    v->cap = 0;
    v->data = malloc(sizeof(void *) * v->cap);
    if (!v->data) {
        /* do something here if needed */
        perror("malloc");
        return -1;
    }
    return 0;
}

int vector_append(vector *v, void *data)
{
    size_t n = v->size;
    if (vector_resize(v, n+1) == -1)
        return -1;

    v->data[n] = data;
    v->size++;
    return 0;
}

void *vector_get(vector *v, size_t index)
{
    if (index >= v->size)
        return NULL;

    return v->data[index];
}

void vector_free(vector *v)
{
    free(v->data);
    v->data = NULL;
}
