#!/bin/bash

module_name="TestModule"
godot_path="/home/flow____/.steam/debian-installation/steamapps/common/Godot Engine/godot.x11.opt.tools.64"

# Navigate to TestModule directory
cd "$module_name"

# Run scons to build the project
scons

# Check if the build failed (exit code of scons is non-zero)
if [[ $? -ne 0 ]]; then
  echo "Error: scons build failed. Exiting..."
  exit 1
fi

# Wait for a few seconds to ensure the build is complete
sleep 1

# Navigate back to the previous directory (parent of module_Name)
cd ..

# Start the Godot editor
"$godot_path" godot -e