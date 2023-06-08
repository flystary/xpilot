#include "utils/string_utils.h"

using pcrecpp::RE;
using std::stringstream;
using std::time_t;

bool isBlank(const string& target) {
    RE  oPattern("^[\\s]*$");
    return oPattern.FullMatch(target);
}

bool isNotBlank(const string& target) {
    return !isBlank(target);
}

bool isPositiveInteger(const string& target) {
    RE  oPattern("^[1-9]+[0-9]*$");
    return oPattern.FullMatch(target);
}

bool isIpv4(const string& target) {
    RE oPattern("^([1-9]|[1-9]\\d|1\\d{2}|2[0-1]\\d|22[0-3])((\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3})$");
    return oPattern.FullMatch(target);
}

bool isIpv4OrIpv4Segment(const string& target) {
    RE oPattern("^([1-9]|[1-9]\\d|1\\d{2}|2[0-1]\\d|22[0-3])((\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3})((/(\\d|[1-2]\\d|[3][0-2]))?)$");
    return oPattern.FullMatch(target);
}

bool isMAC(const string& target) {
    RE oPattern("[A-F\\d]{2}:[A-F\\d]{2}:[A-F\\d]{2}:[A-F\\d]{2}:[A-F\\d]{2}:[A-F\\d]{2}");
    return oPattern.FullMatch(target);
}

bool isPort(const int& port) {
    return (port >= 0 && port < 65536);
}

bool isInteger(const string& target) {
    RE oPattern("^[0-9]+$");
    return oPattern.FullMatch(target);
}

bool isNetmask(const string& target) {
    RE oPattern("(254|252|248|240|224|192|128|0)\\.0\\.0\\.0|255\\.(254|252|248|240|224|192|128|0)\\.0\\.0|255\\.255\\.(254|252|248|240|224|192|128|0)\\.0|255\\.255\\.255\\.(255|254|252|248|240|224|192|128|0)");
    return oPattern.FullMatch(target);
}

bool isHostname(const string& target) {
    RE oPattern("^[a-zA-Z0-9]+(([.]?[a-zA-Z0-9]+)*([-]*[a-zA-Z0-9]+)*)*$");
    return oPattern.FullMatch(target);
}

bool isLetterNumber(const string& target) {
    RE oPattern("^[a-zA-Z0-9]+$");
    return oPattern.FullMatch(target);
}

bool isEmail(const string& target) {
    RE oPattern("^[\\w!#$%&'*+/=?'{|}~^-]+(?:\\.[\\w!#$%&'*+/=?'{|}~^-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,6}$");
    return oPattern.FullMatch(target);
}

bool isPhone(const string& target) {
    RE oPattern("^(\\+?0?86\\-?)?((13\\d|14[57]|15[^4,\\D]|17[678]|18\\d)\\d{8}|170[059]\\d{7})$");
    return oPattern.FullMatch(target);
}

bool isTel(const string& target) {
    RE oPattern("^0\\d{2,3}-\\d{7,8}$");
    return oPattern.FullMatch(target);
}

