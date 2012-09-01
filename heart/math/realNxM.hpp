#ifndef __REALNXM_HPP__
#define __REALNXM_HPP__

namespace heart
{
	struct real3x3
	{
		real3 x, y, z;

		inline real3x3() {}
		inline real3x3(const real3 _x, const real3 _y, const real3 _z) : x(_x), y(_y), z(_z) {}
		inline real3x3(const real3x3 &_m) : x(_m.x), y(_m.y), z(_m.z) {}

		inline real3x3(real _11, real _12, real _13,
					   real _21, real _22, real _23,
					   real _31, real _32, real _33) : x(_11, _12, _13),
													   y(_21, _22, _23), 
													   z(_31, _32, _33) {}
	};

	struct real3x4
	{
		real3 x, y, z, w;
	};

	struct real4x4
	{
		real4 x, y, z, w;

		inline real4x4() {}
		inline real4x4(const real4 _x, const real4 _y, const real4 _z, const real4 _w) : x(_x), y(_y), z(_z), w(_w) {}
		inline real4x4(const real4x4 &_m) : x(_m.x), y(_m.y), z(_m.z), w(_m.w) {}
	};

	static const real4x4 r4x4_0(r4_0, r4_0, r4_0, r4_0);
	static const real4x4 r4x4_1(r4_x, r4_y, r4_z, r4_w);
}

#endif // __REALNXM_HPP__