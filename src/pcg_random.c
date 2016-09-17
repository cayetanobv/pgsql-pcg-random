
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
