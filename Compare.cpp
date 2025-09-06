#include "Compare.hpp"
// Ramzy Elshabasy

bool CompareItemWeight::lessThan(const Item &a, const Item &b) {
    return a.weight_ < b.weight_;
}

bool CompareItemWeight::equal(const Item &a, const Item &b) {
    return std::abs(a.weight_ - b.weight_) < 0.00001; // Note the threshold for float equality (we can't just use
                                                      // '==')
}

bool CompareItemWeight::leq(const Item &a, const Item &b) {
    return lessThan(a, b) || equal(a, b);
}

bool CompareItemType::lessThan(const Item &a, const Item &b) {
    return a.type_ < b.type_;
}

bool CompareItemType::equal(const Item &a, const Item &b) {
    return a.type_ == b.type_;
}

bool CompareItemType::leq(const Item &a, const Item &b) {
    return lessThan(a, b) || equal(a, b);
}

// Newly Implemented Functions For The Item's Name

bool CompareItemName::lessThan(const Item &a, const Item &b) {
    return a.name_ < b.name_; // Implemented
}

bool CompareItemName::equal(const Item &a, const Item &b) {
    return a.name_ == b.name_; // Implemented
}

bool CompareItemName::leq(const Item &a, const Item &b) {
    return lessThan(a, b) || equal(a, b); // Implemented
}