#ifndef RABBITMQ_BASE_H
#define RABBITMQ_BASE_H

#include <string>
#include <json/json.h>
#include <map>
#include <functionnal>
#include <utils/mq_utils.h>

using std::string;

class MQReceiverBase {
public:
    typedef std::function<void (string&, const Json::value &)> MQVRRPALLBACK;
    void handleReceiver(const string &messageType, string& result, const, Json::Value &messageData);

protected:
    std::map<string, MQVRRPCALLBACK> mq_cb_map_;

};


#endif

