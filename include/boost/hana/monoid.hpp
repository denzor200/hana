/*!
@file
Defines `boost::hana::Monoid`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_MONOID_HPP
#define BOOST_HANA_MONOID_HPP

#include <boost/hana/fwd/monoid.hpp>

#include <boost/hana/core/common.hpp>
#include <boost/hana/core/convert.hpp>
#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/method.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/operators.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_common.hpp>
#include <boost/hana/detail/std/declval.hpp>
#include <boost/hana/detail/std/enable_if.hpp>
#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/detail/std/integral_constant.hpp>


namespace boost { namespace hana {
    namespace operators {
        //! Equivalent to `plus`.
        //! @relates boost::hana::Monoid
        template <typename X, typename Y, typename = typename detail::std::enable_if<
            enable_operators<Monoid, datatype_t<X>>::value ||
            enable_operators<Monoid, datatype_t<Y>>::value
        >::type>
        constexpr decltype(auto) operator+(X&& x, Y&& y) {
            return plus(
                detail::std::forward<decltype(x)>(x),
                detail::std::forward<decltype(y)>(y)
            );
        }
    }

    template <typename T, typename U, typename Context>
    struct dispatch_impl<4, plus_impl<T, U>, Context>
        : detail::dispatch_common<plus_impl<T, U>, Monoid, Context>
    { };

    template <typename T>
    struct plus_impl<T, T, when_valid<
        decltype(detail::std::declval<T>() + detail::std::declval<T>())
    >> {
        template <typename X, typename Y>
        static constexpr decltype(auto) apply(X&& x, Y&& y) {
            return detail::std::forward<X>(x) + detail::std::forward<Y>(y);
        }
    };

    template <typename T>
    struct zero_impl<T, when_valid<decltype(static_cast<T>(0))>> {
        static constexpr T apply()
        { return static_cast<T>(0); }
    };

    template <>
    struct models_impl<Monoid> {
        template <typename T, typename Context>
        static constexpr auto apply =
            is_implemented<plus_impl<T, T>, Context> &&
            is_implemented<zero_impl<T>, Context>
        ;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_MONOID_HPP
