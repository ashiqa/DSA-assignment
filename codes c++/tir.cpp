#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

void insert(struct Node* &head,int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
	struct Node* head = NULL;
   insert(head,3);
   insert(head,1);
   insert(head,7);
   insert(head,2);
   insert(head,9);
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}
