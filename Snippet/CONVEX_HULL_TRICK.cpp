// CONVEX HULL TRICK
// RETURNS MAXIMUM OF LINES IN SET
// CAN BE USED TO GET MINIMUM BY MAKING EVERYTHING NEGATIVE
// for doubles, toggle comment
// https://atcoder.jp/contests/abc289/tasks/abc289_g
// https://www.youtube.com/watch?v=KX_-7AqcnEU&t=3822s
// -----------------------------
// using cht_type = long double;
using cht_type = long long;
// -----------------------------
struct Line {
    mutable cht_type c, m, p;
    bool operator<(const Line& o) const { return c < o.c; }
    bool operator<(cht_type x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use infy = 1/.0, div(a,b) = a/b)
    // toggle comment block
    // ----------------------------------------------
    // const cht_type infy = 1/.0;
    // cht_type div(cht_type a, cht_type b) {
    //  return a / b;
    // }
    // ----------------------------------------------
    const cht_type infy = LLONG_MAX;
    cht_type div(cht_type a, cht_type b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    // ----------------------------------------------
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = infy, 0;
        if (x->c == y->c) x->p = x->m > y->m ? infy : -infy;
        else x->p = div(y->m - x->m, x->c - y->c);
        return x->p >= y->p;
    }
    void add(cht_type m, cht_type c) {
        // when minimum line is required, uncomment
        // ------------------
        //c *= -1; m *= -1;
        // ------------------
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    cht_type query(cht_type x) {
        assert(!empty());
        auto l = *lower_bound(x);
        // when minimum query is required, toggle comment
        // ------------------------
        // return -(l.c * x + l.m);
         return l.c * x + l.m;
        // ------------------------
    }
};
