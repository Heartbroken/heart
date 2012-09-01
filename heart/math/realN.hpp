#ifndef __REALN_HPP__
#define __REALN_HPP__

namespace heart
{

	struct real2
	{
		real x, y;

		inline real2() {}
		inline real2(real _x, real _y) : x(_x), y(_y) {}
		inline real2(const real2 &_v) : x(_v.x), y(_v.y) {}

		inline real2& operator = (const real2 &_v) { x = _v.x; y = _v.y; return *this; }

		friend inline real2 neg(const real2 &_v) { return real2(-_v.x, -_v.y); }

		friend inline real2 add(const real2 &_a, const real2 &_b) { return real2(_a.x + _b.x, _a.y + _b.y); }
		friend inline real2 sub(const real2 &_a, const real2 &_b) { return real2(_a.x - _b.x, _a.y - _b.y); }
		friend inline real2 mul(const real2 &_a, const real2 &_b) { return real2(_a.x * _b.x, _a.y * _b.y); }
		friend inline real2 div(const real2 &_a, const real2 &_b) { return real2(_a.x / _b.x, _a.y / _b.y); }

		friend inline real2 mul(const real2 &_a, real _s) { return real2(_a.x * _s, _a.y * _s); }
		friend inline real2 mul(real _s, const real2 &_b) { return real2(_s * _b.x, _s * _b.y); }
		friend inline real2 div(const real2 &_a, real _s) { return real2(_a.x / _s, _a.y / _s); }
		friend inline real2 div(real _s, const real2 &_b) { return real2(_s / _b.x, _s / _b.y); }

		friend inline real dot(const real2 &_a, const real2 &_b) { return _a.x * _b.x + _a.y * _b.y; }

		friend inline real cross(const real2 &_a, const real2 &_b) { return _a.x * _b.y - _a.y * _b.x; }
		friend inline real2 cross(const real2 &_v) { return real2(-_v.y, _v.x); }

		friend inline real length2(const real2 &_v) { return dot(_v, _v); }
		friend inline real length(const real2 &_v) { return sqrtf(length2(_v)); }

		friend inline real2 normal(const real2 &_v) { return _v / length(_v); }


		inline real2 operator - () { return neg(*this); }

		inline real2 operator + (const real2 &_v) const { return add(*this, _v); }
		inline real2& operator += (const real2 &_v) { return *this = add(*this, _v); }
		inline real2 operator - (const real2 &_v) const { return sub(*this, _v); }
		inline real2& operator -= (const real2 &_v) { return *this = sub(*this, _v); }
		inline real2 operator * (const real2 &_v) const { return mul(*this, _v); }
		inline real2& operator *= (const real2 &_v) { return *this = mul(*this, _v); }
		inline real2 operator / (const real2 &_v) const { return div(*this, _v); }
		inline real2& operator /= (const real2 &_v) { return *this = div(*this, _v); }

		inline real2 operator * (real _s) const { return mul(*this, _s); }
		inline real2& operator *= (real _s) { return *this = mul(*this, _s); }
		friend inline real2 operator * (real _s, const real2 &_b) { return mul(_s, _b); }
		inline real2 operator / (real _s) const { return div(*this, _s); }
		inline real2& operator /= (real _s) { return *this = div(*this, _s); }
		friend inline real2 operator / (real _s, const real2 &_b) { return div(_s, _b); }

		inline real operator [] (uint _i) const { return _i == 0 ? x : y; }
		inline real& operator [] (uint _i) { return _i == 0 ? x : y; }

		inline bool operator == (const real2 &_v) const { return x == _v.x && y == _v.y; }
		inline bool operator != (const real2 &_v) const { return x != _v.x || y != _v.y; }
	};

	static const real2 r2_0(0.0f, 0.0f);
	static const real2 r2_1(1.0f, 1.0f);
	static const real2 r2_x(1.0f, 0.0f);
	static const real2 r2_y(0.0f, 1.0f);

	struct real3
	{
		real x, y, z;

		inline real3() {}
		inline real3(real _x, real _y, real _z) : x(_x), y(_y), z(_z) {}
		inline real3(const real3 &_v) : x(_v.x), y(_v.y), z(_v.z) {}

