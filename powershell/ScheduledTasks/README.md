# ScheduledTasks

## Ref

[PowerShell - ScheduledTasks](https://learn.microsoft.com/en-us/powershell/module/scheduledtasks/?view=windowsserver2022-ps)

[Information about Tasks](https://learn.microsoft.com/en-us/windows/win32/taskschd/tasks)

[allow expire](https://iamsupergeek.com/self-deleting-scheduled-task-via-powershell/)

## triggered by time

[run_after_10_sec.ps1](run_after_10_sec.ps1)

Note: we need to run following to clean up the task.

```powershell
Unregister-ScheduledTask -TaskName "RunWorkScript" -Confirm:$false
```