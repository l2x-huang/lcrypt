#pragma once

#include <string>

namespace lcrypt {

std::string randomkey();
std::string hashkey(const std::string& what);
std::string hmac64(const std::string& challenge, const std::string& secret);
std::string dhexchange(const std::string& hmac_x);
std::string dhsecret(const std::string& k1, const std::string& k2);

std::string des_encode(const std::string& key, const std::string& plaintext);
std::string des_decode(const std::string& key, const std::string& ciphertext);

std::string tohex(const std::string& what);
std::string fromhex(const std::string& what);

std::string base64_encode(const std::string& what);
std::string base64_decode(const std::string& what);

}
