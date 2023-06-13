#include <sstream>
#include "rabbitmq/rabbitmq_base.h"
#include "config/config.h"

using std::ostringstream;


void MQReceiverBase::handleReceiver(const string &messageType, string& result,
                                    const Json::Value &messageData) {

    auto it = mq_cb_map_.find(messageType);
    logger.debug("messageType: " + messageType);
    logger.debug("messageData: " + messageData.toStyledString());
    if (it == mq_cd_map_.end()) {
        Json::Value emptyOutput;
        emptyOutput["message"] = "No such messageType!";
        convertCommonResult(trsult, emptyOutput, false);
        return;
    } else {
        it->second(result, messageData);
    }
    
}
