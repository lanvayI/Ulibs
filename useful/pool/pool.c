#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pool.h"

pool* Create_Pool(size_t s, size_t nblocks){
    pool* tmp = (pool*)malloc(sizeof(pool));
    if(tmp==NULL){puts("failed to alloc pool"); return NULL;}
    uint32_t* memtmp = (uint32_t*)calloc(nblocks,s);
    if(memtmp == NULL){free(tmp);puts("falied to alloc mem for pool"); return NULL;}

    tmp->mem = memtmp;
    tmp->n_blocks = nblocks;
    tmp->size = s;
    tmp->freelist = (block*)tmp->mem;
    block* current = tmp->freelist;

    for(size_t i=0; i < nblocks-1;i++){
        current->next = (block*)(unsigned char*)current + tmp->size;
        current = current->next;
    }
    current->next = NULL;

    return tmp;
}

void* PoolAlloc(pool* p){
    if(p->freelist == NULL){puts("full pool"); return NULL;}
    block* ptr = p->freelist;
    p->freelist = p->freelist->next;

    return (void*)ptr;
}

void PoolDealloc(pool* p, void* ptr){
    block* b = (block*)ptr;
    b->next = p->freelist;
    p->freelist = b;
}

void freePool(pool* p){
    if(p==NULL){return;}
    free(p->mem);
    free(p);
}