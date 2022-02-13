#include "fib.h"

namespace fib {
namespace rec {

namespace {
u64 cnt_fib1 = 0, cnt_fib2 = 0;
u64 additiveSequence(u64 x, u64 t0, u64 t1) {
  ++cnt_fib2;
  if (x == 0)
    return t0;
  else if (x == 1)
    return t1;
  else
    return additiveSequence(x - 1, t1, t1 + t0);
}
} // namespace

u64 fib1(u64 x) {
  ++cnt_fib1;
  if (x < 2) // For 0, 1
    return x;
  else
    return fib1(x - 1) + fib1(x - 2);
}

u64 fib2(u64 x) {
  ++cnt_fib2;
  return additiveSequence(x, 0, 1);
}

u64 countFib1(u64 x) {
  cnt_fib1 = 0;
  fib1(x);
  return cnt_fib1;
}

u64 countFib2(u64 x) {
  cnt_fib2 = 0;
  fib2(x);
  return cnt_fib2;
}

} // namespace rec

namespace itr {
u64 fib(u64 x) {
  if (x < 2)
    return x;
  u64 a = 0, b = 1;
  for (u64 i = 1; i < x; i++) { // loop x - 1 times
    auto tmp = b;
    b = a + b;
    a = tmp;
  }
  return b;
}
} // namespace itr

} // namespace fib
