EXTRA_CFLAGS = 

#CC = gcc

# CFLAGS = -g -O2 -Wall $(EXTRA_CFLAGS) -D_HAVE_ETHER_H -D'BIN_IP="/bin/ip"'
CFLAGS = -g -O2 -Wall $(EXTRA_CFLAGS) -D_HAVE_ETHER_H
# For ARM:
# CFLAGS =  -Wall $(EXTRA_CFLAGS)
LDFLAGS = 
OBJS = parprouted.o arp.o config.o

LIBS = -lpthread

all: parprouted

install: all
	install parprouted /usr/local/sbin
	install parprouted.8 /usr/local/man/man8

clean:
	rm -f $(OBJS) parprouted core

parprouted:	${OBJS}
	${CC} -g -o parprouted ${OBJS} ${CFLAGS} ${LDFLAGS} ${LIBS}

parprouted.8:	parprouted.pod
	pod2man --section=8 --center="Proxy ARP Bridging Daemon" parprouted.pod --release "parprouted" --date "`date '+%B %Y'`" > parprouted.8

parprouted.o : parprouted.c parprouted.h config.h

arp.o : arp.c parprouted.h

config.o : config.c config.h

