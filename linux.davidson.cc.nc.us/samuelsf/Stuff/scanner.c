
/* 
 * internet port scanner 
 *
 * This program will scan a hosts TCP ports printing all ports that accept
 * connections, and if known, the service name.
 * This program can be trivially altered to do UDP ports also.
 *
 * Kopywrong (K) Aug. 25, '94 pluvius@io.org
 *
 * Hey kiddies, this is a C program, to run it do this:
 * $ cc -o pscan pscan.c
 * $ pscan <host> [max port]
 *
 * No, this will not get you root.
 * 
 * Changes:
 * Changed fprintf to printf in line 34 to work with my Linux 1.1.18 box
 * Netrunner 1/18/95 11:30pm
 * 
*/
static char sccsid[] = "@(#)pscan.c     1.0     (KRAD) 08/25/94";
#include <stdio.h>
#include </student/csc134HA/samuelsf/include/types.h>
#include </student/csc134HA/samuelsf/include/socket.h>
#include </student/csc134HA/samuelsf/include/in.h>
#include <netdb.h>

#define MAX_PORT 1024 /* scan up to this port */
int s;
struct sockaddr_in addr;
char rmt_host[100];

int skan(port)
int port;
{
 int r;
    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s < 0) {
       /* fprintf("ERROR: socket() failed\n"); */
       /* Changed to printf for my Linux 1.1.18 box */
       printf("ERROR: socket() failed\n");
       exit(0);
    }

    addr.sin_family = PF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = inet_addr(rmt_host);

    r = connect(s,(struct sockaddr *) &addr, sizeof(addr));

    close(s);

    if (r < 0) {
       return (1 == 0);
    }

    return (1 == 1);
}

main(argc,argv) 
int argc;
char *argv[];
{
 int a,b,c,d,e,f;
 struct hostent *foo;
 struct servent *bar;

   if (argc < 2) {
      fprintf(stderr,"usage: %s <host> [highest port]\n",argv[0]);
      exit(0);
   }

   if (sscanf(argv[1],"%d.%d.%d.%d",&a,&b,&c,&d) != 4) {
      foo = gethostbyname(argv[1]);
      if (foo == NULL) {
         fprintf(stderr,"error: cannot resolve host %s\n",argv[1]);
         exit(0);
      }
      sprintf(rmt_host,"%d.%d.%d.%d",(unsigned char )foo->h_addr_list[0][0],
              (unsigned char ) foo->h_addr_list[0][1], 
              (unsigned char ) foo->h_addr_list[0][2], 
              (unsigned char ) foo->h_addr_list[0][3]);
   } else {
      strncpy(rmt_host,argv[1],99);
   }


   if (argc > 2) {
      f = atoi(argv[2]);
   } else
      f = MAX_PORT;

   fprintf(stdout,"Scanning host %s - TCP ports 1 through %d\n",rmt_host,f);

   for (e =1;e<=f;e++) {
    char serv[100];
      if (skan(e)) {
         bar = getservbyport(e,"tcp");
         printf("%d (%s) is running.\n",e,(bar == NULL) ? "UNKNOWN" :
                bar->s_name);
      }
   }
}

