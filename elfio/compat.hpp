/*
Copyright (c) 2025 Sun Daowen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef ELFIO_COMPAT_HPP
#define ELFIO_COMPAT_HPP

#if defined( ELFIO_NO_CSTDINT ) || defined( ELFIO_NO_INTTYPES ) || \
    ( defined( _MSC_VER ) && _MSC_VER < 1600 )
typedef signed char        int8_t;
typedef signed short       int16_t;
typedef signed int         int32_t;
typedef signed long long   int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#else
#include <stdint.h>
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#if defined( __cplusplus )
#include <ostream>

namespace std {
struct nullptr_t
{
    template <class T>                     operator T*() const { return 0; }
    template <class C, class T> operator T C::*() const { return 0; }

  private:
    void operator&() const;
};

template <class _Elem, class _Traits>
basic_ostream<_Elem, _Traits>& operator<<( basic_ostream<_Elem, _Traits>& os,
                                           nullptr_t );

template <>
inline basic_ostream<char, char_traits<char>>&
operator<<( basic_ostream<char, char_traits<char>>& os, nullptr_t )
{
    return os << "nullptr";
}

template <>
inline basic_ostream<wchar_t, char_traits<wchar_t>>&
operator<<( basic_ostream<wchar_t, char_traits<wchar_t>>& os, nullptr_t )
{
    return os << L"nullptr";
}
} // namespace std
static std::nullptr_t nullptr = {};
#endif
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#define emplace_back( x ) push_back( x )
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1700
#define override
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1900
#define noexcept throw()
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#if defined( __cplusplus )
namespace std {
template <class T> T& move( T& t ) { return t; }
} // namespace std
#endif
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#if defined( __cplusplus )
#include <regex>

namespace std {
using tr1::regex;
using tr1::regex_match;
using tr1::smatch;
} // namespace std
#endif
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1800
#include <stdlib.h>

#if defined( __cplusplus )
namespace std {
#endif
static uint64_t strtoull( const char* str, char** str_end, int base )
{
    return _strtoui64( str, str_end, base );
}
#if defined( __cplusplus )
} // namespace std
#endif
#endif

#endif // ELFIO_COMPAT_HPP
