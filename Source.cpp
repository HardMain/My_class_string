#include <iostream>
using namespace std;

class MyString
{
public:

	MyString()
	{
		str = nullptr;
	}
	MyString(const char *str) 
	{
		int length = strlen(str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	MyString(const MyString& other)
	{
		
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString& operator = (const char *&str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
		return *this;
	}
	MyString& operator = (const MyString &other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}
		int length = strlen(other.str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		str[length] = '\0';
		return *this;
	}
	MyString operator +(const MyString& other)
	{
		MyString result;
		int length = strlen(this->str) + strlen(other.str);
		result.str = new char[length+1];
		for (int i = 0, j = 0; i < length; i++)
		{
			if (i < strlen(this->str))
			{
				result.str[i] = str[i];
			}
			else
			{
				result.str[i] = other.str[j];
				j++;
			}
		}
		result.str[length] = '\0';
		return result;
	}
	MyString& operator +=(const MyString& other)
	{
		
		if (this->str != nullptr)
		{
			int length1 = strlen(this->str);
			int length2 = strlen(other.str);
			char* str2 = new char[length1+1];

			for (int i = 0; i < length1; i++)
			{
				str2[i] = str[i];
			}
			str2[length1] = '\0';
			delete[] str;

			str = new char[length1+length2+1];
			int i = 0;

			for (; i < length1; i++)
			{
				str[i] = str2[i];
			}
			for (int j = 0; j < length2; j++,i++)
			{
				str[i] = other.str[j];
			}
			str[length1+length2] = '\0';
			delete[] str2;
			return *this;
		}
		else
		{
			int length = strlen(other.str);
			str = new char[length+1];

			for (int i = 0; i < length; i++)
			{
				str[i] = other.str[i];
			}
			str[length] = '\0';
			return *this;
		}
	}

	void Print()
	{
		cout << str;
	}

private:
	char* str;
};
int main()
{
	
	return 0;
}