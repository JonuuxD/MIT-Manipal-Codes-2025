// We are using gets function so that we can consider the spaces in the text and pattern aswell without gets we'll have to put use underscore..
// ..in order to give spaces between the sentence.

// We cannot use gets in gnu (ubuntu), so we'll be using fgets.

// for windows we can stick to gets.

// there are 2 main functions. One for ubuntu with fgets and other for windows with gets. Use accordingly.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 256

int table[SIZE];
int comparisons = 0;

void shifttable(char p[25]) {
    int i, m;
    m = strlen(p);
    for (i = 0; i < SIZE; i++)
        table[i] = m;
    for (i = 0; i <= m-2; i++)
        table[p[i]] = m-i-1;
}

int horspool(char t[100], char p[25]) {
    int m, n, k, i;
    m = strlen(p);
    n = strlen(t);
    shifttable(p);
    i = m-1;
    
    while (i <= n-1) {
        k = 0;
        while ((k < m) && (p[m-1-k] == t[i - k])) {
            k = k+1;
            comparisons++;
        }
        if (k == m)
            return i-m+1;
        else
            i = i+table[t[i]];
        comparisons++;
    }
    return -1;
}

// for windows 
int main() {
    char text[100], pattern[25];
    int res;
    printf("Enter the text: ");
    gets(text);
    printf("\nEnter the pattern: "); 
    gets(pattern);
    res = horspool(text, pattern);
    if ( res == -1)
        printf("\nPattern not found\n");     
    else 
        printf("\nPattern found at pos %d\n", res);
    printf("Comparsions: %d", comparisons);
    return 0;
}

// for ubuntu
int main() {
    char text[100], pattern[25];
    int res;
    printf("Enter the text: ");
    fgets(text, 100, stdin);
    printf("\nEnter the pattern: ");
    fgets(pattern, 25, stdin);
    res = horspool(text, pattern);
    if (res == -1)
        printf("\nPattern not found\n");
    else
        printf("\nPattern found at pos %d\n", res);
    printf("Comparisons: %d\n", comparisons);
    return 0;
}
