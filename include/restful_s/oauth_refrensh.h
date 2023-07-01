#ifndef OAUTH_REFRESH_H
#define OAUTH_REFRESH_H


void handle_oauth_token(struct mg_connection *nc, struct http_message *hm);

#endif
