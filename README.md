# PostgreSQL C Extension: PCG-Random
PGSQL Extension to compute pseudo random numbers with PCG Random Number Generation library.

## How to use
- Compile source code.
- Load this extension on PostgreSQL:

```sql
postgres@[local] ~>CREATE EXTENSION pcg_random;
CREATE EXTENSION
```
- Use the extension functions:

```sql
postgres@[local] ~>select pcg_random();
 pcg_random
------------
  791006829
(1 row)

postgres@[local] ~>select pcg_random_bound(100);
 pcg_random_bound
------------------
               25
(1 row)

```

## More info
More info about PCG-Random: http://www.pcg-random.org
