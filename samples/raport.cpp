#include <iostream>
#include <cmath>

using namespace std;

/**
 * Algoritmul folosit e o interpretare a cautarii binare.
 * Complexitate: O(log2 N)
 */

int main() {
    // schimbi tu cu citire din fisier, eu am 
    // facut cu tastatura
    double x;
    cin >> x;

    // consideram fractia a/b
    // si cautam a,b astfel incat
    // a/b - x sa fie cat mai mic posibil
    double a = 1;
    double b = 1;

    // conceputl de "cel mai mic posibil" nu e un concept numeric
    // deci luam o variabila care sa reprezinte precizia
    // atunci cand a/b - x va fi mai mic decat precizia stabilita
    // inseamna ca ne-am apropiat destul de x, deci am gasit numerele
    double epsilon = 0.001;

    // abs() -> calculeaza modul din numar
    // cat timp modulul diferentei e mai mare decat
    // precizia dorita continuam sa cautam
    while (abs(a / b - x) > epsilon) {
        // daca rezultatul fractiei e mai mare decat x
        // fractia trebuie micsorata, deci
        // crestem b-ul
        if (a / b > x) {
            b += 1;

        // daca rezultatul fractiei e mai mic decat x
        // fractia trebuia marita, deci
        // crestem a-ul
        } else {
            a += 1;
        }
    }

    cout << a << " " << b << endl;
}
