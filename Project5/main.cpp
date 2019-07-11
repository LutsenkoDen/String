#include<iostream>
using namespace std;
//#define CONSTRUCTORS_CHECK

class String;
String operator+(const String& left, const String& right);
class String
{
	int size; // размер строки
	char* str; // адрес строки в динамической памяти
public:
	const int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//  Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:
	String& operator=(const String& other)
	{
		//0)Проверяем,является ли тот обьект этим обьектом
		if (this == &other) return *this;

		//1)Удаляем старое значение обьекта
		delete[] this->str;
		//2)Копируем значение другого обьекта
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i) const
	{
		//char value = this->str[i];
		//return value;
		return this->str[i];
	}

	char& operator[](int i)
	{
		//char value = this->str[i];
		//return value;
		return this->str[i];
	}

	// Metods:
	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}

};

String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	//cout << cat.get_size() << endl;
	/*for (int i = 0; left.get_str()[i]; i++)
		*(cat.get_str() + i) = *(left.get_str() + i);
	for (int i = 0; right.get_str()[i]; i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/

	for (int i = 0; left[i]; i++)
		cat[i] = left[i];
	for (int i = 0; right[i]; i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	String str1 = "Hello";
	cout << typeid("Hello").name() << endl;
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
	cout << "\n-----------------------------------\n";
	str2 = str2;
	cout << str2 << endl;
	cout << "\n-----------------------------------\n";
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	cout << "\n------------------------\n";
	//String str3 = str1 + " " + str2; //MoveConstructor
	String str3;
	str3 = str1 + " " + str2; //MoveAssignment
	cout << str3 << endl;
	cout << "\n------------------------\n";
	/*str1 += str2;
	cout << str1 << endl;*/




}