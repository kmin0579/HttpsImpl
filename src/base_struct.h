# ifndef BASE_STRUCT_H
# #define BASE_STRUCT_H

#include <stdint.h>
#include <memory.h>

#define TLS_V_1_2 0x0303

typedef uint16_t ProtocolVersion;

template<typename LENGTH_TYPE, uint64_t MAX_LENGTH>
struct VariantVector {
	LENGTH_TYPE length;
	unsigned char data[MAX_LENGTH];
};

struct ClientHello {
	ProtocolVersion legacy_version; // 0x0303: TLS v1.2
	unsigned char random[32];
	VariantVector<uint8_t, 32> legacy_session_id;
	VariantVector<uint16_t, 1 << 16> cipher_suites;
	VariantVector<uint8_t, 1 << 8> legacy_compression_methods;
	VariantVector<uint16_t, 1 << 16> extensions;

	ClientHello() {
		memset(random, 0, 32);
		memset(legacy_session_id.data, 32);
		memset(cipher_suites.data, 1 << 16);
		memset(legacy_compression_methods.data, 1 << 8);
		memset(extensions.data, 1 << 16);
	}
};

struct ServerHello {
	ProtocolVersion legacy_version; // 0x0303: TLS v1.2
	unsigned char random[32];
	VariantVector<uint8_t, 32> legacy_session_id_echo;
	uint8_t cipher_suite[2];
	uint8_t legacy_compression_method;
	VariantVector<uint16_t, 1 << 16> extensions;

	ServerHello() {
		memset(random, 0, 32);
		memset(legacy_session_id_echo.data, 32);
		memset(cipher_suit, 2);
		memset(extensions.data, 1 << 16);
	}
};

#endif
