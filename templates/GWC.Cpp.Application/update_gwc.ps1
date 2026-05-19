#
# :.:.:.:.:.:.:.
# update_gwc.ps1
# :.:.:.:.:.:.:.
#
# Utility di Aggiornamento delle
# inclusioni e delle librerie di
# GWC.
#

$updatePack = "GWC.Cpp.UpdatePack.zip"

$uri = "https://api.github.com/repos/reallukee/gwc/releases"

$releases = Invoke-RestMethod -Uri $uri

#
# Ordine di preferenza di DEFAULT:
#
#  Se NON ci sono Pre-Release -> :(
#  Se NON ci sono Release     -> Ultima Pre-Release
#  Se ci sono Release         -> Utltma Release
#

# Cerco una Release
$target = $releases | Where-Object {
    $_.prerelease -eq $false
} | Sort-Object published_at -Descending | Select-Object -First 1

# Cerco una Pre-Release
if (-not $target) {
    $target = $releases | Where-Object {
        $_.prerelease -eq $true
    } | Sort-Object published_at -Descending | Select-Object -First 1
}

if (-not $target) {
    exit 1
}

$asset = $target.assets | Where-Object name -eq $updatePack

if (-not $asset) {
    exit 1
}

Invoke-WebRequest -Uri $asset.browser_download_url -OutFile "UpdatePack.zip"

# Creo Backup
$timestamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"

New-Item -Path "gwc.old_${timestamp}" -ItemType Directory

if (Test-Path -Path "include") {
    Move-Item -Path "include" -Destination "gwc.old_${timestamp}\include"
}

if (Test-Path -Path "static") {
    Move-Item -Path "static" -Destination "gwc.old_${timestamp}\static"
}

if (Test-Path -Path "shared") {
    Move-Item -Path "shared" -Destination "gwc.old_${timestamp}\shared"
}

# Aggiorno
Expand-Archive -Path "UpdatePack.zip" -DestinationPath .

# Clean-Up
Remove-Item -Path "UpdatePack.zip" -Force
