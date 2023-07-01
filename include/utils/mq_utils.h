#ifndef MQ_UTILS_H
#define MQ_UTILS_H


#include <iostream>
#include <string>
#include <sstream>
#include <json/json.h>

#include "config/config.h"

void convertCommonResult(string &result, const Json::Value &data, const bool &isSuccess);

#endif
