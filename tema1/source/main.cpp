#include <iostream>
#include <cmath>
using namespace std;

#define MAX_ARRAY_LENGTH 100

struct vector
{
	unsigned int length;
	int values[MAX_ARRAY_LENGTH];
};

struct matrix
{
	unsigned int lines;
	unsigned int columns;
	int values[MAX_ARRAY_LENGTH][MAX_ARRAY_LENGTH];
};

struct sequence
{
	unsigned int startPosition;
	unsigned int length;
};

struct point
{
	double x;
	double y;
};

struct equation
{
	double a;
	double b;
	double c;
};

struct date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

/* Tema 1 */

/* Exercitiul 1
   Scrieti o functie care sa calculeze suma cifrelor unui numar natural.
*/

unsigned int computeDigitSum(unsigned int number);

/* Exercitiul 2
   Scrieti o functie care verifica daca un an este bisect.
*/

bool isLeap(unsigned int year);

/* Exercitiul 3
   Scrieti o functie care sa testeze daca un numar este palindrom.
   Un numar este palindrom daca citit de la dreapta la stanga este egal cu numarul citit de la stanga la dreapta.
   Exemple: 36463 este palindrom, dar 2646 nu este palindrom.
*/

bool isPalindrome(int number);

/* Exercitiul 4
   Scrieti un program, care, pentru o luna si un an date, calculeaza numarul de zile din luna respectiva
   (folositi o functie separata care verifica daca un an este bisect).
   Exemplu: pentru luna februarie din anul 2004, numarul de zile este 29.
*/

unsigned int computeNumberOfDays(unsigned int year, unsigned int month);

/* Exercitiul 5
   Scrieti o functie care calculeaza cifra de control a unui numar natural.
   Cifra de control se obtine calculand suma cifrelor numarului,
   apoi suma cifrelor numarului obtinut etc., pana se ajunge la o singura cifra.
   Exemplu: 4879 -> 28 -> 10 -> 1.
*/

unsigned int computeControlDigit(unsigned int number);

/* Exercitiul 6
   Spunem ca un numar natural este perfect daca este egal cu suma divizorilor sai strict mai mici decat el.
   Scrieti o functie care verifica daca un numar este perfect.
   Exemplu: 28 este un numar perfect deoarece 28 = 1 + 2 + 4 + 7 + 14.
   Sa se determine toate numerele perfecte mai mici ca un numar natural n dat.
   Exemplu: pentru n = 1000, se vor determina numerele 6, 28, 496.
*/

bool isPerfect(unsigned int number);
vector getPerfects(unsigned int upperLimit);

/* Exercitiul 7
   Sa se testeze daca un numar este prim.
   Exemple: 1000003 este prim, dar 1000002 este compus deoarece este divizibil prin 3.
*/

bool isPrime(int number);

/* Exercitiul 8
   Doua numere naturale impare consecutive si prime se numesc numere prime gemene.
   Folosind testul de primalitate implementat anterior, determinati primele n perechi de numere prime gemene.
   Exemplu: Primele n = 3 perechi de numere prime gemene sunt (3, 5), (5, 7) si (11, 13).
*/

bool areTwinPrimes(unsigned int number1, unsigned int number2);
matrix getTwinPrimes(unsigned int count);

/* Exercitiul 9
   Se citeste un tablou de numere intregi.
   Scrieti o functie care determina diferenta maxima (in modul) dintre oricare doua elemente ale vectorului.
   Exemplu: pentru tabloul (1, 3, 2, 7, 11, 3, 2), diferenta maxima (in modul) este 12.
*/

unsigned int getMaxDifference(vector v);

/* Exercitiul 10
   Se citeste un tablou de numere intregi.
   Sa se determine, printr-o singura parcurgere a sa, pozitia de inceput si lungimea celei mai lungi secvente de elemente egale.
   Daca exista mai multe secvente de lungimi egale, se va determina secventa cu pozitia de inceput minima.
   Exemplu: pentru tabloul (1, 2, 3, 3, 3, 2, 1, 5, 5, 5), se vor determina pozitia 2 si lungimea 3.
*/

sequence getMaxSequence(vector v);

/* Exercitiul 11
   Se da un vector de numere intregi.
   Sa se determine subsecventa pentru care suma elementelor componente este maxima.
   Daca exista mai multe subsecvente cu aceasta proprietate, se va determina ultima subsecventa gasita.
   Exemplu: pentru tabloul (2, 3, 4, 2, 9, 2, 1, 7, 3), subsecventa este (9, 2, 1, 7).
*/

sequence getMaxSumSequence(vector v);

