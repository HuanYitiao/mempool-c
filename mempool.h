#include <stddef.h>
#include <stdint.h>

typedef struct node
{
    struct node* next;
} node_t;

typedef struct
{
    uint8_t* buffer;
    size_t   block_size;
    size_t   block_count;
    node_t*  free_head;
} mempool_t;

int   mempool_init(mempool_t* mempool);
void* mempool_alloc(mempool_t* mempool);
void  mempool_free(mempool_t* mempool, void* head);