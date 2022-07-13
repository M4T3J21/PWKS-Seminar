//------------------------------------------------------------------------------
/*  Napisati funkciju koja u bitovnom zapisu broja n vraca najveci i najmanji broj uzastopnih jedinica.
 */
//------------------------------------------------------------------------------

void minmax(int n, int* pmax, int* pmin)
{
    int cnt = 0;
    *pmax = 0;
    *pmin = sizeof(int) * 8;
    while (n)
    {
        if (n & 1) cnt++;
        if (((n & 1) == 0 || n == 1) && cnt)
        {
            if (cnt > *pmax)
                *pmax = cnt;
            if (cnt < *pmin)
                *pmin = cnt;
            cnt = 0;
        }
        n >>= 1;
    }

}

int main()
{
    int n, max, min;
    scanf("%d", &n);
    minmax(n, &max, &min);
    printf("max je %d, min je %d\n", max, min);
    return 0;
}

//------------------------------------------------------------------------------
//Napisati funkciju koja vraca koliko puta se u binarnom zapisu broja pojavljuju tri
//uzastopne jedinice.
//------------------------------------------------------------------------------

unsigned uzastopne_jedinice(int n, unsigned k)
{
    int mask = (1<<k) - 1;
    unsigned br;
    while (n)
    {
    if ((n & mask) == mask)
        br++;
        n >>= 1;
    }
    return br;
}
//------------------------------------------------------------------------------
//Napisati funkciju koja u binarnom zapisu prirodnog broja zamjenjuje po dvije susjedne
//znamenke. Funkcija vra´ca novi broj. Ako je broj znamenki u binarnom zapisu neparan,
//vode´ca znamenka se ne mijenja.
//------------------------------------------------------------------------------

void print_bin(int n)
{
    if (!n) return;
    print_bin(n >> 1);
    printf("%d", n&1);
}

int fun(int a)
{
    int mask = 3;
    int br = a, prva, druga;
    while(br)
    {
        prva = (br & 2) >> 1;
        druga = br & 1;

        if (prva != druga)
            a ^= mask;

        br >>= 2;
        mask <<= 2;

    }
    return a;
}

