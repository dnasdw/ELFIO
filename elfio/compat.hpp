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

#if defined( _MSC_VER ) && _MSC_VER < 1600
#include <stddef.h>

#define COMPAT_JOIN( X, Y )     COMPAT_DO_JOIN( X, Y )
#define COMPAT_DO_JOIN( X, Y )  COMPAT_DO_JOIN2( X, Y )
#define COMPAT_DO_JOIN2( X, Y ) X##Y

#define COMPAT_EXPAND( ... ) __VA_ARGS__

#define COMPAT_GET_MACRO_2( _1, _2, NAME, ... ) NAME

#define static_assert( ... )                                     \
    COMPAT_EXPAND(                                               \
        COMPAT_GET_MACRO_2( __VA_ARGS__, COMPAT_STATIC_ASSERT_2, \
                            COMPAT_STATIC_ASSERT_1 )( __VA_ARGS__ ) )

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#if !defined( __cplusplus )
#define COMPAT_STATIC_ASSERT_1( B )                            \
    typedef char COMPAT_JOIN( compat_static_assert_typedef_1_, \
                              __COUNTER__ )[( B ) ? 1 : -1]
#define COMPAT_STATIC_ASSERT_2( B, Msg )                       \
    typedef char COMPAT_JOIN( compat_static_assert_typedef_2_, \
                              __COUNTER__ )[( B ) ? 1 : -1]
#elif defined( __cplusplus )
namespace compat {
template <bool x> struct COMPAT_STATIC_ASSERTION_FAILURE;

template <> struct COMPAT_STATIC_ASSERTION_FAILURE<true>
{
};

template <size_t x> struct compat_static_assert_test
{
};
} // namespace compat

#define COMPAT_STATIC_ASSERT_1( B )                             \
    typedef compat::compat_static_assert_test<sizeof(           \
        compat::COMPAT_STATIC_ASSERTION_FAILURE<(bool)( B )> )> \
    COMPAT_JOIN( compat_static_assert_typedef_1_, __COUNTER__ )
#define COMPAT_STATIC_ASSERT_2( B, Msg )                        \
    typedef compat::compat_static_assert_test<sizeof(           \
        compat::COMPAT_STATIC_ASSERTION_FAILURE<(bool)( B )> )> \
    COMPAT_JOIN( compat_static_assert_typedef_2_, __COUNTER__ )
#endif

