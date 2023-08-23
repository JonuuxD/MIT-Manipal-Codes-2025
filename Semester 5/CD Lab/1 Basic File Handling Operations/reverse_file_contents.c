#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100], c;
    int endpos;
    printf("Enter the name of the file whose contents are to be copied: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Entered filename doesn't exist");
        exit(0);
    }
    printf("Enter the name of the new file: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w");
    fseek(fptr1, 0, SEEK_END);
    endpos = ftell(fptr1);
    for (int i = endpos - 1; i >= 0; i--) {
        fseek(fptr1, i, SEEK_SET);
        c = fgetc(fptr1);
        fputc(c, fptr2);
    }
    printf("The file is of %d bytes\n", endpos);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
