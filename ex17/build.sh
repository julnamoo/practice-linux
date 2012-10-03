#!/bin/sh
gcc main.c -o cvx `pkg-config gtk+-2.0 --cflags --libs`
./cvx
