#include "exercises.h"

// problema 0
//
// compara continutul a doua fisiere, daca este identic returneaza 0, daca este diferit returneaza 1
// continutul fisierelor este binar, adica orice tip de fisier, nu neaparat text ASCII.
//
int compare_files(const char *input_file_1, const char *input_file_2)
{
	char x, y;
	ifstream file1;
	file1.open(input_file_1, ios::binary | ios::in);
	ifstream file2;
	file2.open(input_file_2, ios::binary | ios::in);
	while (!file1.eof() && !file2.eof())
	{
		file1.read(&x, 1);
		file2.read(&y, 1);
		if (x != y)
			return 0;
	}
	return 1;
}
void schimb(char cuvant1[], char cuvant2[])
{
	char aux[100];
	strcpy(aux, cuvant1);
	strcpy(cuvant1, cuvant2);
	strcpy(cuvant2, aux);
}

// problema 1
// Vocalele sunt 'doar' cele clasice: ('a', 'e','i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
// Consoanele sunt tot doar cele clasice, cele din intervalele ['a' - 'z'] ['A' - 'Z']
//
// Nu se ia in considerare encoding-ul pentru fisierul de intrare (e.g. UTF-8, latin1, UTF-16, etc)
// Fisierul de intrare se considera o secventa de bytes, fiecare byte avand 8 biti.
// Printre acesti bytes poate fi orice 'caracter', inclusiv caracterul NULL, oriunde in fisier.
// Size-ul fisierelor de intrare poate depasi 1MB dar nu poate depasi 1GB.
//
// Cand fisierul de intrare nu poate fi citit, programul
// nu trebuie sa dea eroare sau sa intre in bucla infinita,
// trebuie sa scrie ca a gasit 0 vocale si 0 consoane.
//
// Format-ul pentru fisierul de iesire:
// <nr_vocale>|<nr_consoane>, e.g. "213|1234".
// fara alte caractere la sfarsit de linie.
//
void problema1(const char *input_file_name, const char *output_file_name)
{
	int vocale = 0, consoane = 0;
	char s;
	ifstream file_input(input_file_name);
	file_input >> s;
	while (s!='0')
	{
		if ((s >= 'a'&&s <= 'z') || (s >= 'A'&&s <= 'Z'))
		{
			if (strchr("aeiouAEIOU", s)!=NULL)
				vocale++;
			else
				consoane++;
		}
		file_input >> s;
	}
	ofstream file_output(output_file_name);
	file_output << vocale << '|' << consoane;
	file_input.close();
	file_output.close();
}


/*
Problema 2

Să se scrie o functie C++ care să determine numărul de semne de punctuatie si numărul de cuvinte
dintr-un fisier dat

Fisierul de intrare:
 * va contine o serie de paragrafe
 * paragrafele nu sunt neaparat lipite (pot exista si linii goale, continand doar caracterul \n sau/si spatiu).
 * fisierul se va incheia cu un ultim newline.
 * semne de punctuatie ce vor fi luate in calcul:  .  ,  -  ;  :  '  "  (  )  ...  ?  !

Fisierul de iesire:
 * va contine 2 linii
 * pe prima linie va fi numarul de cuvinte
 * pe a doua linie va fi numarul semnelor de punctuatie
 * fiecare linie se va finaliza cu caracterul \n


*/
void problema2(const char *input_file_name, const char *output_file_name)
{
	ifstream f(input_file_name);
	char a, b=' ',c=' ';
	int cuvinte = 0, semne = 0;
	f >> a;
	while (a!='0')
	{
		if (a == '.' || a == ',' || a == '-' || a == ';' || a == ':' || a == '\''||a== '\"' ||a== '(' ||a== ')' ||a== '?' ||a== '!')
			semne++;
		if (a == b&&a == c&&a == '.')
			semne--;
		if ((b >= 'a'&&b <= 'z') || (b >= 'A'&&b <= 'Z'))
			if (a == ' ' || a == '\n' || (a == '.' || a == ',' || a == '-' || a == ';' || a == ':' || a == '\'' || a == '\"' || a == '(' || a == ')' || a == '?' || a == '!'))
				cuvinte++;
		c = b;
		b = a;
		f >> a;
	}
	ofstream g(output_file_name);
	g << cuvinte << '\n' << semne << '\n';
	f.close();
	g.close();
}


