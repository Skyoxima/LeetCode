#include<stdio.h>
#include<stdlib.h>

typedef struct LL_Node {
  int val;
  struct LL_Node* next;
}ListNode;


ListNode* addTwoLL(ListNode* l1, ListNode* l2) {
  ListNode *ans = (ListNode*)malloc(sizeof(ListNode));
  ListNode *p = l1, *q = l2, *r = ans;
  int carry = 0, sum;

  while(p -> next != NULL && q -> next != NULL) {
    sum = p -> val + q -> val + carry;
    carry = sum >= 10 ? 1 : 0;
    r -> val = sum % 10;
    p = p -> next;
    q = q -> next;
    r -> next = (ListNode*)malloc(sizeof(ListNode));
    r = r -> next;
  }
  sum = p -> val + q -> val + carry;
  carry = sum >= 10 ? 1 : 0;
  r -> val = sum % 10;

  if(p -> next == NULL && q -> next == NULL) {
    if(carry == 1) {
      r -> next = (ListNode*)malloc(sizeof(ListNode));
      r = r -> next;
      r -> val = carry;
      r -> next = NULL;
    } else {
      r -> next = NULL;
    }
  }

  if(p -> next != NULL) {
    r -> next = (ListNode*)malloc(sizeof(ListNode));
    r = r -> next;
    p = p -> next;
    while(p -> next != NULL) {
      sum = p -> val + carry;
      carry = sum >= 10 ? 1 : 0;
      r -> val = sum % 10;
      p = p -> next;
      r -> next = (ListNode*)malloc(sizeof(ListNode));
      r = r -> next;
    }
    sum = p -> val + carry;
    carry = sum >= 10 ? 1 : 0;
    r -> val = sum % 10;
    if(carry == 1) {
      r -> next = (ListNode*)malloc(sizeof(ListNode));
      r = r -> next;
      r -> val = carry;
      r -> next = NULL;
    } else {
      r -> next = NULL;
    }
  }
  
  if(q -> next != NULL) {
    r -> next = (ListNode*)malloc(sizeof(ListNode));
    r = r -> next;
    q = q -> next;
    while(q -> next != NULL) {
      sum = q -> val + carry;
      carry = sum >= 10 ? 1 : 0;
      r -> val = sum % 10;
      q = q -> next;
      r -> next = (ListNode*)malloc(sizeof(ListNode));
      r = r -> next;
    }
    sum = q -> val + carry;
    carry = sum >= 10 ? 1 : 0;
    r -> val = sum % 10;
    if(carry == 1) {
      r -> next = (ListNode*)malloc(sizeof(ListNode));
      r = r -> next;
      r -> val = carry;
      r -> next = NULL;
    } else {
      r -> next = NULL;
    }
  }

  return ans;
}

void main() {
  int i;
  ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
  ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
  ListNode* p = l1;
  // 0, 1, 2 and then 3rd index (i.e 4th node) handled outside the loop for proper NULL termination
  for(i = 0; i < 6; i++) {
    p -> val = 9;
    p -> next = (ListNode*)malloc(sizeof(ListNode));
    p = p -> next;
  }
  p -> val = 9;
  p -> next = NULL;
  
  p = l2;
  for(i = 0; i < 3; i++) {
    p -> val = 9;
    p -> next = (ListNode*)malloc(sizeof(ListNode));
    p = p -> next;
  }
  p -> val = 9;
  p -> next = NULL;

  p = addTwoLL(l1, l2);
  while(p != NULL) {
    printf("\nval = %d, address = %d", p -> val, p);
    p = p -> next;
  }
}