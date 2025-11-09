#pragma once

#include <hwangfu/generic.h>

/**
 * @since       09.11.2025
 * @author      Junzhe
 * @modified    09.11.2025
 */
u64 GreatestCommonDivisor(u64 a, u64 b);

/**
 * @since       09.11.2025
 * @author      Junzhe
 * @modified    09.11.2025
 */
u64 LeastCommonMultiple(u64 a, u64 b);

/**
 * @since       09.11.2025
 * @author      Junzhe
 * @modified    09.11.2025
 */
OWNED u64 * SieveEratosthenes(u64 upto);
