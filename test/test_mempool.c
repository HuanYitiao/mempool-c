#include "mempool.h"
#include "unity.h"

#define BLOCKSIZE  16
#define BLOCKCOUNT 3

static uint8_t buffer[BLOCKSIZE * BLOCKCOUNT];
mempool_t      mempool;

void setUp(void)
{
    mempool.block_count = BLOCKCOUNT;
    mempool.block_size  = BLOCKSIZE;
    mempool.buffer      = buffer;
    mempool_init(&mempool);
}

void tearDown(void)
{
}

void test_init(void)
{
    TEST_ASSERT_NOT_NULL(mempool.free_head);
}

void test_alloc(void)
{
    node_t* old_head = mempool_alloc(&mempool);
    TEST_ASSERT_NOT_NULL(old_head);
    TEST_ASSERT_NOT_EQUAL(old_head, mempool.free_head);
}

void test_free(void)
{
    node_t* old_head = mempool_alloc(&mempool);
    mempool_free(&mempool, old_head);
    TEST_ASSERT_EQUAL(old_head, mempool.free_head);
}

void test_alloc_exhausted(void)
{
    for (int i = 0; i < BLOCKCOUNT; i++)
    {
        mempool_alloc(&mempool);
    }
    TEST_ASSERT_NULL(mempool_alloc(&mempool));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    RUN_TEST(test_alloc);
    RUN_TEST(test_free);
    RUN_TEST(test_alloc_exhausted);
    return UNITY_END();
}