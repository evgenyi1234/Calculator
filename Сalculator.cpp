#include <iostream>
#include <string>
#include <iomanip>
#include"Сalculator.h"

Calculator::Calculator()                                                                         // Вызван конструктор по умолчанию
{
	std::cout << "Конструктор вызван. " << "\n";
}

Calculator::~Calculator()                                                                        // Вызван деструктор
{
	std::cout << "Деструктор вызван." << "\n";
}

void Calculator::DoWork()                                                                        // Функция которая по очереди вызывает методы 
{
	std::cout << "Dowork()-начала свою работу" << "\n";
	std::cout << "======= Добро пожаловать в калькулятор =======" << "\n";
	while (true) {
		std::string input;
		std::cout << "Нажмите 'Enter' чтобы продолжить или 'q' для выхода- ";
		std::getline(std::cin, input);
		if (input == "q") {
			std::cout << "======= Выходим с калькулятора! =======" << "\n";
			break;
		}
		inputNumbers();																			 // Вызов метода для ввода чисел
		inputOperation();																		 // Вызов метода для ввода операции
		doOperation();																			 // Вызов метода для выполнения операции
		std::cout << "Результат-" << std::fixed << std::setprecision(2) << result << "\n";
		clear();																				 // Очистка состояния калькулятора для следующей операции
	}
}

void Calculator::inputNumbers()																	 // Функция в которой выполняется ввод значения для num1 и num2
{
	std::cout << "inputNumbers()-начала свою работу" << "\n";
	while (true) {
		std::cout << "Введите число (num1): ";
		if (std::cin >> num1) {
			break;
		}
		else {
			std::cout << "Ошибка ввода! Введите корректное число.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

	while (true) {
		std::cout << "Введите число (num2): ";
		if (std::cin >> num2) {
			break;
		}
		else {
			std::cout << "Ошибка ввода! Введите корректное число.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	std::cin.ignore();
}


char Calculator::inputOperation()															  // Функция в которой выполняется выбор символа для num1 и num2
{
	char operation;
	while (true) {
		std::cout << "inputOperation-начала свою работу" << "\n";
		std::cout << "Введите операцию (+,-,*,/): ";
		std::cin >> operation;
		std::cin.ignore();
		if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
			this->operation = operation;
			return operation;
		}
		else {
			std::cout << "Некоректная операция.Попробуйте снова!" << "\n";
		}
	}
}

double Calculator::add()																	  // Функция в которой выполняется сложение num1 и num2
{
	std::cout << "add()" << "\n";
	result = num1 + num2;
	return result;																			 // Возвращаем результат
}

double Calculator::subtract()																 // Функция в которой выполняется вычитание num1 и num2
{
	std::cout << "subtract()" << "\n";
	result = num1 - num2;
	return result;																			 // Возвращаем результат
}

double Calculator::multiply()																 // Функция в которой выполняется умножение num1 и num2
{
	std::cout << "multiply()" << "\n";
	result = num1 * num2;
	return result;																			 // Возвращаем результат
}

double Calculator::divide()																	 // Функция в которой выполняется деление num1 и num2
{
	if (num2 == 0) {
		std::cout << "Делить на ноль нельзя." << "\n";
		result = 0.0;
	}
	else {
		result = num1 / num2;
	}
	std::cout << "divide()" << "\n";
	return result;																		    // Возвращаем результат
}

void Calculator::clear()																	// Функция которая отвечает за сброс первого,второго числа,результата и операции
{
	num1 = 0.0;
	num2 = 0.0;
	result = 0.0;
	operation = '\0';
	std::cout << "clear()-начала свою работу" << "\n";
	std::cout << "Память калькулятора очищена." << "\n";
}

void Calculator::doOperation()															   // Функция которая вызывает метод в зависимости от выбранного действия
{ 
	switch (operation) {
	case '+':
		std::cout << "doOperation()-начала свою работу вызвав: ";
		add();																			  // Вызывается метод для сложения num1 и num2
		break;
	case '-':
		std::cout << "doOperation()-начала свою работу вызвав: ";
		subtract();																		  // Вызывается метод для вычитания num1 и num2
		break;
	case '*':
		std::cout << "doOperation()-начала свою работу вызвав: ";
		multiply();																		  // Вызывается метод для умножения num1 и num2
		break;
	case '/':
		std::cout << "doOperation()-начала свою работу вызвав: ";
		divide();																		  // Вызывается метод для деления num1 и num2
		break;
	default:
		std::cout << "Ошибка! Неизвестная операция!" << "\n";
		break;
	}
	
}

