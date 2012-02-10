/* 
 * SimpleEmbedR: A very simple demonstration wrapper for R.
 *
 * Disclaimer
 * ----------
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#include <windows.h>
#include "init.h"
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	    case DLL_PROCESS_ATTACH:
            initR();
            break;
	    case DLL_THREAD_ATTACH:
	    case DLL_THREAD_DETACH:
	    case DLL_PROCESS_DETACH:
            endR();
            break;
	}
	return TRUE;
}
#else // not defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#include "init.h"
void __attribute__ ((constructor)) initR(void);
void __attribute__ ((destructor)) endR(void);
#endif // not defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

// not sure what to do if not linux or windows.
