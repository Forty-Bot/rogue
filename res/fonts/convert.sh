#!/bin/bash
# Rename argument 1
FILE="$1"
# Get the full path to the file
FILE_PATH=`dirname $(readlink -f "$FILE")`
# Get the full name of the file
FILE_NAME=`basename "$FILE"`
# Set the filename before the first . to NAME
NAME=`cut -d '.' -f1 <<< "$FILE_NAME"`
# If there is a second argument, use that; otherwise generate an output file name
if [ -n "$2" ]; then OUT_FILE="$2"; else OUT_FILE="$FILE_PATH/$NAME.h"; fi
# Set the include guard
GUARD="${NAME^^}_H"
# Create a temp dir
TMP_DIR=`mktemp -d`
# Split the font into pictures for each glyph
convert "$FILE" -crop "94x1-1-0@" +repage +adjoin "$TMP_DIR/%d-$NAME.xbm"
# Concatenate all the files into one
#ls "$TMP_DIR"/* | sort -zn | xargs cat | \
find "$TMP_DIR" -type f -print0 | sort -zn | xargs -0 cat | \
	# Remove everything but the data
	grep -v "#define" | grep -v "static" | sed 's/ };//g' | \
	# Add some array/header syntax to the beginning and end
	sed -e "1s/^/const unsigned char $NAME[] = {\n/" | sed -e "1s/^/#ifndef $GUARD\n#define $GUARD\n/g" | \
	sed -e '$a};' | sed -e '$a#endif' > \
	$OUT_FILE
# Cleanup
rm -rf "$TMP_DIR"
