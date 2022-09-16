template <class For, class T>
For find(For b, For e, T t) {
    while (b != e) {
        if (*b == t) {
            return b;
        }
        else {
            ++b;
        }
    }
    return b;
}