/* Exercitiul 12
   Se citeste un tablou de numere intregi.
   Sa se rearanjeze elementele astfel incat cele pare sa apara inaintea celor impare.
   In cadrul subsecventei de numere pare, respectiv impare, elementele trebuie sa apara in ordinea in care erau in tabloul initial.
   Exemplu: tabloul (2, 3, 4, 2, 9, 2, 1, 7, 3) va fi rearanjat in (2, 4, 2, 2, 3, 9, 1, 7, 3).
*/

vector orderElements(vector v);

/* Exercitiul 13
   Se considera un tablou cu n elemente.
   Sa se decida daca exista un element majoritar (cu numarul de aparitii mai mare decat n/2).
*/

bool containsMajorElement(vector v);

/* Exercitiul 14
   Se considera o matrice patratica cu n elemente.
   Sa se interschimbe liniile si coloanele acesteia astfel incat, in matricea finala, elementele de pe diagonala principala sa fie in ordine descrescatoare.
   Sa se afiseze matricea initiala si matricea dupa fiecare operatie.
*/

matrix sortDiagonalElements(matrix m);

/* Exercitiul 15
   Scrieti o functie care citeste elementele unei matrici patratice de dimensiune n.
   Afisati sirul format prin parcurgerea acesteia in spirala, pornind din coltul stanga sus catre dreapta pana in centrul matricei.
*/

vector getSpiralVector(matrix m);

/* Exercitiul 16
   Sa se defineasca un tip pentru reprezentarea datelor calendaristice.
   Sa se scrie o functie care primeste la intrare o data calendaristica si returneaza succesorul acesteia.
   Exemplu: succesorul datei "31.10.2014" este "1.11.2014".
*/

date getNextDate(date currentDate);

/* Exercitiul 17
   Sa se determine ecuatia unei drepte care trece prin doua puncte in plan.
   Exemplu: pentru punctele (2, 1) si (5, 7), ecuatia dreptei este 2x – y – 3 = 0.
   Precizia pentru a, b si c va fi de 2 zecimale.
   Ecuatia va fi redusa.
*/

equation computeEquation(point point1, point point2);

unsigned int computeDigitSum(unsigned int n)
{
	unsigned int S = 0;
	while (n != 0)S = S + n % 10, n /= 10;
	return S;
}
bool isLeap(unsigned int year)
{
	if (!(year % 4))return true;
	if (!(year % 100) && !(year % 400))return true;
	return false;
}
bool isPalindrome(int number)
{
	int aux=0, copy; copy = number;
	while (number != 0)
	{
		aux = aux * 10 + number % 10;
		number /= 10;
	}
	if (copy == aux)return true;
	return false;
}
unsigned int computeNumberOfDays(unsigned int year, unsigned int month)
{
	if (isLeap(year))
	{
		if (month == 2)return 29;
		else if (month % 2)return 31;
		else return 30;
	}
	else if (month % 2)return 31;
	else if (month == 2)return 28;
	else return 30;
}
unsigned int computeControlDigit(unsigned int number)
{
	if(!number%9)return 9;
	else return number % 9;
}
bool isPerfect(unsigned int number)
{
	int i, s = 1;
	for (i = 2; i <= number / 2; i++)
        if (number%i == 0)
            s+=i;
	if (s == number)
        return 1;
	return 0;
}
vector getPerfects(unsigned int upperLimit)
{
    vector v;
    int i;
    v.length=0;
    for(i=1;i<upperLimit;i++)
    {
        if(isPerfect(i)==1)
            {
                v.values[v.length]=i;
                v.length+=1;
            }
    }
    return v;
}
bool isPrime(int number)
{
	int d;
	if (number <= 1)return 0;
	else for (d = 2; d <= sqrt(number); d++)if (number%d == 0)return 0;
	return 1;
}

bool areTwinPrimes(unsigned int number1, unsigned int number2)
{
    if(number1%2==1&&number2%2==1)
        if(number1-number2==2||number2-number1==2)
            if(isPrime(number1)==1&&isPrime(number2)==1)
                return 1;
    return 0;
}
matrix getTwinPrimes(unsigned int count)//?
{
    int i;
    matrix m;
    m.columns=2;
    m.lines=0;
    for(i=3;i<count-2;i++)
        if(areTwinPrimes(i,i+2))
        {
            m.values[m.lines][0]=i;
            m.values[m.lines][2]=i+2;
            m.lines++;
        }
    return m;
}
unsigned int getMaxDifference(vector v)
{
    int mini,maxi,i;
    mini=maxi=v.values[0];
    for(i=1;i<v.length;i++)
    {
        if(mini<v.values[i])
            mini=v.values[i];
        if(maxi>v.values[i])
            maxi=v.values[i];
        return maxi-mini;
    }
}

