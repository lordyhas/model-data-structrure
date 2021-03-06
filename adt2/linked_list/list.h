
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct listElmt_ {
    void *data;
    struct listElmt_*next;

} *ListElement, ListElement_;

typedef struct list_ {
    int size;
    ListElement key;
    //int (*match)(const void *key1, const void *key2);
    //void (*destroy)(void *data);
    ListElement head;
    ListElement tail;
} List_, *List;

ListElement creatrElement();
void list_init(List list, void (*destroy)(void *data));
void list_destroy(List list);
int list_insert_next(List list, ListElement element, const void *data);
int list_remove_next(List list, ListElement element, void **data);

int list_insert_head(List list, void * data);
int list_insert_tail(List list, void * data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_is_empty(list) ((list)->size == 0 ? 1 : 0)

#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)


#endif