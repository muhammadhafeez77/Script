#!/bin/zsh
#Exit immediately if a command exits with non-zero status

set -e

gcc -Wall -Wextra nix-script.c -o output

./output
