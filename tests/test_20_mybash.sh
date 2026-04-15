#!/bin/bash
cd ../exercises/20_mybash

gcc -c -Iinclude src/myfile/myfile.c -o test_20.o 2>/dev/null
cp bin/mybash test_20_mybash 2>/dev/null

cat > test_script.sh << 'SCRIPT'
myfile ./test_20.o
myfile ./test_20_mybash
mysed s/unix/linux/ "unix is opensource. unix is free os."
mytrans ./src/mytrans/text.txt
mywc ./src/mytrans/text.txt
SCRIPT

./bin/mybash test_script.sh 2>/dev/null

rm -f test_20.o test_20_mybash test_script.sh
