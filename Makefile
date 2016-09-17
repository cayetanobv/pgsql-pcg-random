
EXTENSION     = pcg_random
MODULE_big    = $(EXTENSION)
DATA          = pcg_random--0.0.1.sql 						# script files to install

OBJS = src/pcg_random.o src/pcg-c-basic/pcg_basic.o
# OBJS = src/pgsql-pgc-random.o

# TARGETS = pcg-random
#
# all: $(TARGETS)
#
# clean:
# 	rm -f *.o $(TARGETS) pcg-c-basic/pcg_basic.o
#
# pcg-rng-test: pcg-random.o pcg-c-basic/pcg_basic.o

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
