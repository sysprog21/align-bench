#include "align.h"
#include <stdlib.h>

void write8(uint8_t *ptr)
{
    for (int i = 0; i < MAX; i++)
        for (int z = 0; z < BUFFER_SIZE; z++) {
            ptr[z] = (i) % 0xff;
        }
}

void read8(uint8_t *ptr)
{
    uint8_t w = 0;
    int i;

    for (i = 0; i < MAX; i++)
        for (int z = 0; z < BUFFER_SIZE; z++) {
            w = ptr[z];
        }

    /* suppress compiler warnings */
    i = w;
}

void default_allocation8(int shift, int align)
{
    uint8_t *ptr;
    clock_t diff;

    ptr = alloc(shift, align);

    diff = measure(&write8, ptr);
    print(false, 1, shift, align, diff);

    diff = measure(&read8, ptr);
    print(true, 1, shift, align, diff);

    free(ptr - shift);
}
