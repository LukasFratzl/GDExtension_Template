#!/bin/bash

# Define Godot path (modify if needed)
godot_path="/home/flow____/Downloads/Godot_v4.2.2-stable_linux.x86_64(1)/Godot_v4.2.2-stable_linux.x86_64"  # Replace with actual path

# Run scons
scons

# Check if scons build failed (exit code)
if [[ $? -ne 0 ]]; then
  echo "Error: scons build failed. Exiting..."
  exit 1
fi

## Store current directory (alternative to set "currentDir=%cd%")
#current_dir=$(pwd)
#
## Loop to search for Godot project
#while true; do
#  # Check for *.godot files
#  if [[ $(find "$PWD" -maxdepth 1  -type f -name "*.godot") ]]; then
#    echo "Found Godot project in $(pwd)."
#    break
#  fi
#
#  # Check if reached starting directory
#  if [[ $(pwd) == "/" ]]; then
#    echo "Godot project not found in any parent directories."
#    exit 1
#  fi
#
#  # Move up one directory
#  cd ..
#done
cd "godot-project"

# Launch Godot with project (assuming single project)
"$godot_path" -e

# Pop directory is not applicable in Bash (no directory stack)