/*
Problema 3

Pentru un fisier de intrare si unul de iesire date, sa se scrie in fisierul de iesire lista tuturor cuvintelor care apar in fisierul de intrare, ordonate lexicografic, fiecare pe
cate un rand in care, separat prin ”***”, se va indica si frecventa de aparitie a cuvantului respectiv.

Exemplu:

Fisier intrare:
__________________________________________
Ana are doua mere, unul verde si unul rosu.
Ciresel nu vrea nici unul din cele doua mere, el vrea unul galben.
__________________________________________

Fisier iesire:
__________________________________________
Ana***1
Ciresel***1
are***1
cele***1
din***1
doua***2
el***1
galben***1
mere***2
nici***1
nu***1
rosu***1
si***1
unul***4
verde***1
vrea***2
__________________________________________


Important!!!
- literele mari (majuscule) sunt mai mici lexicografic ca literele mici (asa este by default)
- cuvintele care sunt la inceput de propozitie si incep cu litera mare sunt numerotate separat de apartiile lor in text
(ex, "El" si "el" vor fi numerotate separat)
- fisierul NU va contine cuvinte separate prin cratima (ex: n-am, intr-un, etc.)
- fisierul poate contine doar urmatorele semne de punctuatie: ,.?!:;
- atentie la extragerea cuvintelor din text:
	-  poate contine mai multe spatii adiacente
	-  poate contine linii goale
	-  semnele de punctuatie pot fi separate de spatii: ex. "Atentie!" sau "Atentie !"
	-  semnele de punctuatie pot fi in grupuri: ex. "...", "!?"

*/

void problema3(const char *input_file_name, const char *output_file_name)
{
	char sir[1000], sir2[1000], litera, countch;
	char array[100][1000];
	int count = 0, i = 0, j, length;
	char *p,*q;
	ifstream f(input_file_name);
	ofstream g(output_file_name);
	f >> litera;
	while (litera!='0')
	{
		f >> litera;
		if ((litera == '.' || litera == ',' || litera == '-' || litera == ';' || litera == ':' || litera == '\'' || litera == '\"' || litera == '(' || litera == ')' || litera == '?' || litera == '!'))
			{
				sir[i] = litera;
				i++;
			}
		else
		{
			if (litera == '-')
			{
				sir[i] = ' ';
				i++;
			}
			if (litera == ' '&&sir[i - 1] != ' ')
			{
				sir[i] = litera;
				i++;
			}
				
		}
		f >> litera;
	}
	length = strlen(sir);
	while (sir != "0")
	{
		count = 0;
		q = strtok(sir, " ");
		p = strstr(sir, q);
			while (p)
			{
				count++;
				strcpy(sir, sir - strlen(p));
				strcat(sir, p + strlen(q));
				p = strstr(p, q);
			}
		strcat(sir2, q);
		strcat(sir2, "***");
		countch = (char)count;
		i = strlen(sir2);
		sir2[i] = ' ';
		i++;
	}
	strcpy(sir, sir2);
	p = strtok(sir2, " ");
	i = 0;
	while (p!="0")
	{
		strcpy(array[i], p);
		p = strtok(NULL, " ");
	}
	for (int n = 0;n < i;n++)
		for (int m = n + 1;m < i;m++)
		{
			if (strcmp(array[n], array[m])>0)
				schimb(array[n], array[m]);
		}
	for (j = 0;j < i;j++)
	{
		for (int m = 0;m < strlen(array[j]);m++)
			g << array[j][m];
		g << '\n';
	}
	f.close();
	g.close();
} 




