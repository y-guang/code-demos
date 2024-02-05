import numpy as np
import time
from functools import wraps
def timeit(func):
    @wraps(func)
    def timeit_wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = func(*args, **kwargs)
        end_time = time.perf_counter()
        total_time = end_time - start_time
        print(f'Function {func.__name__} Took {total_time:.4f} seconds')
        return result
    return timeit_wrapper

@timeit
def dirct_map(arr):
    num0 = np.uint8(10)
    num1 = np.uint8(20)
    arr[arr == 0] = num0
    arr[arr == 1] = num1
    return arr

@timeit
def times_map(arr):
    num0 = np.uint8(10)
    num1 = np.uint8(20)
    arr *= 10
    arr += 10
    return arr

arr1 = np.random.randint(0, 2, (10000, 10000), dtype=np.uint8)
arr2 = arr1.copy()

mapped1 = dirct_map(arr1)
mapped2 = times_map(arr2)