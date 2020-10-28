#include <shlwapi.h>
#include <windows.h>
HRESULT PathCchCanonicalizeEx(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, unsigned long dwFlags) {
	return PathCanonicalizeW(pszPathOut, pszPathIn) ? S_OK : E_FAIL;
}
HRESULT PathCchCombineEx(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, PCWSTR pszMore, unsigned long dwFlags) {
	return PathCombineW(pszPathOut, pszPathIn, pszMore) == NULL ? E_FAIL : S_OK;
}
