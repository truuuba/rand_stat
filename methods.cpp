#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <QVector>

/*   конгруэнтный метод
*   n - количество чисел
*   Ost - ограничение по верхней точке
*   dY_Prev - предыдущее значение y
*   dY_Next - слудующее значение y
*   dA - множитель а
*   dMu - приращение
*   dX - итоговое число */

QVector<int> LK_counter(int n, int Ost)
{
  QVector<int> results(n);
  double dX;
  double dY_Prev=2.0, dY_Next=0.0, dA=8.0, dMu=std::rand();
  for (int i = 0; i < n; i++)
  {
      dY_Next = std::fmod((dA*dY_Prev + dMu),Ost);
      dA++;
      dX = dY_Next;
      results[i] = dX;
      dY_Prev=dY_Next;
  }
  return results;
}

/* Треугольное распределение
*  a - начальное значение
*  c - максимальное значение
*  b - пиковое значение
*  U - функция для первого условия
*  F - функция для второго условия
*  rand_rez - случайное число */

QVector<int> Tr_counter(int a, int b, int c, int n)
{
  QVector<int> results(n);
  for (int i = 0; i < n; i++)
  {
      double rand_rez;
      double U = std::rand() / (double) RAND_MAX;
      double F = (c - a) / (b - a);
      if (U <= F)
          rand_rez = a + std::sqrt(U * (b - a) * (c - a));
      else
          rand_rez = b - std::sqrt((1 - U) * (b - a) * (b - c));
      results[i] = std::round(rand_rez);
  }
  return results;
}


/*  n - количество символов
*   ogr - верхнее граничение
*   value - значение времени */

QVector<int> Time_counter(int n, int ogr)
{
  QVector<int> results(n);
  unsigned value = unsigned(std::time(nullptr));
  for (int i = 0; i < n; ++i)
  {
      value = (value * 73129 + 95121) % ogr;
      results[i] = value;
  }
  return results;
}
