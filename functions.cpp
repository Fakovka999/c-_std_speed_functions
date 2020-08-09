// преобразует строку в целое число типа int
// посимвольно считывает
// проверяет первый символ на отрицательное значение
// далее из диапозона таблицы кодировки ANSI проверяет
// и прибавляет к temp (символ & 0x0f) число
// функция не имеет исключений на выход из диапозона int
// желательно правильно передавать в нее данные

unsigned int StrToInt(char* s)
{
	int sign = 1;
	int temp = 0;
	int i = 0;
	if (s[i] == 0x2D)  //если минус то 
	{
		sign = -1;
		++i;
	}
	while ((s[i] >= 0x30) && (s[i] <= 0x39))
	{
		temp = (temp * 10) + (s[i++] & 0x0F);
	}
	return (temp * sign);
}
// преобразует целое число типа int в строку
// пока не совсем корректно, нужно добавить отицательное значение
std::string IntToStr(int i)
{
	int buf;
	std::string ss;
	while (i > 9)
	{
		buf = i % 10;
		ss.insert(0, 1, char(0x30 | buf));
		i /= 10;
	}
	ss.insert(0, 1, char(0x30 | i));
	return ss;
}

//преобразует строку в число с плавающей точкой типа float
//так же не  имеет исключений и желательно правильно передавать в нее значения
//сначало записывает целую часть числа
// затем найдя точку начинает приращивать дробную часть delim *= 0.1
float stof(char* s)
{
	float sign = 1.0;
	float temp = 0;
	int i = 0;
	bool check = false;
	float delim = 1.0f;
	if (s[i] == 0x2D)  //если минус то 
	{
		sign = -1.0;
		++i;
	}
	while ((s[i] >= 0x2E) && (s[i] <= 0x39))
	{
		if (s[i] == 0x2E)
		{
			check = true;
			++i;
			continue;
		}
		temp = (temp * 10) + (s[i] & 0x0F);
		++i;
		if (check == true)
		{
			delim = delim * 0.1f;
		}
	}
	temp = temp * sign * delim; //
	return temp;
}
