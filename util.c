#include "align.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern bool is_verbose;

static void print_verbose(bool read, int word, int shift, int align, clock_t ms)
{
    char s[12];

    switch (word) {
    case 1:
        strcpy(s, " byte");
        break;
    case 2:
        strcpy(s, " half");
        break;
    case 4:
        strcpy(s, " word");
        break;
    case 8:
        strcpy(s, "dword");
        break;
    default:
        printf("Wrong size usage\n");
        exit(-1);
    }

    if (read) {
        printf("    Read  [%s] :\t%Lf ms\n", s,
               (long double) ms / (1000 * 1000));
    } else {
        printf("    Write [%s] :\t%Lf ms\n", s,
               (long double) ms / (1000 * 1000));
    }
}

static void print_internal(bool is_read,
                           int word,
                           int shift,
                           int align,
                           clock_t ms)
{
    printf("%d| ", align);
    printf("%d: ", shift);

    printf(is_read ? "read " : "write ");

    printf("%d %Lf\n", word, (long double) ms / (1000 * 1000));
}

void print(bool read, int word, int shift, int align, clock_t ms)
{
    if (is_verbose)
        print_verbose(read, word, shift, align, ms);
    else
        print_internal(read, word, shift, align, ms);
}
