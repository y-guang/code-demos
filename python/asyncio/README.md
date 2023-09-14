# asyncio

本质是, 利用单进程解决多个 task 的调度模型.

- 优点
  - 无 context 切换开销, 进程创建等开销. 因此, 利于大量小任务.
- 缺点
  - 单进程. 无多核资源利用.

## simple

The flow of simple:

```mermaid
sequenceDiagram
    participant main
    participant tsk1 as task1
    participant tsk2 as task2

    main->>main: start
    main->>tsk1: create_task(wait_sec(1, "task1"))
    main->>tsk2: create_task(wait_sec(2, "task2"))

    tsk1->>tsk1: start wait
    tsk2->>tsk2: start wait
    Note right of tsk1: sleep 1 sec
    tsk1-->>main: finished
    main->>main: task1 finished

    Note right of tsk2: sleep 2 sec
    tsk2-->>main: finished
    main->>main: stop
```

key ideas:
- task 共享资源.
- 类似 CPU 分时调用. wait 时类似挂起.
- wait时, 所有 task 时间流逝一致, 都是真实世界时间. 类似闹钟.