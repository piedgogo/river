#ifndef CONF_H
#define CONF_H


struct conf {

	char *ip;
	short port;

	char *channel_key;

	int threads;

	int client_timeout;
};

struct conf *
conf_read(const char *filename);

void
conf_free(struct conf *conf);

#endif /* CONF_H */
