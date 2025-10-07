@echo off
set vh="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

for /f "usebackq delims=" %%i in (`%vh% -prerelease -latest -property installationPath`) do (
  if exist "%%i\Common7\Tools\VsMSBuildCmd.bat" (
    call "%%i\Common7\Tools\VsMSBuildCmd.bat" %*
  )
)

b2.exe --layout=versioned --with-serialization link=static runtime-link=shared threading=multi toolset=msvc-14.3

