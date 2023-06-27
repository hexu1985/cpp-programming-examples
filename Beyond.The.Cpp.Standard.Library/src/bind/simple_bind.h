#ifndef SIMPLE_BIND_INCLUDE
#define SIMPLE_BIND_INCLUDE

namespace {
  class placeholder {};
  placeholder _1;
}

template <typename R,typename T, typename Arg>
class simple_bind_t {
  typedef R (T::*fn)(Arg);
  fn fn_;
  T t_;
public:
  simple_bind_t(fn f,const T& t):fn_(f),t_(t) {}

  R operator()(Arg& a) {
    return (t_.*fn_)(a);
  }
};

template <typename R, typename T, typename Arg>
simple_bind_t<R,T,Arg> simple_bind(
  R (T::*fn)(Arg),
  const T& t,
  const placeholder&) {
  return simple_bind_t<R,T,Arg>(fn,t);
}

#endif
