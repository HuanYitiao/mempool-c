#include "mempool.h"

int mempool_init(mempool_t* mempool)
{
    for (int i = 0; i < mempool->block_count; i++)
    {
        node_t* node = (node_t*)(mempool->buffer + mempool->block_size * i);
        if (i == mempool->block_count - 1)
        {
            node->next = NULL;
        }
        else
        {
            node->next = (node_t*)(mempool->buffer + mempool->block_size * (i + 1));
        }
    }
    mempool->free_head = (node_t*)mempool->buffer;
    return 0;
}

void* mempool_alloc(mempool_t* mempool)
{
    if (NULL == mempool->free_head)
    {
        return NULL;
    }
    node_t* free_head  = mempool->free_head;
    mempool->free_head = free_head->next;
    return free_head;
}

void mempool_free(mempool_t* mempool, void* head)
{
    node_t* block      = (node_t*)head;
    block->next        = mempool->free_head;
    mempool->free_head = block;
}