sequence getMaxSequence(vector v)
{
    int i,j,maxs=v.values[0],sum=v.values[0];
    sequence maxSum;
    maxSum.startPosition=1;
    maxSum.length=1;
    for(i=0;i<v.length-1;i++)
    {
        sum=v.values[i];
        for(j=i+1;j<v.length;j++)
        {
            sum=sum+v.values[j];
            if(sum>maxs)
            {
                maxs=sum;
                maxSum.startPosition=i;
                maxSum.length=j-i+1;
            }
        }
    }
    return maxSum;
}

sequence getMaxSumSequence(vector v)
{
	int i, j, k, s, smax = 0;
	sequence ss;
	for (i = 0; i < v.length; i++);
        for (j = i; j < v.length; j++);
            {
                for (k = i; k <= j; k++);
                    s += v.values[k];
                if (s>smax)
                    {
                        ss.startPosition = i;
                        ss.length = k;
                    }
            }
	return ss;
}
vector orderElements(vector v)
{
    vector ord;
    ord.length=0;
    int i;
    for(i=0;i<v.length;i++)
        if(v.values[i]%2==0)
        {
            ord.values[ord.length]=v.values[i];
            ord.length++;
        }
    for(i=0;i<v.length;i++)
        if(v.values[i]%2==1)
        {
            ord.values[ord.length]=v.values[i];
            ord.length++;
        }
    return ord;
}
bool containsMajorElement(vector v)
{
	int cand = v.values[0];
	int g = 1, i;
	for (i = 0; i < v.length; i++)
	{
		if (v.values[i] != cand)
			g--;
		else g++;
		if (g == 0)
		{
			cand = v.values[i];
			g = 1;
		}
	}
	if (g == 0)
		return 0;
	else {
		g = 0;
		for (i = 0; i < v.length; i++)
		if (v.values[i] == cand)
			g++;
		if (g>v.length / 2)
			return 1;
		return 0;
	}
}
matrix sortDiagonalElements(matrix m)
{
   int i,j,g,aux,k,q;
   for(i=0;i<m.lines;i++)
       for(j=0;j<m.columns;j++)
               if(m.values[i][i]<m.values[j][j])
                {
                    for(g=0;g<m.columns;g++)
                    {
                        aux=m.values[i][g];
                        m.values[i][g]=m.values[j][j];
                        m.values[j][g]=aux;
                    }
                for(k=0;k<m.columns;k++)
                {
                    for(q=0;q<m.columns;q++)
                        cout<<m.values[k][q]<<" ";
                    cout<<endl;
                }
                }
    return m;
}
vector getSpiralVector(matrix m)
{
    vector v;
    int i,j;
    v.length=0;
    for(i=0;i<m.columns/2;i++)
    {
        for(j=i;j<m.columns-i;j++)
        {
            v.values[v.length]=m.values[i][j];
            v.length++;
        }
        for(j=i+1;j<m.columns-i;j++)
        {
            v.values[v.length]=m.values[j][m.columns-i];
            v.length++;
        }
        for(j=m.columns-i;j>i+1;j--)
        {
            v.values[v.length]=m.values[m.columns-i][j];
            v.length++;
        }
        for(j=m.columns-i-1;j>i+1;j--)
        {
            v.values[v.length]=m.values[j][i];
            v.length++;
        }
    }
    if(m.columns%2==1)
    {
        v.values[v.length]=m.values[m.columns/2+1][m.columns/2+1];
        v.length++;
    }
    return v;
}
date getNextDate(date currentDate)
{
    int y,m,d,ok;
    y=currentDate.year;
    m=currentDate.month;
    d=currentDate.day;
    if(isLeap(y)==1)
        ok=1;
    else
        ok=0;
    d++;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        if(d>31)
            {
                d=1;
                m++;
                if(m>12)
                {
                    m=1;
                    y++;
                }
            }
    if(m==2)
        {if(ok==1)
            {
                if(d>29)
                    {
                        d=1;
                        m++;
                        if(m>12)
                        {
                            m=1;
                            y++;
                        }
                    }
            }
        else
            if(d>28)
                    {
                        d=1;
                        m++;
                        if(m>12)
                        {
                            m=1;
                            y++;
                        }
                    }
        }
    if(m==4||m==6||m==9||m==11)
        if(d>30)
            {
                d=1;
                m++;
                if(m>12)
                {
                    m=1;
                    y++;
                }
            }
    currentDate.year=y;
    currentDate.month=m;
    currentDate.day=d;
    return currentDate;
}
equation computeEquation(point point1, point point2)
{
    equation dreapta;
    dreapta.a=point1.y-point2.y;
    dreapta.b=point2.x-point1.x;
    dreapta.c=point1.y*(point1.x-point2.x)+point1.x*(point2.y-point1.y);
    return dreapta;
}
int main()
{
	return 0;
}
