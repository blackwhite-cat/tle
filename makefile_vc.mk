# makefile
# date 2017-09-05
# Copyright 2017 Mamoru kaminaga
CC = C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Community\VC\Tools\MSVC\14.11.25503\bin\HostX86\x86\cl.exe
LINK = C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Community\VC\Tools\MSVC\14.11.25503\bin\HostX86\x86\link.exe
OBJDIR = build
TARGET = test.exe
PDB = test.pdb
MAP = test.map
RES =
SRC = test.cc tle.cc
OBJ = $(OBJDIR)/test.obj $(OBJDIR)/tle.obj
LIBS = "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib"\
"advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib"\
"odbc32.lib" "odbccp32.lib"

# Debug build
CPPFLAGS = /nologo /W4 /Zi /O2 /MT /D"UNICODE" /D"_UNICODE" /D"DEBUG" /TP\
	/EHsc /Fd"$(OBJDIR)/" /D"NOMINMAX" /D"WIN32"
LFLAGS = $(LIBS) /NOLOGO /SUBSYSTEM:CONSOLE /PDB:"$(PDB)" /MAP:"$(MAP)"\
	/DEBUG

ALL: $(TARGET)

$(TARGET): $(OBJ) $(RES)
	$(LINK) $(LFLAGS) /OUT:$(TARGET) $(OBJ) $(RES)

.cc{$(OBJDIR)}.obj:
	$(CC) $(CPPFLAGS) /Fo"$(OBJDIR)\\" /c $<