		inline real3& operator = (const real3 &_v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

		friend inline real3 neg(const real3 &_v) { return real3(-_v.x, -_v.y, -_v.z); }

		friend inline real3 add(const real3 &_a, const real3 &_b) { return real3(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z); }
		friend inline real3 sub(const real3 &_a, const real3 &_b) { return real3(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z); }
		friend inline real3 mul(const real3 &_a, const real3 &_b) { return real3(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z); }
		friend inline real3 div(const real3 &_a, const real3 &_b) { return real3(_a.x / _b.x, _a.y / _b.y, _a.z / _b.z); }

		friend inline real3 mul(const real3 &_a, real _s) { return real3(_a.x * _s, _a.y * _s, _a.z * _s); }
		friend inline real3 mul(real _s, const real3 &_b) { return real3(_s * _b.x, _s * _b.y, _s * _b.z); }
		friend inline real3 div(const real3 &_a, real _s) { return real3(_a.x / _s, _a.y / _s, _a.z / _s); }
		friend inline real3 div(real _s, const real3 &_b) { return real3(_s / _b.x, _s / _b.y, _s / _b.z); }

		friend inline real dot(const real3 &_a, const real3 &_b) { return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z; }

		friend inline real3 cross(const real3 &_a, const real3 &_b) { return real3(_a.y * _b.z - _a.z * _b.y, _a.x * _b.z - _a.z * _b.x, _a.x * _b.y - _a.y * _b.x); }

		friend inline real length2(const real3 &_v) { return dot(_v, _v); }
		friend inline real length(const real3 &_v) { return sqrtf(length2(_v)); }

		friend inline real3 normal(const real3 &_v) { return _v / length(_v); }


		inline real3 operator - () { return neg(*this); }

		inline real3 operator + (const real3 &_v) const { return add(*this, _v); }
		inline real3& operator += (const real3 &_v) { return *this = add(*this, _v); }
		inline real3 operator - (const real3 &_v) const { return sub(*this, _v); }
		inline real3& operator -= (const real3 &_v) { return *this = sub(*this, _v); }
		inline real3 operator * (const real3 &_v) const { return mul(*this, _v); }
		inline real3& operator *= (const real3 &_v) { return *this = mul(*this, _v); }
		inline real3 operator / (const real3 &_v) const { return div(*this, _v); }
		inline real3& operator /= (const real3 &_v) { return *this = div(*this, _v); }

		inline real3 operator * (real _s) const { return mul(*this, _s); }
		inline real3& operator *= (real _s) { return *this = mul(*this, _s); }
		friend inline real3 operator * (real _s, const real3 &_b) { return mul(_s, _b); }
		inline real3 operator / (real _s) const { return div(*this, _s); }
		inline real3& operator /= (real _s) { return *this = div(*this, _s); }
		friend inline real3 operator / (real _s, const real3 &_b) { return div(_s, _b); }

		inline operator real2 () const { return real2(x, y); }

		inline real operator [] (uint _i) const { return _i == 0 ? x : _i == 1 ? y : z; }
		inline real& operator [] (uint _i) { return _i == 0 ? x : _i == 1 ? y : z; }

		inline bool operator == (const real3 &_v) const { return x == _v.x && y == _v.y && z == _v.z; }
		inline bool operator != (const real3 &_v) const { return x != _v.x || y != _v.y || z != _v.z; }
	};

	static const real3 r3_0(0.0f, 0.0f, 0.0f);
	static const real3 r3_1(1.0f, 1.0f, 1.0f);
	static const real3 r3_x(1.0f, 0.0f, 0.0f);
	static const real3 r3_y(0.0f, 1.0f, 0.0f);
	static const real3 r3_z(0.0f, 0.0f, 1.0f);

	struct real4
	{
		real x, y, z, w;

		inline real4() {}
		inline real4(real _x, real _y, real _z, real _w) : x(_x), y(_y), z(_z), w(_w) {}
		inline real4(const real4 &_v) : x(_v.x), y(_v.y), z(_v.z), w(_v.w) {}

