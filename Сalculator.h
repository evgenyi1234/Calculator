#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
	         Calculator           ();
	         ~Calculator          ();
	void     DoWork               ();            // -метод который запускает цикл работы.

private:
	double   num1;
	double   num2;
	double   result;
	char     operation;

	void     inputNumbers         ();            // -ввод двух чисел с клавиатуры
	char     inputOperation       ();            // -ввод символа операции
	double   add                  ();            // -сложение(num1 + num2)
	double   subtract             ();            // -вычитание(num1 - num2)
	double   multiply             ();            // -умножение(num1 * num2)
	double   divide               ();            // -деление(num1 / num2) с проверкой деления на 0
	void     clear                ();            // -очистка экрана и внутренней памяти
	void     doOperation          ();            // -берем из памяти операцию и числа, и в зависимости от типа вызываем нужную функцию.результат сохраняем в память.


};

#endif 
