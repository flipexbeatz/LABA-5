//Класс «Прямая призма»(Prisma_Inscribed_Triangular прямая призма,
    //основание которой - треугольник, вписанный в окружность).Создать массив объектов
    //класса с параметрами : a, b, c - стороны треугольника, R - радиус описанной окружности,
    //Н - высота призмы.Вычислить площадь основания, боковую и полную поверхности
    //объектов - призм, упорядочив массив по возрастанию площади основания.
    //S = abc / 4R, Sook = a * H + by + cH, S, = 2S + S

#include <iostream>
#include <algorithm> // для использования функции сортировки std::sort
#include <vector> // для использования контейнера std::vector
#include <cmath> // для использования математических функций

class Prisma_Inscribed_Triangular {
public:
    // Конструктор класса
    Prisma_Inscribed_Triangular(double a, double b, double c, double R, double H)
        : a(a), b(b), c(c), R(R), H(H) {}

    // Функция, вычисляющая площадь основания
    double base_area() {
        return (a * b * c) / (4 * R);
    }

    // Функция, вычисляющая боковую поверхность
    double lateral_area() {
        return a * H + b * H + c * H;
    }

    // Функция, вычисляющая полную поверхность
    double total_area() {
        return 2 * base_area() + lateral_area();
    }

    // Функция для сравнения объектов класса по площади основания
    bool operator<(const Prisma_Inscribed_Triangular& other) const {
        return this->base_area() < other.base_area();
    }

private:
    double a, b, c, R, H;
};

int main() {
    // Создание массива объектов класса
    std::vector<Prisma_Inscribed_Triangular> prismas = {
        {3, 4, 5, 2, 6},
        {2, 2, 2, 1, 4},
        {5, 12, 13, 6, 10},
        {8, 15, 17, 7, 12}
    };

    // Сортировка массива по возрастанию площади основания
    std::sort(prismas.begin(), prismas.end());

    // Вывод площади основания, боковой и полной поверхности для каждой призмы
    for (auto& prisma : prismas) {
        std::cout << "Base area: " << prisma.base_area() << std::endl;
        std::cout << "Lateral area: " << prisma.lateral_area() << std::endl;
        std::cout << "Total area: " << prisma.total_area() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
