#! /bin/bash

for filename in build/Debug/*; do
  echo "Executing $filename";
  if [[ $filename == "build/Debug/bookstore" ]]; then
    ./$filename < ./src/input.txt
  else
    ./$filename
  fi
done

