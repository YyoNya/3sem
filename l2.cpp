#include <iostream>
static int ID = 0;
class tovar
{
	friend class prodavec;
	friend void outData(tovar&);
public:
	~tovar()
	{
		std::cout << "destructor\n";
	}
	void input();
private:
	int id;
	std::string name;
	int cost;
};
class prodavec
{
public:
	void setRate(tovar* arr);
};
void tovar::input()
{
	std::cout << "Name: ";
	std::cin >> name;
	id = ID;
	cost = 0;
	ID++;
}
void outData(tovar& obj)
{
	std::cout << "student id : " << obj.id << "\n name : " << obj.name << "\n Cost : " << obj.cost << std::endl;
}
void prodavec::setRate(tovar* arr)
{
	while (1)
	{
		std::cout << "Enter cost of" << (*arr).name << "\n";
		int num;
		std::cin >> num;
		(*arr).cost = num;
		break;
	}
}
int main()
{
	const size_t studcount = 2;
	tovar arr[studcount];

	for (int i = 0; i < studcount; i++)
	{
		arr[i].input();
	}
	for (int i = 0; i < studcount; i++)
	{
		outData(arr[i]);
	}
	prodavec Prodavec;
	while (1)
	{
		std::cout << "1-set cost,2-exit\n";
		int k;
		std::cin >> k;
		if (k == 1)
		{
			while (1)
			{
				std::cout << "id-set cost,100-end vvod" << std::endl;
				int id;
				int truefl;
				std::cin >> id;
				if (id > studcount || id < 0)
				{
					truefl = 0;
				}
				else
					truefl = 1;
				if (truefl == 1)
					Prodavec.setRate(&arr[id]);
				if (id == 100)
					break;
			}
		}
		if (k == 2)
		{
			break;
		}

	}
	for (int i = 0; i < studcount; i++) {
		outData(arr[i]);
	}
	return 0;
}