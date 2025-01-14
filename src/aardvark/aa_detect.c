/*=========================================================================
| (c) 2003-2007  Total Phase, Inc.
|--------------------------------------------------------------------------
| Project : Aardvark Sample Code
| File    : aadetect.c
|--------------------------------------------------------------------------
| Auto-detection test routine
|--------------------------------------------------------------------------
| Redistribution and use of this file in source and binary forms, with
| or without modification, are permitted.
|
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
| "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
| LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
| FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
| COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
| INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
| BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
| LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
| CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
| LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
| ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
| POSSIBILITY OF SUCH DAMAGE.
 ========================================================================*/

//=========================================================================
// INCLUDES
//=========================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aardvark.h"


//=========================================================================
// MAIN PROGRAM ENTRY POINT
//=========================================================================
// int main (int argc, char *argv[])
int aa_detect(void)
{
	u16 ports[16];
	u32 unique_ids[16];
	int nelem = 16;

	// Find all the attached devices
	int count = aa_find_devices_ext(nelem, ports, nelem, unique_ids);
	int i;

	printf("%d device(s) found:\n", count);

	// Print the information on each device
	if (count > nelem) {
		count = nelem;
	}
	for (i = 0; i < count; ++i) {
		// Determine if the device is in-use
		const char *status = "(avail) ";
		if (ports[i] & AA_PORT_NOT_FREE) {
			ports[i] &= ~AA_PORT_NOT_FREE;
			status = "(in-use)";
		}

		// Display device port number, in-use status, and serial number
		printf("    port=%-3d %s (%04d-%06d)\n",
		       ports[i], status,
		       unique_ids[i] / 1000000,
		       unique_ids[i] % 1000000);
	}

	return 0;
}
