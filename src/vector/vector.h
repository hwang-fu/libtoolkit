#pragma once

#include <hwangfu/generic.h>
#include <hwangfu/assertion.h>
#include <hwangfu/memory.h>
#include <hwangfu/result.h>

#ifndef VECTOR_DEFAULT_CAPACITY
#define VECTOR_DEFAULT_CAPACITY (20)
#endif // VECTOR_DEFAULT_CAPACITY

typedef struct Vector Vector;
typedef struct VectorData VectorData ;

/**
 * @since       16.11.2025
 * @author      Junzhe
 * @modified    16.11.2025
 */
struct Vector
{
          u64           Capacity;
          u64           Size;
    OWNED VectorItem ** Items;
};

/**
 * @since       16.11.2025
 * @author      Junzhe
 * @modified    16.11.2025
 */
OWNED Vector * vector_init(OWNED Vector * vec, u64 capacity);

/**
 * @since       16.11.2025
 * @author      Junzhe
 * @modified    16.11.2025
 *
 * @brief       Customize a @struct {Vector}.
 *
 * Possible overloads:
 * @li OWNED Vector * mk_vector(0)
 * @li OWNED Vector * mk_vector(1, u64 capacity)
 */
OWNED Vector * mk_vector(int mode, ...);
