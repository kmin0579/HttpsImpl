#include "HttpsClient.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "mlog.h"
#include "base_struct.h"

HttpsClient::HttpsClient(std::string ip, int port) : m_ip(ip), m_port(port) {

}

HttpsClient::~HttpsClient() {

}

int HttpsClient::Send() {
	if (InitTcpConnect()) {
		Close();
		return -1;
	}
	if (TLSHandShake()) {
		Close();
		return -2;
	}


	Close();
	return 0;
}

int HttpsClient::InitTcpConnect() {
	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, m_ip, &address.sin_addr);
	address.in_port = htons(m_port);
	int m_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	const int BUFFER_SIZE = 128;
	char log_buffer[BUFFER_SIZE];
	memset(log_buffer, 0, BUFFER_SIZE);
	if (m_sockfd < 0) {
		snprintf(log_buffer, BUFFER_SIZE, "InitTcpConnect, init socket error, sockfd=%d", m_sockfd);
		log_info(log_buffer);
		return -1;
	}
	int ret = connect(m_sockfd, (struct sockaddr*) &address, sizeof(address));
	if (ret < 0) {
		snprintf(log_buffer, BUFFER_SIZE, "InitTcpConnect, connect error, ret=%d", ret);
		return -2;
	}
	return 0;
}

int HttpsClient::TLSHandShake() {
	ClientHello client;
	client.legacy_version = TLS_V_1_2;
}

void HttpsClient::Close() {
	if (m_sockfd >= 0) {
		close(m_sockfd);
	}
}
