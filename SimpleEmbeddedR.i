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
 
%module SimpleEmbeddedR
%{
#include "SimpleEmbeddedR.h"
%}

%typemap(newfree) char const* "free($1);";
%newobject runRCode;
%include "SimpleEmbeddedR.h"
