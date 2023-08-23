#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *fptr1, *fptr2;
	char filename[100], c;
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
	c = fgetc(fptr1);
	while (c != EOF)
	{
		if (c == '\t') {
			while (c == '\t'){
				c = fgetc(fptr1);
			}
			fputc(' ', fptr2);
		}

		if (c == ' ') {
			while (c == ' '){
				c = fgetc(fptr1);
			}
			fputc(' ', fptr2);
		}
		else {
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
	}
	printf("\nContents copied to %s\n", filename);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