#if defined( __cplusplus )
namespace std {
template <class _Ty, _Ty _Val> struct integral_constant
{
    static const _Ty value = _Val;

    typedef _Ty                          value_type;
    typedef integral_constant<_Ty, _Val> type;

    operator value_type() const noexcept { return value; }

    value_type operator()() const noexcept { return value; }
};

template <bool _Val> struct bool_constant : integral_constant<bool, _Val>
{
};

typedef bool_constant<true>  true_type;
typedef bool_constant<false> false_type;

template <bool _Test, class _Ty = void> struct enable_if
{
}; // no member "type" when !_Test

template <class _Ty> struct enable_if<true, _Ty>
{ // type is _Ty for _Test
    typedef _Ty type;
};

template <bool _Test, class _Ty1, class _Ty2> struct conditional
{ // Choose _Ty1 if _Test is true, and _Ty2 otherwise
    typedef _Ty1 type;
};

template <class _Ty1, class _Ty2> struct conditional<false, _Ty1, _Ty2>
{
    typedef _Ty2 type;
};

// STRUCT TEMPLATE is_same
template <class _Ty1, class _Ty2> struct is_same : false_type
{ // determine whether _Ty1 and _Ty2 are the same type
};

template <class _Ty1> struct is_same<_Ty1, _Ty1> : true_type
{ // determine whether _Ty1 and _Ty2 are the same type
};

template <class _Ty> struct remove_reference
{
    typedef _Ty type;
};

template <class _Ty> struct remove_reference<_Ty&>
{
    typedef _Ty type;
};

template <class B1 = true_type,
          class B2 = true_type,
          class B3 = true_type,
          class B4 = true_type,
          class B5 = true_type>
struct conjunction : conditional<static_cast<bool>( B1::value ),
                                 conjunction<B2, B3, B4, B5>,
                                 B1>::type
{
};

template <class B1> struct conjunction<B1> : B1
{
};

template <class _Trait>
struct negation : bool_constant<!static_cast<bool>( _Trait::value )>
{
}; // The negated result of _Trait

template <class = void> struct compat_void
{
    typedef void type;
};

template <class _Ty, class = void> struct _Add_reference
{ // add reference (non-referenceable type)
    typedef _Ty _Lvalue;
};

template <class _Ty>
struct _Add_reference<_Ty, typename compat_void<_Ty&>::type>
{ // (referenceable type)
    typedef _Ty& _Lvalue;
};

template <class _Ty> struct add_lvalue_reference
{
    typedef typename _Add_reference<_Ty>::_Lvalue type;
};

template <class _Ty> struct remove_extent
{ // remove array extent
    typedef _Ty type;
};

template <class _Ty, size_t _Ix> struct remove_extent<_Ty[_Ix]>
{
    typedef _Ty type;
};

template <class _Ty> struct remove_extent<_Ty[]>
{
    typedef _Ty type;
};

template <class _Ty> struct remove_pointer
{
    typedef _Ty type;
};

template <class _Ty> struct remove_pointer<_Ty*>
{
    typedef _Ty type;
};

template <class _Ty> struct remove_pointer<_Ty* const>
{
    typedef _Ty type;
};

template <class _Ty> struct remove_pointer<_Ty* volatile>
{
    typedef _Ty type;
};

template <class _Ty> struct remove_pointer<_Ty* const volatile>
{
    typedef _Ty type;
};

// STRUCT TEMPLATE is_array
template <class _Ty> struct is_array : false_type
{ // determine whether _Ty is an array
};

template <class _Ty, size_t _Nx> struct is_array<_Ty[_Nx]> : true_type
{ // determine whether _Ty is an array
};

template <class _Ty> struct is_array<_Ty[]> : true_type
{ // determine whether _Ty is an array
};

// STRUCT TEMPLATE is_pointer
template <class _Ty> struct is_pointer : false_type
{ // determine whether _Ty is a pointer
};

template <class _Ty> struct is_pointer<_Ty*> : true_type
{ // determine whether _Ty is a pointer
};

template <class _Ty> struct is_pointer<_Ty* const> : true_type
{ // determine whether _Ty is a pointer
};

template <class _Ty> struct is_pointer<_Ty* volatile> : true_type
{ // determine whether _Ty is a pointer
};

template <class _Ty> struct is_pointer<_Ty* const volatile> : true_type
{ // determine whether _Ty is a pointer
};

template <class _From, class _To>
struct is_convertible : bool_constant<__is_convertible_to( _From, _To )>
{
    // determine whether _From is convertible to _To
};

template <class _Ty> struct is_empty : bool_constant<__is_empty( _Ty )>
{
}; // determine whether _Ty is an empty class

template <class _Ty> struct is_final : false_type
{
}; // determine whether _Ty is a final class

template <class _Ty, unsigned int _Ix = 0>
struct extent : integral_constant<size_t, 0>
{
};

template <class _Ty, size_t _Nx>
struct extent<_Ty[_Nx], 0> : integral_constant<size_t, _Nx>
{
};

template <class _Ty, unsigned int _Ix, size_t _Nx>
struct extent<_Ty[_Nx], _Ix>
    : integral_constant<size_t, extent<_Ty, _Ix - 1>::value>
{
};

template <class _Ty> struct extent<_Ty[], 0> : integral_constant<size_t, 0>
{
};

template <class _Ty, unsigned int _Ix>
struct extent<_Ty[], _Ix>
    : integral_constant<size_t, extent<_Ty, _Ix - 1>::value>
{
};

struct _Zero_then_variadic_args_t
{
    explicit _Zero_then_variadic_args_t() {}
}; // tag type for value-initializing first, constructing second from remaining args

struct _One_then_variadic_args_t
{
    explicit _One_then_variadic_args_t() {}
}; // tag type for constructing first from one arg, constructing second from remaining args

template <class _Ty1,
          class _Ty2,
          bool = is_empty<_Ty1>::value && !is_final<_Ty1>::value>
class _Compressed_pair : private _Ty1
{ // store a pair of values, deriving from empty first
  public:
    _Ty2 _Myval2;

    typedef _Ty1 _Mybase; // for visualization

    explicit _Compressed_pair( _Zero_then_variadic_args_t ) noexcept
        : _Ty1(), _Myval2()
    {
    }

