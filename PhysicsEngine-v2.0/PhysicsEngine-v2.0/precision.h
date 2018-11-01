#pragma once
#include <stdio.h>
#include <math.h>


namespace PhyEng {
	
	/*re-defining functions allows to change to double presicion*/
	/*define sqrt_r to single precision*/
	#define sqrt_r sqrtf;

	/* defines precision
	 currently single precision
	 can be changed to double */
	typedef float real;

}
