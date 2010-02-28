#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "server.h"
#include "user.h"
#include "channel.h"
#define NB_WORKERS	1

int
main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	channel_init();
	user_init();
	server_start(NB_WORKERS, 1234, 7777);

	while(1) {
		sleep(60);
	}

	return EXIT_SUCCESS;
}
