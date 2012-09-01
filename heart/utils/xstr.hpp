#ifndef __XSTR_HPP__
#define __XSTR_HPP__

namespace heart
{
    /* Fixed string
     */
    template <uint _S>
    struct xstr_
    {
        static const uint size = _S;
        typedef char type[size];
        type str;

        inline xstr_() { str[0] = 0; }
        inline xstr_(const char* _s, ...) { va_list l_args; va_start(l_args, _s); vsprintf_s(str, size, _s, l_args); va_end(l_args); }
        template <uint _S2> inline xstr_(const xstr_<_S2> &_s) { strcpy_s(str, _s.str); }
        template <uint _S2> inline xstr_& operator = (const xstr_<_S2> &_s) { strcpy_s(str, _s.str); return *this; }
        inline xstr_& operator = (const char* _s) { strcpy_s(str, _s); return *this; }
        inline operator type& () { return str; }
        inline operator const char* () const { return str; }
    };

    static const uint MAX_NAME = 32;
    typedef xstr_<MAX_NAME> xname;
    static const xname xname_0;
}

#endif // __XSTR_HPP__