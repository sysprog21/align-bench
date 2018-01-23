#include "align.h"
#include <string.h>
#include <stdio.h>

bool is_verbose = true;

int main(int argc, char **argv)
{
    int align[] = {0, 256, 1024, 4096};

    if ((argc > 1) && !strcmp(argv[1], "-v"))
        is_verbose = false;

    for (int b = 0; b < sizeof(align) / sizeof(int); b++) {
        if (is_verbose) {
            printf("\n================================================\n");
            printf("Memory allocating aligned in %d", align[b]);
            if (align[b] == 0)
                printf(" (malloc default)\n");
            else
                printf("\n");
            printf("================================================\n");
        }
        for (int shift = 0; shift < 8; shift++) {
            if (is_verbose) {
                if (shift == 0)
                    printf("\nAligned access\n");
                else
                    printf("\nUn-aligned in +%d bytes access\n", shift);
            }
            default_allocation8(shift, align[b]);
            default_allocation16(shift, align[b]);
            default_allocation32(shift, align[b]);
            default_allocation64(shift, align[b]);
        }
    }

    return 0;
}
