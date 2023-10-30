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
$trigger.EndBoundary = "{0:yyyy-MM-dd'T'HH:mm:ss}" -f $startTime.AddSeconds(5) # trick needed for setting the -DeleteExpiredTaskAfter

#setting
$setting = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -DeleteExpiredTaskAfter (New-TimeSpan -Seconds 0)

Register-ScheduledTask -Action $action -Trigger $trigger -TaskName $taskName -Description "Run work.ps1 after $delay seconds" -Settings $setting