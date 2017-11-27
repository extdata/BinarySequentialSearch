#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;

void bubblesort( vector< int > & );
void fillvector( vector< int > & );
void printvector( vector< int > & );
int binarysearch( vector< int > &, int &, int &, int &, int & );
int sequentialsearch( vector< int > &, int & );
bool change( int &, int & );
bool change( double &, double & );


int main()
{
	srand( ( int ) time( 0 ) );
	int size = 30;
	int count = 0;
	int first, last, middle, search;
	
	cout << "Programa para encontrar um valor em um vetor!\n";
	cout << "O vetor ser" << char(160) << " preenchido com valores aleat" << char(162) << "rios variando de 1 a 100!\n";
	cout << "O vetor ter" << char(160) << " um tamanho fixo de 30 posi" << char(135) << char(228) <<"es!\n";
	cout << "O valor pesquisado ser" << char(160) << " aleat" << char(162) << "rio dentre os valores gerados!\n";
	cout << "Ser" << char(160) << " mostrado quantos passos foram necess" << char(160) << "rios para encontrar o valor!\n";
	
	vector< int > array( size );
	
	int i;
	double meanbinary, meansequential;
	double sumbinary = 0.0;
	double sumsequential = 0.0;
	const int NITER = 10;
	int nstepbinary;
	int nstepsequential;
	
	for (i = 0; i < NITER; i++ )
	{
		fillvector( array );
		
		bubblesort( array );
		
		printvector( array );
		
		search = array[ rand() % 30 ];
		
		cout << "\nValor que ser" << char(160) << " pesquisado: " << search;
	
		nstepbinary = binarysearch( array, first, last, middle, search  );
		
		nstepsequential = sequentialsearch( array, search  );
		
		cout << "\nN" << char(163) << "mero de passos pela pesquisa bin" << char(160) << "ria: " << nstepbinary;
		
		cout << "\nN" << char(163) << "mero de passos pela pesquisa sequencial: " << nstepsequential;
		
		sumbinary += nstepbinary;
		
		sumsequential += nstepsequential + 1;
	}
		
	meanbinary =  sumbinary / NITER;
	
	meansequential = sumsequential / NITER;
	
	cout << "\n\nA m" << char(130) << "dia de itera" << char(135) << char(228) <<"es pela pesquisa bin" << char(160) << "ria " << char(130) << ": " << meanbinary << '\n';
	
	cout << "\nA m" << char(130) << "dia de itera" << char(135) << char(228) <<"es pela pesquisa sequencial " << char(130) << ": " << meansequential << '\n';
}

void fillvector( vector< int > & array )
{
	for ( int i = 0; i < array.size(); i++ )
		array[i] = rand() % 100 + 1;
}

void bubblesort( vector< int > & array )
{	
	for ( int i = 0; i < array.size() - 1; i++ )
		for ( int j = 0; j < array.size() - 1; j++ )
			if ( change( array[j], array[j+1] ) );
}

void printvector( vector< int > & array )
{
	cout << "\n\nValores ordenados: ";
	for ( int j = 0; j < array.size(); j++ )
		cout << array[j] << " ";
}

int binarysearch( vector< int > &array, int & first, int & last, int & middle, int & search )
{
	first = 0;
	last = array.size() - 1;
	middle = ( first + last ) / 2;
	int counttwo = 0;
	
	while ( first <= last )
	{
		counttwo++;
		
		if ( array[middle] < search )
		{
			first = middle + 1;
		}
		else if ( array[middle] == search )
		{
			cout << "\nValor " << search << " encontrado na posi" << char(135) << char(198) << "o " << middle+1 << " do vetor";
			break; 
		}
		else
		{
			last = middle - 1;
		}
		middle = ( first + last ) / 2;
	}
	if ( first > last )
	{
		cout << "\nValor " << search << " n" << char(198) << "o encontrado no vetor!";
	}
	return counttwo;
}

int sequentialsearch ( vector< int > & array, int & search )
{
	int i;
	for ( i = 0; i < array.size(); i++ )
		if ( search == array[i] )
		   return i;
}

bool change( int &a, int &b )
{
	int temp;
	if ( a > b )
	{
		temp = a;
		a = b;
		b = temp;
		
		return true;
	}
	else return false;
}

bool change( double &a, double &b )
{
	double temp;
	if ( a > b )
	{
		temp = a;
		a = b;
		b = temp;
		
		return true;
	}
	else return false;
}