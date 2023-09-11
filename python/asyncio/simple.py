"""
Following graph show part of the code logic.
-------------------------------------------------------------------
tsk2           |                |-sleep-|   |-1sec-|
tsk1  |                 |-sleep-|           |
main -|-create-|-create-|await              |      |-await-finished
-------------------------------------------------------------------
"""

import asyncio
import time

start = time.time()


def get_sec() -> int:
    return int(round(time.time() - start, 0))


async def wait_sec(delay, who):
    print(f"\t[{who}] start wait at sec {get_sec()}")
    await asyncio.sleep(delay)
    print(f"\t[{who}] stop wait at sec {get_sec()}")


async def main():
    task1 = asyncio.create_task(wait_sec(1, "task1"))
    task2 = asyncio.create_task(wait_sec(2, "task2"))

    print("[main] start at sec", get_sec())

    await task1
    print("[main] task1 finished at sec", get_sec())
    await task2

    print("[main] stop at sec", get_sec())


asyncio.run(main())