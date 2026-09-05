#ifndef POOL_H
#define POOL_H

typedef unsigned int uint32_t;

typedef struct block{
    struct block *next;
}block;

typedef struct pool{
    uint32_t* mem;
    block* freelist;
    size_t size,n_blocks;
}pool;

pool* Create_Pool(size_t s, size_t nblocks);
void* PoolAlloc(pool* p);
void PoolDealloc(pool* p, void* ptr);
void freePool(pool* p);
#endif