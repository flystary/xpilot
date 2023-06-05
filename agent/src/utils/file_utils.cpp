
#include <cstring>
#include <fstream>
#include <iostream>
#include "utils/command.h"

using cmd::command_xc;
#include "utils/file_utils.h"


using std::ios;
using std::ofstream;


bool writeStringTofile(const string& file, const string& content) {
    ofstream fout(file, ios::out | ios::trunc);
    if (!fout.is_open()) {
        return false;
    }
    
    fout << content;
    fout.close();
    return true;
}

int readLinesToFile(vector<string>& lines, const string& filePath) {
    std::fstream in(filePath, std::ios::in);
    if(!in.is_open())
    {
        return 1;
    }

    std::string line;
    while (getline(in, line))
    {
        lines.push_back(line);
    }
    in.close();

    return 0;
}

int copyFile(const string& src, const string& desc) {
    int nRet = 0;
    std::fstream in(src, std::ios::in);
    std::ofstream out(desc, std::ios::out);
    
    if (!in || !out) {
        in.close();
        out.close();
        return -1;
    }

    in.unsetf(ios::skipws);
    char ch;
    while (in.get(ch)) {
        out << ch;
    }
    in.close();
    out.close();
    return nRet;
}
