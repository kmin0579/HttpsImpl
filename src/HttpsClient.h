#ifndef HTTPS_CLINET_H
#define HTTPS_CLIENT_H

#include <string>

class HttpsClient {
public:
	HttpsClient(std::string ip, int port);
	~HttpsClient();

	int Send();

private:
	int InitTcpConnect();

	int TLSHandShake();

	void Close();

private:
	std::string m_ip;
	int m_port;
	int m_sockfd;
};

#endif