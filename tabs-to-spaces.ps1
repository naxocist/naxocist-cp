Get-ChildItem -Recurse -Include *.cpp, *.hpp, *.h, *.c | ForEach-Object {
    $filePath = $_.FullName
    $content = Get-Content $filePath -Raw
    $newContent = $content -replace "`t", "  "  # Replace each tab with 2 spaces
    if ($content -ne $newContent) {
        Set-Content $filePath $newContent
        Write-Host "Updated: $filePath"
    }
}
