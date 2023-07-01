//
//

#ifndef RSA_H
#define RSA_H

#include <iostream>

/**
 * 产生RSA密钥
*/
std::string generateKey();

/**
 * 解密函数
*/
std::string decryptWithPrivateKey(const std::string &ciphertext);

/**
 * 检查是否存在 rsa_private.key 文件
*/
bool isPrivateKeyPresent();

#endif
