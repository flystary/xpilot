#ifndef RESTFUL_S_H
#define RESTFUL_S_H

#include <string>
#include <json/json.h>

#include "mongoose.h"
#include "config/config.h"
#include "restful_s/oauth_init.h"
#include "restful_s/oauth_refresh.h"
#include "restful_s/ping.h"
#include "restful_s/tranceroute.h"
#include "restful_s/cpe_control.h"


using std::string;

void startRestfulServer();

string findValue(string &kvs, const string &key);

void handle_account(mg_connection *nc, http_message *hm);

void  loadHttpServerConfig();

#endif
