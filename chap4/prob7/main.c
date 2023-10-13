#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[]) {
	struct student rec;
	FILE *fp;

	if (argc != 2) {
		fprintf(stderr, "How to use : %s FileName\n", argv[0]);
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error Open File\n");
		return 2;
	}

	printf("------------------------------\n");
	printf("%10s  %6s  %6s\n", "StudentID", "Name", "Score");
	printf("------------------------------\n");

	while (fscanf(fp, "%d %s %d", &rec.id, rec.name, &rec.score) == 3) {
			printf("%10d %6s %6d\n", rec.id, rec.name, rec.score);
	}

	printf("-------------------------------\n");

	fclose(fp);
	return 0;
}
