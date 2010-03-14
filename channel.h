#ifndef COMETD_CHANNEL_H
#define COMETD_CHANNEL_H

#include "dict.h"

#define CHANNEL_LOCK(c)(pthread_mutex_lock(&c->lock))
#define CHANNEL_UNLOCK(c)(pthread_mutex_unlock(&c->lock))

struct p_user;

struct p_channel_user {
	struct p_user *user;
	int fd;

	struct p_channel_user *prev;
	struct p_channel_user *next;
};

struct p_channel_message {

	time_t ts;
	char *data;
	size_t data_len;
	/* TODO: add producer? */

	struct p_channel_message *next;
};

struct p_channel {
	char *name;
	dict *users;

	struct p_channel_user *user_list;

	struct p_channel_message *log;

	pthread_mutex_t lock;
};

void
channel_init() ;

struct p_channel *
channel_new(const char *name);

void
channel_free(struct p_channel *);

struct p_channel * 
channel_find(const char *name);

int
channel_add_user(struct p_channel *, struct p_user *, int fd) ;

int
channel_has_user(struct p_channel *channel, struct p_user *user);

void
channel_del_user(struct p_channel *channel, long uid);

void
channel_write(struct p_channel *channel, const char *data, size_t data_len);

void
channel_catchup_user(struct p_channel *channel, int fd, time_t timestamp);

#endif /* COMETD_CHANNEL_H */

