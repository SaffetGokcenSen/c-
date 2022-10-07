template <class For, class Predicate>
For find_if(For b, For e, Predicate p) {
    while (b != e) {
        if (p(*b)) {
            return b;
        }
        else {
            ++b;
        }
    }
    return b;
}