/*
Problema 4

Pentru un fisier de intrare dat, si un numãr de caractere N, sã se determine cel mai periculos punct al sirului
circular format prin concatenarea primelor N caractere alfanumerice din fisierul de intrare.


In sirul a0,a1,a2,...,aN spunem cã punctul i este mai periculos decat punctul j dacã sirul care incepe cu pozitia i

i: ai,ai+1,...,aN,a0,a1,a2,...,ai-1

este mai mic lexicografic decat sirul care incepe cu pozitia j

j: aj,aj+1,...,aN,a0,a1,a2,...,aj-1.


Exemplu punct punct periculor:

Pentru sirul: autocar
Avem urmatorele subsiruri circulare: autocar, utocara, tocarau, ocaraut, carauto, arautoc, rautoca
Punctul cel mai periculos este 5 deoarce subsirul care incepe de la pozitia respectiva (arautoc) este cel mai mic lexicografic.

Exemplu input: (fisier_intrare, 15)

Fisier intrare:
___________________
ana are 15 mere
ciresel vine si cere
___________________

Functia va returna: 6 (de la pozitia 6 incepe cel mai periculos subsir "15mereciranaare")

Important!!!
- numerotarea in fisier incepe de la pozitia 0
- se iau in considerare doare primele N carctere alfanumerice, celelalte sunt ignorate (spatii, newline, semne de punctuatie, etc.)
- in cazul in care in fisier nu sunt N carcatere alfanumerice se vor citi cate sunt
- daca fisierul nu contine niciun caracter alfanumeric se va returna -1

*/

int problema4(const char *input_file_name, int N)
{
	ifstream f(input_file_name);
	char sir[1000], sir_i[1000], sir_initial[1000];
	int count=0,min=0;
	int i = 0,j;
	f >> sir[i];
	while ((i < N) || sir[i]!='0')
	{
		
		if ((sir[i] >= 'A'&&sir[i] <= 'Z') || (sir[i] >= 'a'&&sir[i] <= 'z') || (sir[i] >= '0'&&sir[i] <= '9'))
			i++;
		f >> sir[i];
	}
	f.close();
	if (sir == "0")
		return -1;
	strcpy(sir_i, sir);
	strcpy(sir_initial, sir);
	while(count!=i)
	{
		sir[i + 1] = sir[0];
		for (j = 0;j < i;j++)
			sir[j] = sir[j + 1];
		count++;
		if (strcmp(sir, sir_i) < 0)
		{
			strcpy(sir_i, sir);
			min = count;
		}
	}
	return min;
}




//	problema 5
//	Primul cuvant se gaseste pe prima linie din fisierul de intrare.
//	Al doilea cuvant se gaseste pe a doua linie din fisierul de intrare.
//	In fisierul de iesire, sirurile care indeplinesc proprietatea din enunt se vor gasi fiecare pe cate o linie incepand cu prima.
//	Cuvintele vor contine doar litere mici din alfabetul englez. ([a - z])
//	"Sufix" reprezinta un subsir nevid ramas prin eliminarea a 0 sau mai multe litere aflate pe pozitii consecutive incepand cu prima litera.
//	"Prefix" reprezinta un subsir nevid ramas prin eliminarea a 0 sau mai multe litere aflate pe pozitii consecutive incepand cu ultima litera.
//
//	Exemplu:
//
//	fisier de intrare:

//	fetele
//	elefant

//	fisier de iesire:

//	ele
//	e

//	Dacă nu există astfel de sufixe, se afiseaza valoarea 0.
//  Tot timpul va fi un '\n' folosit pentru sfarsit de linie, ultima linie din fisier are doar un '\n'.

void problema5(const char *input_file_name, const char *output_file_name)
{
	ifstream f(input_file_name);
	ofstream g(output_file_name);
	char cuvant1[1000], cuvant2[1000],s;
	int ok = 0,length1=0,length2=0,i,j,count=0;
	f >> s;
	while (s!='0')
		{
			
			if (s == '\n')
				ok = 1;
			if (ok == 0)
				cuvant1[length1] = s;
			else
				cuvant2[length2] = s;
			f >> s;
		}
	while (length1 > 0)
	{
		i = 0;
		ok = 1;
		for (j = length1;j >= 0,i<length2;j--,i++)
		{
			if (cuvant1[j] != cuvant2[i])
			{
				ok = 0;
				break;
			}
		}
		if (ok == 1)
		{
			count = 1;
			for (i = 0;i <= length1;i++)
			{
				g << cuvant1[i];
			}
			g << '\n';
		}
	}
	if (count == 0)
		g << 0 << '\n';
	f.close();
}


