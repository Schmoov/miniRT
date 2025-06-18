#!/bin/bash

output_file="random_numbers.txt"

# Clear the file if it exists
> "$output_file"

# Generate 256 lines
for ((i = 0; i < 256; i++)); do
    line=""
    for ((j = 0; j < 256; j++)); do
        num=$((RANDOM % 256))
        line+="$num "
    done
    echo "${line::-1}" >> "$output_file"  # Remove trailing space
done

echo "File '$output_file' created with 256x256 random numbers."
