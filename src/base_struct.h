# ifndef BASE_STRUCT_H
# #define BASE_STRUCT_H

#include <stdint.h>

typedef uint16_t ProtocolVersion;

template<typename LENGTH_TYPE, uint64_t MAX_LENGTH>
struct VariantVector {
	LENGTH_TYPE length;
	unsigned char data[MAX_LENGTH];
};

struct CipherSuite {
	uint8_t data[2];
};

struct ClientHello {
	ProtocolVersion legacy_version; // 0x0303: TLS v1.2
	unsigned char random[32];
	VariantVector<uint8_t, 32> legacy_session_id;
	VariantVector<uint16_t, 1 << 16> legacy_compression_methods;
};

#endif
