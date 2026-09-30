#!/usr/bin/sh

BUILD_DIR='build/'
NINJA_FILE="${BUILD_DIR}build.ninja"
SOURCES=src/*.c

set -ex

mkdir -p $BUILD_DIR
echo 'rule cc' > $NINJA_FILE
echo '  command = gcc -c $in -o $out' >> $NINJA_FILE
echo >> $NINJA_FILE

for srcf in $SOURCES;
do
    srcrel="../${srcf}"
    objf=$(echo $srcf | sed "s/src/obj/")
    objf=$(echo $objf | sed "s/.c/.o/")
    echo "build ${objf}: cc ${srcrel}" >> $NINJA_FILE
done
