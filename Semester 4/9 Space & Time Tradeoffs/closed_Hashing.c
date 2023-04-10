#include<stdio.h>
#include<stdlib.h>

#define tsize 11

int htable[tsize];

void initTable() {
    for (int i = 0; i < tsize; i++)
        htable[i] = -1;
}

void insert(int key) {
    int h, j, flag = 0, i = 1;
    h = j = (key % tsize);
    while(flag == 0 && htable[j] != -1) {
        j = (j+1) % tsize;
        if ( j == h)
            flag = 1;
            i++;
    }
    if (flag == 1)
        printf("\n Insertion cannot be Done");
    else {
        htable[j] = key;
        printf("\n Key %d Insertion successful at %d", key, j);
    }
}
// Here find function will work for both finding and removing a key.
void find(int key) {
    int h, j, flag = 0, i = 1;
    h = j = (key % tsize);
    while (flag == 0 && htable[j] != key) {
        j = (j+1) % tsize;
        if ( j == h)
            flag = 1;
        i++;
    }

    if (flag == 1)
        printf("\n Finding Key failed");
    else {
        htable[j] = -1;
        printf("\n Key %d removed", j);
    }
}

void display() {
    printf("\n Hash Table: ");
    for ( int i = 0; i < tsize; i++) {
        printf("\n %d | %d |", i, htable[i]);
    }
}

int main() {
    int n, ch, ele;
    initTable();
    printf("\nHash Table Before Insertion: ");
    display();

    do {
        printf("\n1. Insert\n2. Display\n3. Remove Key\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter the element: ");
            scanf("%d", &ele);
            insert(ele);
            break;

            case 2: display();
            break;

            case 3: printf("Enter the element to be removed: ");
            scanf("%d", &ele);
            find(ele);

           case 4:
           break;
           
           default:
           printf("Invalid entry");

        }
    }while(ch != 4);
}
