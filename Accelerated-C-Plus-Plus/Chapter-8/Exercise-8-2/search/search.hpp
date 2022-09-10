template <class For>
For search(For b, For e, For b2, For e2) {
    if ((e2 - b2) > (e - b)) {
        // if the subsequence represented by the iterators b2 and e2 is longer 
        // than the sequence denoted by the iterators b and e, then do nothing.
        return e; 
    }
    else {
        while (b != e) {
            if (*b == *b2) {
                For it = b;
                do
                {
                    ++b;
                    ++b2;
                } while ((b2 != e2) && (*b == *b2));
                if (b2 == e2) {
                    return it; 
                }
            }
            else {
                ++b;
            }
        }
        return e;
    }
}