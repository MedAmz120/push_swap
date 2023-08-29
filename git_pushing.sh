#!/bin/bash

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "--------> Error :Usage: $0 <commit_message>"
    exit 1
fi

# Commands
git add *
git commit -m "$1"
git push

