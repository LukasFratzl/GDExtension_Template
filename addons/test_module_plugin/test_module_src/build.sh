#!/bin/bash

# Run scons
scons

# Check if scons build failed (exit code)
if [[ $? -ne 0 ]]; then
  echo "Error: scons build failed. Exiting..."
  exit 1
fi