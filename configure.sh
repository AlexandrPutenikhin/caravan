#!/usr/bin/sh

BUILD_DIR='build/'
NINJA_FILE="${BUILD_DIR}build.ninja"
SOURCES=src/*.c
CFLAGS='-Wall -Wextra -O3'

set -ex

mkdir -p $BUILD_DIR

echo "cflags = $CFLAGS" > $NINJA_FILE

echo 'rule cc' >> $NINJA_FILE
echo '  command = gcc $cflags -c $in -o $out' >> $NINJA_FILE

echo 'rule link' >> $NINJA_FILE
echo '  command = gcc $cflags -s -o $out $in' >> $NINJA_FILE

objs=""

for srcf in $SOURCES;
do
    srcrel="../${srcf}"
    objf=$(echo $srcf | sed "s/src/obj/")
    objf=$(echo $objf | sed "s/.c/.o/")
    objs="${objf} ${objs}"
    echo "build ${objf}: cc ${srcrel}" >> $NINJA_FILE
done

echo "build romulus: link ${objs}" >> $NINJA_FILE
