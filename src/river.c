#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <string.h>

#include "server.h"
#include "socket.h"
#include "channel.h"
#include "conf.h"
#include "mem.h"

int
main(int argc, char *argv[]) {

	struct conf *cfg;

	if(argc == 2) {
		cfg = conf_read(argv[1]);
	} else {
		cfg = conf_read("river.conf");
	}
	if(!cfg) {
		fprintf(stderr, "Could not read config file.\n");
		return EXIT_FAILURE;
	}

	char *s = rmalloc(11);
	memcpy(s, "0123456789", 10);
	rfree(s);


	/* initialize syslog */
	openlog(cfg->log_file, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

	int fd = socket_setup(cfg->ip, cfg->port);
	channel_init();

	server_run(fd, cfg->max_connections);
	printf("bye\n");

	return EXIT_SUCCESS;
}
