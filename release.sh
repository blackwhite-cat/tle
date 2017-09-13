#!/bin/bash
# Author Mamoru Kaminaga
# Date 2017/09/08
# Shell script for release
# Copyright 2017 Mamoru Kaminaga

# Required: The latest version.
VERSION=`git tag | tail -n 1`

# Output directory is created
OUTDIR="release"
mkdir -p ${OUTDIR}

# Output sub directory is created
TARGET="${OUTDIR}/release_${VERSION}"
mkdir -p ${TARGET}

# common are copied.
cp *.md ${TARGET}

# files for gcc (Ubuntu)
touch *.cc
make
if [ $? != 0 ]; then exit 1; fi

touch *.cc
make -f tle.mk
if [ $? != 0 ]; then exit 1; fi

GCCDIR=${TARGET}/gcc
mkdir -p ${GCCDIR}
cp *.cc ${GCCDIR}			# Source files
cp *.h ${GCCDIR}			# Header files
cp makefile ${GCCDIR}		# Makefiles
cp tle.mk ${GCCDIR}			# Lib makefiles
cp *.a ${GCCDIR}			# Library files
cp *.out ${GCCDIR}			# Executable files

# files for vc (Windows)
touch *.cc
nmake /f tle_cl.mk | iconv -f cp932 -t utf-8
if [ $? != 0 ]; then exit 1; fi

touch *.cc
nmake /f makefile_vc.mk | iconv -f cp932 -t utf-8
if [ $? != 0 ]; then exit 1; fi

CLDIR=${TARGET}/vc
mkdir -p ${CLDIR}
cp *.cc ${CLDIR}			# Source files
cp *.h ${CLDIR}				# Header files
cp makefile_vc.mk ${CLDIR}	# Makefiles
cp tle_vc.mk ${CLDIR}		# Lib makefiles
cp *.lib ${CLDIR}			# Lib files
cp *.exe ${CLDIR}			# Executable files

# Zip file is created.
zip -r ${TARGET}.zip ${TARGET}