string& strReplace(string& strBig, const string& strsrc, const string& strdst) {
    string::size_type pos = 0;
    string::size_type srclen = strsrc.size();
    string::size_type dstlen = strdst.size();
    while ((pos = strBig.find(strsrc, pos)) != string::npos) {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
    return strBig;
}

int strSplit(const string& str, vector<string>& v, const char* p) {
    char* tmp_str = NULL;
    tmp_str = (char*)malloc(str.size() + 1);
    memset(tmp_str, 0, str.size() + 1);
    memcpy(tmp_str, str.c_str(), str.size() + 1);
    v.clear();
    char* savePtr;
    char* pTmp = strtok_r(tmp_str, p, &savePtr);
    while (NULL != pTmp) {
        string tempStr = pTmp;
        v.push_back(tempStr);
        pTmp = strtok_r(NULL, p, &savePtr);
    }
    free(tmp_str);
    return v.size();
}

string covertTime(long duration) {
    time_t tt;
    tt = duration;
    char now[64];
    strftime(now, 64, "%Y-%m-%d %H:%M:%S", localtime(&tt));
    return now;
}

time_t covertTime(string str) {
    tm tm_;
    char* cha = (char*)str.data();
    int year, month, day, hour, minute, second;
    std::sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    tm_.tm_year = year - 1900;
    tm_.tm_mon  = month - 1;
    tm_.tm_mday = day;
    tm_.tm_hour = hour;
    tm_.tm_min  = minute;
    tm_.tm_sec  = second;
    tm_.tm_isdst = 0;

    time_t t_ = mktime(&tm_);
    return t_;
}

string bool_to_str(bool b) {
    string s;
    b ? s = "true" : s = "false";
    return s;
}

void int_to_bytes(int32_t i, char *bytes) {
    memset(bytes, '\0', 4);
    bytes[3] = 0xff & i;
    bytes[2] = 0xff & i >> 8;
    bytes[1] = 0xff & i >> 16;
    bytes[0] = 0xff & i >> 24;
}

int32_t bytes_to_int(char *bytes) {
    int32_t i = 0;
    i += ((unsigned char) bytes[0] << 24);
    i += ((unsigned char) bytes[1] << 16);
    i += ((unsigned char) bytes[2] << 8);
    i += (unsigned char)  bytes[3];

    return i;
}

string& replace_all(string& str, const string& old_value, const string& new_value) {
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != string::npos)
            str.replace(pos, old_value.length(), new_value);
        else
            break;
    }
    return str;
}

bool equals(const string& str1, const string& str2) {
    bool b;
    str1 == str2 ? b = true : b = false;

    return b;
}

bool str_to_bool(const string& str) {
    if (str == "true")
        return true;
    if (str == "false")
        return false;

    return false;
}

string uuidGenerate() {
    string uuidStr;
    uuid_t uu;

    uuid_generate(uu);
    char out[37];
    uuid_unparse(uu, out);
    uuidStr.append(out);
    return uuidStr;
}

Json::Value str_to_json(const string& str) {
    Json::Value value;
    string err;
    
    Json::CharReaderBuilder reader;
    std::unique_ptr<Json::CharReader> const json_read(reader.newCharReader());
    json_read->parse(str.c_str(), str.c_str() + str.length(), &value, &err);
    return value;
}

string formatCurTime(const string& format) {
    string time;
    stringstream strtime;

    time_t currenttime = std::time(0);
    char tAll[255];
    std::strftime(tAll, sizeof(tAll), format.c_str(), std::localtime(&currenttime));
    strtime << tAll;
    time = strtime.str();
    return time;
}

string formatTime(const string& format, time_t time) {
    string strTime;
    stringstream stime;
    time_t currenttime = 0;
    if (time <= 0)
        currenttime = std::time(0);
    else
        currenttime = time;
    char tAll[255];
    std::strftime(tAll, sizeof(tAll), format.c_str(), std::localtime(&currenttime));
    stime << tAll;
    strTime = stime.str();
    return strTime;
}

time_t strTime2unix(const std::string& timeStamp) {
    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    sscanf(timeStamp.c_str(), "%d-%d-%d %d:%d:%d",
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);

    tm.tm_year -= 1900;
    tm.tm_mon--;

    return mktime(&tm);
}

int prefixToint(string prefix) {
    if (prefix == "0") {
        return 0;
    }
    int result = -1;
    result = result << (32 - atoi(prefix.c_str()));
    return result;
}

string intToStr(int intIPv4) {
    return to_string(((intIPv4 >> 24) & 0xFF)) + "." + to_string(((intIPv4 >> 16) & 0xFF)) + "." + to_string(((intIPv4 >> 8) & 0xFF)) + "." + to_string((intIPv4 & 0xFF));
}

string prefixToStr(string prefix) {
    return intToStr(prefixToint(prefix));
}

int jsonStrtoStyledString(string &jsonStr){
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value value;
    bool temp = reader->parse(jsonStr.c_str(), jsonStr.c_str() + jsonStr.length(), &value, &errs);
    delete reader;
    if (!temp)
    {
        return -1;
    }
    jsonStr = value.toStyledString();
    return 0;
}

