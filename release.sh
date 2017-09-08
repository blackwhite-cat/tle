#!/bin/bash
# Author Mamoru Kaminaga
# Date 2017/09/08
# Shell script for release
# Copyright 2017 Mamoru Kaminaga

# The compilation is done
nmake /f tle.mk | iconv -f cp932 -t utf-8
nmake | iconv -f cp932 -t utf-8

# Required: The latest version.
VERSION=`git tag | tail -n 1`

# Output directory is created
OUTDIR="release"
if [ ! -e "${OUTDIR}" ]; then
  mkdir ${OUTDIR}
fi

# Output sub directory is created
TARGET="${OUTDIR}/release_${VERSION}"
if [ ! -e "${TARGET}" ]; then
  mkdir ${TARGET}
fi

# Files are copied.
cp *.cc ${TARGET}
cp *.h ${TARGET}
cp makefile ${TARGET}
cp *.mk ${TARGET}
cp *.lib ${TARGET}

# Zip file is created.
zip -r ${TARGET}.zip ${TARGET}
