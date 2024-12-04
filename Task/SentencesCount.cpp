﻿// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include <string>
#include <fstream>

int GetSentencesCount(std::string fname)
{
	std::ifstream f(fname);
	if (f)
	{
		char c;
		bool word = false;
		int result = 0;
		while (c = f.get())																						// считывание символа из файла
		{
			if (c != ' ' && c != '\t' && c != '\n' && c != '.' && c != '!' && c != '?' && c != (char)-1)		// проверка на пробелы, табуляцию, конец строки, знаки препинания и конец файла
				word = true;
			if ((c == '.' || c == '!' || c == '?' || c == (char)-1) && word == true)							// проверка на (. или ? или ! или конец файла) и наличие слова до этого
			{
				result++;
				word = false;
			}
			if (f.eof()) break;																					// проверка на конец файла
		}
		return result;
	}
	else return -1;
}

/*
	Разместите в данном файле функцию подсчета количества предложений, находящихся в текстовом файле.
	Признаком конца предложения считать символы '.', '!', '?' и конец файла (если последним символом 
	в файле не является ни один из вышеперечисленных символов. Несколько подряд идущих символов 
	'.', '!', '?' вы должны рассматривать, как один символ. Предложение должно состоять хотя бы из
	одного символа, отличного от пробела, табуляции, новой строки и вышперечисленных символов.


	1. Функция должна иметь имя GetSentencesCount
	2. Функция в качестве параметров должна принимать следующее:
		- первый параметр - Имя файла, строковый тип std::string
	3. Функция должна возвращать целое число int

	Если переданный в качестве параметра файл не существует - функция должна вернуть -1.
	В противном случае - количество предложений. В пустовм файле, или в файле только с пробелами
	- 0 предложений.

	Примеры:
	1 Предложение:

	Word


	5 предложений:

	Это первое
	предложение.
	А еще предложение есть?? Да, вот еще одно!А вот еще!!!
	И еще

	0 Предложений:

	.... ???? !!!!!


	!!!!! ВАЖНО !!!!!
	В данном файле разрешается разместить кроме кода требуемой функции - код любых других вспомогательных
	функций. Никакой функции main() в этом файле быть не должно.
	Если вы хотите испытать и отладить вашу функцию - пишите код в файле Example.cpp проекта Example данного решения
	Для этого задайте в качестве запускаемого проекта проект Example.

	ДЛЯ АВТОМАТИЧЕСКОГО ТЕСТИРОВАНИЯ  проверки правильности работы вашего задания - сделайте запукаемым проект
	Tests и запустите его. Если функция написана правильно - все тесты должны успешно выполниться
	(зеленый цвет в консоли). Если ваша функция работает некорректно - в консоли будут сообщения красным цветом
*/
