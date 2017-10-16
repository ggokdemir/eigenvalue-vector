
//gurkan gokdemir

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "eispack.h"

int main ( );
void cark ( );
void ozdeger ( );
void ozvektor ( );
void schur ( );
void nilpotent ( );
/******************************************************************************/

int main ()

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for Prolab1.

  Discussion:

    Prolab calls the <cark> function to choose number and another function.

  Modified:

    30 September 2017

  Author:

    gurkan
*/
{
    timestamp ( );
    srand(time(NULL));


    printf ( "* \n" );
    printf ( "* Prolab 1\n" );
    printf ( "*   by gurkan.\n" );
    printf ( "*   with the EISPACK library.\n" );

    printf ( "* \n" );
    printf ( "* Prolab1\n" );
    printf ( "*   Normal end of execution.\n" );

    printf ( "* \n" );
    timestamp ( );
    printf("********************************************************************************\n");
    printf("* Cark is spining... There are 241 posible positive numbers in the cark.\n");
    cark();

    printf("***********************************************************************gurkan********\n");
    return 0;
}
/******************************************************************************/


void cark()
/******************************************************************************/
/*
  Purpose:

    choose an random operation

  Modified:

    30 September 2017

  Author:

    gurkan
*/
{
    int num,r;
    printf("* Please insert a number to stop the cark:  \n");
    printf("* ");
    scanf("%d",&num);
    printf("* Now %d number generating for you from the cark. \n", num);
    FILE *f = fopen("cark.txt", "w");
    for (int i = 0 ; i < num; i++)
    {
        r = rand() % 241;

        if (f == NULL)
        {
            printf("* Error opening file!\n");
            exit(1);
        }

        fprintf(f,"* %d. number that generated = %d \n",i+1,r);



        printf("* %d. number that generated = %d \n",i+1,r);
    }
    fclose(f);
    printf("* I will choose your process... \n");

    //ozdeger();
    //ozvektor();
    //schur();
    //nilpotent();
    switch(r%4+1)
    {
    case 1:
        printf("\n *** Ozdeger has been choosen randomly \n");
        ozdeger();
        break;
    case 2:
        printf("\n *** Schur theorem has been choosen randomly \n");
        schur();
        break;
    case 3:
        printf("\n *** Ozvektor has been choosen randomly \n");
        ozvektor();
        break;
    case 4:
        printf("\n *** Nilpotent has been choosen randomly \n");
        nilpotent();
        break;
    }
}


void ozdeger( )

/******************************************************************************/
/*
  Purpose:

    calculating ozdeger

  Modified:

    2 October 2017

  Author:

    gurkan
*/
{
    int m_num;//n of the matrix
    printf("* -> Ozdeger process is using. \n");
    printf("* How many colums and rows do you want in your square matrix ? :");
    scanf("%d",&m_num);
    double matrix[m_num*m_num];

    for (int n = 0; n < m_num*m_num; n++)
    {
        printf("* %d th variable in the matrix = ",n+1);
        scanf("%lf",&matrix[n]);
    }

    double matrix2[m_num*m_num]; //to save copy of the matrix
    int i; //counter
    int ierr; //returns error flag
    int j; //counter
    int matz;  //error check
    double *r;  //eigenvector
    double w[m_num]; //eigenvalues lambda
    double x[m_num*m_num];  //eigenvector matrix
    /*
      Save a copy of the matrix.
    */
    for ( j = 0; j < m_num; j++ )
    {
        for ( i = 0; i < m_num; i++ )
        {
            matrix2[i+j*m_num] = matrix[i+j*m_num];
        }
    }
    printf ( "* \n" );
    printf ( "* calculating ozdeger\n" );
    printf ( "*  RS computes the ozdeger\n" );
    printf ( "*  of a real symmetric matrix.\n" );
    printf ( "* \n" );
    printf ( "*  Matrix order = %d\n", m_num );

    r8mat_print ( m_num, m_num, matrix, "*  The matrix:" );

    matz = 1;

    ierr = rs ( m_num, matrix, w, matz, x );

    if ( ierr != 0 )
    {
        printf ( "* \n" );
        printf ( "* Ozdeger Warning!\n" );
        printf ( "*   The error return flag IERR = %d\n", ierr );
        return;
    }

    r8vec_print ( m_num, w, "*   The ozdeger Lambda:" );

    printf ( "* \n" );

    FILE *f = fopen("ozdeger.txt", "w");
    if (f == NULL)
    {
        printf("* Error opening file!\n");
        exit(1);
    }
    for (int i = 0 ; i < m_num; i++)
    {
        fprintf(f,"\n*  ozdeger[%d] = %lf",i,w[i]);
    }

    fclose(f);

    return;
}

