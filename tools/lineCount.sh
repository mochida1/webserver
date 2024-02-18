#!/bin/bash

# Initialize variables to store total line counts
total_cpp_lines=0
total_hpp_lines=0

# Find all .cpp and .hpp files and count lines
for file in $(find $(pwd) -type f \( -name "*.cpp" -o -name "*.hpp" \)); do
    lines=$(wc -l < "$file")
    if [[ $file == *.cpp ]]; then
        total_cpp_lines=$((total_cpp_lines + lines))
    elif [[ $file == *.hpp ]]; then
        total_hpp_lines=$((total_hpp_lines + lines))
    fi
done

# Display the total line counts
echo "Total lines in .cpp files: $total_cpp_lines"
echo "Total lines in .hpp files: $total_hpp_lines"