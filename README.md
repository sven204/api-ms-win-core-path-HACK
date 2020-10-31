# Python 3.9+ on Windows 7
## What is this?
This project reimplements some of the functions in the library `api-ms-win-core-path-l1-1-0.dll` bundled with Windows 8/Server 2012 and later so that Python 3.9+ can be used on Windows 7.
## But why?
I use Windows 7 and do not want to switch to Windows 8 or later for a lot of reasons.

The Python 3.9.0 installers prevent installation on Windows 7.  
Furthermore, Python 3.9.0 will not run on Windows 7 because the Python executable imports the functions `PathCchCanonicalizeEx` and `PathCchCombineEx` from the aforementioned DLL.
## And how do I use it?
**Note:** The following steps were only tested on 64-bit Windows 7.
1. Install Python 3.9.0 from the [embeddable .zip file](//www.python.org/ftp/python/3.9.0/python-3.9.0-embed-amd64.zip).
2. Grab a binary release. Alternatively...
3. Install a C/C++ compiler. I used the compiler available from [mingw-w64.org](//mingw-w64.org/doku.php/download/mingw-builds) -- however, it's hosted on Sourceforge, so choose it at your own risk.
4. Compile `api-ms-win-core-path-HACK.cpp`. Add the flags `-shared` to create a DLL and `-lshlwapi` to properly link with another Windows DLL. Make sure the output DLL is named `api-ms-win-core-path-l1-1-0.dll`.
5. Move the DLL to System32 or another directory in your PATH environment variable.
