#include "mallocCollector.h"

t_mallocCollector *malloc_start()
{
    t_mallocCollector *mc = (t_mallocCollector *)malloc(sizeof(t_mallocCollector));
    if (mc != NULL)
    {
        mc->new_malloc = NULL;
        mc->next = NULL;
    }
    return mc;
}

void *new_malloc(t_mallocCollector *mc, size_t size)
{
    if (mc == NULL)
    {
        return NULL;
    }

    void *ptr = malloc(size);
    if (ptr != NULL)
    {
        t_mallocCollector *newNode = (t_mallocCollector *)malloc(sizeof(t_mallocCollector));
        if (newNode != NULL)
        {
            newNode->new_malloc = ptr;
            newNode->next = mc->next;
            mc->next = newNode;
        }
    }
    return ptr;
}

void delete_malloc(t_mallocCollector *mc, void *ptr_to_delete)
{
    if (mc == NULL || ptr_to_delete == NULL)
    {
        return;
    }

    t_mallocCollector *current = mc;
    t_mallocCollector *prev = NULL;

    while (current != NULL && current->new_malloc != ptr_to_delete)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (prev == NULL)
            mc = current->next;
        else
            prev->next = current->next;

        if (current->new_malloc)
            free(current->new_malloc);
        free(current);
    }
}

void end_malloc(t_mallocCollector *mc)
{
    if (mc->next != NULL)
        end_malloc(mc->next);
    if (mc->new_malloc)
        free(mc->new_malloc);
    free(mc);
}
