//
// Created by liql on 06/03/2023
//

#include "unistd.h"
#include "stdio.h"

#include "iostream"
#include "config/config.h"
#include "utils/file_utils.h"
#include "config.h"

using std::string;


int main(int argc, char* argv[]) {
    if(argc == 2) {
        if(strcmp(argv[1], "-v") == 0) {
            printf("%d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, COMPACT_BUILD_TIMESTAMP);
        }

        if(strcmp(argv[1], "-V") == 0) {
            printf("NAME: %s\n", PROJECT_NAME);
            printf("VERSION: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
            printf("BUILD_TIMESTAMP: %s\n", INDENTED_BUILD_TIMESTAMP);
        }
        return 0;
    }

    string src = "/etc/passwd";
    string dst = "/tmp/tmp_passwd";
    sleep(1);

    int nRet = copyFile(src, dst);

    printf("%d\n", nRet);

    return 0;
}
