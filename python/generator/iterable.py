"""
Iterable -> Iterator
        生成

Iterator 实现了
- __iter__
- __next__

Reflection:
- 尽管以下代码使用了继承, 但继承不是必须的. 这体现了 Duck type.
"""

from collections.abc import Iterable, Iterator


class MyRange(Iterable):
    def __init__(self, lower, upper):
        self.lower = lower
        self.upper = upper

    def __iter__(self):
        return MyRangeIterator(self.lower, self.upper)


class MyRangeIterator(Iterator):
    def __init__(self, lower, upper):
        self.current = lower
        self.upper = upper

    def __iter__(self):
        return self

    def __next__(self):
        if self.current >= self.upper:
            raise StopIteration
        else:
            self.current += 1
            return self.current - 1


my_range = MyRange(0, 5)
for i in my_range:
    print(i)
