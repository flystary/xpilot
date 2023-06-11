#ifndef RABBITMQ_CLIENT_H
#define RABBITMQ_CLIENT_H


#include <string.h>
#include <json/json.h>
#include <amqp.h>
#include <amqp_ssl_socket.h>
#include <unistd.h>

#include "config/config.h"
#include "utils/thread_utils.h"
#include "utils/mq_utils.h"

void *thrInitMQ(void *arg);

void handleBUSINESS(string &result, const Json::Value &messageData);

void handleCPE_STATUS(string &result);


#endif
