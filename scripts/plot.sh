#!/bin/bash

OUTPUT=$(mktemp /tmp/align-bench.XXXXXX)
WRITE="tmp_write"
READ="tmp_read"

echo "Benchmarking memory access (* be patient *)"
./bench -v > $OUTPUT

echo "Processing..."
cat $OUTPUT | grep 0\| | grep write > $WRITE
cat $OUTPUT | grep 0\| | grep \read > $READ

# Add a new gnuplot index after 4 lines
awk ' {print $4 " " $5;} NR % 4 == 0 { print "\n"; }' $WRITE > $WRITE.tmp
awk ' {print $4 " " $5;} NR % 4 == 0 { print "\n"; }' $READ > $READ.tmp

gnuplot -c scripts/write.gp $WRITE.tmp
gnuplot -c scripts/read.gp $READ.tmp

echo "Done!"
rm $OUTPUT
rm $WRITE $WRITE.tmp $READ $READ.tmp
