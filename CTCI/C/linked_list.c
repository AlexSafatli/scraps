// LinkedList
// Author: Alex Safatli
// Date: Fri 16 Oct 2015

#include <stdlib.h>
#include "linked_list.h"

linked_list_t* linked_list_init() {

  linked_list_t* list = (linked_list_t*) malloc(sizeof(linked_list_t));
  if (list != NULL) {
    // Initialize head to NULL.
    list->head = NULL;
  }
  return list;

}

void linked_list_destroy(linked_list_t *list) {

  node_t *temp = NULL;
  if (list != NULL) {
    while (list->head != NULL) {
      // Keep setting head to next node. Free along the way.
      temp = list->head;
      list->head = list->head->next;
      free(temp);
    }
    list->head = NULL;
  }    

}

int linked_list_get(linked_list_t *list, int pos, void **data) {

  int status = 0, i = 0;
  if (list != NULL && list->head != NULL) {
    node_t *temp = list->head;
    while (temp->next != NULL && i++ < pos) temp = temp->next;
    if (i-1 == pos) {
      *data = temp->data;
      status = 1;
    }
  }
  return status;

}

int linked_list_append_to_head(linked_list_t *list, void *data) {

  int status = 0;
  if (list != NULL) {
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if (node != NULL) {
      node->next = list->head;
      node->data = data;
      list->head = node;
      status = 1;
    }
  }
  return status;
  
}

int linked_list_remove_head(linked_list_t *list, void **data) {

  int status = 0;
  if (list != NULL && data != NULL) {
    if (list->head != NULL) {
      // Get data.
      *data = list->head->data;
      // Remove node.
      node_t *temp = list->head;
      list->head = temp->next;
      free(temp);
      status = 1;
    }
    else *data = NULL;
  }
  return status;

}

int linked_list_append_to_tail(linked_list_t *list, void *data) {

  int status = 0;
  if (list != NULL) {
    if (list->head != NULL) {
      node_t *node = (node_t*) malloc(sizeof(node_t));
      if (node != NULL) {
        node_t *temp = list->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
        node->next = NULL;
        node->data = data;
        status = 1;
      }
    }
  }
  return status;

}

int linked_list_remove_tail(linked_list_t *list, void **data) {

  int status = 0;
  if (list != NULL && data != NULL) {
    if (list->head != NULL) {
      // Go to tail.
      node_t *prev = NULL;
      node_t *temp = list->head;
      while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
      }
      // Get data.
      *data = temp->data;
      // Remove node.
      if (prev != NULL) prev->next = temp->next;
      else list->head = NULL;
      free(temp);
      status = 1;
    }
    else *data = NULL;
  }
  return status;

}
