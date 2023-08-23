#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *fptr1, *fptr2;
	char filename[100], line[200];
	int pre_directive = 0;
	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}	
	printf("Enter the filename to open for writing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+");
	while (fgets(line, sizeof(line), fptr1) != NULL) {
		if (strncmp(line, "#include", 8) == 0 || strncmp(line, "#define", 7) == 0) {
			pre_directive = 1;
		}
		else {
			fputs(line, fptr2);
			pre_directive = 0;
		}
	}
	printf("\nContents copied to %s\n", filename);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