int main()
{
    int a = 45, b;
    printf("originalni: %d, binarno: ", a);
    print_bin(a);
    b = fun(a);
    printf("\nrezultat: %d, binarno: ", b);
    print_bin(b);

    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja raˇcuna sumu prvih n trokutnih brojeva. Trokutni
brojevi su brojevi oblika 1
2
∗ i ∗ (i + 1), za i prirodan broj. Problem riješiti
iterativno i rekurzivno*/
//------------------------------------------------------------------------------
unsigned triangle_nums_iter(unsigned n)
/* iterativno rjesenje */
{
    unsigned i, s = 0;
    for (i = 1; i <= n; i++)
        s += i * (i + 1) / 2;
    return s;
}
unsigned triangle_num_rek(unsigned n)
/* rekurzivno rjesenje */
{
/* ako je n jednak 0 ili 1 - kraj rekurzije*/
    if (n <= 1) return n;
    return n * (n + 1) /2 + triangle_num_rek(n - 1) ;
}
int main(void)
{
    unsigned n;
    printf("unesi n\n");
    scanf("%u",&n);
    printf("suma trokutnih iterativno %u\n",
        triangle_num_iter(n));
    printf("suma trokutnih rekurzivno %u\n",
        triangle_num_rek(n));
return 0;
}

//------------------------------------------------------------------------------
/*Napisati funkciju koja za dva unesena znaka vra´ca koliko daleko se nalaze
u engleskom alfabetu (udaljenost je pozitivan broj). Ako jedan od znakova
nije slovo, funkcija vra´ca -1.*/
//------------------------------------------------------------------------------

#include <ctype.h>
int distance(char a, char b)
{
    int d;
    if (!isalpha(a) || !isalpha(b))
        return -1;
    d = toupper(a) - toupper(b);
    if (d < 0 )
        return -d;
    return d;
}

/* Napisati funkciju koja sortira niz struktura koji predstavljaju tocku u kooordinatnom sustavu
po udaljenosti od zadane tocke koja je argument funkcije. Za sortiranje koristiti qsort.
*/
//------------------------------------------------------------------------------

#include <math.h>
typedef struct
{
    double x,y;
    double dist;
} point;

void puni_niz(point arr[], int n, point p)
{
    int i;
    for (i = 0; i < n; ++i)
        arr[i].dist = sqrt(pow(arr[i].x - p.x, 2) + pow(arr[i].y - p.y, 2));
}

void ispisi(point arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%lf, %lf, dist =  %lf\n", arr[i].x, arr[i].y, arr[i].dist);
}

void cmp(const void* p1, const void* p2)
{
    const point* pt1 = (const point* )p1;
    const point* pt2 = (const point* )p2;
    return pt1->dist - pt2->dist;
}

void sortiraj(point arr[], int n, point p)
{
    puni_niz(arr, sizeof arr/sizeof arr[0], p);
    qsort(arr, n, sizeof(point), cmp);
}

int main()
{
    point arr[] = {{2, 3, 0}, {4, 2, 0}, {5, 5, 0}};
    point p;
    puts("unesi tocku: koordinate odvojene zarezom");
    scanf("%lf, %lf", &p.x, &p.y);

    sortiraj(arr, sizeof arr/sizeof arr[0], p);
    ispisi(arr, sizeof arr/sizeof arr[0]);
    return 0;
}

//------------------------------------------------------------------------------
/*1. zadatak - napisati funkciju koja će ispisvati sve načine na koji se broj n može prikazati
kao zbroj dvaju ili više uzastopnih visekratnika broja 3. U slučaju da se ne može prikazati
na taj način, funkcija ispisuje poruku. U main funkciji korisnik unosi prirodan broj i za njega
poziva funkciju. Ukoliko korisnik unese nulu ili negativan broj, unos se ponavlja sve dok se ne
unese prirodan broj. */
//------------------------------------------------------------------------------

void ispisi(int  a, int b, int d)
{
    int i, s = 0;
    for (i = a; i <= b; i += d)
        printf("%c %d ", i != a ? '+' : ' ', i);
    printf("\n");
}

int suma(int a, int n, int d)
/* suma n brojeva pocevsi od a sa razlikom d*/
{
    int i, s = a;
    for (i = 0; i < n; i+=d)
        s += i ;
    return s;
}

int suma_artitm(int a, int n, int d)
/* suma n brojeva pocevsi od a sa razlikom d - koristeci sumu aritmetickog niza */
{
    return n * (2 * a + (n-1) * d)/2;
}
int funkcija(int br)
{
    int n, a, i;
    int flag = 0;
    n = br/3; /* najduzi niz neparnih je 3, 6, 9, ..., br - 1 */
    for (a = 3; a < br; a+=3)
    {
        for (i = 1; i <= n; ++i)
        {
            if (br == suma_artitm(a, i, 3))
            {
                ispisi(a, a + (i-1)*3, 3);
                flag = 1;
            }
        }
        n--;    /* svaka sljedeca provjera ima jedan element manje*/
    }
    return flag;

}
int main()
{
    int n;
    while (n <= 0)
    {
        printf("Unesi broj: ");
        scanf("%d", &n);
        if (!funkcija(n))
            puts("ne moze se rastavit na taj nacin");
    }
    return 0;
}

//------------------------------------------------------------------------------
//Napisati funkciju koja raˇcuna najve´cu i najmanju znamenku u oktalnom zapisu broja.
//------------------------------------------------------------------------------

#include <stdio.h>


void min_max_oct(int n, int* pmin, int* pmax)
{
    int zn = n % 8;
    *pmin = *pmax = zn;
    while(n)
    {
        zn = n % 8;
        if (zn > *pmax)
            *pmax = zn;
        if (zn < *pmin)
            *pmin = zn;
        n /= 8;
    }
}

int main()
{
    int n = 16, pmin, pmax;
    min_max_oct(n,&pmin,&pmax);
    printf("Najmanji je %d a najveci %d",pmin,pmax);
}
//------------------------------------------------------------------------------
//Napisati funkciju koja u niz brojeva ume´ce drugi niz na mjestu k.
//------------------------------------------------------------------------------


int* umetanje(int* arr, int* n, int* brr, int m, int k)
{
    arr = (int*) realloc(arr, (*n + m) * sizeof(int));
    if (!arr)
        return NULL;
    memmove(arr + k + m, arr + k,  *n - k);
    memmove(arr + k, brr, m * sizeof(int));
    *n += m;
    return arr;

}
int main()
{
    int n = 5, k = 3, i, m;
    int b[] = {1,2,3,4,5};
    int* arr = (int*) malloc(n * sizeof(int));
    if (!arr)
        return NULL;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    m = sizeof b/sizeof b[0];
    arr = umetanje(arr, &n, b, m, k);
    for ( i = 0; i < n; ++i)
        printf("%d", arr[i]);
}

//------------------------------------------------------------------------------
//Napisati funkciju koja za niz znakova vra´ca brojˇcanu vrijednost sume znamenki.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int suma(char* arr, int n)
{
    int s = 0, i;
    for (i = 0; i < n; ++i)
    {
        if (isdigit(arr[i]))
            s += arr[i] - '0';
    }
    return s;

}
int main()
{
    int n;
    char arr[]={'a','2','a','3','4'};
    n=sizeof(arr);
    printf("Suma je %d",suma(arr,n));
}

//------------------------------------------------------------------------------
//Napisati rekurzivnu funkciju koja racuna sumu od n elemenata
//------------------------------------------------------------------------------

float suma_rek(int n)
{
    if (!n) return 0;
    return suma_rek(n - 1) + pow (-1., n - 1) * n / (n + 1);
}
int main()
{
    int n=5;
    printf("Suma je %f",suma_rek(n));
}
//Primjer 2
double suma(int n)
{
    if (n <= 0) return 0;
    return suma(n-1) + pow(-1., n+1) / (n * n);
}

int main()
{
    int n = 1;
    printf("%lf\n", suma(n));
    return 0;
}
//------------------------------------------------------------------------------
//Napisati funkciju koja za prirodni broj n, n < 100, vra´ca broj manji od n koji ima
//najviˇse djelitelja, te broj djelitelja koje ima taj broj.
//------------------------------------------------------------------------------

int broji_djelitelje ( int n )
{
    int i , cnt = 2;
    for ( i = 2; i <= n /2; ++ i )
        if ( n % i == 0)
            ++ cnt ;
    return cnt ;
}
int max_djelitelj ( int n , int * max )
{
    int i , cnt , broj ;
    * max = 1;
    for ( i = 1; i < n ; ++ i )
    {
        cnt = broji_djelitelje ( i ) ;
        if ( cnt > * max )
        {
            * max = cnt ;
            broj = i ;
        }
    }
    return broj ;
}
int main()
{
    int n=69;
    int max;
    printf("Broj djelitelja je %d\n",broji_djelitelje(n));
    printf("Broj je %d",max_djelitelj(n,&max));
}

//------------------------------------------------------------------------------
//. Napisati funkciju koja iz stringa izbacuje sve duplikate znakova
//------------------------------------------------------------------------------


char * unique ( char * str )
{
    int i , j ;
    for ( i = 0; i < strlen ( str ) - 1; ++ i )
        for ( j = i + 1; j < strlen ( str ) ;)
            if ( tolower ( str [ i ]) == tolower ( str [ j ]) )
                memmove ( str + j , str + j + 1 , strlen ( str ) - j ) ;
            else
                ++ j ;
    return str ;
}
int main()
{
    char str[]="HHAAJJDDUUKK";
    printf("%s",unique(str));
}

//------------------------------------------------------------------------------
//Predloˇziti strukturu koja opisuje ˇzivotinju. Zivotinja ima ime, vrstu, teˇzinu i koliˇcinu ˇ
//hrane koju moˇze pojesti u jednom danu. Napisati funkciju koja sortira niz struktura
//po omjeru koliˇcine hrane i teˇzine silazno.
//------------------------------------------------------------------------------


typedef struct
{
    float ime;
    float vrsta;
    float tezina;
    float kolh;

}animal;

int podjela(const void* pa,const void* pb)
{
    animal* paa=(animal*)pa;
    animal* pab=(animal*)pb;

    float pr1= paa->tezina/paa->kolh;
    float pr2= pab->tezina/pab->kolh;

    if(pr1-pr2 > 0)
        return 1;
    else if(pr1-pr2 < 0)
        return -1;

    return 0;

}
void sortiraj(animal* arr, int n)
{
    qsort(arr,n, sizeof(animal),podjela);
}

void ispis(animal* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Ime %f\n Vrsta %f\n Tezina %f\n Kolicina Hrane %f\n",arr[i].ime,arr[i].vrsta,arr[i].tezina,arr[i].kolh);

    }
}
int main()
{
    animal arr[]={{1,1,500,40},{2,2,300,10}};

    sortiraj(arr,sizeof(arr)/sizeof(arr[0]));
    ispis(arr,sizeof(arr)/sizeof(arr[0]));

}
//------------------------------------------------------------------------------
/* Zadana je datoteka u kojoj je u svakom redu zapis oblika
(x, y), (r, g, b)
gdje su x i y koordinate koje predstavljaju tocku, a r, g i b vrijednosti izmedu 0 i 255 koje
pretstavljaju vrijednosti crvene, zelene i plave boje u boji tocke. Napisati funkciju koja cita
datoteku te vraca koliko ima crnih (kombinacija 0, 0, 0) te koliko ima bijelih  (255,
255, 255).
*/
//------------------------------------------------------------------------------
void funkcija (FILE* fp, int* pc, int* pb)
{
    double x,y;
    int r, g, b;
    *pb = *pc = 0;
    while (fscanf(fp, "(%lf, %lf), (%d, %d, %d) ", &x, &y, &r, &g, &b) != EOF)
    {
         if (r == g && g == b)
        {
            if (r == 255)
                (*pb)++;
            if (r == 0)
                (*pc)++;
        }
    }
}
int main()
{
    FILE* fp;
    int br_crnih, br_bijelih;
    fp = fopen("dat.txt", "r");
    if (!fp)
        return -1;
    funkcija(fp, &br_crnih, &br_bijelih);
    printf("ima %d bijelih i %d crnih\n", br_bijelih, br_crnih);
    fclose(fp);
    return 0;
}
//------------------------------------------------------------------------------
//Korisnik sa tastature unosi stringove red po red. Napisati funkciju koja zapisuje u
//datoteku one redove koji predstavljaju palindrom. Palindrom je niz znakova koji je
//isti od naprijed i od nazad, ignoriraju´ci znakove interpunkcije i razliku izmedu malih
//i velikih slova
//------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
void funkcija (FILE* fp, int* pc, int* pb)
{
    double x,y;
    int r, g, b;
    *pb = *pc = 0;
    while (fscanf(fp, "(%lf, %lf), (%d, %d, %d) ", &x, &y, &r, &g, &b) != EOF)
    {
         if (r == g && g == b)
        {
            if (r == 255)
                (*pb)++;
            if (r == 0)
                (*pc)++;
        }
    }
}
int main()
{
    FILE* fp;
    int br_crnih, br_bijelih;
    fp = fopen("dat.txt", "r");
    if (!fp)
        return -1;
    funkcija(fp, &br_crnih, &br_bijelih);
    printf("ima %d bijelih i %d crnih\n", br_bijelih, br_crnih);
    fclose(fp);
    return 0;
}
//------------------------------------------------------------------------------
//Palindrom datoteke
//------------------------------------------------------------------------------

