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

#include <Rembedded.h>

void initR(void) {
    int argc = 1;
    char *argv[] = {"dummy"};
    Rf_initEmbeddedR(argc, argv);
}

void endR(void) {
    Rf_endEmbeddedR(0);
}
