#include<iostream>

using namespace std;

struct list {
	int value;
	struct list *next;
};
 
typedef struct list LIST;

bool insert_list(struct list *head, int i) {
	 struct list *current = (struct list *)malloc(sizeof(struct list));
	 if (current==NULL) {
		return false;
	 }
	 current->value = i;
	 struct list *next = head->next;
	 current->next = next;
	 head->next = current;
	 return true;
}


void print_list(struct list *head) {
	while(head!=NULL) {
		cout << head->value << "	";
		head = head ->next;
	}
	cout<<endl;
}

LIST* reverse_list(LIST *head){
	LIST* pre = NULL;
	LIST* next;
	while(head) {
        /// key 
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

int main() {
	struct list *head = (struct list *)malloc(sizeof(struct list));
	head->value = 3;
	head->next = NULL;
 
	insert_list(head,1);
	insert_list(head,2);
	print_list(head);
	
	print_list(reverse_list(head));
	return 0;
}
