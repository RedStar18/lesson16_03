// lesson16_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
protected:
    unsigned int sides_count{ 0 };

public:
    Figure()
    {
    }
    unsigned int get_sides_count()
    {
        return sides_count;
    }

    virtual std::string get_name()
    {
        return "Фигура";
    }
    virtual std::string get_sides_info()
    {
        return "";
    }
    virtual std::string get_angles_info()
    {
        return "";
    }
    virtual bool check()
    {
        return sides_count == 0 ? true : false;
    }
    virtual void print_info()
    {
        std::cout << get_name() << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
    }
};

class Triangle : public Figure
{
protected:
    unsigned int a{ 0 }, b{ 0 }, c{ 0 }, A{ 0 }, B{ 0 }, C{ 0 };
public:
    Triangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B, unsigned int C) : a(a), b(b), c(c), A(A), B(B), C(C)
    {
        sides_count = 3;
    }

    unsigned int get_a() const { return a; }
    unsigned int get_b() const { return b; }
    unsigned int get_c() const { return c; }
    unsigned int get_A() const { return A; }
    unsigned int get_B() const { return B; }
    unsigned int get_C() const { return C; }

    std::string get_name() override
    {
        return "Треугольник";
    }
    std::string get_sides_info() override
    {
        return "a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c);
    }
    std::string get_angles_info() override
    {
        return "A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C);
    }
    bool check() override
    {
        return ((sides_count == 3) && ((A + B + C) == 180)) ? true : false;
    }

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: " << get_sides_info() << std::endl;
        std::cout << "Углы: " << get_angles_info() << std::endl;
    }
};

class RightTriangle : public Triangle
{
public:

    RightTriangle(unsigned int a, unsigned int b, unsigned int c, unsigned int A, unsigned int B) : Triangle(a, b, c, A, B, 90) {}

    std::string get_name() override
    {
        return "Прямоугольный треугольник";
    }
    bool check() override
    {
        return (Triangle::check() && (C == 90)) ? true : false;
    }
};

class IsoscelesTriangle : public Triangle
{
public:

    IsoscelesTriangle(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Triangle(a, b, a, A, B, A) {}

    std::string get_name() override
    {
        return "Равнобедренный треугольник";
    }
    bool check() override
    {
        return (Triangle::check() && (a == c) && (A == C)) ? true : false;
    }
};

class EquilateralTriangle : public Triangle
{
public:

    EquilateralTriangle(unsigned int a) : Triangle(a, a, a, 60, 60, 60) {}

    std::string get_name() override
    {
        return "Равносторонний треугольник";
    }
    bool check() override
    {
        return (Triangle::check() && (a == b) && (b == c) && (A == B) && (B == C)) ? true : false;
    }
};

class Quadrangle : public Figure
{
protected:
    unsigned int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
public:
    Quadrangle(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int A, unsigned int B, unsigned int C, unsigned int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {
        sides_count = 4;
    }

    unsigned int get_a() const { return a; }
    unsigned int get_b() const { return b; }
    unsigned int get_c() const { return c; }
    unsigned int get_d() const { return d; }
    unsigned int get_A() const { return A; }
    unsigned int get_B() const { return B; }
    unsigned int get_C() const { return C; }
    unsigned int get_D() const { return D; }

    std::string get_name() override
    {
        return "Четырёхугольник";
    }
    std::string get_sides_info() override
    {
        return "a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d);
    }
    std::string get_angles_info() override
    {
        return "A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D);
    }
    bool check() override
    {
        return ((sides_count == 4) && ((A + B + C + D) == 360)) ? true : false;
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: " << get_sides_info() << std::endl;
        std::cout << "Углы: " << get_angles_info() << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(unsigned int a, unsigned int b, unsigned int A, unsigned int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

    std::string get_name() override
    {
        return "Параллелограмм";
    }
    bool check() override
    {
        return (Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D)) ? true : false;
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(unsigned int a, unsigned int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

    std::string get_name() override
    {
        return "Прямоугольник";
    }
    bool check() override
    {
        return (Quadrangle::check() && (a == c) && (b == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) ? true : false;
    }
};

class Square : public Quadrangle
{
public:
    Square(unsigned int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {}

    std::string get_name() override
    {
        return "Квадрат";
    }
    bool check() override
    {
        return (Quadrangle::check() && (a == b) && (b == c) && (c == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) ? true : false;
    }
};

class Rhombus : public Quadrangle
{
public:
    Rhombus(unsigned int a, unsigned int A, unsigned int B) : Quadrangle(a, a, a, a, A, B, A, B) {}

    std::string get_name() override
    {
        return "Ромб";
    }
    bool check() override
    {
        return (Quadrangle::check() && (a == b) && (b == c) && (c == d) && (A == C) && (B == D)) ? true : false;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);

    Figure figure = Figure();

    Triangle triangle = Triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle = RightTriangle(10, 20, 30, 50, 60);
    RightTriangle right_triangle_2 = RightTriangle(10, 20, 30, 50, 40);
    IsoscelesTriangle isosceles_triangle = IsoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle = EquilateralTriangle(30);

    Quadrangle quadrangle = Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    class Rectangle rectangle = class Rectangle(10, 20);
    Square square = Square(20);
    Parallelogram parallelogram = Parallelogram(20, 30, 30, 40);
    Rhombus rhombus = Rhombus(30, 30, 40);

    figure.print_info();
    std::cout << std::endl;
    triangle.print_info();
    std::cout << std::endl;
    right_triangle.print_info();
    std::cout << std::endl;
    right_triangle_2.print_info();
    std::cout << std::endl;
    isosceles_triangle.print_info();
    std::cout << std::endl;
    equilateral_triangle.print_info();
    std::cout << std::endl;
    quadrangle.print_info();
    std::cout << std::endl;
    rectangle.print_info();
    std::cout << std::endl;
    square.print_info();
    std::cout << std::endl;
    parallelogram.print_info();
    std::cout << std::endl;
    rhombus.print_info();
    std::cout << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