int is_palindrome ( char * str )
{
    char * p = str ;
    char * q = p + strlen ( str ) - 1;
    while ( p < q )
    {
        while (! isalnum (* p ) ) ++ p ;
        while (! isalnum (* q ) ) --q ;
        if ( tolower (* p ) == tolower (* q ) )
            ++ p , --q ;
        else
            return 0;
    }
        return 1;
}
void write_lines ( FILE * fp )
{
    char str [ N ];
    while ( fgets ( str , N , stdin ) != NULL )
        if ( is_palindrome ( str ) )
            fputs ( str , fp ) ;
}
//------------------------------------------------------------------------------
//Napisati rekurzivnu funkciju koja za broj n vra´ca broj koji se dobije tako da se iz
//broja n uzme svako druga znamenka
//------------------------------------------------------------------------------
int create_num ( int n )
{
    if (( int ) log10 ( n ) %2)
        n/=10;
    if (! n )
        return 0;
    return create_num ( n /100) * 10 + n %10;
}
int main()
{
    int n=629442200;
    printf("Rezultat je %d",create_num(n));
}
//------------------------------------------------------------------------------
/* Napisati funkciju koja mijenja redoslijed riječi u rečenici tako da zamijeni prvu i zadnju riječ. */
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char* start, char* end)
{
    char* p = start;
    char* q = end;

    while(p < q)
        swap(p++, q--);
}

int is_punct(char ch)
{
    char punct[] = " .,!?:;";
    if (strchr(punct, ch))
        return 1;
    return 0;
}

void switch_words(char* str)
{
    char* p = str;
    char* q = str + strlen(str) - 1;
    char* end, *start;

    while (is_punct(*q)) --q; // preskacemo znakove interpunkcije na kraju recenice
    while (is_punct(*p)) ++p; // preskacemo znakove interpunkcije na pocetku recenice
    start = p;
    end = q;

    reverse(p, q);                      // okrenemo cijelu recenicu
    while (p < q)
    {
        if (!is_punct(*p)) ++p;             // idemo do kraja prve (koja je bila zadnja) rijeci
        if (!is_punct(*q)) --q;             // idemo do pocetka zadnje rijeci

        if ((is_punct(*p)) && (is_punct(*q)))
            break;
    }
    reverse(p, q );
    reverse(start, p - 1);
    reverse(q + 1, end);
}
int main()
{
    char rec[] = "...ali ovo je recenica, ima zarez i tocku.";
    switch_words(rec);
    puts(rec);
    return 0;
}
//------------------------------------------------------------------------------
//U datoteci, ˇcije ime zadaje korisnik, nalazi se tekst podijeljen na paragrafe, gdje su
//paragrafi odvojeni oznakom za novi red. Napisati funkciju koja ˇcita datoteku, te vra´ca
//paragraf u kojem ima najviˇse reˇcenica. Reˇcenica zavrˇsava jednim od znakova ’.’, ’!’
//ili ’?’.
//------------------------------------------------------------------------------

