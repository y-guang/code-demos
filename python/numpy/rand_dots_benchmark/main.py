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
        print(f'Function {func.__name__}{args} {kwargs} Took {total_time:.4f} seconds')
        return result
    return timeit_wrapper

@timeit
def get_rand_dots(shape: tuple, light, dark):
    pic = np.random.randint(0, 2, shape, dtype=np.uint8)
    pic[pic == 0] = dark
    pic[pic == 1] = light
    return pic

@timeit
def get_rand_dots_times_mapping(shape: tuple, light, dark):
    """
    replacing with times calculation
    """
    pic = np.random.randint(0, 2, shape, dtype=np.uint8)
    diff = light - dark
    pic *= diff
    pic += dark
    return pic

@timeit
def gen_rand_dots_opt(shape: tuple, light, dark):
    """
    utilizing all bits for random number
    """
    height, width = shape
    rand_int32_cnt = height * width
    rand_int32_cnt = (rand_int32_cnt + 31) // 32
    # note here introduces a memory allocation, which is not desired
    seeds = np.random.randint(0, 1 << 32, rand_int32_cnt, dtype=np.uint32)
    seeds = seeds.view(dtype=np.uint8)
    pic = np.unpackbits(seeds)
    pic.resize((height, width))
    diff = light - dark
    pic *= diff
    pic += dark
    return pic

# benchmark
shape = (120 * 1920, 1080)
mapped1 = get_rand_dots(shape, 22, 11)
mapped2 = get_rand_dots_times_mapping(shape, 22, 11)
mapped3 = gen_rand_dots_opt(shape, 22, 11)

# check the result contains both light and dark
print(mapped1[0,:10])
print(mapped2[0,:10])
print(mapped3[0,:10])
