//
//


#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

using std::string;
using std::vector;


bool writeStingToFile(const string &file, const string &conntent);

int readLinesToFile(vector<string> &lines, const string &filePath);

int copyFile(const string &src, const string &desc);

#endif
