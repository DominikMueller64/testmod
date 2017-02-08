#include <Rcpp.h>


class Foo;
RCPP_EXPOSED_CLASS(Foo)

class Foo
{
  public:
    Foo():
      ancestor_ptr(NULL){}
    Foo(const Foo& ancestor):
      ancestor_ptr(&ancestor){}

    const Foo& get_ancestor() {return *ancestor_ptr;}

    const Foo* ancestor_ptr;
};


RCPP_MODULE(mymodule){
  using namespace Rcpp ;

  class_<Foo>("Foo")
    .default_constructor()
    .constructor<const Foo&>()
    .property("ancestor", &Foo::get_ancestor)
    ;
}



