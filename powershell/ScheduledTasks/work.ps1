# provide a trivial task for testing
# just pop-up a message box

Add-Type -AssemblyName PresentationFramework
[System.Windows.MessageBox]::Show('Hello World')