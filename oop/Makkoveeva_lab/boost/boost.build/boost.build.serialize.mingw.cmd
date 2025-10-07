call C:\QT\6.8.0\mingw_64\bin\qtenv2.bat 
cd /d %~dp0
b2.exe --layout=versioned --with-serialization link=shared runtime-link=shared address-model=64 threading=multi toolset=gcc
