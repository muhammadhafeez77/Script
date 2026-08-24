#!/bin/zsh
#Exit immediately if a command exits with non-zero status

set -e

g++ -Wall -Wextra nix-script.c -o output

./output
