#ifndef __TYPES_HPP__
#define __TYPES_HPP__

namespace heart
{
	typedef float real;
	typedef int sint;
	typedef unsigned int uint;
	typedef signed s32;
	typedef unsigned u32;
	typedef signed short s16;
	typedef unsigned short u16;
	typedef signed char s8;
	typedef unsigned char u8;

	static const uint BAD_ID = uint(-1);

    template <uint _S>
    struct xstr_
    {
        static const uint size = _S;
        typedef char type[size];
        type str;

        inline xstr_() { str[0] = 0; }
        template <uint _S2> inline xstr_(const xstr_<_S2> &_s) { strcpy_s(str, _s.str); }
        inline xstr_(const char* _s) { strcpy_s(str, _s); }
        template <uint _S2> inline xstr_& operator = (const xstr_<_S2> &_s) { strcpy_s(str, _s.str); return *this; }
        inline xstr_& operator = (const char* _s) { strcpy_s(str, _s); return *this; }
        inline operator type& () { return str; }
        inline operator const char* () const { return str; }
        //inline operator char* () { return str; }
    };

    typedef xstr_<32> xstr32;

    static const xstr32 xs32_0;
}

#endif // __TYPES_HPP__