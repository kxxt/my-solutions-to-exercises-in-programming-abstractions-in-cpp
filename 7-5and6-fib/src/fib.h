#ifndef FIB_H
#define FIB_H

#include <iostream>

typedef unsigned long long u64;

namespace fib {

namespace rec {

u64 fib1(u64 x);
u64 fib2(u64 x);

u64 countFib1(u64 x);
u64 countFib2(u64 x);

} // namespace rec

namespace itr {

u64 fib(u64 x);

} // namespace itr

} // namespace fib

#endif // FIB_H
