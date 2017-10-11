# makefile
# date 2017-09-07
# Copyright 2017 Mamoru Kaminaga
CC = C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Community\VC\Tools\MSVC\14.11.25503\bin\HostX86\x86\cl.exe
LIB = C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Community\VC\Tools\MSVC\14.11.25503\bin\HostX86\x86\lib.exe
OBJDIR = build
TARGET = tle.lib
SRC = tle.cc
OBJ = $(OBJDIR)/tle.obj
CCFLAGS = /W4 /Zi /O2 /MT /EHsc /D"WIN32" /D"NODEBUG" /D"_LIB" /D"_UNICODE"\
	/D"UNICODE" /D"NOMINMAX=0x0800" /Fo"$(OBJDIR)\\"

$(TARGET): $(OBJ)
	$(LIB) /OUT:$(TARGET) $(OBJ)

.cc{$(OBJDIR)}.obj:
	@[ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	$(CC) $(CCFLAGS) /c $<
