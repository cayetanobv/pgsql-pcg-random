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
postgres@[local] ~>SELECT pcg_random(0);
 pcg_random
------------
 -900850644
(1 row)

postgres@[local] ~>SELECT pcg_random_bound(0,100);
 pcg_random_bound
------------------
               95
(1 row)
```

## More info
More info about PCG-Random: http://www.pcg-random.org
