/*
 * allowing to tune parprouted constants through command line
 */
#ifndef _PARPROUTED_CONFIG_H
#define _PARPROUTED_CONFIG_H

/* default values */

#define ARP_TABLE_ENTRY_TIMEOUT_   60       /* seconds */
#define SLEEPTIME_                 1000000  /* microseconds */
#define REFRESHTIME_               50       /* seconds */
#define MAX_RQ_SIZE_               50       /* maximum size of request queue */


typedef struct _parp_config_t {
    // int arp_table_entry_len ;
    int arp_table_entry_timeout ;   /* seconds */
    int sleeptime ;                 /* ms */
    int refreshtime ;               /* seconds */
    int max_rq_size ;               /* maximum size of request queue */
} parp_config_t ;

extern parp_config_t parp_config;

// #define ARP_TABLE_ENTRY_LEN      (parp_config.arp_table_entry_len)
#define ARP_TABLE_ENTRY_TIMEOUT  (parp_config.arp_table_entry_timeout)
#define SLEEPTIME                (parp_config.sleeptime)
#define REFRESHTIME              (parp_config.refreshtime)
#define MAX_RQ_SIZE              (parp_config.max_rq_size)

extern int set_config(int argc, char **argv);

#endif
