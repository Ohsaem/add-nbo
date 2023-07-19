#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

uint32_t readNum(char* filename) {
	FILE *fp = fopen(filename, "r");
	uint32_t n;
	fread(&n, 1, sizeof(n), fp);
	n = htonl(n);
    	fclose(fp);
    	return n;
}

int main(int argc, char *argv[]) {
	uint32_t n1 = readNum(argv[1]);
	uint32_t n2 = readNum(argv[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);

    	return 0;
}
