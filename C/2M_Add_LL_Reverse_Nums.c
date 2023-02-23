#include<stdio.h>
#include<stdlib.h>

typedef struct List_Node {
  int val;
  struct List_Node* next;
}Node;

void decide_final_node(int carry, Node* r) {
  if(carry == 1) {
    r -> next = (Node*)malloc(sizeof(Node));
    r = r -> next;
    r -> val = carry;
    r -> next = NULL;
  } else {
    r -> next = NULL;
  }
}

Node* addTwoNumbers(Node* l1, Node* l2) {
  int sum, carry = 0;
  Node* ans = (Node*)malloc(sizeof(Node));
  Node* p = l1;
  Node* q = l2;
  Node* r = ans;

  // reach ON the last common nth node and stop for both the linked lists(LL)
  while(p -> next != NULL && q -> next != NULL) {
    sum = p -> val + q -> val + carry;
    r -> val = (sum % 10);
    carry = sum >= 10 ? 1 : 0;
    printf("\n\033[38;5;220mp-value: %d, q-value: %d, r-value: %d, carry: %d, p-address: %d, q-address: %d, r-address: %d\033[0m", p -> val, q -> val, r -> val, carry, p, q, r);
    p = p -> next;
    q = q -> next;
    r -> next = (Node*)malloc(sizeof(Node));
    r = r -> next;
  }
  sum = p -> val + q -> val + carry;
  r -> val = (sum % 10);
  carry = sum >= 10 ? 1 : 0;

  // both numbers had equal noofdigits, possibilities are that the answer might have more digits or not
  if(p -> next == NULL && q -> next == NULL) {
    decide_final_node(carry, r);
    return ans;
  }
  
  // if the first LL has numbers left
  if(p -> next != NULL) {
    while(p -> next != NULL) {
      sum = p -> val + carry;
      r -> val = sum % 10;
      carry = sum >= 10 ? 1 : 0;
      printf("\n\033[38;5;85mp-value: %d, q-value: %d, r-value: %d, carry: %d, p-address: %d, q-address: %d, r-address: %d\033[0m", p -> val, q -> val, r -> val, carry, p, q, r);
      p = p -> next;
      r -> next = (Node*)malloc(sizeof(Node));
      r = r -> next;
    }
    sum = p -> val + carry;
    r -> val = sum % 10;
    carry = sum >= 10 ? 1 : 0;
  }
  // if the second LL has numbers left
  while(q -> next != NULL) {
    sum = q -> val + carry;
    r -> val = sum % 10;
    carry = sum >= 10 ? 1 : 0;
    printf("\nq-value: %d, r-value: %d, carry: %d", q -> val, r -> val, carry);
    q = q -> next;
    r -> next = (Node*)malloc(sizeof(Node));
    r = r -> next;
  }
  // sum = q -> val + carry;
  // r -> val = sum % 10;
  // carry = sum >= 10 ? 1 : 0;
  decide_final_node(carry, r);
  return ans;
}

void main() {
  Node* l1 = (Node*)malloc(sizeof(Node));
  Node* l2 = (Node*)malloc(sizeof(Node));
  Node* p = l1;
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = NULL;
//=========================================================================== Second LL 
  p = l2;
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;
  
  p -> val = 9;
  p -> next = (Node*)malloc(sizeof(Node));
  p = p -> next;

  p -> val = 9;
  p -> next = NULL;

  Node* ans = addTwoNumbers(l1, l2);
  p = ans;
  printf("\n");
  while(p != NULL) {
    printf("%d ", p -> val);
    p = p -> next;
  }
}

// there must be a point in giving the linked lists in reverse