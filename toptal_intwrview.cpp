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

/* A, B product problem */
void F(const int A[], int B[], unsigned int N) {
    long long int product = 1LL;
    for (unsigned int i = 0; i < N; ++i) product *= A[i];
    for (unsigned int j = 0; j < N; ++j) B[j] = product / A[j];
}

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
    
    int A[] = {2, 1, 5, 9};
    int B[] = {0, 0, 0, 0};
    F(A, B, 4);
    for (unsigned int i = 0; i < 4; ++i) {
        cout << B[i] << " ";   
    }
    cout << endl;
}
