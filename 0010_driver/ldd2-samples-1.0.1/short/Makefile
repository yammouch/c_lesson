# Comment/uncomment the following line to enable/disable debugging
#DEBUG = y

# This Makefile has been simplified as much as possible, by putting all
# generic material, independent of this specific directory, into
# ../Rules.make. Read that file for details

TOPDIR  := $(shell cd ..; pwd)
include $(TOPDIR)/Rules.make

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSHORT_DEBUG
else
  DEBFLAGS = -O2
endif

CFLAGS += $(DEBFLAGS) -I..

OBJS = short.o

all: $(OBJS)

install:
	install -d $(INSTALLDIR)
	install -c short.o $(INSTALLDIR)

clean:
	rm -f *.o *~ core
