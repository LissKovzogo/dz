#include <string>
#include <stdexcept>
#include <numeric>
#include <iostream>
using namespace std;
class Fraction {

public:

    Fraction(const int num = 0, const int den = 1);

    Fraction(const Fraction& other) = default;

    ~Fraction() = default;

    std::string toString() const;



    Fraction& operator+=(int a);

    friend bool operator==(const Fraction& left, const Fraction& rigth);

    friend const Fraction operator+(const Fraction& left, const Fraction& rigth);



private:

    void reduce();



private:

    int _numeratotr;

    int _denomenator;

};



Fraction::Fraction(const int num, const int den) {

    if (den == 0) {

        throw std::invalid_argument("denomenator can't be zero");

    }



    _numeratotr = num;

    _denomenator = den;



    reduce();

}



std::string Fraction::toString() const {

    if (_numeratotr == 0) {

        return "0";

    }



    if (_denomenator == 1) {

        return std::to_string(_numeratotr);

    }



    return std::to_string(_numeratotr) + "/" + std::to_string(_denomenator);

}
Fraction& Fraction::operator+=(int a) {
  
    this->_numeratotr = a * this->_denomenator + this->_numeratotr;
    return *this;
}



bool operator==(const Fraction& left, const Fraction& rigth) {
    return  left._numeratotr * rigth._denomenator == rigth._numeratotr * left._denomenator;
}



const Fraction operator+(const Fraction& left, const Fraction& rigth) {
    return left._numeratotr * rigth._denomenator + rigth._numeratotr * left._denomenator,
        left._denomenator* rigth._denomenator;

}


void Fraction::reduce() {

    auto gcd = (std::abs(_numeratotr), _denomenator);



    if (gcd != 1) {

        _numeratotr /= gcd;

        _denomenator /= gcd;

    }

}












int main() {

    Fraction a(0, 10);

    Fraction b(2, 5);

   cout << a.toString() << " " << b.toString() << " " << (a == b) << "\n";



    a += 2;

    Fraction c(40, 20);

    cout << a.toString() << " " << c.toString() << " " << (a == c) << "\n";



    auto d = a + b;
cout << d.toString() << " " << "\n";

}