#include <iostream>
using namespace std;
void arie()
{
	long double a, b, arie[10] = { 1,0.01,0.0002471053,10000 ,10.76426264,0.0001 ,1549.907005 ,0.000001 ,1000000 ,1.19598939404 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Metru patrat \n (1) Ar \n (2) Acru \n (3) Centimetru patrat \n (4) Picior patrat \n (5) Hectar \n (6) Tol patrat \n (7) Kilometru patrat \n (8) Milimetru patrat \n (9) Yard patrat \n " << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Metru patrat \n (1) Ar \n (2) Acru \n (3) Centimetru patrat \n (4) Picior patrat \n (5) Hectar \n (6) Tol patrat \n (7) Kilometru patrat \n (8) Milimetru patrat \n (9) Yard patrat \n " << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / arie[i])*arie[j];
	cout << b;
}
void densitate()
{
	long double a, b, densitate[20] = { 1,0.001 ,1,1000,0.001,0.000001,0.000001,0.001,0.06243 , 0.0000361273 , 0.0083454044531 , 0.0100224128552 , 1000,1000,1000000, 0.160358605 ,0.133526499 ,0.998847369091 ,0.000578036672 ,0.001 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Kilogram pe metru cub \n (1) Gram pe centimetru cub \n (2) Gram pe litru \n (3) Gram pe metru cub \n (4) Gram pe mililitru \n (5) Gram pe mililitru cub \n (6) Kilogram pe centimetru cub \n (7) Kilogram pe litru \n (8) Funt pe picior cub \n (9) Funt pe tol cub \n (10) Funt pe galon(UK) \n (11) Funt pe galon(US) \n (12) Miligram pe centimetru cub \n (13) Miligram pe litru \n (14) Miligram pe metru cub \n (15) Uncie Avoirdupois pe galon(UK) \n (16) Uncie Avoirdupois pe galon(US) \n (17) Uncie Avordupois pe picior cub \n (18) Uncie Avordupois pe tol cub \n (19) Tona pe metru cub \n" << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Kilogram pe metru cub \n (1) Gram pe centimetru cub \n (2) Gram pe litru \n (3) Gram pe metru cub \n (4) Gram pe mililitru \n (5) Gram pe mililitru cub \n (6) Kilogram pe centimetru cub \n (7) Kilogram pe litru \n (8) Funt pe picior cub \n (9) Funt pe tol cub \n (10) Funt pe galon(UK) \n (11) Funt pe galon(US) \n (12) Miligram pe centimetru cub \n (13) Miligram pe litru \n (14) Miligram pe metru cub \n (15) Uncie Avoirdupois pe galon(UK) \n (16) Uncie Avoirdupois pe galon(US) \n (17) Uncie Avordupois pe picior cub \n (18) Uncie Avordupois pe tol cub \n (19) Tona pe metru cub \n" << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / densitate[i])*densitate[j];
	cout << b;
}
void energie()
{
	long double a, b, energie[19] = { 1,9.478 ,10000000 ,0.2388 ,0.73746312684 ,8.850745791 ,0.10197,0.0002388 ,0.001 ,2.77778 ,9.478 ,3.41143 ,3.41143 ,3.41143 ,2.388 ,2.38845896 ,2.388 ,0.00027777 ,1 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Joule \n (1) British Thermal Units \n (2) Erg. \n (3) Caloria \n (4) Picior-funt forta \n (5) Tol-funt forta \n (6) Kilogram-metru \n (7) Kilocalorie \n (8) Kilojoule \n (9) Kilowatt-ora \n (10) Quad British Thermal Units \n (11) Tona echivalent carbune \n (12) Tona de combustibil conventional \n (13) Tona echivalent carbon \n (14) Tona echivalent petrol \n (15) Thermie \n (16) Tona echivalent ulei \n (17) Watt-ora \n" << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Joule \n (1) British Thermal Units \n (2) Erg. \n (3) Caloria \n (4) Picior-funt forta \n (5) Tol-funt forta \n (6) Kilogram-metru \n (7) Kilocalorie \n (8) Kilojoule \n (9) Kilowatt-ora \n (10) Quad British Thermal Units \n (11) Tona echivalent carbune \n (12) Tona de combustibil conventional \n (13) Tona echivalent carbon \n (14) Tona echivalent petrol \n (15) Thermie \n (16) Tona echivalent ulei \n (17) Watt-ora \n" << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / energie[i])*energie[j];
	cout << b;
}
void lungime()
{
	long double a, b, lungime[9] = { 1,100,3.28083,39.37007,0.001,0.000621371192 ,0.000539957 ,1000 ,0.000621371192 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Metru \n (1) Centimetru \n (2) Picior \n (3) Tol \n (4) Kilometru \n (5) Mila \n (6) Mila marina \n (7) Milimetru \n (8) Yarda \n " << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Metru \n (1) Centimetru \n (2) Picior \n (3) Tol \n (4) Kilometru \n (5) Mila \n (6) Mila marina \n (7) Milimetru \n (8) Yarda \n " << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / lungime[i])*lungime[j];
	cout << b;
}
void masa()
{
	long double a, b, masa[8] = { 1,1000 ,2.20462,1000000 ,35.27399072 ,	32.15072259 ,0.068521765, 0.001 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Kilogram \n (1) Gram \n (2) Funt \n (3) Miligram \n (4) Uncie(Avordupois) \n (5) Uncie(Troy) \n (6) Slug \n (7) Tona \n " << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Kilogram \n (1) Gram \n (2) Funt \n (3) Miligram \n (4) Uncie(Avordupois) \n (5) Uncie(Troy) \n (6) Slug \n (7) Tona \n " << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / masa[i])*masa[j];
	cout << b;
}
void presiune()
{
	long double a, b, presiune[18] = { 1, 9.8692059, 1.0197, 0.00001 ,0.0040186465, 0.0002952998, 0.0000102, 0.001,	0.0208855472,	0.0208855472, 0.01 , 0.0001020408,  0.1020408 , 0.007500617, 0.000001 , 0.00014503773 , 0.00014503773, 0.007500617 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Pascal \n (1) Atmosfera standard \n (2) Atmosfera tehnica \n (3) Bar \n (4) Tol coloana de apa \n (5) Tol coloana de mercur \n (6) Kilopond pe centimetru patrat \n (7) Kilopascal \n (8) Funt-forta pe picior patrat \n (9) Funt-forta pe tol patrat \n (10) Millibar \n (11) Metru coloana de apa \n (12) Milimetru coloana de apa \n (13) Milimetru coloana de mercur \n (14) Megapascal \n (15) Newton pe milimetru patrat \n (16) Pound square inch \n (17) Torr \n" << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Pascal \n (1) Atmosfera standard \n (2) Atmosfera tehnica \n (3) Bar \n (4) Tol coloana de apa \n (5) Tol coloana de mercur \n (6) Kilopond pe centimetru patrat \n (7) Kilopascal \n (8) Funt-forta pe picior patrat \n (9) Funt-forta pe tol patrat \n (10) Millibar \n (11) Metru coloana de apa \n (12) Milimetru coloana de apa \n (13) Milimetru coloana de mercur \n (14) Megapascal \n (15) Newton pe milimetru patrat \n (16) Pound square inch \n (17) Torr \n" << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / presiune[i])*presiune[j];
	cout << b;
}
void temperatura()
{
	double temp;
	int choice = 0;
	while (choice == 0)
	{
		cout << "Alegeti una din urmatoarele transformari: \n (1) Fahrenheit - Celsius \n (2) Celsius - Fahrenheit \n (3) Kelvin - Celsius \n (4) Celsius - Kelvin \n (5) Kelvin - Fahrenheit \n (6) Fahrenheit - Kelvin \n";
		do
		{
			cin >> choice;
			if (choice < 1 || choice>6)
				cout << "Varianta gresita. Introduceti un numar de la 1 la 6 \n";
		} while (choice <1 && choice>6);
            cout<<"Introduceti valoarea pe care vreti sa o converiti: \n";
            cin>>temp;
				if(choice==1)
					cout << (temp - 32) * 5 / 9 << endl;
				else if(choice==2)
					cout << temp * 9 / 5 + 32 << endl;
				else if(choice==3)
					cout << temp - 273 << endl;
				else if(choice==4)
					cout << temp + 273 << endl;
				else if(choice==5)
					cout << temp - 459.67 << endl;
				else if(choice==6)
					cout << temp + 459.67 << endl;
	}
}
void timp()
{
	int choice;
	cout << "Alegeti intervalul de timp pentru care doriti sa realizati conversia: (1) Saptamana - Attosecunda \n (2) Luna - An \n (3) An - Megaannum\n";
	cin >> choice;
	if (choice == 1)
	{
		long double a, b, timp[13] = { 1, 1.65344 , 1.15741 , 0,.00277778 ,	0.166667, 10, 100, 1000, 10^6, 10^9, 10^12, 10^15, 10^18 };
		int i, j;
		cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
		cout << " (0) Secunda \n (1) Saptamana \n (2) Zi \n (3) Ora \n (4) Minute \n (5) Decisecunda \n (6) Centisecunda \n (7) Milisecunda \n (8) Microsecunda \n (9) Nanosecunda \n (10) Picosecunda \n (11) Femtosecunda \n (12) Attosecunda \n";
		cin >> i;
		cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
		cout << " (0) Secunda \n (1) Saptamana \n (2) Zi \n (3) Ora \n (4) Minute \n (5) Decisecunda \n (6) Centisecunda \n (7) Milisecunda \n (8) Microsecunda \n (9) Nanosecunda \n (10) Picosecunda \n (11) Femtosecunda \n (12) Attosecunda \n";
		cin >> j;
		cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
		cin >> a;
		b = (a / timp[i])*timp[j];
		cout << b;
	}
	else if (choice == 2)
	{
		long double a, b, timp[6] = { 1, 0.5, 0.333,	0.25, 0.166667,	0.08333 };
		int i, j;
		cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
		cout << " (0) Luna \n (1) Bimestru \n (2) Trimestru \n (3) Patru luni \n (4) Semestru \n (5) An \n";
		cin >> i;
		cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
		cout << " (0) Luna \n (1) Bimestru \n (2) Trimestru \n (3) Patru luni \n (4) Semestru \n (5) An \n";
		cin >> j;
		cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
		cin >> a;
		b = (a / timp[i])*timp[j];
		cout << b;
	}
	else if (choice == 3)
	{
		long double a, b, timp[12] = { 1, 0.5, 0.333,	0.25, 0.2, 0.166667, 0.14285, 0.1, 0.02, 0.01, 0.001, 0.000001 };
		int i, j;
		cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
		cout << " (0) An \n (1) Biennium \n (2) Triennium \n (3) Quadrennium \n (4) Lustru \n (5) Sexennium \n (6) Septennium \n (7) Deceniu \n (8) Decalustro \n (9) Seculol \n (10) Mileniu \n (11) Megaannum \n";
		cin >> i;
		cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
		cout << " (0) An \n (1) Biennium \n (2) Triennium \n (3) Quadrennium \n (4) Lustru \n (5) Sexennium \n (6) Septennium \n (7) Deceniu \n (8) Decalustro \n (9) Seculol \n (10) Mileniu \n (11) Megaannum \n";
		cin >> j;
		cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
		cin >> a;
		b = (a / timp[i])*timp[j];
		cout << b;
	}
}
void viteza()
{
	long double a, b, viteza[23] = { 1, 6000 ,100, 11810.9771221 , 196.8503937, 3.28083, 11810.9771221, 39.3700787, 39.3700787, 3.6, 0.06, 0.001, 3600, 60, 0.000621371192, 0.037282271534, 2.2369362920, 1, 1.94384449, 11810.9771221, 196.8503937, 3.28083 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Metru pe secunda \n (1) Centimetru pe minut \n (2) Centimetru pe secunda \n (3) Picior pe ora \n (4) Picior pe minut \n (5) Picior pe secunda \n (6) Picior pe ora \n (7) Tol pe secunda \n (8) Inch pe secunda \n (9) Kilometru pe ora \n (10) Kilometru pe minut \n (11) Kilometru pe secunda \n (12) Metru pe ora \n (13) Metru pe minut (14) Mila(statut) pe secunda \n (15) Mila(statut) pe minut \n (16) Mila(statut) pe ora \n (17) Metru pe secunda(US) \n (18) Mila marian pe ora \n (19) Yard pe ora \n (20) Yard pe minut \n (21) Yard pe secunda \n" << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Metru pe secunda \n (1) Centimetru pe minut \n (2) Centimetru pe secunda \n (3) Picior pe ora \n (4) Picior pe minut \n (5) Picior pe secunda \n (6) Picior pe ora \n (7) Tol pe secunda \n (8) Inch pe secunda \n (9) Kilometru pe ora \n (10) Kilometru pe minut \n (11) Kilometru pe secunda \n (12) Metru pe ora \n (13) Metru pe minut (14) Mila(statut) pe secunda \n (15) Mila(statut) pe minut \n (16) Mila(statut) pe ora \n (17) Metru pe secunda(US) \n (18) Mila marian pe ora \n (19) Yard pe ora \n (20) Yard pe minut \n (21) Yard pe secunda \n" << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / viteza[i])*viteza[j];
	cout << b;
}
void volum()
{
	long double a, b, volum[12] = { 1,100000, 1000000, 10000, 1000, 35.31, 220, 264.2, 61023.7440947, 1000, 1000000, 1.308 };
	int i, j;
	cout << "Alegeti unitatea de masura pentru valoarea de intrare" << endl;
	cout << " (0) Metru cub \n (1) Centilitru \n (2) Centimetru cub \n (3) Decilitru \n (4) Decilitru cub \n (5) Picior cub \n (6) Galon(UK) \n (7) Galon(US) \n (8) Tol cub \n (9) Litru \n (10) Mililitru \n (11) Yard cub \n" << endl;
	cin >> i;
	cout << "Alegeti unitatea de masura pentru valoarea de iesire" << endl;
	cout << " (0) Metru cub \n (1) Centilitru \n (2) Centimetru cub \n (3) Decilitru \n (4) Decilitru cub \n (5) Picior cub \n (6) Galon(UK) \n (7) Galon(US) \n (8) Tol cub \n (9) Litru \n (10) Mililitru \n (11) Yard cub \n" << endl;
	cin >> j;
	cout << "Introduceti valoarea pe care vreti sa o convertiti \n";
	cin >> a;
	b = (a / volum[i])*volum[j];
	cout << b;
}
int main()
{
	int choice;
	int a=0;
	cout << "\t \t Convertor" << endl << endl;
	do
	{
		do
		{
			cout << "Alegeti tipul de marime fizica in care doriti sa realizati conversia: \n";
			cout << " (1) Arie \n (2) Densitate \n (3) Energie \n (4) Lungime \n (5) Masa \n (6) Presiune \n (7) Temperatura \n (8) Timp \n (9) Viteza \n (10) Volum \n (0) Iesire \n";
			cin >> choice;
			if (choice < 0 || choice>10)
				cout << "Ati introdus o valoare gresita. Incercati din nou." << endl;
		} while (choice < 0 || choice>10);
		if(choice==0)
            return 0;
        else if(choice==1)
            arie();
        else if(choice==2)
            densitate();
        else if(choice==3)
            energie();
        else if(choice==4)
            lungime();
        else if(choice==5)
            masa();
        else if(choice==6)
            presiune();
        else if(choice==7)
            temperatura();
        else if(choice==8)
            timp();
        else if(choice==9)
			viteza();
        else if(choice==10)
			volum();
    //cout << string(50, '\n');
				do
				{
					cout << "\n \n Doriti sa mai realizati o alta conversie? \n (0) Nu \n (1) Da \n ";
					cin >> a;
					if (a != 1 && a != 0)
						cout << "\n Ati introdus o valoare gresita. Incercati din nou\n \n";
				} while (a!=1 && a != 0);
        if(a==0)
            return 0;
	} while (a == 1);
}

