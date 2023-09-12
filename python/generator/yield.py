"""
相较于 Iterable, yield 引入了一种更自然的写法. 可以直接将其视为一种替代 Iterable 的语法糖.
"""


def my_range(lower, upper):
    curr = lower
    while curr < upper:
        yield curr
        curr += 1


ran = my_range(0, 5)
print(type(ran))
for i in my_range(0, 5):
    print(i)