#define N 1024
char* max_paragraph(FILE* fp)
{
    int n = N, cnt = 0, max_cnt = 0, k;
    char c;
    char* par = (char*) malloc(n * sizeof(char));
    char* maxpar = (char*) malloc(n * sizeof(char));
    char* p = par;
    if (!par || !maxpar)
        return NULL;
    *p = '\0';

    while ((c = fgetc(fp)) != EOF)
    {
        if (strlen(par) == n) /* ako smo dosegli najvecu alociranu velicinu za paragraf */
        {
            n *= 2;
            par = (char*) realloc(par, n * sizeof(char));
            maxpar = (char*) realloc(maxpar, n * sizeof(char));
            p = par + n/2;
        }
        if (c == '\n')  /* kraj paragrafa */
        {
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                strcpy(maxpar, par);
            }
            cnt = 0;
            p = par;
            *p = '\0';
            continue;

        }
        *p++ = c;   // punimo par
        *p = '\0';
        if (c == '.' || c == '!' || c == '?')
            cnt++;
    }
    free(par);
    return maxpar;
}
int main()
{
    FILE* fp;
    char filename[N];
    char* par;
    gets(filename);
    fp = fopen(filename, "r");
    if (!fp)
        return -1;
    printf("najveci paragraf\n");
    par = max_paragraph(fp);
    puts(par);
    free(par);
    fclose(fp);

}//------------------------------------------------------------------------------
//INVERZ DATOTEKE
//------------------------------------------------------------------------------

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse(char* start, char* end)
{
    char* p = start;
    char* q = end;

    while(p < q)
        swap(p++, q--);
}

void puni(FILE* fp)
{
    char str[1024];
    while(1)
    {
        fgets(str, 1024, stdin);
        if (str[0] == '\n')
            break;
        fprintf(fp, "%s", str);
        reverse(str, str + strlen(str) - 1);
        fprintf(fp, "%s\n", str);
    }
}
int main()
{
    FILE* fp;
    fp = fopen("inverz.txt", "w");
    if (!fp)
        return -1;
    puni(fp);
    fclose(fp);
    return 0;
}
//------------------------------------------------------------------------------
//Napisati funkciju koja modificira string tako da iz njega izbaci sva pojavljivanja nekog
//podstringa kojeg zadaje korisnik.
//------------------------------------------------------------------------------