    template <class _Other2>
    explicit _Compressed_pair( _Zero_then_variadic_args_t,
                               _Other2 _Val2 ) noexcept
        : _Ty1(), _Myval2( _Val2 )
    {
    }

    template <class _Other1, class _Other2>
    _Compressed_pair( _One_then_variadic_args_t,
                      _Other1 _Val1,
                      _Other2 _Val2 ) noexcept
        : _Ty1( _Val1 ), _Myval2( _Val2 )
    {
    }

    _Ty1& _Get_first() noexcept { return *this; }

    const _Ty1& _Get_first() const noexcept { return *this; }
};

template <class _Ty1, class _Ty2> class _Compressed_pair<_Ty1, _Ty2, false>
{ // store a pair of values, not deriving from first
  public:
    _Ty1 _Myval1;
    _Ty2 _Myval2;

    explicit _Compressed_pair( _Zero_then_variadic_args_t ) noexcept
        : _Myval1(), _Myval2()
    {
    }

    template <class _Other2>
    explicit _Compressed_pair( _Zero_then_variadic_args_t,
                               _Other2 _Val2 ) noexcept
        : _Myval1(), _Myval2( _Val2 )
    {
    }

    template <class _Other1, class _Other2>
    _Compressed_pair( _One_then_variadic_args_t,
                      _Other1 _Val1,
                      _Other2 _Val2 ) noexcept
        : _Myval1( _Val1 ), _Myval2( _Val2 )
    {
    }

    _Ty1& _Get_first() noexcept { return _Myval1; }

    const _Ty1& _Get_first() const noexcept { return _Myval1; }
};

template <class _Ty> struct default_delete
{ // default deleter for unique_ptr
    default_delete() noexcept {}

    template <class _Ty2>
    default_delete( const default_delete<_Ty2>&,
                    typename enable_if<is_convertible<_Ty2*, _Ty*>::value,
                                       int>::type = 0 ) noexcept
    {
    }

    void operator()( _Ty* _Ptr ) const noexcept /* strengthened */
    {                                           // delete a pointer
        static_assert( 0 < sizeof( _Ty ), "can't delete an incomplete type" );
        delete _Ptr;
    }
};

template <class _Ty> struct default_delete<_Ty[]>
{ // default deleter for unique_ptr to array of unknown size
    default_delete() noexcept {}

    template <class _Uty>
    default_delete(
        const default_delete<_Uty[]>&,
        typename enable_if<is_convertible<_Uty ( * )[], _Ty ( * )[]>::value,
                           int>::type = 0 ) noexcept
    {
    }

    template <class _Uty>
    void operator()(
        _Uty* _Ptr,
        typename enable_if<is_convertible<_Uty ( * )[], _Ty ( * )[]>::value,
                           int>::type = 0 ) const noexcept /* strengthened */
    {                                                      // delete a pointer
        static_assert( 0 < sizeof( _Uty ), "can't delete an incomplete type" );
        delete[] _Ptr;
    }
};

template <class _Ty, class _Dx_noref, class = void>
struct _Get_deleter_pointer_type
{ // provide fallback
    typedef _Ty* type;
};

//template <class _Ty, class _Dx_noref>
//struct _Get_deleter_pointer_type<
//    _Ty,
//    _Dx_noref,
//    typename compat_void<typename _Dx_noref::pointer>::type>
//{ // get _Dx_noref::pointer
//    typedef typename _Dx_noref::pointer type;
//};

template <class, class = void> struct _Can_form_pointer : false_type
{
};

template <class _Ty>
struct _Can_form_pointer<_Ty, typename compat_void<_Ty*>::type> : true_type
{
};

template <class _Ty /*, class _Dx*/ /* = default_delete<_Ty> */>
class unique_ptr
{ // non-copyable pointer to an object
    typedef default_delete<_Ty> _Dx;

  public:
    static_assert( _Can_form_pointer<_Ty>::value,
                   "unique_ptr<T, D> requires T* to be a valid type (N5001 "
                   "[unique.ptr.single.general]/1)." );

    typedef typename _Get_deleter_pointer_type<
        _Ty,
        typename remove_reference<_Dx>::type>::type pointer;
    typedef _Ty                                     element_type;
    typedef _Dx                                     deleter_type;

    unique_ptr() noexcept : _Mypair( _Zero_then_variadic_args_t() ) {}

    unique_ptr( nullptr_t ) noexcept : _Mypair( _Zero_then_variadic_args_t() )
    {
    }

