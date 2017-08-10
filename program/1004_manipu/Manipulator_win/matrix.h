/*** for matrix calculation ***/
/*** definition ***/
#define	MATRIX_ERROR0	1
#define MATRIX_OK	0
#define	PRECISION_FOR_INVERSE_MATRIX 0.0000001
#define EVEN 0
#define ODD 1
#define INFINITESIMAL_THRESHOLD 0.000001

/*** struct definition ***/
struct	matrix{
	int	row, column;
        double	**data;
};

/*** function definitions ***/
int	matrix_alloc( struct matrix *, int, int );	/* argments: data, row number and column number */
int	matrix_free( struct matrix );
int	matrix_addition( struct matrix *a, struct matrix b, struct matrix c );  /* [*a] = [b] + [c] */
int	matrix_subtraction( struct matrix *a, struct matrix b, struct matrix c );  /* [*a] = [b] - [c] */
int	matrix_multiplication( struct matrix *a, struct matrix b, struct matrix c );  /* [*a] = [b]*[c] */
int	matrix_multiplication_mv( double *y, struct matrix A, double *c );

/*** functions ***/
int	matrix_alloc( struct matrix *mat, int a, int b )
{
	int	i;

        mat->row = a;
        mat->column = b;

	mat->data = (double **)malloc( sizeof(double *) * a );
        for( i=0; i<a; i++ )
              mat->data[i] = (double *)malloc( sizeof( double ) * b );

        return 0;
}

int	matrix_free( struct matrix mat )
{
        int	i;

        for( i=0; i<mat.row; i++ )	free( mat.data[i] );
        free( mat.data );

        return 0;
}

int	matrix_addition( struct matrix *a, struct matrix b, struct matrix c )
{
	int	i, j;

        if( ( a->row != b.row ) || ( a->column != b.column )
         || ( b.row != c.row ) || ( b.column != c.column ) ){
         	printf("matrix addition error \n");
        	return( MATRIX_ERROR0 );
        }else{
        	for( i=0; i<b.row; i++ ){
                	for( j=0; j<b.column; j++ ){
                        	a->data[i][j] = b.data[i][j] + c.data[i][j];
                        }
                }
                return( MATRIX_OK );
        }
}

int	matrix_copy( struct matrix *a, struct matrix b )
{
	int	i, j;

        if( ( a->row != b.row ) || ( a->column != b.column ) ){
         	printf("matrix copy error \n");
        	return( MATRIX_ERROR0 );
        }else{
        	for( i=0; i<b.row; i++ ){
                	for( j=0; j<b.column; j++ ){
                        	a->data[i][j] = b.data[i][j];
                        }
                }
                return( MATRIX_OK );
        }
}

int	matrix_subtraction( struct matrix *a, struct matrix b, struct matrix c )
{
	int	i, j;

        if( ( a->row != b.row ) || ( a->column != b.column )
         || ( b.row != c.row ) || ( b.column != c.column ) ){
         	printf("matrix subtraction error \n");
        	return( MATRIX_ERROR0 );
        }else{
        	for( i=0; i<b.row; i++ ){
                	for( j=0; j<b.column; j++ ){
                        	a->data[i][j] = b.data[i][j] - c.data[i][j];
                        }
                }
                return( MATRIX_OK );
        }
}

int	matrix_multiplication( struct matrix *a, struct matrix b, struct matrix c )
{
	int	i, j, k;

        if( ( a->row != b.row ) || ( a->column != c.column ) || ( b.column != c.row ) ){
         	printf("matrix multiplication error \n");
        	return( MATRIX_ERROR0 );
        }else{
            for( i=0; i<b.row; i++ ){
               	for( j=0; j<b.column; j++ ){
                    a->data[i][j] = 0.0;
                    for( k=0; k<b.column; k++ )
                            a->data[i][j] += ( b.data[i][k] * c.data[k][j] );
                }
            }
            return( MATRIX_OK );
        }
}

int     matrix_initialization( struct matrix A, double val )
{
        int     i, j;

        for( i=0; i<A.row; i++ )
                for( j=0; j<A.column; j++ )
                        A.data[i][j] = val;

        return( 0 );
}

int     vector_initialization( double *A, int num, double val )
{
        int     i;

        for( i=0; i<num; i++ )  A[i] = val;

        return( 0 );
}

int	matrix_multiplication_mv( double *y, struct matrix A, double *c )
{
	int	i, j;

        for( i=0; i<A.row; i++ ){
                y[i] = 0.0;
                for( j=0; j<A.column; j++ ) y[i] += A.data[i][j] * c[j];
        }
        
        return( MATRIX_OK );
}

int	matrix_print( struct matrix a )
{
	int	i, j;

        for( i=0; i<a.row; i++ ){
		for( j=0; j<a.column; j++ ){
                	//printf("%5.3e ", a.data[i][j] );
                        printf("%4.2lf ", a.data[i][j] );
                }
                printf("\n");
        }

        return 0;
}

int	vector_print( double *a, int num )
{
	int	i;

        for( i=0; i<num; i++ ) printf("%8.4lf  ", a[i] );

        return 0;
}

int	matrix_inverse_precise( struct matrix *inv_a )
{
        int	i, j, k, max_num;
        double	pivot, max_val;
        struct	matrix b;

        matrix_alloc( &b, inv_a->row, inv_a->column );
        matrix_copy( &b, *inv_a );

        for( i=0; i<inv_a->row; i++ ){
            for( j=0; j<inv_a->column; j++ ){
               	/*** unit matrix ***/
               	if( i == j )	inv_a->data[i][j] = 1.0;
                else            inv_a->data[i][j] = 0.0;
            }
        }

        for( i=0; i<b.row; i++ ){
            /*** compute max value among i column ***/
            for( max_num=i, max_val=fabs(b.data[i][i]), k=i+1; k<b.row; k++ ){
                if( max_val < fabs( b.data[k][i] ) ){
                    max_num = k;
                    max_val = fabs( b.data[k][i] );
                }
            }
            if( max_val < INFINITESIMAL_THRESHOLD ){
                printf("  Warning01: sweeping out %d/%d \n", i, b.row );    getchar();
                exit(1);
            }
            if( max_num != i ){
               	for( j=i; j<b.column; j++ ){
              		pivot = b.data[i][j];
                        b.data[i][j] = b.data[max_num][j];
                        b.data[max_num][j] = pivot;
                }
                for( j=0; j<b.column; j++ ){
                       	pivot = inv_a->data[i][j];
                        inv_a->data[i][j] = inv_a->data[max_num][j];
                        inv_a->data[max_num][j] = pivot;
                }
            }
            /*** sweep out ***/
            pivot = b.data[i][i];
            for( j=i; j<b.column; j++ )	b.data[i][j] /= pivot;
            for( j=0; j<b.column; j++ ) inv_a->data[i][j] /= pivot;
            for( k=0; k<b.row; k++ ){
              	if( i != k ){
                    pivot = b.data[k][i];
                    for( j=i; j<b.column; j++ )
                            b.data[k][j] -= ( b.data[i][j] * pivot );
                    for( j=0; j<b.column; j++ )
                            inv_a->data[k][j] -= ( inv_a->data[i][j] * pivot );
                }
            }
        }

	matrix_free( b );

        return 0;
}