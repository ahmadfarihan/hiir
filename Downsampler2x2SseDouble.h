/*****************************************************************************

        Downsampler2x2SseDouble.h
		Port of Downsampler2x4Sse.h from double to double by Dario Mambro
        Downsampler2x4Sse.h by Laurent de Soras, 2015

Downsamples vectors of 4 double by a factor 2 the input signal, using SSE
instruction set.

This object must be aligned on a 16-byte boundary!

Template parameters:
	- NC: number of coefficients, > 0

--- Legal stuff ---

This program is free software. It comes without any warranty, to
the extent permitted by applicable law. You can redistribute it
and/or modify it under the terms of the Do What The Fuck You Want
To Public License, Version 2, as published by Sam Hocevar. See
http://sam.zoy.org/wtfpl/COPYING for more details.

*Tab=3***********************************************************************/



#pragma once
#if ! defined (hiir_Downsampler2x2SseDouble_HEADER_INCLUDED)
#define hiir_Downsampler2x2SseDouble_HEADER_INCLUDED

#if defined (_MSC_VER)
	#pragma warning (4 : 4250)
#endif



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "hiir/def.h"
#include "hiir/StageDataSseDouble.h"

#include <emmintrin.h>

#include <array>



namespace hiir
{



template <int NC>
class Downsampler2x2SseDouble
{

	static_assert ((NC > 0), "Number of coefficient must be positive.");

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:

	enum {         NBR_COEFS = NC };

	               Downsampler2x2SseDouble ();

	void           set_coefs (const double coef_arr []);

	hiir_FORCEINLINE __m128d
	               process_sample (const double in_ptr [4]);
	hiir_FORCEINLINE __m128d
	               process_sample (__m128d in_0, __m128d in_1);
	void           process_block (double out_ptr [], const double in_ptr [], long nbr_spl);

	hiir_FORCEINLINE void
	               process_sample_split (__m128d &low, __m128d &high, const double in_ptr [4]);
	hiir_FORCEINLINE void
	               process_sample_split (__m128d &low, __m128d &high, __m128d in_0, __m128d in_1);
	void           process_block_split (double out_l_ptr [], double out_h_ptr [], const double in_ptr [], long nbr_spl);

	void           clear_buffers ();



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

	typedef std::array <StageDataSseDouble, NBR_COEFS + 2> Filter;   // Stages 0 and 1 contain only input memories

	Filter         _filter; // Should be the first member (thus easier to align)



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

	bool           operator == (const Downsampler2x2SseDouble <NC> &other) const;
	bool           operator != (const Downsampler2x2SseDouble <NC> &other) const;

}; // class Downsampler2x2SseDouble



}  // namespace hiir



#include "hiir/Downsampler2x2SseDouble.hpp"



#endif   // hiir_Downsampler2x2SseDouble_HEADER_INCLUDED



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
