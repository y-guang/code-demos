# Comparing atomic_fetch_add with Big Lock Serial Add

## Observation

Atomic add, i.e. `atomic_fetch_add`, get worse performance than serial add with big lock.

Also, we see that `atomic_fetch_add` with `memory_order_relaxed` is faster than `memory_order_seq_cst`.

### atomic add is not that bad

However, in our experiment, the only workloads is adding 1 to a variable. There are 1e9 such operations. If we have significant workload to parallelize, the cost of locking and unlocking the big lock will be amortized. The the cost is not unacceptable.

In fact, considering consistency problems, this result of `./atomic` is surprisingly fast, and there must be some optimization within the cpu for this.

### mutex is very slow

using mutex to do atomic add is very slow. Avoid it.

```bash
time ./serial
real    0m0.054s
user    0m0.055s
sys     0m0.000s

time ./atomic
real    0m0.727s
user    0m6.034s
sys     0m0.001s

time ./atomic_strict
real    0m0.843s
user    0m7.266s
sys     0m0.001s

time ./mutex
real    0m4.473s
user    0m6.445s
sys     0m34.610s
```