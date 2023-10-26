#include <stdio.h>

int main(int argc, char* argv[]) {
	struct coffee rec;
	FILE *fp;
	if (argc != 2) {
		fprintf(stderr, "How to Use : %s FileName\n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "w");
	printf("%-9s %-10d %-9d %-4s %s\n", "id", "name", "category", "expired data", "stock");
	while (scanf(