		inline real4& operator = (const real4 &_v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; return *this; }

		friend inline real4 neg(const real4 &_v) { return real4(-_v.x, -_v.y, -_v.z, -_v.w); }

		friend inline real4 add(const real4 &_a, const real4 &_b) { return real4(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z, _a.w + _b.w); }
		friend inline real4 sub(const real4 &_a, const real4 &_b) { return real4(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z, _a.w - _b.w); }
		friend inline real4 mul(const real4 &_a, const real4 &_b) { return real4(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z, _a.w * _b.w); }
		friend inline real4 div(const real4 &_a, const real4 &_b) { return real4(_a.x / _b.x, _a.y / _b.y, _a.z / _b.z, _a.w / _b.w); }

		friend inline real4 mul(const real4 &_a, real _s) { return real4(_a.x * _s, _a.y * _s, _a.z * _s, _a.w * _s); }
		friend inline real4 mul(real _s, const real4 &_b) { return real4(_s * _b.x, _s * _b.y, _s * _b.z, _s * _b.w); }
		friend inline real4 div(const real4 &_a, real _s) { return real4(_a.x / _s, _a.y / _s, _a.z / _s, _a.w / _s); }
		friend inline real4 div(real _s, const real4 &_b) { return real4(_s / _b.x, _s / _b.y, _s / _b.z, _s / _b.w); }

		friend inline real dot(const real4 &_a, const real4 &_b) { return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w; }

		friend inline real length2(const real4 &_v) { return dot(_v, _v); }
		friend inline real length(const real4 &_v) { return sqrtf(length2(_v)); }

		friend inline real4 normal(const real4 &_v) { return _v / length(_v); }


		inline real4 operator - () { return neg(*this); }

		inline real4 operator + (const real4 &_v) const { return add(*this, _v); }
		inline real4& operator += (const real4 &_v) { return *this = add(*this, _v); }
		inline real4 operator - (const real4 &_v) const { return sub(*this, _v); }
		inline real4& operator -= (const real4 &_v) { return *this = sub(*this, _v); }
		inline real4 operator * (const real4 &_v) const { return mul(*this, _v); }
		inline real4& operator *= (const real4 &_v) { return *this = mul(*this, _v); }
		inline real4 operator / (const real4 &_v) const { return div(*this, _v); }
		inline real4& operator /= (const real4 &_v) { return *this = div(*this, _v); }

		inline real4 operator * (real _s) const { return mul(*this, _s); }
		inline real4& operator *= (real _s) { return *this = mul(*this, _s); }
		friend inline real4 operator * (real _s, const real4 &_b) { return mul(_s, _b); }
		inline real4 operator / (real _s) const { return div(*this, _s); }
		inline real4& operator /= (real _s) { return *this = div(*this, _s); }
		friend inline real4 operator / (real _s, const real4 &_b) { return div(_s, _b); }

		inline operator real2 () const { return real2(x, y); }
		inline operator real3 () const { return real3(x, y, z); }

		inline real operator [] (uint _i) const { return _i == 0 ? x : _i == 1 ? y : _i == 2 ? z : w; }
		inline real& operator [] (uint _i) { return _i == 0 ? x : _i == 1 ? y : _i == 2 ? z : w; }

		inline bool operator == (const real4 &_v) const { return x == _v.x && y == _v.y && z == _v.z && w == _v.w; }
		inline bool operator != (const real4 &_v) const { return x != _v.x || y != _v.y || z != _v.z || w != _v.w; }
	};

	static const real4 r4_0(0.0f, 0.0f, 0.0f, 0.0f);
	static const real4 r4_1(1.0f, 1.0f, 1.0f, 1.0f);
	static const real4 r4_x(1.0f, 0.0f, 0.0f, 0.0f);
	static const real4 r4_y(0.0f, 1.0f, 0.0f, 0.0f);
	static const real4 r4_z(0.0f, 0.0f, 1.0f, 0.0f);
	static const real4 r4_w(0.0f, 0.0f, 0.0f, 1.0f);

}

#endif // __REALN_HPP__