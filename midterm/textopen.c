#include <stdio.h>

int main() {
	char str[50] = {0, };
	FILE *fp = fopen("data.txt", "r");
	fread(str, 1, 50, fp);
	printf("%s\n", str);
	fclose(fp);
	return 0;
}
