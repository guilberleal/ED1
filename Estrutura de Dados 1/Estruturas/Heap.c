
#include<stdio.h>
#include<stdlib.h>
#define N 10


int filhoesq ( int i ) {
	int fe;
	fe = (i*2)+1;
	return fe;
}

int filhodir ( int i ) {
	int fd;
	fd = (i*2)+2;
	return fd;
}

int epai ( int i ) {
	int pai;
	pai = ((i-1)/2);
	return pai;
}

void verificaHeap ( int heap[], int i ) {
	int pai, aux;
	while ( i!=0 ) {
		pai=epai ( i );
		if ( heap[i] > heap[pai] ) {
			aux = heap[i];
			heap[i] = heap[pai];
			heap[pai]=aux;

		}
		i = pai;
	}

}

void heapSort ( int heap[], int n )
{
    int i, filho, pai, valor;
    for ( i = n - 1 ; i > 0 ; i-- )
    {
        valor = heap[i] ;
        heap[i] = heap[0] ;
        pai = 0 ;
        if ( i == 1 )
            filho = -1 ;
        else
            filho = 1 ;
        if ( i > 2 && heap[2] > heap[1] )
            filho = 2 ;
        while ( filho >= 0 && valor < heap[filho] )
        {
            heap[pai] = heap[filho] ;
            pai = filho ;
            filho = 2 * pai + 1 ;
            if ( filho + 1 <= i - 1 && heap[filho] < heap[filho + 1] )
                filho++ ;
            if ( filho > i - 1 )
                filho = -1 ;
        }
        heap[pai] = valor ;
    }
}

void printing ( int *heap, int j ) {
	int i;
	for ( i=0; i<=j; i++ ) {
		printf ( "[%d]", heap[i] );
	}
	printf ( "\n\n" );
}

int main ( int argc, char *argv[] ) {
	int heap[N];
	int i;

	for ( i=0; i<N; i++ ) {
		scanf ( "%d", &heap[i] );
		verificaHeap ( heap, i );
		printing ( heap, i );
	}

	heapSort ( heap, i );
    printing ( heap, N );

	return 0;
}
