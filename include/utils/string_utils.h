//
//

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <pcrecpp.h>
#include <uuid/uuid.h>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <json/json.h>
#include <memory>

using pcrecpp::RE;
using std::string;
using std::stringstream;
using std::time_t;
using std::vector;

string prefixToStr(string prefix);

bool isBlank(const string &target);

bool isNotBlank(const string &target);

bool isPositiveInteger(const string &target);

bool isIpv4(const string &target);

bool isIpv4OrIpv4Segment(const string &target);

bool isMAC(const string &target);

bool isPort(const int &port);

bool isInteger(const string &target);

bool isNetmask(const string &target);

bool isHostname(const string &target);

bool isLetterNumber(const string &target);

bool isEmail(const string &target);

bool isPhone(const string &target);

bool isTel(const string &target);

string &strReplace(string &strBig, const string &strsrc, const string &strdst);

int strSplit(const string &str, vector<string> &v, const char *p);

int jsonStrtoStyledString(string &jsonStr);

string covertTime(long time);

time_t covertTime(string str);

string bool_to_str(bool b);

void int_to_bytes(int32_t i, char *bytes);

int32_t bytes_to_int( char *bytes);

/*
 * replace_all(string(“12212″),“12″,“21″)
 * 12212 to 21221
 */
string &replace_all(string &str, const string &old_value, const string &new_value);

bool equals(const string &str1, const string &str2);

bool str_to_bool(const string &str);

string uuidGenerate();

Json::Value str_to_json(const string &str);

// format "%Y-%m-%d-%H:%M:%S"
string formatCurTime(const string &format);

// format "%Y-%m-%d-%H:%M:%S" time 0 is current time
string formatTime(const string &format, time_t time);

// simple: "2017-04-14_16:41:40"
time_t strTime2unix(const std::string &timeStamp);

#endif 
