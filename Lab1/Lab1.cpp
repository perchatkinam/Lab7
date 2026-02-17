#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include<iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    printf("Задание 1\n");
    printf("f(x) = sin(x) / x\n");

    double start_x; 
    printf("Введите начальную точку интервала (0 < x <= 4): ");
    scanf("%lf", &start_x);

    if (start_x <= 0 || start_x > 4) {
        printf("Начальная точка должна быть в интервале (0, 4]\n");
        return 1;
    }

    printf("-------------------------------------------------\n");
    printf("   x        |      f(x)\n");
    printf("-------------------------------------------------\n");

    // делим интервал на 9 частей 
    double step = (4.0 - start_x) / 9.0;

    // вычисление значений в 10 точках
    for (int i = 0; i < 10; i++) {
        double x = start_x + i * step; // вычисление текущего х
        double fx; // значение функции

        if (fabs(x) < 0.0000000001) { // если х стремится к 0
            fx = 1.0; // предел функции
        }
        else {
            fx = sin(x) / x; // основная формула функции
        }

        printf(" %10.6lf | %10.6lf\n", x, fx);
    }
    printf("-------------------------------------------------\n");

    printf("\nЗадание 2\n");
    long long MAX = 0;
    printf("MAX: ");
    scanf("%lld", &MAX);

    if (MAX <= 0) {
        printf("MAX должен быть положительным числом\n");
        return 1; 
    }

    // инициализация переменных
    long long a = 0, b = 1, S = 0;
    int N = 0;

    // цикл суммирования
    while (S <= MAX) {
        S += a;
        N++;
        // вычисление следующего числа 
        long long next = a + b;
        a = b;
        b = next;
    }

    // если последнее значение привело к превышению максимального числа
    S -= a;
    N--;

    printf("N = %d\n", N);
    printf("S = %lld\n", S);

    printf("\nЗадание 3\n");
    double loan_amount = 0, annual_rate = 0;
    int months = 0;

    printf("Сумма кредита: ");
    scanf("%lf", &loan_amount);

    printf("Срок кредита (в месяцах): ");
    scanf("%d", &months);

    printf("Процентная ставка (годовая): ");
    scanf("%lf", &annual_rate);

    if (loan_amount <= 0 || months <= 0 || annual_rate <= 0) {
        printf("Все значения должны быть положительными\n");
        return 1; 
    }

    // расчет ежемесячного аннуитетного платежа
    double monthly_rate = annual_rate / 12.0 / 100.0; // месячная процентная ставка
    // платеж = сумма * (ставка * (1+ставка)^срок) / ((1+ставка)^срок -1)
    double monthly_payment = loan_amount * monthly_rate * pow(1 + monthly_rate, months) /
        (pow(1 + monthly_rate, months) - 1);

    double remaining_debt = loan_amount; // остаток долга (начинается с полной суммы)
    double total_interest = 0; // общая сумма процентов

    printf("\n=================================================\n");
    printf("| Месяц |   Долг   | Процент | Платеж |\n");
    printf("=================================================\n");

    for (int month = 1; month <= months; month++) {
        double interest_payment = remaining_debt * monthly_rate; // проценты за месяц
        double principal_payment = monthly_payment - interest_payment; // погашение основного долга

        // в последнем месяце - весь оставшийся долг
        if (month == months) {
            principal_payment = remaining_debt; // погашаем весь остаток
            monthly_payment = principal_payment + interest_payment; // пересчитываем платеж
        }

        printf("| %6d | %8.2lf | %7.2lf | %7.2lf |\n",
            month, remaining_debt, interest_payment, monthly_payment);

        // обновление значений для следующего месяца
        remaining_debt -= principal_payment; // уменьшаем долг
        total_interest += interest_payment; // суммируем проценты

        // восстанавливаем оригинальный платеж для следующего месяца
        if (month < months - 1) {
            monthly_payment = loan_amount * monthly_rate * pow(1 + monthly_rate, months) /
                (pow(1 + monthly_rate, months) - 1);
        }
    }

    printf("=================================================\n");
    printf("Всего процентов: %.2lf\n", total_interest);

    return 0;
}