    unique_ptr& operator=( nullptr_t ) noexcept
    {
        reset();
        return *this;
    }

    // The Standard depicts these constructors that accept pointer as taking type_identity_t<pointer> to inhibit CTAD.
    // Since pointer is an opaque type alias in our implementation, it inhibits CTAD without extra decoration.
    unique_ptr( pointer _Ptr ) noexcept
        : _Mypair( _Zero_then_variadic_args_t(), _Ptr )
    {
    }

    unique_ptr( const unique_ptr& _Right ) noexcept
        : _Mypair( _One_then_variadic_args_t(),
                   const_cast<unique_ptr&>( _Right ).get_deleter(),
                   const_cast<unique_ptr&>( _Right ).release() )
    {
    }

    template <class _Ty2 /*, class _Dx2*/>
    unique_ptr(
        const unique_ptr<_Ty2 /*, _Dx2*/>& _Right,
        typename enable_if<
            conjunction<
                negation<is_array<_Ty2>>,
                is_convertible<typename unique_ptr<_Ty2 /*, _Dx2*/>::pointer,
                               pointer> /*,
                typename conditional<is_reference<_Dx>::value,
                                     is_same<_Dx2, _Dx>,
                                     is_convertible<_Dx2, _Dx>>::type*/
                >::value,
            int>::type = 0 ) noexcept
        : _Mypair(
              _One_then_variadic_args_t(),
              const_cast<unique_ptr<_Ty2 /*, _Dx2*/>&>( _Right ).get_deleter(),
              const_cast<unique_ptr<_Ty2 /*, _Dx2*/>&>( _Right ).release() )
    {
    }

    template <class _Ty2 /*, class _Dx2*/>
    unique_ptr& operator=( const unique_ptr<_Ty2 /*, _Dx2*/>& _Right ) noexcept
    {
        static_assert(
            ( is_same<
                typename enable_if<
                    conjunction<negation<is_array<_Ty2>>,
                                /*is_assignable<_Dx&, _Dx2>,*/
                                is_convertible<typename unique_ptr<
                                                   _Ty2 /*, _Dx2*/>::pointer,
                                               pointer>>::value,
                    int>::type,
                int>::value ) );
        reset( const_cast<unique_ptr<_Ty2 /*, _Dx2*/>&>( _Right ).release() );
        _Mypair._Get_first() =
            const_cast<unique_ptr<_Ty2 /*, _Dx2*/>&>( _Right )
                ._Mypair._Get_first();
        return *this;
    }

    unique_ptr& operator=( const unique_ptr& _Right ) noexcept
    {
        reset( const_cast<unique_ptr&>( _Right ).release() );
        _Mypair._Get_first() =
            const_cast<unique_ptr&>( _Right )._Mypair._Get_first();
        return *this;
    }

    void swap( unique_ptr& _Right ) noexcept
    {
        std::swap( _Mypair._Myval2, _Right._Mypair._Myval2 );
        std::swap( _Mypair._Get_first(), _Right._Mypair._Get_first() );
    }

    ~unique_ptr() noexcept
    {
        if ( _Mypair._Myval2 ) {
            _Mypair._Get_first()( _Mypair._Myval2 );
        }
    }

    _Dx& get_deleter() noexcept { return _Mypair._Get_first(); }

    const _Dx& get_deleter() const noexcept { return _Mypair._Get_first(); }

    typename add_lvalue_reference<_Ty>::type operator*() const noexcept
    {
        return *_Mypair._Myval2;
    }

    pointer operator->() const noexcept { return _Mypair._Myval2; }

    pointer get() const noexcept { return _Mypair._Myval2; }

    operator bool() const noexcept
    {
        return static_cast<bool>( _Mypair._Myval2 != nullptr );
    }

    pointer release() noexcept
    {
        pointer _Ans    = _Mypair._Myval2;
        _Mypair._Myval2 = pointer();
        return ( _Ans );
    }

    void reset( pointer _Ptr = pointer() ) noexcept
    {
        pointer _Old    = _Mypair._Myval2;
        _Mypair._Myval2 = _Ptr;
        if ( _Old != pointer() ) {
            _Mypair._Get_first()( _Old );
        }
    }

  private:
    template <class /*, class*/> friend class unique_ptr;

