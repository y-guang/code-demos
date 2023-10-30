# Task

The Task Scheduler allows the program to be run automatically when driven by a specific time or event.

Compared with daemon process, the significant benefits is that it avoids memory cost during idle time.

The `at` tool on Windows.

## ref

- Usage ref: [taskscheduler test cases](https://github.com/mhammond/pywin32/tree/main/com/win32comext/taskscheduler/test)
- API doc: 
  - [Using the Task Scheduler](https://learn.microsoft.com/en-us/windows/win32/taskschd/using-the-task-scheduler)
  - [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/en-us/windows/win32/taskschd/task-scheduler-2-0-interfaces)
  - [ITaskScheduler interface (mstask.h)](https://learn.microsoft.com/en-us/windows/win32/api/mstask/nn-mstask-itaskscheduler)

## alternative

Powershell scripts, see [New-ScheduledTask](https://learn.microsoft.com/en-us/powershell/module/scheduledtasks/new-scheduledtask?view=windowsserver2022-ps)
