#include "Calculator.h"

#include <iostream>
#include <fstream>

	void Calculator::Start() 
	{
		Welcome();
		while (op != Operation::EXIT)
		{
			AskForNum();
			AskForOperation();
			AskForNum();
			ProceedOperation();
		}
		Bye();
	}

	void Calculator::Welcome() const
	{
		std::cout << "*******Welcome to Simple-Calculator*******" << std::endl;
	}

	void Calculator::Bye() const
	{
		std::cout << "*****************See ya*******************" << std::endl;
	}


	void Calculator::SaveOperation(char oper)
	{
		switch (oper)
		{
		case '+':
			op = Operation::ADDITION;
			break;
		case '-':
			op = Operation::SUBSTRACTION;
			break;
		case '/':
			op = Operation::DIVISION;
			break;
		case '*':
			op = Operation::MULTIPLICATION;
			break;
		case '~':
			op = Operation::EXIT;
			break;
		default:
			break;
		}
	}

	void Calculator::AskForOperation()
	{
		std::cout << LINE << std::endl;
		std::cout << "Choose an operation: " << std::endl;
		std::cout << Operation::ADDITION;
		std::cout << Operation::SUBSTRACTION;
		std::cout << Operation::DIVISION;
		std::cout << Operation::MULTIPLICATION;
		std::cout << Operation::EXIT;
		std::cout << LINE << std::endl;
		char operation;
		std::cin >> operation;
		Calculator::SaveOperation(operation);
	}


	void Calculator::AskForNum()
	{
		std::cout << LINE << std::endl;
		std::cout << "Enter num: " << std::endl;
		std::cout << LINE << std::endl;
		int num = 0;
		std::cin >> num;
		if (flag)
		{
			num2 = num;
			flag = false;
		}
		else
		{
			num1 = num;
			flag = true;
		}
	}


	void Calculator::ProceedOperation() const
	{
		switch (op)
		{
		case ADDITION:
			std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
			break;
		case SUBSTRACTION:
			std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
			break;
		case DIVISION:
			if (num2 == 0)
			{
				std::cout << DivisionException << std::endl;
			}
			else
			{
				std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
			}
			break;
		case MULTIPLICATION:
			std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
			break;
		case EXIT:
			break;
		default:
			std::cout << "Please enter a valid operation from the list" << std::endl;
			break;
		}
	}
