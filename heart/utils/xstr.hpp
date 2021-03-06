#ifndef __XSTR_HPP__
#define __XSTR_HPP__

namespace heart
{
    /* Fixed string
     */
    template <uint _S> struct xstr_
    {
        static const uint SIZE = _S;
        typedef char type[SIZE + 1];
        type str;

        inline xstr_() { str[0] = str[SIZE] = 0; }
        inline xstr_(const char* _s, ...) { va_list l_args; va_start(l_args, _s); vsnprintf_s(str, SIZE, _s, l_args); va_end(l_args); }
        template <uint _S2> inline xstr_(const xstr_<_S2> &_s) { strncpy_s(str, _s.str, SIZE); }
        template <uint _S2> inline xstr_& operator = (const xstr_<_S2> &_s) { strncpy_s(str, _s.str, SIZE); return *this; }
        inline xstr_& operator = (const char* _s) { strncpy_s(str, _s, SIZE); return *this; }
        template <uint _S2> inline bool operator == (const xstr_<_S2> &_s) const { return strcmp(str, _s.str) == 0; }
        template <uint _S2> inline bool operator != (const xstr_<_S2> &_s) const { return strcmp(str, _s.str) != 0; }
        inline bool operator == (const char* _s) const { return strcmp(str, _s) == 0; }
        inline bool operator != (const char* _s) const { return strcmp(str, _s) != 0; }
        friend inline bool operator == (const char* _s1, const xstr_ &_s2) { return strcmp(_s1, _s2.str) == 0; }
        friend inline bool operator != (const char* _s1, const xstr_ &_s2) { return strcmp(_s1, _s2.str) != 0; }
        inline operator type& () { return str; }
        inline operator const char* () const { return str; }
    };

    static const uint MAX_NAME = 31;
    typedef xstr_<MAX_NAME> xname;
    static const xname xname_0;
}

#endif // __XSTR_HPP__