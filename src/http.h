#ifndef HTTP_H
#define HTTP_H

#include "http-parser/http_parser.h"
#include "dict.h"

/* Send an HTTP response */
void
http_response(int fd, int code, const char *status, const char *data, size_t len);


/* Start streaming with chunked encoding */
void
http_streaming_start(int fd, int code, const char *status);

/* Send data chunk */
int
http_streaming_chunk(int fd, const char *data, size_t len);

/* Stop streaming, close connection. */
void
http_streaming_end(int fd);



struct http_request {

	int fd;

	char *path;
	size_t path_len;

	dict *get;
};

int
http_parser_onurl(http_parser *parser, const char *at, size_t len);

int
http_parser_onpath(http_parser *parser, const char *at, size_t len);

#endif /* HTTP_H */