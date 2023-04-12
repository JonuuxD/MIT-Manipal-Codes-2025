#include <stdio.h>
#include <stdlib.h>
#define size 7

struct node
{
  int data;
  struct node *next;
};

struct node *chain[size];

void init()
{
  int i;

  for(i = 0; i < size; i++)
    chain[i] = NULL;
}

void insert(int value)
{
  struct node *newNode = malloc(sizeof(struct node));

  newNode->data = value;
  newNode->next = NULL;

  int key = value % size;

  if(chain[key] == NULL)
    chain[key] = newNode;

  else
  {
    struct node *temp = chain[key];

    while(temp->next)
    {
      temp = temp->next;
    }

    temp->next = newNode;
  }
}

int successful_search(int value)
{
  int key = value % size;
  struct node *temp = chain[key];
  int comparisons = 0;

  while(temp != NULL)
  {
    comparisons++;
    if(temp->data == value)
      return comparisons;
    temp = temp->next;
  }

  return comparisons;
}

int unsuccessful_search(int value)
{
  int key = value % size;
  struct node *temp = chain[key];
  int comparisons = 0;

  while(temp != NULL)
  {
    comparisons++;
    if(temp->data == value)
      return comparisons;
    temp = temp->next;
  }

  return comparisons;
}

void print()
{
  int i;

  for(i = 0; i < size; i++)
  {
    struct node *temp = chain[i];

    printf("chain[%d]-->",i);

    while(temp)
    {
      printf("%d -->",temp->data);
      temp = temp->next;
    }

    printf("NULL\n");
  }
}

int main() {
    init();
   int choice, data, key;
   do {
    printf("1. Insert\n");
    printf("2. Return key comparison\n");
    printf("3. Display the chain\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: printf("Insertion: please enter an element\n");
        scanf("%d", &data);
        insert(data);
        break;

        case 2: printf("Enter the key you want to find: ");
        scanf("%d", &key);
        int successful_comparisons = successful_search(key);
        if (successful_comparisons == 0) {
            int unsuccessful_comparisons = unsuccessful_search(key);
            printf("Unsuccessful search for key %d took %d comparisons.\n", key, unsuccessful_comparisons);
        }
        else {
            printf("Successful search for key %d took %d comparisons.\n", key, successful_comparisons);   
        }
        
        break;

        case 3: print();
        break;
        case 4: break;
        default: printf("Invalid choice.");
        break; 
        }
    }while(choice != 4);
    return 0;
}
