# Get the registry value where the path of the current wallpaper is stored
$registryPath = "HKCU:\Control Panel\Desktop"
$registryValue = "WallPaper"
$currentWallpaperPath = (Get-ItemProperty -Path $registryPath -Name $registryValue).$registryValue

# Output the current wallpaper path
$currentWallpaperPath