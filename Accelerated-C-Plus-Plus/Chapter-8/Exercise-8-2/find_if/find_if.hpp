template <class For>
For find_if(For b, For e, bool p) {
    while (b != e) {
        if p(*b) {
            return b;
        }
        else {
            ++b;
        }
    }
    return b;
}