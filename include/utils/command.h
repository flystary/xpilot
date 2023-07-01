//
//


#ifndef COMMAND_H
#define COMMAND_H

#include <sstream>
#include <string>
#include <vector>
#include <json/json.h>

using std::ostringstream;
using std::string;
using std::vector;


namespace cmd
{
    class command_xc
    {
    public:
        command_xc();

        command_xc(string &basePath);

        command_xc(const char *basePath);

        void setName(string name);

        void addArgs(string srg);

        int execute(vector<string> &v);

        int execute();

    private:
        string base_path_;
        ostringstream os_cmd_;
    };
}


#endif
