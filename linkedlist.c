#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list( struct node *head ) {
  struct node* tmp = head;
  if(tmp->next) {
    printf("%d -> ", tmp->i);
    print_list(tmp->next);
  }
  else {
    printf("%d\n", tmp->i);
  }
}

struct node* insert_front( struct node *head, int val ) {
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->i=val;
  new->next=head;
  return new;
}

struct node* free_list( struct node *head ) {
  while(head) {
    free(head);
    head = head->next;
  }
  free(head);
  return head;
}

int main() {
  struct node* l = (struct node *)malloc(sizeof(struct node));
  l->i = 4;
  l->next = NULL;

  l=insert_front(l, 23);
  l=insert_front(l, 81);
  l=insert_front(l, 67);

  printf("BEFORE FREEING: \n");
  printf("print list object: %s\n", l);
  printf("print_list method: \n");
  print_list(l);

  printf("\nAFTER FREEING: \n");
  free_list(l);
  printf("print list object: %s\n", l);
  printf("print_list method: \n");
  print_list(l);
  
  return 0;
}
