# PostgreSQL C Extension: PCG-Random
PGSQL Extension to compute pseudo random numbers with PCG Random Number Generation library.

## How to use
- Compile source code.
```bash
$ make
$ make install
```
- Load this extension on PostgreSQL:
```sql
postgres@[local] ~>CREATE EXTENSION pcg_random;
CREATE EXTENSION
```
- Using the extension functions:

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

postgres@[local] ~>select pcg_random_array(5);
                   pcg_random_array                    
-------------------------------------------------------
 {820463269,460605526,-309849101,-625982128,271322389}
(1 row)

postgres@[local] ~>select pcg_random_bound_array(6,100);
 pcg_random_bound_array
------------------------
 {53,44,14,6,88,38}
(1 row)

postgres@[local] ~>select unnest(pcg_random_array(5)) as myresult;
  myresult   
-------------
  1047932521
 -1108075650
 -1221655856
    37262442
   523930964
(5 rows)
```

Performance (generating 1,000,000 random numbers):

```sql

postgres@[local] ~>select unnest(pcg_random_array(1000000)) as myresult;
  myresult   
-------------
  1133480166
  1379111184
  2100723887
   388373823
   512117098
  2065379777
 -1377196825
  -544835353
   157365482
 -1638627195
 -2076358158
 -1993131885
  1068188469
 -1726641504
   484564773
  1618828780
  ..........
  ..........
Time: 275.471 ms
```

## More info
More info about PCG-Random: http://www.pcg-random.org
