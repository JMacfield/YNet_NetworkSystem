#pragma once

#include "IPVersion.h"

#include <string>
#include <vector>
#include <WS2tcpip.h>

namespace YNet 
{
	class IPEndpoint 
	{

	public:

		IPEndpoint() {};
		IPEndpoint(const char* ip, unsigned short port);
		IPEndpoint(sockaddr* addr);

		IPVersion GetIPVersion();

		std::vector<uint8_t> GetIPBytes();
		std::string GetHostName();
		std::string GetIPString();

		unsigned short GetPort();

		sockaddr_in GetSockaddrIPv4();
		sockaddr_in6 GetSockaddrIPv6();

		void Print();

		std::string ToString();

	private:

		IPVersion ip_version = IPVersion::Unknown;

		std::string hostname = "";
		std::string ip_string = "";

		std::vector<uint8_t> ip_bytes;
		unsigned short port = 0;
	};
}