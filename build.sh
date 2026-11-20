#!/bin/bash

gcc -Wall -Wextra \
    -I../myutils/include \
    random_walk.c \
    -o program
