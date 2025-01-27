#!/bin/bash

gcc -c -fPIC *.c

gcc -shared -o liball.so *.o

rm *.o

echo "Dynamic library liball.so has been created."
