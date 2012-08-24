#ifndef __FLOAT2_HPP__
#define __FLOAT2_HPP__

namespace heart
{

	struct float2
	{
		float x, y;

		inline float2() {}
		inline float2(float _x, float _y) : x(_x), y(_y) {}
		inline float2(const float2 &_v) : x(_v.x), y(_v.y) {}

		inline float2& operator = (const float2 &_v) { x = _v.x; y = _v.y; return *this; }


		friend inline float2 neg(const float2 &_v) { return float2(-_v.x, -_v.y); }

		friend inline float2 add(const float2 &_a, const float2 &_b) { return float2(_a.x + _b.x, _a.y + _b.y); }
		friend inline float2 sub(const float2 &_a, const float2 &_b) { return float2(_a.x - _b.x, _a.y - _b.y); }
		friend inline float2 mul(const float2 &_a, const float2 &_b) { return float2(_a.x * _b.x, _a.y * _b.y); }
		friend inline float2 div(const float2 &_a, const float2 &_b) { return float2(_a.x / _b.x, _a.y / _b.y); }

		friend inline float2 mul(const float2 &_a, float _s) { return float2(_a.x * _s, _a.y * _s); }
		friend inline float2 mul(float _s, const float2 &_b) { return float2(_s * _b.x, _s * _b.y); }
		friend inline float2 operator * (float _s, const float2 &_b) { return mul(_s, _b); }
		friend inline float2 div(const float2 &_a, float _s) { return float2(_a.x / _s, _a.y / _s); }
		friend inline float2 div(float _s, const float2 &_b) { return float2(_s / _b.x, _s / _b.y); }
		friend inline float2 operator / (float _s, const float2 &_b) { return div(_s, _b); }

		friend inline float dot(const float2 &_a, const float2 &_b) { return _a.x * _b.x + _a.y * _b.x; }

		friend inline float cross(const float2 &_a, const float2 &_b) { return _a.x * _b.y - _a.y * _b.x; }
		friend inline float2 cross(const float2 &_v) { return float2(-_v.y, _v.x); }

		friend inline float length2(const float2 &_v) { return dot(_v, _v); }
		friend inline float length(const float2 &_v) { return sqrtf(length2(_v)); }


		inline float2 operator - () { return neg(*this); }

		inline float2 operator + (const float2 &_v) const { return add(*this, _v); }
		inline float2& operator += (const float2 &_v) { return *this = add(*this, _v); }
		inline float2 operator - (const float2 &_v) const { return sub(*this, _v); }
		inline float2& operator -= (const float2 &_v) { return *this = sub(*this, _v); }
		inline float2 operator * (const float2 &_v) const { return mul(*this, _v); }
		inline float2& operator *= (const float2 &_v) { return *this = mul(*this, _v); }
		inline float2 operator / (const float2 &_v) const { return div(*this, _v); }
		inline float2& operator /= (const float2 &_v) { return *this = div(*this, _v); }
		inline float2 operator * (float _s) const { return mul(*this, _s); }
		inline float2& operator *= (float _s) { return *this = mul(*this, _s); }
		inline float2 operator / (float _s) const { return div(*this, _s); }
		inline float2& operator /= (float _s) { return *this = div(*this, _s); }
	};

}

#endif // __FLOAT2_HPP__