    _Compressed_pair<_Dx, pointer> _Mypair;
};

template <class _Ty /*, class _Dx*/> class unique_ptr<_Ty[] /*, _Dx*/>
{ // non-copyable pointer to an array object
    typedef default_delete<_Ty[]> _Dx;

  public:
    typedef typename _Get_deleter_pointer_type<
        _Ty,
        typename remove_reference<_Dx>::type>::type pointer;
    typedef _Ty                                     element_type;
    typedef _Dx                                     deleter_type;

    unique_ptr() noexcept : _Mypair( _Zero_then_variadic_args_t() ) {}

    template <class _Uty, class _Is_nullptr = is_same<_Uty, nullptr_t>>
    struct _Enable_ctor_reset
        : enable_if<
              is_same<_Uty, pointer>::value || _Is_nullptr::value ||
                  ( is_same<pointer, element_type*>::value &&
                    is_pointer<_Uty>::value &&
                    is_convertible<typename remove_pointer<_Uty>::type ( * )[],
                                   element_type ( * )[]>::value ),
              int>
    {
    };

    template <class _Uty>
    unique_ptr( _Uty _Ptr,
                typename _Enable_ctor_reset<_Uty>::type = 0 ) noexcept
        : _Mypair( _Zero_then_variadic_args_t(), _Ptr )
    {
    }

    unique_ptr( const unique_ptr& _Right ) noexcept
        : _Mypair( _One_then_variadic_args_t(),
                   const_cast<unique_ptr&>( _Right ).get_deleter(),
                   const_cast<unique_ptr&>( _Right ).release() )
    {
    }

    unique_ptr& operator=( const unique_ptr& _Right ) noexcept
    {
        if ( this != &_Right ) {
            reset( const_cast<unique_ptr&>( _Right ).release() );
            _Mypair._Get_first() = std::move(
                const_cast<unique_ptr&>( _Right )._Mypair._Get_first() );
        }

        return *this;
    }

    template <class _Uty,
              /*class _Ex,
              class _More,*/
              class _UP_pointer = typename unique_ptr<_Uty /*, _Ex*/>::pointer,
              class _UP_element_type =
                  typename unique_ptr<_Uty /*, _Ex*/>::element_type>
    struct _Enable_conversion
    {
        typedef typename enable_if<
            conjunction<is_array<_Uty>,
                        is_same<pointer, element_type*>,
                        is_same<_UP_pointer, _UP_element_type*>,
                        is_convertible<_UP_element_type ( * )[],
                                       element_type ( * )[]> /*,
                                      _More*/
                        >::value,
            int>::type type;
    };

    template <class _Uty /*, class _Ex*/>
    unique_ptr( const unique_ptr<_Uty /*, _Ex*/>& _Right,
                typename _Enable_conversion<_Uty /*,
            _Ex,
            typename conditional<is_reference<_Dx>::value,
                                 is_same<_Ex, _Dx>,
                                 is_convertible<_Ex, _Dx>>::type*/
                                            >::type = 0 ) noexcept
        : _Mypair(
              _One_then_variadic_args_t(),
              const_cast<unique_ptr<_Uty /*, _Ex*/>&>( _Right ).get_deleter(),
              const_cast<unique_ptr<_Uty /*, _Ex*/>&>( _Right ).release() )
    {
    }

    template <class _Uty /*, class _Ex*/>
    unique_ptr& operator=( const unique_ptr<_Uty /*, _Ex*/>& _Right ) noexcept
    {
        static_assert( ( is_same<typename _Enable_conversion<_Uty /*, _Ex,
                                                is_assignable<_Dx&, _Ex>*/
                                                             >::type,
                                 int>::value ) );
        reset( const_cast<unique_ptr<_Uty /*, _Ex*/>&>( _Right ).release() );
        _Mypair._Get_first() = const_cast<unique_ptr<_Uty /*, _Ex*/>&>( _Right )
                                   ._Mypair._Get_first();
        return *this;
    }

    unique_ptr( nullptr_t ) noexcept : _Mypair( _Zero_then_variadic_args_t() )
    {
    }

    unique_ptr& operator=( nullptr_t ) noexcept
    {
        reset();
        return *this;
    }

    void reset( nullptr_t = nullptr ) noexcept { reset( pointer() ); }

    void swap( unique_ptr& _Right ) noexcept
    {
        std::swap( _Mypair._Myval2, _Right._Mypair._Myval2 ); // intentional ADL
        std::swap( _Mypair._Get_first(),
                   _Right._Mypair._Get_first() ); // intentional ADL
    }

    ~unique_ptr() noexcept
    {
        if ( _Mypair._Myval2 ) {
            _Mypair._Get_first()( _Mypair._Myval2 );
        }
    }

    _Dx& get_deleter() noexcept { return _Mypair._Get_first(); }

    const _Dx& get_deleter() const noexcept { return _Mypair._Get_first(); }

    _Ty& operator[]( size_t _Idx ) const noexcept /* strengthened */
    {
        return _Mypair._Myval2[_Idx];
    }

    pointer get() const noexcept { return _Mypair._Myval2; }

    operator bool() const noexcept
    {
        return static_cast<bool>( _Mypair._Myval2 != nullptr );
    }

    pointer release() noexcept
    {
        pointer _Ans    = _Mypair._Myval2;
        _Mypair._Myval2 = pointer();
        return ( _Ans );
    }

    template <class _Uty>
    void
    reset( _Uty _Ptr,
           typename _Enable_ctor_reset<_Uty, false_type>::type = 0 ) noexcept
    {
        pointer _Old    = _Mypair._Myval2;
        _Mypair._Myval2 = _Ptr;
        if ( _Old != pointer() ) {
            _Mypair._Get_first()( _Old );
        }
    }

  private:
    template <class /*, class*/> friend class unique_ptr;

    _Compressed_pair<_Dx, pointer> _Mypair;
};

template <class _Ty>
unique_ptr<_Ty>
    make_unique( typename enable_if<!is_array<_Ty>::value, int>::type = 0 )
{ // make a unique_ptr
    return unique_ptr<_Ty>( new _Ty() );
}

template <class _Ty, class A1>
unique_ptr<_Ty>
make_unique( const A1& a1,
             typename enable_if<!is_array<_Ty>::value, int>::type = 0 )
{ // make a unique_ptr
    return unique_ptr<_Ty>( new _Ty( a1 ) );
}

template <class _Ty, class A1, class A2>
unique_ptr<_Ty>
make_unique( const A1& a1,
             const A2& a2,
             typename enable_if<!is_array<_Ty>::value, int>::type = 0 )
{ // make a unique_ptr
    return unique_ptr<_Ty>( new _Ty( a1, a2 ) );
}

template <class _Ty>
unique_ptr<_Ty>
make_unique( const size_t _Size,
             typename enable_if<is_array<_Ty>::value && extent<_Ty>::value == 0,
                                int>::type = 0 )
{ // make a unique_ptr
    typedef remove_extent_t<_Ty> _Elem;
    return unique_ptr<_Ty>( new _Elem[_Size]() );
}

template <class _Ty>
void make_unique( typename enable_if<extent<_Ty>::value != 0, int>::type = 0 );

template <class _Ty, class A1>
void make_unique( const A1& a1,
                  typename enable_if<extent<_Ty>::value != 0, int>::type = 0 );

template <class _Ty, class A1, class A2>
void make_unique( const A1& a1,
                  const A2& a2,
                  typename enable_if<extent<_Ty>::value != 0, int>::type = 0 );

template <class _Ty /*, class _Dx*/>
bool operator==( const unique_ptr<_Ty /*, _Dx*/>& _Left, nullptr_t ) noexcept
{
    return !_Left;
}

template <class _Ty /*, class _Dx*/>
bool operator==( nullptr_t, const unique_ptr<_Ty /*, _Dx*/>& _Right ) noexcept
{
    return !_Right;
}

template <class _Ty /*, class _Dx*/>
bool operator!=( const unique_ptr<_Ty /*, _Dx*/>& _Left, nullptr_t ) noexcept
{
    return !( _Left == nullptr );
}

template <class _Ty /*, class _Dx*/>
bool operator!=( nullptr_t, const unique_ptr<_Ty /*, _Dx*/>& _Right ) noexcept
{
    return !( nullptr == _Right );
}
} // namespace std
#endif
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#if defined( __cplusplus )
#include <array>

namespace std {
using tr1::array;
} // namespace std
#endif
#endif

#if defined( _MSC_VER ) && _MSC_VER < 1600
#if defined( __cplusplus )
#include <memory>

namespace std {
using tr1::shared_ptr;
} // namespace std
#endif
#endif

#endif // ELFIO_COMPAT_HPP
