#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { return NULL; }

void insert_at_head(struct linked_list *list, size_t value) {
	struct list_node new_node = {value, list -> head -> next};
	list -> head = &new_node;
	return;
}

void insert_at_tail(struct linked_list *list, size_t value) {
	struct list_node * cur = list -> head;
	while(cur -> next != NULL){
		cur = cur -> next;
	}
	struct list_node new_node = {value, NULL};
	cur -> next = &new_node;
	return;
}

size_t remove_from_head(struct linked_list *list) { 
	struct list_node * temp = list -> head;
	size_t out;
	out = list -> head -> val;
	list -> head = list -> head -> next;
	free(temp);
	return out; 
}

size_t remove_from_tail(struct linked_list *list) { 
	struct list_node * temp = list -> head;
	size_t out;
	while(temp -> next -> next != NULL){
		temp = temp -> next;
	}
	out = temp ->next -> value;
	free(temp -> next);
	temp -> next = NULL;
	return out; 
}

void free_list(struct linked_list list) {
	while(list.head != NULL){
		remove_from_head(&list);
	}
	return;
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
