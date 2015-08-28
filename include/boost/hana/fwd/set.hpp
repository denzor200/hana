/*!
@file
Forward declares `boost::hana::set`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_SET_HPP
#define BOOST_HANA_FWD_SET_HPP

#include <boost/hana/fwd/erase_key.hpp>
#include <boost/hana/fwd/core/make.hpp>


namespace boost { namespace hana {
    //! @ingroup group-datatypes
    //! Basic unordered container requiring compile-time `Comparable` elements.
    //!
    //! A set is an unordered container that can hold heterogeneous objects.
    //! As usual, a set requires (and ensures) that no duplicates are present.
    //!
    //! @note
    //! The actual representation of a `hana::set` is implementation-defined.
    //! In particular, one should not take for granted the order of the
    //! template parameters and the presence of any constructor or assignment
    //! operator. The canonical way of creating a `hana::set` is through
    //! `hana::make_set`.
    //!
    //!
    //! Modeled concepts
    //! ----------------
    //! 1. `Comparable`\n
    //! Two sets are equal iff they contain the same elements, regardless of
    //! the order.
    //! @include example/set/comparable.cpp
    //!
    //! 2. Foldable\n
    //! Folding a set is equivalent to folding the sequence of its values.
    //! However, note that the values are not required to be in any specific
    //! order, so using the folds provided here with an operation that is not
    //! both commutative and associative will yield non-deterministic behavior.
    //! @include example/set/foldable.cpp
    //!
    //! 3. Searchable\n
    //! The elements in a set act as both its keys and its values. Since the
    //! elements of a set are unique, searching for an element will return
    //! either the only element which is equal to the searched value, or
    //! `nothing`. Also note that `operator[]` can be used instead of the
    //! `at_key` function.
    //! @include example/set/searchable.cpp
    //!
    //!
    //! Conversion from any `Foldable`
    //! ------------------------------
    //! Any `Foldable` structure can be converted into a `hana::set` with
    //! `to<Set>`. The elements of the structure must all be compile-time
    //! `Comparable`. If the structure contains duplicate elements, only
    //! the first occurence will appear in the resulting set. More
    //! specifically, conversion from a `Foldable` is equivalent to
    //! @code
    //!     to<Set>(xs) == fold_left(xs, make<Set>(), insert)
    //! @endcode
    //!
    //! __Example__
    //! @include example/set/convert.cpp
    template <typename ...Xs>
    struct set;

    //! Tag representing the `hana::set` container.
    //! @relates hana::set
    struct Set { };

    //! Function object for creating a `hana::set`.
    //! @relates hana::set
    //!
    //! Given zero or more values `xs...`, `make<Set>` returns a `set`
    //! containing those values. The values must all be compile-time
    //! `Comparable`, and no duplicate values may be provided. To create
    //! a `set` from a sequence with possible duplicates, use `to<Set>`
    //! instead.
    //!
    //!
    //! Example
    //! -------
    //! @include example/set/make.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    template <>
    constexpr auto make<Set> = [](auto&& ...xs) {
        return set<implementation-defined...>{forwarded(xs)...};
    };
#endif

    //! Equivalent to `make<Set>`; provided for convenience.
    //! @relates hana::set
    //!
    //!
    //! Example
    //! -------
    //! @include example/set/make.cpp
    constexpr auto make_set = make<Set>;

    //! Insert an element in a `hana::set`.
    //! @relates hana::set
    //!
    //! If the set already contains an element that compares equal, then
    //! nothing is done and the set is returned as is.
    //!
    //!
    //! @param set
    //! The set in which to insert a value.
    //!
    //! @param element
    //! The value to insert. It must be compile-time `Comparable`.
    //!
    //!
    //! Example
    //! -------
    //! @include example/set/insert.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto insert = [](auto&& set, auto&& element) -> decltype(auto) {
        return tag-dispatched;
    };
#endif

    //! Remove an element from a `hana::set`.
    //! @relates hana::set
    //!
    //! Returns a new set containing all the elements of the original,
    //! except the one comparing `equal` to the given element. If the set
    //! does not contain such an element, a new set equal to the original
    //! set is returned.
    //!
    //!
    //! @param set
    //! The set in which to remove a value.
    //!
    //! @param element
    //! The value to remove. It must be compile-time `Comparable`.
    //!
    //!
    //! Example
    //! -------
    //! @include example/set/erase_key.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto erase_key = [](auto&& set, auto&& element) -> decltype(auto) {
        return tag-dispatched;
    };
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_SET_HPP