/**
 * Functia rimes face parte din problema 6
 *
 * Completati codul pentru aceasta functie astfel incat sa returneze true daca cele doua cuvinte rimeaza
 * si false altfel.
 * Spunem ca doua cuvinte rimeaza daca ultimele n litere coincid.
 * Aceasta functie va returna false in cazul in care un cuvant este mai scurt de n litere si celalalt nu.
 * Ex: gigel, angel, n = 3 => functia returneaza true
 * au, bau, n = 3 => functia returneaza false
 * au, bau, n = 2 => functia returneaza true
 */
bool rimes(char* first_word, char* second_word, int n)
{
	for (int i = 0;i < n;i++)
	{
		if (first_word[strlen(first_word) - i] != second_word[strlen(second_word) - i])
			return 0;
	}
	return 1;
}

/**
 * Completati aceasta functie astfel incat sa citeasca din fisierul de intrare parametrul n (necesar functiei de mai sus)
 * si o catrena, si scrie in fisierul de iesire litera corespunzatoare rimei catrenei.
 * Rima impercheata: A -> (a, a, b, b)
 * Rima incrusicata: B -> (a, b, a, b)
 * Rima imbratisata: C -> (a, b, b, a)
 * Rima inbratisata: D -> (a, a, a, a)
 * Rima alba: E -> in cazul in care niciuna din rimele de mai sus nu se potriveste.
 *
 * Fisierul de intrare va avea urmatorul format:
 * Pe prima linie se afla numarul natural n (1 <= n <= 5)
 * Pe urmatoarele 4 linii se afla versurile catrenei. Fiecare vers poate avea maxim 100 de caractere. Cuvintele din versuri
 * vor fi separate prin urmatorii separatori: .(Punct) ,(Virgula) !(Semnul exclamarii) ?(Semnul intrebarii)  (Spatiu)
 *
 * Fisierul de iesire va avea urmatorul format:
 * Pe prima linie se va scrie caracterul corespunzator tipului de rima urmat de caracterul NEWLINE (\n).
 *
 * Atentie: Nu uitati de caracterul NEWLINE de la finalul fisierului de iesire.
 * Fisierul de intrare contine litere mici din alfabetul englez, litere mari din alfabetul englez si separatorii mentionati mai sus.
 */
void problema6(const char *input_file, const char *output_file)
{
	ifstream f(input_file);
	ofstream g(output_file);
	char *p;
	char sir[1000], rand1[1000], rand2[1000], rand3[1000], rand4[1000], cuv1[100], cuv2[100], cuv3[100],cuv4[100];
	int i = 0,count=1,ok=0;
	f >> sir[i];
	while (sir[i]!='0')
	{
		
		if (sir[i] == ',' || sir[i] == '.' || sir[i] == '?' || sir[i] == '!')
			sir[i] = ' ';
		i++;
		if (sir[i] == '\n'&&sir[i - i] == ' ')
			i--;
		f >> sir[i];
	}
	p = strtok(sir, "\n");
	strcpy(rand1, p);
	p = strtok(NULL, "\n");
	strcpy(rand2, p);
	p = strtok(NULL, "\n");
	strcpy(rand3, p);
	p = strtok(NULL, "\n");
	strcpy(rand4, p);
	for (i = strlen(rand1);rand1[i] == ' ';i--)
	{
		cuv1[0] = rand1[i];
		for (int j = strlen(cuv1);j >= 0;j--)
			cuv1[j] = cuv1[j - 1];
	}
	for (i = strlen(rand2);rand2[i] == ' ';i--)
	{
		cuv2[0] = rand2[i];
		for (int j = strlen(cuv2);j >= 0;j--)
			cuv2[j] = cuv2[j - 1];
	}
	for (i = strlen(rand3);rand3[i] == ' ';i--)
	{
		cuv3[0] = rand3[i];
		for (int j = strlen(cuv3);j >= 0;j--)
			cuv3[j] = cuv3[j - 1];
	}
	for (i = strlen(rand4);rand4[i] == ' ';i--)
	{
		cuv4[0] = rand4[i];
		for (int j = strlen(cuv4);j >= 0;j--)
			cuv4[j] = cuv4[j - 1];
	}
	if (rimes(cuv1, cuv2, 2) == 1 && rimes(cuv3, cuv4, 2) == 1)
	{
		if (cuv1[strlen(cuv1)] == cuv3[strlen(cuv3)] && cuv1[strlen(cuv1) - 1] == cuv3[strlen(cuv3) - 1])
			g << 'D' << '\n';
		else
			g << 'A' << '\n';
		ok = 1;
	}
	if (rimes(cuv1, cuv3, 2) == 1 && rimes(cuv2, cuv4, 2) == 1)
	{
		g << 'B' << '\n';
		ok = 1;
	}
	if (rimes(cuv1, cuv4, 2) == 1 && rimes(cuv2, cuv3, 2) == 1)
	{
		g << 'C'<< '\n';
		ok = 1;
	}
	if (ok == 0)
		g << 'E' << '\n';
	f.close();
}



