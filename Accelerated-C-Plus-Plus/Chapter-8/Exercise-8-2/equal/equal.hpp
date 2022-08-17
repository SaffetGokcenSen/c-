template <class In, class Out> 
bool equal(In b, In e, Out b2) {
    bool equal = true;
    while (b != e & equal) {
        equal = *b2 == *b;
        ++b;
    }
    return equal;
}