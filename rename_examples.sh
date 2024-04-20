#!/bin/bash

# Function to process a file
process_file() {
    file="$1"
    
    # Check if the file is a .cpp file and its name starts with 't'
    if [[ "$file" == *.cpp && "$(basename "$file")" == t* ]]; then
        # Get the directory of the file
        dir=$(dirname "$file")
        
        # Get the base name of the file
        base=$(basename "$file")
        
        # Replace the first 't' with 'e'
        new_base="e${base:1}"
        
        # Rename the file
        mv "$file" "$dir/$new_base"
        echo "Renamed $base to $new_base"
    fi
}

# Function to process a directory
process_directory() {
    dir="$1"
    
    # If the directory is named "examples", process all .cpp files in it
    if [[ "$(basename "$dir")" == "examples" ]]; then
        for file in "$dir"/*.cpp; do
            process_file "$file"
        done
    fi
    
    # Recursively process all subdirectories
    for subdir in "$dir"/*/; do
        if [[ -d "$subdir" ]]; then
            process_directory "$subdir"
        fi
    done
}

# Get the directory of the script
script_dir=$(dirname "$0")

# Process the script directory and all its subdirectories
process_directory "$script_dir"

echo "Renaming completed."

