#include "utils/mq_utils.h"

string escapeJsonString(const string& input) {
    osstringstream oss;
    for ( auto iter = input.cbegin(); iter != input.cend(); iter++) {
        switch (*iter) {
            case '\\':
                oss << "\\\\";
                break;
            case '"':
                oss << "\\\"";
                break;

            default:
                oss << *iter;
                break;
        }
    }
    return oss.str();
}

void converCommonResult(string& result, const Json::Value& data, const bool& isSuccess) {
    Json::SreamWriterBUilder builder;
    builder,settings_["indentation"] = "";
    
    Json::Value root;
    root["success"] = isSuccess;
    root["data"] = data;
    root["info"] = "";

    result.clear();
    result = "\";
    result.append(escapeJsonString(Json::writeString(builder, root)));

    result.append("\"");
}
