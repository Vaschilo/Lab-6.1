#pragma once
#include <iostream>
#include <functional>
#include <time.h>
using namespace std;

template <class T> 
class Array
{
private:
	int n, m; //size of matrix
	T** ar;
public:
	Array()
	{
		this->n = 0;
		this->m = 0;
		this->ar = nullptr;
	}
	Array(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			function <int(string)> f = [](string str)
			{
				int n = 1;
				do
				{
					if (n <= 0) "������� �����, ������������� 0";
					cout << "\n������� " << str << endl;
					cin >> n;
				} while (n <= 0);
				return n;
			};
			cout << "������� ������� �������\n";
			n = f("����� �����");
			m = f("����� ��������");
		}
		this->n = n;
		this->m = m;
		this->ar = new T*[this->n];
		for (int i = 0; i < this->n; i++)
			this->ar[i] = new T[this->m];
	}
	~Array()
	{
		for (int i = 0; i < this->n; i++)
			delete[] this->ar[i];
		delete[] this->ar;
	}
	T Max()
	{
		T max = this->ar[0][0];
		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
				if (this->ar[i][j] > max) max = this->ar[i][j];
		return max;
	}
	void print()
	{
		system("cls");
		if (this->n == 0 || this->m == 0)
		{
			
		}
		cout << "� ������� " << this->n << " ����� � " << this->m << " ��������\n";
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
				cout << this->ar[i][j] << "\t";
			cout << endl;
		}
	}
	void input()
	{
		system("cls");
		if (this->n == 0 || this->m == 0)
		{
			function <int(string)> f = [](string str)
			{
				int n = 1;
				do
				{
					if (n <= 0) "������� �����, ������������� 0";
					cout << "\n������� " << str << endl;
					cin >> n;
				} while (n <= 0);
				return n;
			};
			cout << "������� ������� �������\n";
			this->n = f("����� �����");
			this->m = f("����� ��������");
			this->ar = new T*[this->n];
			for (int i = 0; i < this->n; i++)
				this->ar[i] = new T[this->m];
		}
		system("cls");
		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
			{
				cout << "a[" << i << "][" << j << "] = "; cin >> this->ar[i][j];
				cout << endl;
			}
	}
	void random()
	{
		if (this->n <= 0 || this->m <= 0)
		{
			function <int(string)> f = [](string str)
			{
				int n = 1;
				do
				{
					if (n <= 0) "������� �����, ������������� 0";
					cout << "\n������� " << str << endl;
					cin >> n;
				} while (n <= 0);
				return n;
			};
			cout << "������� ������� �������\n";
			this->n = f("����� �����");
			this->m = f("����� ��������");
			this->ar = new T * [this->n];
			for (int i = 0; i < this->n; i++)
				this->ar[i] = new T[this->m];
		}
		T left = 0, right = 1;
		do
		{
			if (left >= right) cout << "����� ������� ������ ���� ������ ������";
			cout << "\n������� ������� �������" << endl;
			cin >> left >> right;
		} while (left >= right);

		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
				this->ar[i][j] = rand() % int(right - left + 1) + left;
		this->print();
	}
};