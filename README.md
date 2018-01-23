# Microbenchmark for unaligned memory access

Perform read/write on different types of memory addresses in order to measure
time of each operation with certain memory allocation.

The bench program allocates a memory block aligned in default, 256, 1024 and
4096 bytes. Then, it writes byte, half word, word and double word on this
block. It writes on aligned and then starts to write on unaligned address and
measure the timing.
