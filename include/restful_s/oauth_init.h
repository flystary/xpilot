#ifndef OAUTH_H
#define OAUTH_H


#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;


struct oauth_client {
    string clientId;
    string secret;
    vector<string> authorizedGrantTypes;
    string scopes;
    int  accessTokenValiditySeconds;
    int  refreshTokenValiditySeconds;
};


#endif
