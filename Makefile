EXEC = bench

CC ?= gcc
CFLAGS = -Wall -std=gnu11 -O0 -g

OBJS = \
	byte.o half.o word.o double.o \
	util.o bench.o

deps := $(OBJS:%.o=.%.o.d)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ -MMD -MF .$@.d $<

plot: $(EXEC)
	bash scripts/plot.sh

GEN_PIX = read.png write.png
clean:
	$(RM) $(EXEC) $(OBJS) $(deps) $(GEN_PIX)

-include $(deps)