void ozvektor( )

/******************************************************************************/
/*
  Purpose:

    calculating ozvektor

  Modified:

    2 October 2017

  Author:

    gurkan
*/
{
    int m_num;//n of the matrix
    printf("* -> Ozvektor process is using. \n");
    printf("* How many colums and rows do you want in your square matrix ? :");
    scanf("%d",&m_num);
    double matrix[m_num*m_num];

    for (int n = 0; n < m_num*m_num; n++)
    {
        printf("* %d th variable in the matrix = ",n+1);
        scanf("%lf",&matrix[n]);
    }

    double matrix2[m_num*m_num]; //to save copy of the matrix
    int i; //counter
    int ierr; //returns error flag
    int j; //counter
    int matz;  //error check
    double *r;  //eigenvector
    double w[m_num]; //eigenvalues lambda
    double x[m_num*m_num];  //eigenvector matrix
    /*
      Save a copy of the matrix.
    */
    for ( j = 0; j < m_num; j++ )
    {
        for ( i = 0; i < m_num; i++ )
        {
            matrix2[i+j*m_num] = matrix[i+j*m_num];
        }
    }
    printf ( "* \n" );
    printf ( "* calculating ozvektor\n" );
    printf ( "*   RS computes the ozvektor\n" );
    printf ( "*   of a real symmetric matrix.\n" );
    printf ( "* \n" );
    printf ( "*   Matrix order = %d\n", m_num );

    r8mat_print ( m_num, m_num, matrix, "*  The matrix:" );

    matz = 1;

    ierr = rs ( m_num, matrix, w, matz, x );

    if ( ierr != 0 )
    {
        printf ( "* \n" );
        printf ( "* Ozvektor Warning!\n" );
        printf ( "*   The error return flag IERR = %d\n", ierr );
        return;
    }

    //r8vec_print ( m_num, w, "*   The ozdeger Lambda:" );

    printf ( "* \n" );
    if ( matz != 0 )
    {
        printf ( "* \n" );
        r8mat_print ( m_num, m_num, x, "*   The ozvektor matrix:" );
        printf ( "* \n" );

        FILE *f = fopen("ozvektor.txt", "w");
        if (f == NULL)
        {
            printf("* Error opening file!\n");
            exit(1);
        }

        for (int i = 0 ; i < m_num*m_num; i++)
        {
        fprintf(f,"\n*  ozvektor[%d] = %lf",i,x[i]);
        }

        printf ( "* \n" );

        fclose(f);

    }

    free ( r );

    return;
}

void schur( )

