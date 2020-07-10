
#include "config.h"
#include <stdlib.h> /* atoi() */
#include <string.h> /* strcmp() */

parp_config_t parp_config ;

/*
 * main() variables
 */

//  char * ifaces[MAX_IFACES];
//  int last_iface_idx=-1;
extern char* ifaces[];
extern int last_iface_idx;

extern int debug ;
extern int sdebug ;

extern int option_arpperm ;

/*
 * "argv parser" ))
 */


/* returns: 'help' value */
int set_config(int argc, char **argv) {
    
    int help=0;
    
    /* set default values */
    parp_config.arp_table_entry_timeout = ARP_TABLE_ENTRY_TIMEOUT_ ;
    parp_config.sleeptime               = SLEEPTIME_ ;
    parp_config.refreshtime             = REFRESHTIME_ ;
    parp_config.max_rq_size             = MAX_RQ_SIZE_ ;
    
    int i;
    for (i = 1; i < argc; i++) {
        
	if (!strcmp(argv[i],"-d")) { 
	    debug=1;
	}
	else if (!strcmp(argv[i],"-D")) { 
	    sdebug=1;
	}
	else if (!strcmp(argv[i],"-p")) { 
	    option_arpperm=1;
	    // help=0;
	}
	else if (!strcmp(argv[i],"--atet")) { 
	    parp_config.arp_table_entry_timeout = atoi(argv[++i]);
	}
	else if (!strcmp(argv[i],"--stime")) { 
	    parp_config.sleeptime = atoi(argv[++i]);
	}
	else if (!strcmp(argv[i],"--rtime")) { 
	    parp_config.refreshtime = atoi(argv[++i]);
	}
	else if (!strcmp(argv[i],"--rqsize")) { 
	    parp_config.max_rq_size = atoi(argv[++i]);
	}
	else if (!strcmp(argv[i],"-h") || !strcmp(argv[i],"--help")) {
	    help=1;
            break;
	}
	else {
	    last_iface_idx++;
	    ifaces[last_iface_idx]=argv[i];
	    //help=0;
	}        
    }

    return help;
    
}