void modify(char* str, char* substr)
{
    char* pos;
    while (pos = strstr(str, substr))
        memmove(pos, pos + strlen(substr), str + strlen(str) - pos - strlen(substr) + 1);
}
int main()
{
    char str[1024], substr[1024];
    puts("unesi string");
    gets(str);
    puts("unesi podstring");
    gets(substr);
    modify(str, substr);
    puts(str);
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja generira pseudosluˇcajni broj iz zatvorenog intervala
[a, b], gdje su a i b argumenti funkcije.
Za generiranje pseudosluˇcajnog broja koristiti se funkcijom rand() definiranom u stdlib.h, koja generira broj u rasponu od 0 do RAND_MAX.
Za transformaciju generiranog broja x u broj y iz intervala [a, b] upotrebljavajte y = a + rand()%(b-a+1)*/
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <time.h>
int generate(int a, int b)
{
    if (a > b)
    {
    int t = a; a = b; b = t;
    }
    srand(time(NULL));
    return a + rand()%(b - a + 1);
}

//------------------------------------------------------------------------------
/*Napisati funkciju koja za dva broja ispituje je li u zapisu jedan završetak
drugog.*/
//------------------------------------------------------------------------------

#include <math.h>
int count(int m)
/* broji znamenke u broju*/
{
    if (n <= 0)
        return -1;
    return (int)log10(n)+1;
}
int zavrsetak(int m, int n)
{
    int k, t;
    if (m < n) n ^= m ^= n ^= m; // zamjena

    k = (int)pow(10, count(n));

    if (m % k == n) return 1;
    else return 0;
}
//------------------------------------------------------------------------------
/*. Napisati rekurzivnu funkciju za ispisivanje prirodnog broja u binarnom
obliku.*/
//------------------------------------------------------------------------------

void print_bin(unsigned n)
{
    if (!n) return;
    print_bin(n/2);
    printf("%d", n%2);
}
int main(void)
{
    unsigned n;
    printf("unesi broj\n");
    scanf("%u", &n);
    print_bin(n);
    printf("\n");
    return 0;
}

//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja vra´ca sumu prvih n kvadrata prirodnih
brojeva.*/
//------------------------------------------------------------------------------

unsigned sum_of_squares(unsigned n)
{
    if (n == 1) return 1;
    return n * n + sum_of_squares(n - 1);
}
int main(void)
{
    unsigned n;
    scanf("%u", &n);
    printf("suma kvadrata je %u\n", sum_of_squares(n));
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja provjerava ima li prirodni broj u heksadecimalnom zapisu sve jedinice.
*/
//------------------------------------------------------------------------------

int all_ones(unsigned n)
/* za strogo pozitivne brojeve */
{
    if (!n) return 1;
    if (n%16 == 1) return all_ones(n/16);
    else return 0;
}
void print_hexa(unsigned n)
/*ispisuje sve znamenke*/
{
    int k;
    if (!n) return;
    print_hexa(n/16);
    k = n%16;
    if (k > 9)
        printf("%c", k + ’A’ - 10);
    else
        printf("%u", k);
}
int main()
{
    unsigned n;
    while (1)
    {
        printf("Unesi poz. cijeli broj, nulu za kraj\n");
        scanf("%u", &n);
        if (!n) break;
        print_hexa(n);

    }
return 0;
}

//------------------------------------------------------------------------------
/*Napisati rekurzivnu finkciju koja vra´ca umnožak kvadrata znamenki prirodnog broja*/
//------------------------------------------------------------------------------
unsigned product_digits_square(unsigned n)
{
    int zn;
    if (!n) return 1;
    zn = n%10;
    return zn * zn * product_digits_square(n/10);
}
int main(void)
{
    unsigned n;
    do
    {
        scanf("%u", &n);
    }while(!n);
    printf("produkt kvdrata znamenki je %u\n",
        product_digits_square(n));
    return 0;
}

//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja raˇcuna broj koji je obratan od originalnog,
npr. za 12345 obratni broj je 54321.*/
//------------------------------------------------------------------------------
#include <stdio.h>

int reverse(int n, int novi)
{
    if(!n)
        return novi;
    return reverse(n/10, novi*10 + (n%10));
}

int main()
{
    unsigned n;
    scanf("%u", &n);
    n == reverse(n, 0) ? printf("palindrom\n") : printf("nije palindrom\n");
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja ispisuje sve znamenke svaku u svom
redu. Ne zna se unaprijed broj znamenki u danom broju.*/
//------------------------------------------------------------------------------
#include <stdio.h>
void print_dec(unsigned n)
{
    unsigned zn = n%10;
    if (!n) return;
    print_dec(n/10);
    printf("%u\n",zn);
}
int main()
{
    unsigned n;
    scanf("%u", &n);
    print_dec(n);
    return 0;
}

//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja za uneseni broj n ispisuje vrijednost prve
znamenke.
*/
//------------------------------------------------------------------------------
void print_first_sec(unsigned n)
{
    if (!n) return;
    if (n/100 == 0 && n > 9)
    {
    printf("prva i druga %u\n", n);
    return;
    }
    print_first_sec(n/10);
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja ispituje da li uneseni prirodni broj ima u binarnom
zapisu jednaki broj nula i jedinica.*/
//------------------------------------------------------------------------------
int is_equal01(unsigned n)
{
    unsigned br0 = 0, br1 = 0, zn;
    while(n)
    {
        zn = n % 2; /* zadnja znamenka u binarnom zapisu
        */
        if (zn == 0)
            br0 = br0 + 1;
        else
            br1 = br1 + 1;
        n = n / 2;
    }
    if (br0 == br1)
        return 1;
    return 0;
}
int main(void)
{
    int n, p;
    printf("unesi n\n");
    scanf("%u", &n);
    p = is_equal01(n);
    if (p == 0)
        printf("nema jednak broj nula i jedinica\n");
    else
        printf("ima jednak broj nula i jedinica\n");
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja ispisuje sve brojeve do n koji imaju toˇcno 4 prava
djelitelja*/
//------------------------------------------------------------------------------

unsigned non_trivial_divisor(unsigned n)
{
    unsigned cnt = 0, i;
    for (i = 2; i <= n/2; ++i)
        if (n % i == 0)
            ++cnt;
    return cnt;
}
void print_4_divisor(unsigned n)
{
    unsigned i;
    for (i = 1; i <= n; ++i)
        if (non_trivial_divisor(i) == 4)
            printf("%u\n", i);
}
int main(void)
{
    print_4_divisor(1000);
    return 0;
}

//------------------------------------------------------------------------------
/*. Napisati funkciju koja vra´ca predzadnju znamenku produkta prvih n prostih brojeva.
*/
//------------------------------------------------------------------------------
int is_prime(unsigned n)
{
    unsigned i;
    for (i = 2; i <= n/2; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
unsigned penultimate_digit(unsigned n)
{
    unsigned p = 1, i = 2, br = 1;
    while (br < n)
    {
        if (is_prime(i))
        {
            p = p * i;
            ++br;
        }
        ++i;
    }
    p = p / 10;
    return p%10;
}
int main(void)
{
    unsigned n, p;
    printf("unesi n\n");
    scanf("%u", &n);
    printf("%u\n", penultimate_digit(n));
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja rekurzivno računa sumu prvih n brojeva djeljivih sa m*/
//------------------------------------------------------------------------------
#include<stdio.h>

int main()
{
    printf("Zbroj je: %d",zbroj(6,2,2));
}

int zbroj(int i, int br, int br_brojeva)
{
    if(!i || br_brojeva==0)
        return 0;
    if(i%br==0)
        return i+zbroj(i-1,br,br_brojeva-1);
    else
        zbroj(i-1,br,br_brojeva);


}
//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja za dani broj n ispisuje sve neparne brojeve unazad
do 1.*/
//------------------------------------------------------------------------------
#include<stdio.h>
int main()
{
    printf("Neparni brojevi: ");
    nepar(14);
}

void nepar(int broj)
{
    if(!broj)
        return;

    if(broj%2==1)
    printf("%d \n",broj);
    nepar(broj-1);


}

//------------------------------------------------------------------------------
/*Napisati rekurzivnu funkciju koja traži n-to pojavljivanje nekog znaka u stringu.
Funkcija vraća indeks ili -1 ako se znak ne pojavljuje n puta*/
//------------------------------------------------------------------------------

#include<stdio.h>

int ponavljanje(char*tekst)
{
    if(!tekst)
        return -1;
    char*znak_br;
    int brojac=0;
    znak_br=strchr(tekst,"h");
    if (znak_br=NULL)
        return -1;
    brojac++;
    if (brojac=2)
        return (tekst-znak_br+1);
    ponavljanje(tekst);

}

int main()
{

    printf("Broj ponavljanja je %d",ponavljanje("hhhhadajen"));
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja će otvoriti postojeću datoteku i izračunati njezinu veličinu u
bajtovima.
*/
//------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
   FILE *fptr;
   fptr = fopen("example.txt","r");
   fseek(fptr, 0L, SEEK_END);
   int size = ftell(fptr);
   printf("Velicina je %d",size);


   return 0;

}

//------------------------------------------------------------------------------
/*Napisati funkciju koja čita datoteku znak po znak, sprema u string znakove koji su
mala slova alfabeta i vraća kreirani string. Memoriju za string alocirati na heapu.
*/
//------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
    FILE* fptr;
    fptr = fopen("example.txt", "r");
    int ch;
    while((ch=fgetc(fptr))!=EOF)
    {

        if((ch>='a')&&(ch<='z'))
        {
            printf("%c",ch);
        }
    }

    return 0;
    }

//------------------------------------------------------------------------------
/*Napisati funkciju koja čita datoteku red po red, izbaci sve znakove interpunkcije,
praznine i prazne redove i tako izmjenjeni tekst zapiše u drugu datoteku. U main
funkciji korisnik unosi imena obiju datoteka.
*/
//------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
    FILE* fptr;
    FILE* fptr1;
    fptr = fopen("example.txt", "r");

    int ch;
    while((ch=fgetc(fptr))!=EOF)
    {
        if((ch==' ')||(ch=='*')||(ch=='?')||(ch=='!')||(ch=='.')||(ch==',')||(ch=='-'))

        {
            ch='a';
            fptr1 = fopen("example1.txt","w");
            fprintf(fptr1,"%c",ch);

        }
    printf("%c",ch);
    }

    return 0;
    }

//------------------------------------------------------------------------------
/* Definirati strukturu za vrijeme. Napisati funkciju koja prima dva argumenta koja
predstavljaju vrijeme i vraća razliku vremena. Ispišite tu razliku u formatu hh:mm:ss.
*/
//------------------------------------------------------------------------------
#include <stdio.h>
typedef struct
{
    int mm,mm2;
    int ss,ss2;
    int hh,hh2;
}vrijeme;


int main(void)
{

    vrijeme vr1;
    vr1.hh = 19;
    vr1.mm =0;
    vr1.ss = 0;

    vrijeme vr2;
    vr2.hh2 = 20;
    vr2.mm2 = 0;
    vr2.ss2 = 0;
    podjela(vr1,vr2);

}

int podjela(vrijeme *vr1,vrijeme *vr2)
{
    int hh3,ss3,mm3;

    if (vr1->hh>vr2->hh2)
        hh3=24-vr1->hh+vr2->hh2;
    else
        hh3=vr2->hh2-vr1->hh;
    if (vr1->mm>vr2->mm2)
        mm3=60-vr1->mm+vr2->mm2;
    else if (vr2->mm2>=vr1->mm)
        mm3=vr2->mm2-vr1->mm;
    if (vr1->ss>vr2->ss2)
        ss3=60-vr1->ss+vr2->ss2;
    else if (vr2->ss2>=vr1->ss)
        ss3=vr2->ss2-vr1->ss;

    printf("Razlika je: %d : %d : %d\n", hh3,mm3,ss3);

}
//------------------------------------------------------------------------------
/*Napisati funkciju koja za tri broja računa i vraća najveći i najmanji element. Za
računanje najvećeg i najmanjeg elementa napisati dvije predprocesorske direktive.
*/
//------------------------------------------------------------------------------
#include <stdio.h>

#define MAX(a,b,c) (a > b) ? ((a > c) ? a : c)  : ((b > c)? b:c)
#define MIN(a,b,c) (a < b) ? ((a < c) ? a : c)  : ((b < c)? b:c)

int main()
{
    printf("Najveci broj je : %d \n",MAX(30,20,10));
    printf("Najmanji broj je : %d \n",MIN(30,20,10));
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja za neki string vraća poziciju i adresu drugog pojavljivanja
nekog slova. U slučaju da se slovo ne pojavljuje dva puta, funkcija vraća -1 i NULL.
Primjer: Za string "ONoffON" pozicija drugog pojavljivanja slova 'O' je 6*/
//------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

int main () {

   printf("Unesite string ");
   char string[20];
   scanf("%s", string);
   int i,j,br;

   for (  i=0; i<strlen(string); i++){
    int br=0;
	for( j=0; j<strlen(string); j++){
		if(string[i]==string[j] && i!=j ){
			br=1;
			if(i<j){
				printf("Slovo %c se ponavlja %d \n", string[i], j );
			}

		}
	}
		if(br==0){
			printf("Slovo %c se javlja samo jednom \n", string[i]);
		}

	}

	return 0;

}

//------------------------------------------------------------------------------
/*Napisati funkciju koja modificira string tako da izbaci sve samoglasnike iz njega.
Primjer: "Popokatepetl" postaje "Ppktptl"*/
//------------------------------------------------------------------------------
#include <string.h>

int main() {

    char rijec[50];
    int k, l, rijec_vel = 0;
    printf("Unesite rijec : ");
    scanf("%s", rijec);


    rijec_vel = strlen(rijec);

    for (k = 0; k < rijec_vel; k++) {

        if (rijec[k] == 'a' || rijec[k] == 'e' || rijec[k] == 'i' || rijec[k] == 'o' || rijec[k] == 'u' ||
            rijec[k] == 'A' || rijec[k] == 'E' || rijec[k] == 'I' || rijec[k] == 'O' || rijec[k] == 'U') {

            for (l = k; l < rijec_vel; l++) {

                rijec[l] = rijec[l + 1];
            }
            k--;
            rijec_vel--;
        }
        rijec[rijec_vel + 1] = '\0';
    }
   printf("Nakon sto izbacimo samoglasnike rijec je : %s", rijec);
   return 0;
}

//------------------------------------------------------------------------------
/*Napisati funkciju koja ispituje da li su dvije riječi anagrami (jedna riječ je permutirana
druga riječ).
Primjer: riječi "vatra", "trava" i "vrata" su anagrami*/
//------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>


int main () {

   printf("Prvi tekst ");
   char prva[20];
   scanf("%s", prva);

   printf("Drugi tekst ");
   char druga[20];
   scanf("%s", druga);
   bool anagram;

   for ( int a=0; a<strlen(prva); a++){
   	anagram = false;
   	for (int b=0; b<strlen(druga); b++){
   		if (prva[a]==druga[b]){
   			anagram = true;
		   }
	   }
	if ( anagram == false ){
		printf("Ova dva teksta nisu anagrami.");
		break;
	}
   }
   if(anagram == true){
   	printf("Tekstovi su anagrami.");
   }
   return 0;

}


//------------------------------------------------------------------------------
/*Napisati funkciju koja računa sumu elemenata niza na neparnim mjestima u nizu*/
//------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_SIZE 2

int main()
{
    int arr[MAX_SIZE];
    int i, n, sum=0;
    do{
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);
    } while (n>MAX_SIZE);
    printf("Unesite %d brojeva niza: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        if (i%2!=0)
            sum += arr[i];
    }

    printf("Suma na neparnim %d", sum);

    return 0;
}

//------------------------------------------------------------------------------
/*Napisati funkciju koja ispisuje broj n u obliku potencija broja k, za 2 ≤ k ≤ 16.
Primjer: Za broj n = 200 i k = 8, ispisuje se 200 = 3 * 8**2 + 1 * 8**1.
*/
//------------------------------------------------------------------------------

#include <stdio.h>

int main(void)
{
    int br, k=0;
    printf("Upisite vas broj: \n");
    scanf("%d", &br);
    while (k<2 || k>16)
    {
        printf("Potencija broj k: \n");
        scanf("%d", &k);
    }

    potencija(br, k);
    void potencija(int x, int y);
    return 0;
}

void potencija(int x, int y)
{
    int z=0;
    int q=0;

    while (x>0)
    {
        if (x%y!=0)
            printf(" + %d*%d**%d",x%y, y, z);

        x=x/y;
        z=z+1;
    }
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja računa n-ti član aritmetičkog niza a1, a2, ..., an, sa zadanim
prvim članom a1 i udaljenošću među članovima d.
*/
//------------------------------------------------------------------------------
#include <stdio.h>

int main(void)
{
   int first,d,n,rje;
   printf("Unesite prvi clan niza,udaljenost izmedu clanova te clan do kojeg zelite doc: \n");
   scanf("%d %d %d", &first, &d, &n);
   rje=niz(first,n,d);
   printf("%d-ti clan je: %d",n, rje);



}

int niz(first,n,d)
{
    int rez;
    if (n>0);

        rez=first+(d*(n-1));
    return rez;


}

//------------------------------------------------------------------------------
/*Napisati funkciju koja za neparne vrijednosti argumenta n vraća vrijednost 3 * n
+ 1, a za parne n/2.
*/
//------------------------------------------------------------------------------
int main()
{
    int n,rje;
    printf("Unesite Vas broj; \n");
    scanf("%d",&n);
    rje=oddeven(n);
    printf("Rjesenje je: %d \n", rje);

}

int oddeven(n)
{
    int rez;
    if (n%2==0)
        rez=n/2;
    else if (n%2!=0)
        rez=3*n+1;
    return rez;
}

//------------------------------------------------------------------------------
/*Napisati funkciju koja za uneseni broj n provjerava je li trimorfan, tj. završava li
njegov kub istim znamenkama. Napisati program u kojem korisnik unosi brojeve sve
dok ne unese nulu, te se za uneseni broj poziva funkcija i ispisuje rezultat. Primjer:*/
//------------------------------------------------------------------------------
#include <stdio.h>

int main(void)
{
    int broj=1;
    int kubni,rjesenje,znamenkePrvog;
    while (broj != 0){
        printf("unesi broj: \n");
        scanf("%d",& broj);

        kubni=kub(broj);

        znamenkePrvog=znamenke(broj);

        rjesenje=trimorfan(broj,kubni,znamenkePrvog);

        printf("kub trimorfana je: %d\n",rjesenje);

    }


    return 0;
}


int kub(int a)
{
    return a*a*a;
}
int znamenke(int broj)
{
    int brjc=0;
    while (broj%10!=0) {
            brjc++;
            broj=broj/10;

}
    return brjc;
}

int trimorfan(int q, int w , int e)
{
    int brojac=0;
    int x,y;
    x=q;
    y=w;

    while ((x%10 != 0) || (y%10 != 0)) {
            if ((x%10) == (y%10))
            {
                brojac++;
            }
            x=x/10;
            y=y/10;
    }
    if (brojac == e)
        {
            return w;
        }
    else
        return 0;
}


//------------------------------------------------------------------------------
/*Napisati funkciju koja za prirodni broj n vraća najmanji prost broj koji je veći od n.
Koristiti naredbu break. Posebno napisati funkciju koja provjerava je li broj prost.*/
//------------------------------------------------------------------------------
#include <stdio.h>


int main (void)
{
    int n, k=0;
    printf("Unesite broj\n");
    scanf("%d", &n);
    k=n+1;
    for(;;)
    {
        if (primecheck(k)==0)
            break;
        else
            k++;
    }
    printf("Najblizi prosti broj je %d",k);
    return 0;
}


int primecheck (int n)
{
    int i, num=0;
    for(i=1;i<n;i++)
    {
        if (n%i==0)
            num++;
    }
    if (num>2)
        return 1;
    else
        return 0;

}


//------------------------------------------------------------------------------

/*Napisati funkciju koja računa sumu znamenki broja sve dok ne dođe do broja od jedne
znamenke.*/

//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

    int zbroj(int broj){
    int zadnji = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    while(broj>= 1){
        a = broj % 10;
        zadnji = zadnji + a;
        broj = broj / 10;
    }
    if(zadnji <= 10){
        return zadnji;
    }
    else if(zadnji >= 10){
        while(zadnji >= 10){
            b = zadnji % 10;
            c = c + b;
            zadnji = zadnji / 10;
            return zadnji + c;
        }
    }


    }
int main()
{
    int broj;
    printf("Unesite broj: ");
    scanf("%d",&broj);
    printf("%d",zbroj(broj));
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati program koja za interval [a, b] i cijele brojeve m i n ispisuje ”Fizz” za sve
brojeve izmedju a i b koji su djeljivu sa m, ”Buzz” za sve brojeve djeljive sa n, a
”FizzBuzz” za sve brojeve djeljive i sa m i sa n.*/
//------------------------------------------------------------------------------
#include<stdio.h>
int main(void)
{
    int a,b,m,n,i;

    printf("Unesite interval:");
    scanf("%d %d",&a,&b);

    printf("Unesite brojeve sa sa kojima dijelite m(fizz) i n(buzz)");
    scanf("%d %d",&m,&n);
    for (i=a;i<=b;i=i+1)
    {
        if(i%m==0 && i%n==0)
        {

            printf("\nfizz-buzz");

        }
        else if(i%m==0)
        {
            printf("\nfizz");
        }
        else if(i%n==0)
        {
            printf("\nbuzz");

        }
        else
        {
            printf("\n%d",i);
        }
    }


    return 0;

}
//------------------------------------------------------------------------------
/*Napisati funkciju bitovni zapis nekog broja, pretvara u unsigned broj*/
//------------------------------------------------------------------------------
#include<stdio.h>
#include<math.h>
int funk(char broj[])
{
    int brojac=0;
    int duzina=strlen(broj); // =4
    int suma=0;
    for(int i=duzina-1; i>=0; i--)
    {
        char znak=broj[i];
        if (znak=='1')
        {
            int izracun=pow(2,brojac);

            suma=suma+izracun;
        }


        brojac++;
    }
    return suma;
}





int main()
{

    char prvi[] = "1000000";
    int z;
    z=funk(prvi);
    printf("%d",z);


    return 0;
}

//------------------------------------------------------------------------------
/*Funkcija koja za niz prirodnih brojeva vraca najveci i najmanji prosti broj*/
//------------------------------------------------------------------------------
#include <stdbool.h>
#include <stdio.h>

int maxprime(int* array, int size)
{
  int max=0;
  for(int i=0;i<size;i++){
    bool prime=true;
    int a=array[i];
    for(int j=2;j<a;j++){
      if(a%j==0) {
        prime=false;
        break;
      }
    }
    if (prime) max=a>max?a:max;
  }
  return max;
}
int minprime(int* array, int size)
{
  int min=99999;
  for(int i=0;i<size;i++){
    bool prime=true;
    int a=array[i];
    if(a==1)
    {
        prime=false;

    }
    else
    {
        for(int j=2;j<a;j++){
        if(a%j==0)  {
        prime=false;
        break;
      }
    }
    if (prime)
    {
        if(min>a)
            min=a;
    }
    }

  }
  return min;
}
int main()
{
  int array[] = {4,1,2,3,4,5,6,7,8,9};
  int n;
  n=sizeof(array)/sizeof(array[0]);
  printf("Najveci je %d, najmanji je %d\n", maxprime(array,n),minprime(array,n));

}

//------------------------------------------------------------------------------
/*Okretanje broja*/
//------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
    int broj;
    printf("Unesite broj: \n");
    scanf("%d",&broj);

    while(broj!=1000)
    {
        printf("Okrenuti je %d\n",okretanje(broj));
        printf("Unesite broj: \n");
        scanf("%d",&broj);
    }

}
int okretanje(int n)
{
    int okrenuti = 0, ostatak;
    while (n != 0)
    {
        ostatak = n % 10;
        okrenuti = okrenuti * 10 + ostatak;
        n /= 10;
    }
    return okrenuti;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja za broj n vraca broj nula i broj jedinica u bitovnom zapisu*/
//------------------------------------------------------------------------------
#include <stdio.h>

void pretvordba(int n)
{
    int binarni[32];
    int i = 0;
    int jed=0,nul=0;
    while (n > 0)
    {
        binarni[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if(binarni[j]==1)
            jed++;
        else if(binarni[j]==0)
            nul++;

    }
    printf("Nula je %d a jedinica %d",nul,jed);


}
int main()
{
    int n = 16;

    pretvordba(n);

    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja iz dva stringa koji predstavljaju ime izvodaca i naziv pjesme*/

//------------------------------------------------------------------------------
#include<stdio.h>
#include<string.h>

char* pretvoriPrvoUVelikoOstalaUMalo(char recenica[])
{
    char* novi= malloc(sizeof(char) * strlen(recenica));
    int veliko=1;
    for(int i=0; i<strlen(recenica); i++)
    {
        char znak=recenica[i];
        if(znak==' ')
        {
           veliko = 1;
        } else {

            if(veliko==1)
            {
                znak=toupper(znak);
                veliko=0;
            }
            else
            {
                znak=tolower(znak);
            }

        }

        novi[i]=znak;

    }

    novi[strlen(recenica)] = '\0';
    return novi;

}

char* poplocajSUnderscorom(char recenica[]) {

    char* novi = malloc(sizeof(char) * strlen(recenica) + sizeof(char));
    for(int i=0;i<strlen(recenica);i++)
    {
        char znak=recenica[i];
        if(znak==' ')
        {
            znak='_';
        }
     novi[i]=znak;
    }

    novi[strlen(recenica)] = '\0';


    return novi;
}

char* spojiPjesmuIBend(char recenica1[],char recenica2[])
{
    char* novi=malloc(
        sizeof(char)* strlen(recenica1)+
        sizeof(char)*strlen(recenica2)
                      +sizeof(char)*6
    );
    //"tbf je"  "bomb"

    //"tbf jebomb"

    int brojac_novi=0;
    for(int i=0;i<strlen(recenica1);i++)
    {
        char znak=recenica1[i];
    novi[brojac_novi]=znak;
        brojac_novi++;
    }

    novi[brojac_novi] = '-';
    brojac_novi++;
    for(int i=0;i<strlen(recenica2);i++)
    {
        char znak=recenica2[i];
        novi[brojac_novi]=znak;
        brojac_novi++;
    }

    strcpy(novi + brojac_novi, ".mp3");

    return novi;
}



char* uradiZadatak(char* a, char* b) {

    a = pretvoriPrvoUVelikoOstalaUMalo(a);
    a = poplocajSUnderscorom(a);


    b = pretvoriPrvoUVelikoOstalaUMalo(b);
    b = poplocajSUnderscorom(b);


    char* c = spojiPjesmuIBend(a, b);

    return c;
}

int main()
{
    char* rez =uradiZadatak("TBF je majka", "malo sam maka");


    printf("%s", rez);
    return 0;

}

//------------------------------------------------------------------------------
/*Napisati funkciju koja broji u koliko se koraka od broja n mnozeci znamenke*/

//------------------------------------------------------------------------------
#include<stdio.h>
int mnozenje(int a)
{
    int znam,brojac=0;
    while(a>10)
    {
        int umnozak=1;
        while(a!=0)
        {
            znam=a%10;
            umnozak=umnozak*znam;
            a=a/10;

        }

        a=umnozak;



        brojac++;
    }

    return brojac;
}
int main()
{
    int broj=213;
    int a=mnozenje(broj);
    printf("%d",a);
    return 0;
}
//------------------------------------------------------------------------------
/*Napisati funkciju koja provjerava palindrom*/
//------------------------------------------------------------------------------

int usporedi(char rec[])
{
    /*
    char kopirani[strlen(rec)];
    strcpy(kopirani,rec);
    strrev(kopirani);
    //printf("%s",rec);
    //printf("%s",kopirani);
    for(int i=0;i<strlen(rec);i++)
    {
        char znak1 =kopirani[i];
        char znak2 =rec[i];
        if(znak1!=znak2)
            return 0;

    }*/



    for(int i=0,j=strlen(rec) - 1; i<strlen(rec); i++,j--) {
        char znak1 = rec[i];
        char znak2 = rec[j];
        if(znak1!=znak2)
            return 0;
    }

    return 1;
}



int main()
{
    char prvi[]="mama";
    int a=usporedi(prvi);
    if(a==1)
        printf("DA");
    else
        printf("NE");
    return 0;

}
