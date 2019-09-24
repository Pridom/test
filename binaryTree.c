#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef char element;
typedef struct node {
  element data;
  int state;
}Node;

element left(Node[], int);
element right(Node[], int);
element parent(Node[], int);

int height(Node[], int);
int isEmpty(Node[], int);
int isRoot(Node[], int);

void print(Node[]);

void init(Node tree[]) {
  for (int i = 1; i < SIZE; i++) {
    tree[i].state = 0;
  }
}

void set(Node tree[], int index, element data) {
  tree[index].state = 1;
  tree[index].data = data;
}

int main(){
  Node tree[SIZE] = {0};
  
  set(tree, 1, 'A');
  set(tree, 2, 'B');
  set(tree, 3, 'C');
  set(tree, 7, 'D');
 
  print(tree);

  printf("\n");
  printf("%c \n", parent(tree, 3));
}

void print(Node tree[]) {
  int i = 0, level = 2;
  for(i = 1; i < SIZE; i++){
    if(tree[i].state != 0){
      printf("%c ", tree[i].data);
    }
    else
	printf("* ");
    if (i == (level ) - 1 ) {
	printf("\n");
        level*=2;
    }
  }
}

element left(Node tree[], int index){
  int leftIndex = 2 * index;

  if(leftIndex >= SIZE || tree[leftIndex].state == 0){
    printf("error \n");
    exit(0);
  }
  return tree[leftIndex].data;
}

element right(Node tree[], int index){
  int rightIndex = 2 * index + 1;
  if(rightIndex >= SIZE || tree[rightIndex].state == 0){
    printf("error \n");
    exit(0);
  }
  return tree[rightIndex].data;
}

element parent(Node tree[], int index){
  int parentIndex = index/2;
  if(parentIndex == 0 || tree[parentIndex].state == 0){
    printf("error \n");
    exit(0);
  }
  return tree[parentIndex].data;
}

int height(Node tree[], int index){
  int height = 0;

  while(index / 2 != 1){
    height++;
    index /= 2;
  }
  return height;
}

int isEmpty(Node tree[], int index){
  if (tree[index].state == 0 ) {
      return 1;
  } else {
      return 0;
  }
}

int isRoot(Node tree[], int index){
  if(index == 1){
    return 1;
  } else {
    return 0;
  }
}



