#include "linked_list.h"
#include <stdio.h>

int main(void) {
  int a = 5;
  int b = 6;
  linked_list_t* list = linked_list_init();
  linked_list_append_to_head(list, &a);
  linked_list_append_to_head(list, &b);
  int *ptr;
  while (linked_list_remove_head(list, (void**) &ptr)) {
    printf("%d ", *ptr);
  } printf("\n");
  linked_list_destroy(list);
  return 0;
}
