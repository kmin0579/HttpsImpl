# ifndef BASE_STRUCT_H
# #define BASE_STRUCT_H

#include <stdint.h>

typedef uint16_t ProtocolVersion;

template<typename LENGTH_TYPE, uint64_t MAX_LENGTH>
class VariantVector {
public:
	LENGTH_TYPE length;
	unsigned char data[MAX_LENGTH];
};

class ClientHello {
private:
	ProtocolVersion legacy_version; // 0x0303: TLS v1.2
	unsigned char random[32];
	VariantVector<uint8_t, 32> legacy_session_id;
	VariantVector<uint16_t, 1 << 16> cipher_suites;
	VariantVector<uint8_t, 1 << 8> legacy_compression_methods;
	VariantVector<uint16_t, 1 << 16> extensions;
};

class ServerHello {
private:
	ProtocolVersion legacy_version; // 0x0303: TLS v1.2
	unsigned char random[32];
	VariantVector<uint8_t, 32> legacy_session_id_echo;
	uint8_t cipher_suite[2];
	uint8_t legacy_compression_method;
	VariantVector<uint16_t, 1 << 16> extensions;
};

#endif
