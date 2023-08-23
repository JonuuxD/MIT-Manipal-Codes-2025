#include <stdio.h>
#include <stdlib.h>

int lcount;
int ccount;

int main() {
	FILE *fptr1;
	char filename[100], c;
	printf("Enter the name of the file\n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	if (fptr1 == NULL) {
		printf("Entered file doesn't exist.\n");
		exit(0);
	}
	c = fgetc(fptr1);
	while (c != EOF) {
		ccount++;
		c = fgetc(fptr1);
		if (c == '\n') {
			lcount++;
		}
	}
	fclose(fptr1);
	printf("Number of characters: %d\n", ccount);
	printf("Number of lines: %d\n", lcount);
	return 0;
}