/******************************************************************************/
/*
  Purpose:

    calculating schur theorem

  Modified:

    9 October 2017

  Author:

    gurkan
*/
{
    int m_num;//n of the matrix
    printf("* -> Schur theorem process is using. \n");
    printf("* How many colums and rows do you want in your square matrix ? :");
    scanf("%d",&m_num);
    double matrix[m_num*m_num];

    for (int n = 0; n < m_num*m_num; n++)
    {
        printf("* %d th variable in the matrix = ",n+1);
        scanf("%lf",&matrix[n]);
    }

    double matrix2[m_num*m_num]; //to save copy of the matrix
    int i; //counter
    int ierr; //returns error flag
    int j; //counter
    int matz;  //error check
    double *r;  //eigenvector
    double w[m_num]; //eigenvalues lambda
    double x[m_num*m_num];  //eigenvector matrix
    /*
      Save a copy of the matrix.
    */
    for ( j = 0; j < m_num; j++ )
    {
        for ( i = 0; i < m_num; i++ )
        {
            matrix2[i+j*m_num] = matrix[i+j*m_num];
        }
    }
    printf ( "* \n" );
    printf ( "* calculating schur theorem\n" );
    printf ( "*  computes the schur theorem\n" );
    printf ( "*  of a real symmetric matrix.\n" );
    printf ( "* \n" );
    printf ( "*  Matrix order = %d\n", m_num );

    r8mat_print ( m_num, m_num, matrix, "*  The matrix:" );

    matz = 1;

    ierr = rs ( m_num, matrix, w, matz, x );

    if ( ierr != 0 )
    {
        printf ( "* \n" );
        printf ( "* Schur theorem Warning!\n" );
        printf ( "*   The error return flag IERR = %d\n", ierr );
        return;
    }

    r8vec_print ( m_num, w, "*   Ozdeger Lambda:" );

    double var1=0;
    double var2=0;

    for (int i = 0 ; i < m_num; i++)
    {

        var1 = (w[i] * w[i]) + var1;
        printf("\n* %d. step %lf",i+1,var1);
    }
    printf("\n*");

    for (int n = 0; n < m_num*m_num; n++)
    {

        var2 = (matrix[n] * matrix[n]) + var2;
        printf("\n* %d. step %lf",n+1,var2);
    }
    printf("\n* Schur theorem is: \n");
    printf("*\n");
    printf("* %lf <= %lf" ,var1,var2);
    printf("\n*");

    FILE *f = fopen("schur.txt", "w");
    if (f == NULL)
    {
        printf("* Error opening file!\n");
        exit(1);
    }
    for (int i = 0 ; i < m_num; i++)
    {
        fprintf(f,"\n* Schur theorem is: = %lf <= %lf",var1,var2);
    }

    fclose(f);

    return;
}

void nilpotent( )

/******************************************************************************/
/*
  Purpose:

    checking nilpotent matrix.

  Modified:

    1 October 2017

  Author:

    gurkan
*/
{

    printf ( "* \n" );
    printf ( "* nilpotent\n" );
    printf ( "*   checking random nilpotent matrix. \n" );
    printf ( "*   of a real symmetric matrix.\n" );
    printf ( "* \n" );
    int m_num;
    printf("* ->  Nilpotent process is using. \n");
    printf("* How many colums and rows do you want in your square matrix ? :");
    scanf("%d",&m_num);
    printf ( "*\n" );
    double matrix[m_num][m_num];
    double nilpotent[m_num][m_num];


    for (int i = 0 ; i < m_num; i++)
    {
        for (int j = 0 ; j < m_num; j++)
        {
            double randomNum = rand() % 25 + (-15);
            matrix[i][j]=randomNum;
            printf("*  matrix[%d][%d] = %lf",i,j,matrix[i][j]);

        }
        printf("\n*");
    }
    printf("\n*");

    for (int i = 0 ; i < m_num; i++)
    {
        for (int j = 0 ; j < m_num; j++)
        {
            for (int k = 0 ; k < m_num; k++)
            {
                nilpotent[i][j] = matrix[i][k]*matrix[k][j] + nilpotent[i][j];
            }
        }
    }
    printf ( "* \n" );
    printf("*  square of the matrix = ");
    printf ( " \n*" );
    for (int i = 0 ; i < m_num; i++)
    {
        printf("\n");
        for (int j = 0 ; j < m_num; j++)
        {
            printf("*  nilpotent[%d][%d] = %lf",i,j,nilpotent[i][j]);
        }
}
    printf("*\n");
    printf ("*\n");

    for (int a=0 ; a<m_num ; a++)
    {
        for(int b = 0; b<m_num; b++)
        {
            if (nilpotent[a][b] != 0)
            {
                printf("*  Its not nilpotent \n");
                break;
            }
        }
    }

    printf ( "* \n" );

    FILE *f = fopen("nilpotent.txt", "w");

    printf ( "* \n" );

    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0 ; i < m_num; i++)
    {
        for (int j = 0 ; j < m_num; j++)
        {
            fprintf(f,"\n*  nilpotent[%d][%d] = %lf",i,j,nilpotent[i][j]);
        }
    }

    printf ( "* \n" );

    fclose(f);

    return;
}
