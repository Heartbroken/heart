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
		friend inline float2 div(const float2 &_a, float _s) { return float2(_a.x / _s, _a.y / _s); }
		friend inline float2 div(float _s, const float2 &_b) { return float2(_s / _b.x, _s / _b.y); }

		friend inline float dot(const float2 &_a, const float2 &_b) { return _a.x * _b.x + _a.y * _b.y; }

		friend inline float cross(const float2 &_a, const float2 &_b) { return _a.x * _b.y - _a.y * _b.x; }
		friend inline float2 cross(const float2 &_v) { return float2(-_v.y, _v.x); }

		friend inline float length2(const float2 &_v) { return dot(_v, _v); }
		friend inline float length(const float2 &_v) { return sqrtf(length2(_v)); }

		friend inline float2 normal(const float2 &_v) { return _v / length(_v); }


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
		friend inline float2 operator * (float _s, const float2 &_b) { return mul(_s, _b); }
		inline float2 operator / (float _s) const { return div(*this, _s); }
		inline float2& operator /= (float _s) { return *this = div(*this, _s); }
		friend inline float2 operator / (float _s, const float2 &_b) { return div(_s, _b); }
	};

	struct float3
	{
		float x, y, z;

		inline float3() {}
		inline float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		inline float3(const float3 &_v) : x(_v.x), y(_v.y), z(_v.z) {}

		inline float3& operator = (const float3 &_v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

		friend inline float3 neg(const float3 &_v) { return float3(-_v.x, -_v.y, -_v.z); }

		friend inline float3 add(const float3 &_a, const float3 &_b) { return float3(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z); }
		friend inline float3 sub(const float3 &_a, const float3 &_b) { return float3(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z); }
		friend inline float3 mul(const float3 &_a, const float3 &_b) { return float3(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z); }
		friend inline float3 div(const float3 &_a, const float3 &_b) { return float3(_a.x / _b.x, _a.y / _b.y, _a.z / _b.z); }

		friend inline float3 mul(const float3 &_a, float _s) { return float3(_a.x * _s, _a.y * _s, _a.z * _s); }
		friend inline float3 mul(float _s, const float3 &_b) { return float3(_s * _b.x, _s * _b.y, _s * _b.z); }
		friend inline float3 div(const float3 &_a, float _s) { return float3(_a.x / _s, _a.y / _s, _a.z / _s); }
		friend inline float3 div(float _s, const float3 &_b) { return float3(_s / _b.x, _s / _b.y, _s / _b.z); }

		friend inline float dot(const float3 &_a, const float3 &_b) { return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z; }

		friend inline float3 cross(const float3 &_a, const float3 &_b) { return float3(_a.y * _b.z - _a.z * _b.y, _a.x * _b.z - _a.z * _b.x, _a.x * _b.y - _a.y * _b.x); }

		friend inline float length2(const float3 &_v) { return dot(_v, _v); }
		friend inline float length(const float3 &_v) { return sqrtf(length2(_v)); }

		friend inline float3 normal(const float3 &_v) { return _v / length(_v); }


		inline float3 operator - () { return neg(*this); }

		inline float3 operator + (const float3 &_v) const { return add(*this, _v); }
		inline float3& operator += (const float3 &_v) { return *this = add(*this, _v); }
		inline float3 operator - (const float3 &_v) const { return sub(*this, _v); }
		inline float3& operator -= (const float3 &_v) { return *this = sub(*this, _v); }
		inline float3 operator * (const float3 &_v) const { return mul(*this, _v); }
		inline float3& operator *= (const float3 &_v) { return *this = mul(*this, _v); }
		inline float3 operator / (const float3 &_v) const { return div(*this, _v); }
		inline float3& operator /= (const float3 &_v) { return *this = div(*this, _v); }

		inline float3 operator * (float _s) const { return mul(*this, _s); }
		inline float3& operator *= (float _s) { return *this = mul(*this, _s); }
		friend inline float3 operator * (float _s, const float3 &_b) { return mul(_s, _b); }
		inline float3 operator / (float _s) const { return div(*this, _s); }
		inline float3& operator /= (float _s) { return *this = div(*this, _s); }
		friend inline float3 operator / (float _s, const float3 &_b) { return div(_s, _b); }

		inline operator float2 () const { return float2(x, y); }
	};

}

#endif // __FLOAT2_HPP__