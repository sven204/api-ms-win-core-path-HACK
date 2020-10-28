# api-ms-win-core-path-l1-1-0.dll HACK
This is an (extremely) hacky implementation of some of the functions in the original `api-ms-win-core-path-l1-1-0.dll` bundled with Windows 8.1/Server 2012 and later, required so that Python 3.9+ will work on Windows 7.
## But why?
The Python 3.9.0 installers prevent installation on Windows 7.  
Furthermore, Python 3.9.0 will not run on Windows 7 because the Python executable depends on `api-ms-win-core-path-l1-1-0.dll` which, AFAIK, does not exist for Windows 7.

However, the Python executable only imports `PathCchCanonicalizeEx` and `PathCchCombineEx` from `api-ms-win-core-path-l1-1-0.dll`, so this project implements these two functions.
## Installation of Python 3.9.0 with the hack (tested on Windows 7 x64 only)
1. Install Python 3.9.0 from the [embeddable .zip file](//www.python.org/ftp/python/3.9.0/python-3.9.0-embed-amd64.zip).
2. Install a C/C++ compiler (for now, there is no binary release). I used the compiler available from [mingw-w64.org](//mingw-w64.org/doku.php/download/mingw-builds) -- however, it's hosted on Sourceforge, so choose it at your own risk.
3. Compile `api-ms-win-core-path-HACK.cpp`. Add the flags `-shared` to create a DLL and `-lshlwapi` to properly link with another Windows DLL.
4. Make sure the output DLL is named `api-ms-win-core-path-l1-1-0.dll`.
5. Move the DLL to System32 or another directory in your PATH environment variable.
