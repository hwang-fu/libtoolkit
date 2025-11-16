#include "vector.h"

/**
 * @since       16.11.2025
 * @author      Junzhe
 * @modified    16.11.2025
 */
struct VectorItem
{
    arch         Value;
    dispose_fn * Dispose;
};

