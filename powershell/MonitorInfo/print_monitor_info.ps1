# Retrieve instances of WMI objects for monitors
$monitors = Get-WmiObject WmiMonitorID -Namespace root\wmi

# Loop through each monitor and extract details
foreach ($monitor in $monitors) {
    $manufacturer = ($monitor.ManufacturerName -notmatch 0 | foreach { [char]$_ }) -join ""
    $serial = ($monitor.SerialNumberID -notmatch 0 | foreach { [char]$_ }) -join ""
    $InstanceName = $monitor.InstanceName

    # Output the information
    Write-Host "Manufacturer: $manufacturer"
    Write-Host "Serial Number: $serial"
    Write-Host "InstanceName: $InstanceName"
    Write-Host "----------------"
}
Write-Host "sample output"
$monitor