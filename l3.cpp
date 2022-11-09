#include <iostream>
class intarr
{
private:
	int* arr;
	int size;
	int count;
public:
	intarr(int size_ = 3, int count_ = 0) :size(size_), count(count_)
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	friend void output(intarr& a);
	friend void input(intarr& a);
	int& operator()(int num, int num_);
	int& operator[](int num);
	friend intarr operator+(intarr& a, int num);
	intarr operator+(intarr& a);
	friend intarr operator--(intarr& a);
	intarr operator++(int);
	intarr& operator=(const intarr& a);
	bool operator==(intarr& f1);
	friend bool operator==(intarr& a, int num);
	friend std::ostream& operator<< (std::ostream& out, intarr& a);
	operator int();
};
void input(intarr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		std::cin >> a.arr[i];
	}
}
void output(intarr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		std::cout << a.arr[i] << " ";
	}

}
int& intarr::operator()(int num, int num_)
{
	return(arr[num] = num_);
}
int& intarr::operator[](int num)
{
	return(arr[num]);
}
intarr intarr::operator+(intarr& a)
{
	intarr A;
	for (int i = 0; i < a.size; i++)
	{
		A.arr[i] = a.arr[i] + arr[i];
	}
	return A;
}
intarr operator+(intarr& a, int num)
{
	for (int i = 0; i < a.size; i++)
	{
		a.arr[i] = a.arr[i] + num;
	}
	return a;
}
intarr operator--(intarr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		a.arr[i]--;
	}
	return a;
}
intarr intarr::operator++(int)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return *this;
}
intarr& intarr::operator=(const intarr& a)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
	return *this;
}

bool intarr::operator==(intarr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		if (arr[i] != a.arr[i])
			return false;
	}
	return true;
}
bool operator==(intarr& a, int num)
{
	int tmp1 = 0;
	for (int i = 0; i < a.size; i++)
	{
		if (a.arr[i] == num)
		{
			tmp1 = i;
			std::cout << "[" << tmp1 + 1 << "] == " << num;
		}
	}
	return(a.arr[tmp1] == num);
}
std::ostream& operator<< (std::ostream& out, intarr& a)
{
	for (int i = 0; i < a.size; i++)
		out << a.arr[i] << ' ';

	return out;
}
intarr::operator int()
{
	for (int i = 0; i < size; i++)
	{
		count = count + arr[i];
	}
	std::cout << "сумма элементов : ";
	return count;
}
void print(float value)
{
	std::cout << value;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	intarr arr1;
	std::cout << "Введите первый массив:\n";
	input(arr1);
	std::cout << "Первый массив:\n";
	output(arr1);
	intarr arr2;
	std::cout << "\nВведите второй массив:\n";
	input(arr2);
	std::cout << "Второй массив:\n";
	output(arr2);
	std::cout << "\nПерегрузка оператора [] в первом массиве\n";
	arr1[0] = 10;
	output(arr1);
	std::cout << "\nПерегрузка оператора () в 1 массиве\n";
	arr1(1, 100);
	output(arr1);
	intarr arr3;
	std::cout << "\nПерегрузка оператора + (сумма двух массивов)\n";
	arr3 = arr1 + arr2;
	output(arr3);
	int num = 1;
	std::cout << "\nПерегрузка оператора + с числом 1\n";
	arr2 = arr2 + num;
	output(arr2);
	std::cout << "\nПерегрузка оператора --(первый массив)\n";
	--arr1;
	output(arr1);
	std::cout << "\nПерегрузка оператора ++ (первый массив)\n";
	arr1++;
	output(arr1);
	std::cout << "\nПерегрузка <<\n";
	std::cout << arr1;
	std::cout << "\nПерегрузка оператора == с числ\n";
	int tmp;
	std::cout << "Число для сравнивания с первым массивом:";
	std::cin >> tmp;
	if (arr1 == tmp)
	{
	}
	else
	{
		std::cout << "\nЧисла " << tmp << "нет в первом массиве\n";
	}
	std::cout << "\nПерегрузка оператора == с массив\n";
	if (arr1 == arr2)
	{
		std::cout << "Массивы одинаковы";
	}
	else
	{
		std::cout << "Массивы не равны";
	}
	std::cout << "\nПерегрузка оператора =\n";
	arr1 = arr2;
	output(arr1);
	std::cout << "\n";
	output(arr2);
	std::cout << "\n";
	std::cout << "Перегрузка типа\n";
	print(arr1);
	return 0;
}