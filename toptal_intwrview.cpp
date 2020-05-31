#include <iostream>

using namespace std;

/* Check if D is derived from B at compile-time */
template<typename D, typename B>
class IsDerivedFromHelper
{
    static constexpr bool Test( B* ) { return true; }
    static constexpr bool Test( ... ) { return false; }
public:
    static constexpr bool Is = Test(static_cast<D*>(0));
};

template <class C, class P> 
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}


/* Testing */
class Base {};
class Child: public Base {};
class Test {};

int main()
{
    cout << IsDerivedFrom<Child, Base>() << endl;
    cout << IsDerivedFrom<Test, Base>() << endl;
}
