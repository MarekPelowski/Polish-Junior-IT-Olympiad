#include <iostream>
#include <iomanip>

double Add(double num1, double num2);
double Subtract(double num1, double num2);
double Multiply(double num1, double num2);
double Divide(double num1, double num2);

int main()
{
    double A, B;
    std::string sign;

    std::cout << "Addition, Subtraction, Multiplication or Division: ";
    std::cin >> sign;

    std::cout << "Enter first number: ";
    std::cin >> A;

    std::cout << "Enter second number: ";
    std::cin >> B;

    std::cout << std::fixed;

    if(sign == "Addition"){
        std::cout << std::setprecision(2) << Add(A, B);
    }
    else if(sign == "Subtraction"){
        std::cout << std::setprecision(2) << Subtract(A, B);
    }
    else if(sign == "Multiplication"){
        std::cout << std::setprecision(2) << Multiply(A, B);
    }
    else if(sign == "Division"){
        std::cout << std::setprecision(2) << Divide(A, B);
    }
    else{
        std::cout << "\nERROR\n";
        return 1;
    }

    return 0;
}

double Add(double num1, double num2){
    return num1 + num2;
}
double Subtract(double num1, double num2){
    return num1 - num2;
}
double Multiply(double num1, double num2){
    return num1 * num2;
}
double Divide(double num1, double num2){
    if(num2 == 0){
        std::cout << "Nie dziel przez 0!" << std::endl;
        return 0.0;
    }
    return num1 / num2;
}