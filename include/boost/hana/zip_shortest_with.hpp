/*!
@file
Defines `boost::hana::zip_shortest_with`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ZIP_SHORTEST_WITH_HPP
#define BOOST_HANA_ZIP_SHORTEST_WITH_HPP

#include <boost/hana/fwd/zip_shortest_with.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>

#include <boost/hana/detail/fast_and.hpp>
#include <boost/hana/length.hpp>
#include <boost/hana/minimum.hpp>
#include <boost/hana/take.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/zip_with.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename F, typename Xs, typename ...Ys>
    constexpr auto
    zip_shortest_with_t::operator()(F&& f, Xs&& xs, Ys&& ...ys) const {
    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(detail::fast_and<
            _models<Sequence, Xs>::value, _models<Sequence, Ys>::value...
        >::value,
        "hana::zip_shortest_with(f, xs, ys...) requires 'xs' and 'ys...' to be Sequences");
    #endif

        return zip_shortest_with_impl<typename datatype<Xs>::type>::apply(
            static_cast<F&&>(f),
            static_cast<Xs&&>(xs),
            static_cast<Ys&&>(ys)...
        );
    }
    //! @endcond

    template <typename S, bool condition>
    struct zip_shortest_with_impl<S, when<condition>> : default_ {
        template <typename F, typename ...Xs>
        static constexpr decltype(auto) apply(F&& f, Xs&& ...xs) {
            auto min = hana::minimum(hana::make_tuple(hana::length(xs)...));
            return hana::zip_with(static_cast<F&&>(f),
                hana::take(static_cast<Xs&&>(xs), min)...
            );
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_ZIP_SHORTEST_WITH_HPP
