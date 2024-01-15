/*
 * Test whether the `struct` can be omitted in C.
 *
 * result: Can't, but it is ok in C.
 */

struct Sales_item {
    char bookNo[25];
    double revenue;
    int units_sold;
};

void combine(struct Sales_item *i1, struct Sales_item *i2) {
    ;
}