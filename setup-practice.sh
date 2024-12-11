#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Usage: $0 <chapter> <section>"
  exit 1
fi

CHAPTER=$1
SECTION=$2
PRACTICE_FOLDER="${CHAPTER}/${SECTION}"
mkdir -p "$PRACTICE_FOLDER"

cd "$PRACTICE_FOLDER"

cat > main.c <<EOL
#include <stdio.h>
#include <stdlib.h>

int main(void) {

//
  return 0;
}

EOL

echo "Setup completed."
