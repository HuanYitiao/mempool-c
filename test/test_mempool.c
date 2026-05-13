#include "mempool.h"
#include "unity.h"

#define BLOCKSIZE  16
#define BLOCKCOUNT 3

void setUp(void)
{
}
void tearDown(void)
{
}

void test_init(void)
{
    static uint8_t buffer[BLOCKSIZE * BLOCKCOUNT];
    mempool_t      mempool;
    mempool.block_count = BLOCKCOUNT;
    mempool.block_size  = BLOCKSIZE;
    mempool.buffer      = buffer;
    mempool_init(&mempool);
    TEST_ASSERT_NOT_NULL(mempool.free_head);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    return UNITY_END();
}