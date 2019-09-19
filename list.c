// list/list.c
// 
// Implementation for linked list.
//
// <Latifat Ozoya>

#include <stdio.h>
#include<stdlib.h> 

#include "list.h"

list_t *list_alloc() { 
    node_t* new_node;
    list_t* new_list;
    new_node = malloc(sizeof(node_t));
    new_list->head = new_node;
    return new_list; 
}

void list_free(list_t *l) {free(l);}

void list_print(list_t *l) {
    node_t *current = l->head;
	while (current != NULL) {
        printf(" %d ", current->value);
		current = current->next;
	}
}

int list_length(list_t *l) {
    node_t *current = l->head;
    int count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void list_add_to_back(list_t *l, elem value) {
	node_t *new_node;
	new_node->value = value;
    new_node->next = NULL;
    node_t *current = l->head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
	node_t *new_node;
	new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
    int ctr = 0;
    node_t *new_node;
	new_node->value = value;
    new_node->next = l->head;
    node_t *current = l->head;
    node_t *previous = NULL;

    while(ctr < index){
        previous = current;
        current = current->next;
        ctr++;
    }
    new_node->next = current;
    previous->next = new_node;
}

elem list_remove_from_back(list_t *l) { 
    elem val = 0;
    node_t *current = l->head;
    node_t *prev = NULL;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    val = current->value;
    list_t *remove;
    remove->head = current;
    list_free(remove);
    prev->next = NULL;
    return val;
}
elem list_remove_from_front(list_t *l) { 
    elem val = 0;
    node_t *current = l->head;
    val = current->value;
    l->head = current->next;
    list_t *remove;
    remove->head = current;
    list_free(remove);
    return val;
}

elem list_remove_at_index(list_t *l, int index) {
    if(index == 0){
        return list_remove_from_front(l);
    }
    else if(index == list_length(l) - 1){
        return list_remove_from_back(l);
    }
    elem val = 0;
    int ctr = 0;
    node_t *current = l->head;
    node_t *previous = NULL;
    while(ctr < index){
        ctr++;
        previous = current;
        current = current->next;
    }
    
    val = current->value;
    previous->next = current->next;
    list_t *remove;
    remove->head = current;
    list_free(remove);
    return val;
}

bool list_is_in(list_t *l, elem value) {
    node_t *current = l->head;
    while(current != NULL){
        if(current->value == value){
            return true;
        }
        current = current->next;
    }
    return false; 
}
elem list_get_elem_at(list_t *l, int index) {
    
    if(index == 0){
        return l->head->value;
    }
    int ctr = 0;
    node_t *current = l->head;
    while(ctr < index){
        ctr++;
        current = current->next;
    }
    return current->value;
}
int list_get_index_of(list_t *l, elem value) {
    
    int idx = 0;
    node_t*current = l->head;
    while(current != NULL){
        if(current->value == value){
            return idx;
        }
        idx++;
        current = current->next;
    }
    if(current == NULL && idx == 0){
        return -1;
    }
    return idx;
}
