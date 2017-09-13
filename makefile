# makefile
# date 2017-09-13
# Copyright 2017 Mamoru kaminaga
TARGET = test.out
SRC = test.cc tle.cc
OBJDIR = build
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cc=.o)))

GCC = g++
INCLUDE =
CFLAGS = -std=c++0x -g -Wall -O2 -DUNICODE
LIBS = -lrt -lstdc++
LDFLAGS =

$(TARGET): $(OBJS)
#	@echo TARGET: $(TARGET)
#	@echo SRC: $(SRC)
#	@echo OBJDIR: $(OBJDIR)
#	@echo OBJS: $(OBJS)
#	@echo GCC: $(GCC)
#	@echo CFLAGS: $(CFLAGS)
#	@echo INCLUDE: $(INCLUDE)
#	@echo LIBS: $(LIBS)
#	@echo LDFLAGS: $(LDFLAGS)
	$(GCC) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: %.cc
	mkdir -p $(OBJDIR)
	$(GCC) $(CFLAGS) $(INCLUDE) -o $@ -c $^
