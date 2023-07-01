#ifndef CONTROL_H
#define CONTROL_H


#include <mongoose.h>

void handle_reboot(mg_connection *nc, http_message *hm);

void handle_reset(mg_connection *nc, http_message *hm);

#endif
