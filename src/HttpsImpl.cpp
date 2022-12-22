// HttpsImpl.cpp: 定义应用程序的入口点。
//

#include "HttpsImpl.h"
#include "utils.h"
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(timeus());

	unsigned char random[32];
	memset(random, 0, 4);
	generate_random(random, 32);
	printf("0x");
	for (int i = 0; i < 32; i++) {
		printf("%02x", random[i]);
	}
	printf("\n");
	return 0;
}
