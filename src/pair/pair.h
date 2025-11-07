#pragma once

#include <stdarg.h>

#include <hwangfu/generic.h>
#include <hwangfu/assertion.h>
#include <hwangfu/result.h>
#include <hwangfu/memory.h>

typedef struct Pair Pair;

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
struct Pair
{
    arch First;
    arch Second;
    dispose_fn * DisposeFirst;
    dispose_fn * DisposeSecond;
};

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
OWNED Pair * pair_init(OWNED Pair * pair, arch fst, arch snd, dispose_fn * cleanup1, dispose_fn * cleanup2);

/**
 * @since       06.11.2025
 * @author      Junzhe
 * @modified    06.11.2025
 *
 * @brief       Customize a @struct {Pair}.
 *
 * Possible overloads:
 * @li OWNED Pair * mk_pair(0, arch fst, arch snd)
 * @li OWNED Pair * mk_pair(1, arch fst, arch snd, dispose_fn * cleanup1, dispose_fn * cleanup2)
 * @li OWNED Pair * mk_pair(2, arch fst, arch snd, dispose_fn * cleanup1)
 * @li OWNED Pair * mk_pair(3, arch fst, arch snd, dispose_fn * cleanup2)
 */
OWNED Pair * mk_pair(int mode, ...);

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
arch pair_fst(BORROWED Pair * pair);

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
arch pair_snd(BORROWED Pair * pair);

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
OWNED Result * pair_try_fst(BORROWED Pair * pair);

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
OWNED Result * pair_try_snd(BORROWED Pair * pair);

/**
 * @since       07.11.2025
 * @author      Junzhe
 * @modified    07.11.2025
 *
 */
COPIED void * pair_dispose(OWNED void * arg);

