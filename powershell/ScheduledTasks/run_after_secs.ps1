# get path
$currentDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$wokerPath = Join-Path -Path $currentDir -ChildPath "work.ps1"
$taskName = "RunWorkScript"
$delay = 5

# Define action to execute work.ps1
$action = New-ScheduledTaskAction `
-Execute 'powershell' `
-Argument "-NoProfile -WindowStyle Hidden -ExecutionPolicy Bypass -File $wokerPath"

# Define trigger
$startTime = (Get-Date).AddSeconds($delay)
$trigger = New-ScheduledTaskTrigger -At $startTime -Once

Register-ScheduledTask -Action $action -Trigger $trigger -TaskName $taskName -Description "Run work.ps1 after $delay seconds"