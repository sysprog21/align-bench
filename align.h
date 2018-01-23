#ifndef BENCH_ALIGN_H
#define BENCH_ALIGN_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>

/* Times that a loop repeats */
#define MAX 128
#define BUFFER_SIZE 4096 * 1024

extern void default_allocation8(int shift, int align);
extern void default_allocation16(int shift, int align);
extern void default_allocation32(int shift, int align);
extern void default_allocation64(int shift, int align);

static inline uint8_t *alloc(int shift, int aligned)
{
    if (aligned == 0) {
        /* Allocating a bit extra to try unaligned */
        return malloc((BUFFER_SIZE + shift) * sizeof(uint8_t)) + shift;
    }
    return aligned_alloc(aligned, (BUFFER_SIZE + shift) * sizeof(uint8_t)) +
           shift;
}

static inline time_t measure(void (*func)(uint8_t *), uint8_t *buf)
{
    clock_t begin = clock();
    func(buf);
    clock_t end = clock();
    return end - begin;
}

extern void print(bool is_read, int word, int shift, int align, clock_t diff);

#endif
