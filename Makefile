
# PGSQL Extension to compute pseudo random numbers with
# PCG Random Number Generation library.
#
# Cayetano Benavent 2016.


EXTENSION     = pcg_random
MODULE_big    = $(EXTENSION)
DATA          = pcg_random--0.0.1.sql

OBJS = src/pcg_random.o src/pcg-c-basic/pcg_basic.o

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
