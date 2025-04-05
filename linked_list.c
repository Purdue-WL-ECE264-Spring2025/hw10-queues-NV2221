#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
	struct list_node* out = malloc(sizeof(struct list_node));
	return out; 
}

void insert_at_head(struct linked_list *list, size_t value) {
	struct list_node *node = new_node(value);
	node -> value = value;
	if(list->head == NULL){
		list -> head = node;
	}
	else{
		node -> next = list -> head;
		list -> head = node;
	}
	return;
}

void insert_at_tail(struct linked_list *list, size_t value) {
	struct list_node * cur = list -> head;
	while(cur -> next != NULL){
		cur = cur -> next;
	}
	struct list_node* node = new_node(value);
	node -> next = NULL;
	cur -> next = node;
	return;
}

size_t remove_from_head(struct linked_list *list) { 
	struct list_node * temp = list -> head;
	size_t out;
	out = list -> head -> value;
	list -> head = list -> head -> next;
	free(temp);
	return out; 
}

size_t remove_from_tail(struct linked_list *list) { 
	size_t out;
	if(list -> head == NULL){
		return 0;
	}
	struct list_node* temp = list -> head;
	if (list->head->next == NULL){
		out = list->head->value;
		free(temp);
		list->head = NULL;
		return out;
	}

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
