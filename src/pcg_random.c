/*
 * PGSQL Extension to compute pseudo random numbers with
 * PCG Random Number Generation library.
 *
 * Cayetano Benavent 2016.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include <postgres.h>
#include <fmgr.h>
#include <utils/numeric.h>

#include "pcg-c-basic/pcg_basic.h"

PG_MODULE_MAGIC;


PG_FUNCTION_INFO_V1(pcg_random);
Datum
pcg_random(PG_FUNCTION_ARGS)
{

    int32 seedinitseq;
    uint32_t result;
    pcg32_random_t rng;

    seedinitseq = PG_GETARG_INT32(0);

    pcg32_srandom_r(&rng, time(NULL) ^ (intptr_t)&printf,(intptr_t)&seedinitseq);

    result = pcg32_random_r(&rng);

    PG_RETURN_UINT32(result);
}


PG_FUNCTION_INFO_V1(pcg_random_bound);
Datum
pcg_random_bound(PG_FUNCTION_ARGS)
{

    int32 seedinitseq;
    uint32_t bound;
    uint32_t result;
    pcg32_random_t rng;

    bound = PG_GETARG_INT32(0);
    seedinitseq = PG_GETARG_INT32(1);

    pcg32_srandom_r(&rng, time(NULL) ^ (intptr_t)&printf,(intptr_t)&seedinitseq);

    result = pcg32_boundedrand_r(&rng, bound);

    PG_RETURN_UINT32(result);
}
