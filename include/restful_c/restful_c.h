#ifndef RESTFUL_C_H
#define RESTFUL_C_H

#include <string>
#include "mongoose.h"

using std::string;


class REST_IF {
protected:
    string url;
    string method;
    int    exitFlag;
    int    timeout;
    string heaContentType;
    string heaAccept;

    bool    resSuccess;
    string resInfo;

public:
    RESt_IF() : exitFlag(0), timeout(8000) {}

    virtual ~REST_IF() {}

    virtual const string genHeaders();
    virtual const string genReqBody();
    virtual void  parseResBody(const string &reBody);
    
    const string &getUrl() const;


};

void setHttpMethod(mg_connection *pConnection, const string &method);

#endif
