//
//

#ifndef IPV4_UTILS_H
#define IPV4_UTILS_H

#include <string>

using std::string;

string int_to_ipv4(unsigned int intIPv4);

unsigned int ipv4_to_int(string ipv4);

unsigned int prefix_to_int(string prefix);

unsigned int prefix_to_available_ips(string prefix);

string prefix_to_netmask(string prefix);

int netmask_to_prefix(string netmask);

void cidr_to_network_netmask(string cidr, uint32_t &network, uint32_t &netmask);

string ip_netmask_to_cidr(string ip, string netmask);

#endif 