/*
 Problema 7

 Sa se scrie o functie C++ care primeste 2 cuvinte si determina daca acestea sunt anagrame.
 Doua cuvinte se numesc anagrame daca au acelasi litere dar in alta ordine.
 Exemplul 1: rac, arc, car
 Exemplul 2: mama, amma, maam

 Sa se determine daca intr-un fisier de intrare dat exista anagrame, caz in care se vor returna intr-un fisier de iesire, in urmatorul format:
	- grupurile de anagrame relative (formate cu aceleasi litere) in ordine descrescatoare a lungimii acestora (numarul de cuvinte din grup)
	- pe un rand se vor afisa toate anagramele unui grup ordonate lexicografic si separate printr-un spatiu
	- daca doua grupuri de anagrame au aceeasi lungime (acelasi numar de cuvinte) se vor ordona lexicografic dupa primul cuvant din grup

 Exemplu:

 Input:
 -----------------------
 rac arc car
 mama are mere amam
 erem

 era

 a b c d e f g

 ab ba

 cd
 dc
 ab
 -----------------------
 Output:
 ab ab ba     | ambele au cate 3 cuvinte in grup
 arc car rac  | dar "ab" este mai mic lexicografic ca "arc"
 amam mama
 are era
 cd dc
 erem mere
 a            | toate au cate un singur cuvant in grup
 b            | deci se ordoneaza lexicografic dupa primul cuvant din grup
 c            |
 d            |
 e            |
 f            |
 g            |
 -----------------------
 */
int anagram(char cuvant1[], char cuvant2[])
{
	if (strlen(cuvant1) != strlen(cuvant2))
		return 0;
	int ok;
	for (unsigned i = 0;i < strlen(cuvant1);i++)
	{
		ok = 0;
		for (unsigned j = 0;j < strlen(cuvant2);j++)
			if (cuvant1[i] == cuvant1[j])
			{
				ok= 1;
				break;
			}
		if (ok == 0)
			return 0;
	}
	return 1;
}

void problema7(const char *input_file_name, const char *output_file_name)
{
	ifstream f(input_file_name);
	ofstream g(output_file_name);
	char sir[100][1000],s;
	int i = 0, j = 0, count[100] = { 0 },countk=1;
	f >> s;
	while (s!='0')
	{
		
		if ((s >= 'a'&&s <= 'z') || (s >= 'A'&&s <= 'Z'))
		{
			sir[i][j] = s;
			j++;
		}
		else
			{
				i++;
				j = 0;
			}
		f >> s;
	}
	for (int n = 0;n < i;n++)
		for (int m = n+1;m < i;m++)
		{
			if (strcmp(sir[n], sir[m])<0)
				schimb(sir[n], sir[m]);
		}

	for (int n = 0;n < i;n++)
	{
		for (int m = n + 1;m < i;m++)
		{
			if (anagram(sir[n], sir[m]) == 1)
				count[n] = countk;

		}
		countk++;
	}
	for (int n = 1;n <= countk;n++)
	{
		for (int m = 0;m < i;m++)
		{
			if (count[m] == countk)
				for (unsigned q = 0;q < strlen(sir[m]);q++)
					g << sir[q];
			g << ' ';
		}
		g << '\n';
	}
	for (int m = 0;m < i;m++)
	{
		if (count[m] == 0)
			for (unsigned q = 0;q < strlen(sir[m]);q++)
				g << sir[q];
		g << ' ';
	}
	g << '\n';
	f.close();
	g.close();
}
