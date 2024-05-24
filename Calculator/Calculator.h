#pragma once

#include <iostream>
#include <fstream>

namespace  {

	const std::string DivisionException = "Division by zero";
	const std::string LINE = "*************************";

	enum Operation
	{
		ADDITION = '+',
		SUBSTRACTION = '-',
		DIVISION = '/',
		MULTIPLICATION = '*',
		EXIT = '~'
	};


	std::ostream& operator<<(std::ostream& out, Operation oper)
	{
		switch (oper)
		{
		case ADDITION:
			out << "1.Addition = '+'" << std::endl;
			break;
		case SUBSTRACTION:
			out << "2.Substraction = '-'" << std::endl;
			break;
		case DIVISION:
			out << "3.Division = '/'" << std::endl;
			break;
		case MULTIPLICATION:
			out << "4.Multiplication = '*'" << std::endl;
			break;
		case EXIT:
			out << "5.Close Calculator" << std::endl;
			break;
		default:
			out << "Please, choose an operation" << std::endl;
			break;
		}

		return out;
	}
}

class Calculator
{
public:

	void Start();

private:

	void Welcome() const;

	void Bye() const;

	void SaveOperation(char oper);

	void AskForOperation();

	void AskForNum();

	void ProceedOperation() const;

	int num1 = 0;
	int num2 = 0;
	Operation op;
	bool flag = false;
};