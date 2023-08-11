#include <stdio.h>
#include <stdlib.h>

int main() {
    int integerVar;
    float floatVar;
    char charVar;
    char stringVar[100];  // It will take the string upto 100 characters
    
    FILE *sourceFile = fopen("test.txt", "r"); 
    FILE *destFile = fopen("destination.txt", "w");
    
    if (sourceFile == NULL || destFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    fscanf(sourceFile, "%d", &integerVar);
    fscanf(sourceFile, "%f", &floatVar);
    fscanf(sourceFile, " %c", &charVar);  // Adding space before %c to skip newline
    fscanf(sourceFile, " %99[^\n]", stringVar);  // Reading the new line upto 100 characters

    fprintf(destFile, "Formatted Integer: %d\n", integerVar);
    fprintf(destFile, "Formatted Float: %.2f\n", floatVar);
    fprintf(destFile, "Formatted Character: %c\n", charVar);
    fprintf(destFile, "Formatted String: %s\n", stringVar);

    fclose(sourceFile); 
    fclose(destFile);  
    
    return 0;
}
