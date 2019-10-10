/*****************************************************************************

        StageProc4AvxDouble.h
		Port of StageProc4Sse.h from float to double by Dario Mambro
        StageProc4Sse.h Laurent de Soras, 2015

Template parameters:
	- REMAINING: Number of remaining coefficients to process, >= 0

--- Legal stuff ---

This program is free software. It comes without any warranty, to
the extent permitted by applicable law. You can redistribute it
and/or modify it under the terms of the Do What The Fuck You Want
To Public License, Version 2, as published by Sam Hocevar. See
http://sam.zoy.org/wtfpl/COPYING for more details.

*Tab=3***********************************************************************/



#if ! defined (hiir_StageProc4AvxDouble_HEADER_INCLUDED)
#define hiir_StageProc4AvxDouble_HEADER_INCLUDED

#if defined (_MSC_VER)
	#pragma once
	#pragma warning (4 : 4250) // "Inherits via dominance."
#endif



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "hiir/def.h"

#include <xmmintrin.h>



namespace hiir
{



class StageDataAvxDouble;

template <int REMAINING>
class StageProc4AvxDouble
{

	static_assert ((REMAINING >= 0), "REMAINING must be >= 0");

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:

	static hiir_FORCEINLINE void
	               process_sample_pos (const int nbr_coefs, __m256d &spl_0, __m256d &spl_1, StageDataAvxDouble *stage_arr);
	static hiir_FORCEINLINE void
	               process_sample_neg (const int nbr_coefs, __m256d &spl_0, __m256d &spl_1, StageDataAvxDouble *stage_arr);



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

	               StageProc4AvxDouble ();
	               StageProc4AvxDouble (const StageProc4AvxDouble <REMAINING> &other);
	StageProc4AvxDouble <REMAINING> &
						operator = (const StageProc4AvxDouble <REMAINING> &other);
	bool           operator == (const StageProc4AvxDouble <REMAINING> &other);
	bool           operator != (const StageProc4AvxDouble <REMAINING> &other);

}; // class StageProc4AvxDouble



}  // namespace hiir



#include "hiir/StageProc4AvxDouble.hpp"



#endif   // hiir_StageProc4AvxDouble_HEADER_INCLUDED



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/