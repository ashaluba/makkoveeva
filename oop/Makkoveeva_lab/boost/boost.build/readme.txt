1. Загрузить последнюю версию библиотеки с https://www.boost.org.

2. Запустить bootstrap.bat (bootstrap.sh для unix-версий) в распакованном каталоге.

3. Скопировать boost.build.serialize.vc.cmd в распакованный каталог и запустить.
3.1 boost.build.serialize.mingw.cmd в случае mingw; уточнить путь в первой строке, если mingw из поставки Qt 
3.2 boost.build.serialize.linux.sh в случае linux
3.3 boost.build.serialize.linux.sh в случае macos

4. Указать в проекте либо Property Manager пути для включаемых файлов (путь до каталога boost) и библиотек (подкаталог stage/libs).
4.1 При использовании CMake указать путь в BOOST_ROOT, добавить:
	find_package(Boost) 
	include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${Boost_LIBRARY_DIRS})

Если в Property Manager нет разделов Microsoft.Cpp.Win32.user/Microsoft.Cpp.x64.user, 
создать каталог C:\Users\<Username>\AppData\Local\Microsoft\MSBuild\v4.0\
и скопировать в него файлы *.props.
