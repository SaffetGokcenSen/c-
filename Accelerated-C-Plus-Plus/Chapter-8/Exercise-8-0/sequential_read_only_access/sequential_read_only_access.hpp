template <class In, class X> In find(In begin, In end, const X& x) {
    while (begin != end && *begin != x) ++begin;
    return begin;
}