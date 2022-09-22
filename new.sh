#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: ./new.sh <project_name>"
    echo "      project_name: <id>-<name>, e.g. \"1.1-rearrange-string\"."
    exit 1
fi

project_name=$1

# create project dir
mkdir $project_name
# create main.c
cat > $project_name/main.c <<EOF
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    return EXIT_SUCCESS;
}
EOF
# add build item into makefile
ch=$(echo "$project_name" | awk -F '-' '{print $1}')
cat >> Makefile <<EOF

$ch: init
	@gcc $project_name/main.c -o \$(BUILD_DIR)/\$(DEAFULT_OUTPUT_FILE)
	\$(call run_user_application,\$(DEAFULT_OUTPUT_FILE))
EOF
