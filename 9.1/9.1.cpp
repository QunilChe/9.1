// кращий спосіб
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;
enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { ME, MF, FI, INF, KN };
string specStr[] = { "математика і економіка", "трудове навчання", "фізика та інформатика", "інформатика", "компютерні науки"}; //були посади стали оцінки

struct Student
{
	string prizv;
	unsigned rikNar;
	unsigned kurs;
	Spec spec;
	union
	{
		int otsinka1;
		int otsinka2;
		int otsinkaPR;
		int otsinkaCM;
		int otsinkaPD;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
double LineSearch1(Student* p, const int N);
double LineSearch2(Student* p, const int N);
double Line(Student* p, const int N);
double Line1(Student* p, const int N);
double Line2(Student* p, const int N);
int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double hg = LineSearch(p, N);
	double cg = LineSearch1(p, N);
	double rg = LineSearch2(p, N);
	int gg = (hg + cg + rg);

	double hj = LineSearch(p, N);
	double cj = LineSearch1(p, N);
	double rj = LineSearch2(p, N);
	int gj = (hj + cj + rj);
	cout << "кількість студентів, які вчаться без трійок:" << gg <<  endl;
	cout << "процент студентів, у яких середній бал менший 4:" << gj << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "stydent No " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " рік нар.: "; cin >> p[i].rikNar;
		cout << " курс.:    "; cin >> p[i].kurs;
		cout << " spec (0 - робітник, 1 - інженер, 2 - службовець): ";
		cin >> spec;
		p[i].spec = (Spec)spec;

		switch (p[i].spec)
		{
		case KN:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaPR;
			break;
		case INF:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaCM;
			break;
		case ME:
		case MF:
		case FI:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaPD;
			break;
		}
		cout << endl;

	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| No | Прізвище | Рік.нар. | kyrs | spec | fizyka | matematika | informatika | програмування |чисельних методів |педагогіки | "
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].rikNar << " ";
		cout << "| " << setw(3) << right << p[i].kurs << " ";
		cout << "| " << setw(11) << left << specStr[p[i].spec - 1];
		cout << "| " << setw(3) << right << p[i].otsinka1 <<  " ";
		cout << "| " << setw(3) << right << p[i].otsinka2 << " ";
		cout << "| " << setw(3) << right << p[i].kurs << " ";
		
		switch (p[i].spec)
		{
		case KN:
			cout << "| " <<  p[i].otsinkaPR << " " << endl;
			break;
		case INF:
			cout << "| " << p[i].otsinkaCM << " " << endl;
		case ME:
		case MF:
		case FI:
			cout << "| " << p[i].otsinkaPD << " " << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == KN)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaPR > 3)
			{
				k++;		
			}
		}
	}
	return k ;
}
double LineSearch1(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == INF)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaCM > 3)
			{
				k++;
			}
		}
	}
	return k;
}
double LineSearch2(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == ME, MF, FI)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaPD > 3)
			{
				k++;
			}
		}
	}
	return k;
}
double Line(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == KN)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaPR > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
double Line1(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == INF)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaCM > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
double Line2(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == ME, MF, FI)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaPD > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}