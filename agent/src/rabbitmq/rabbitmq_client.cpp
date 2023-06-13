#include <amqp.h>
#include <amqp_ssl_socket.h>
#include <unistd.h>
#include <sstream>

#include "config/config.h"
#include "utils/thread_utils.h"

#include "rabbitmq/rabbitmq_client.h"

#include "exec_xc/xc_network_interface.h"
#include <utils/Singleton.h>

using std::string;
using std::to_string;


static amqp_connection_state_t conn;

bool initMQLogin();

bool retryMQInit();

void initMQ();

bool initMQSSLConn();
