#!/bin/bash
# Author Mamoru Kaminaga
# Date 2017/09/08
# Shell script for release
# Copyright 2017 Mamoru Kaminaga

if [ "$1" = "" ]; then
  echo 'need args, 1->gcc, 2->cl'
  exit 1
fi

# Required: The latest version.
VERSION=`git tag | tail -n 1`

# Output directory is created
OUTDIR="release"
mkdir -p ${OUTDIR}

# files for gcc (Ubuntu)
if [ "$1" = "1" ]; then
  touch *.cc
  make
  if [ $? != 0 ]; then exit 1; fi

  touch *.cc
  make -f tle.mk
  if [ $? != 0 ]; then exit 1; fi

  # Output sub directory is created
  TARGET="${OUTDIR}/release_${VERSION}_gcc"
  mkdir -p ${TARGET}

  mkdir -p ${TARGET}
  cp *.md ${TARGET}       # descriptions
  cp *.cc ${TARGET}			  # Source files
  cp *.h ${TARGET}			  # Header files
  cp makefile ${TARGET}		# Makefiles
  cp tle.mk ${TARGET}			# Lib makefiles
  cp *.a ${TARGET}			  # Library files
  cp *.out ${TARGET}			# Executable files

  # Zip file is created.
  zip -r ${TARGET}.zip ${TARGET}
elif [ "$1" = "2" ]; then
  # files for VC (Win32)
  touch *.cc
  nmake /f tle_cl.mk | iconv -f cp932 -t utf-8
  if [ $? != 0 ]; then exit 1; fi

  touch *.cc
  nmake /f makefile_vc.mk | iconv -f cp932 -t utf-8
  if [ $? != 0 ]; then exit 1; fi

  # Output sub directory is created
  TARGET="${OUTDIR}/release_${VERSION}_win32"
  mkdir -p ${TARGET}

  mkdir -p ${TARGET}
  cp *.md ${TARGET}           # descriptions
  cp *.cc ${TARGET}			      # Source files
  cp *.h ${TARGET}				      # Header files
  cp makefile_vc.mk ${TARGET}	# Makefiles
  cp tle_vc.mk ${TARGET}		    # Lib makefiles
  cp *.lib ${TARGET}			      # Lib files
  cp *.exe ${TARGET}			      # Executable files

  # Zip file is created.
  zip -r ${TARGET}.zip ${TARGET}
fi

exit 0
