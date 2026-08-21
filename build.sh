#!/usr/bin/env bash

set -e

bear -- clang \
  $NIX_CFLAGS_COMPILE \
  -std=c17 \
  -lm \
  main.c \
  -o gpa-calculator.out
