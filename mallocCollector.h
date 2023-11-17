#ifndef MALLOCCOLLECTOR_H
#define MALLOCCOLLECTOR_H

#include <stdlib.h>

typedef struct s_mallocCollector
{
    void *new_malloc;
    struct s_mallocCollector *next;
} t_mallocCollector;

/* Garbage collector'i baslatan fonksiyon */
t_mallocCollector *malloc_start();

// Yeni bellek alani ayiran fonksiyon
void *new_malloc(t_mallocCollector *mc, size_t size);

// olusturulan bir bellegi silen fonksiyon
void delete_malloc(t_mallocCollector *mc, void *ptr_to_delete);

// Garbage collector'i sonlandiran fonksiyon
void end_malloc(t_mallocCollector *mc);


#endif
