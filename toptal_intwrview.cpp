#include <iostream>

using namespace std;

/* Check if D is derived from B at compile-time */
template<typename D, typename B>
class IsDerivedFromHelper
{
    static constexpr bool Test( B* ) { return true; }
    static constexpr bool Test( ... ) { return false; }
public:
    static constexpr bool Is = Test(static_cast<D*>(nullptr));
};

template <class C, class P> 
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}

/* Another (more elegant) solution */
template <class P>
class Is {
    static constexpr bool Test( P* )  { return true ; }
    static constexpr bool Test( ... ) { return false; }
public:
    template <class C>
    static constexpr bool ParentOf() {
        return Test(static_cast<C*>(nullptr));
    }
};


/* Testing */
class Base {};
class Child: public Base {};
class Test {};

int main()
{
    cout << IsDerivedFrom<Child, Base>() << endl;
    cout << IsDerivedFrom<Test, Base>() << endl;
    
    cout << Is<Base>::ParentOf<Child>() << endl;
    cout << Is<Base>::ParentOf<Test>() << endl;
}
