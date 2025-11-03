#pragma once

#include "hwangfu/generic.h"
#include "hwangfu/result.h"

typedef struct Dequeue Dequeue;

struct Dequeue
{
    u64             Size    ;
    u64             Capacity;
    arch       *    Data    ;
    dispose_fn *    Dispose ;
};

void dq_init(BORROWED Dequeue * dq, u64 capacity, dispose_fn * cleanup);

OWNED Dequeue * mk_dq();
OWNED Dequeue * mk_dq(dispose_fn * cleanup);
OWNED Dequeue * mk_dq2(u64 capacity, dispose_fn * cleanup);

arch dq_at(BORROWED Dequeue * dq, u64 idx);
void dq_pushfront(BORROWED Dequeue * dq, arch value);
void dq_pushback(BORROWED Dequeue * dq, arch value);
arch dq_front(BORROWED Dequeue * dq);
arch dq_back(BORROWED Dequeue * dq);
arch dq_popfront(BORROWED Dequeue * dq);
arch dq_popback(BORROWED Dequeue * dq);

OWNED Result * dq_try_at(BORROWED Dequeue * dq, u64 idx);
bool dq_try_pushfront(BORROWED Dequeue * dq, arch value);
bool dq_try_pushback(BORROWED Dequeue * dq, arch value);
OWNED Result * dq_try_front(BORROWED Dequeue * dq);
OWNED Result * dq_try_back(BORROWED Dequeue * dq);
OWNED Result * dq_try_popfront(BORROWED Dequeue * dq);
OWNED Result * dq_try_popback(BORROWED Dequeue * dq);





COPIED void * dq_dispose(OWNED void * arg);
