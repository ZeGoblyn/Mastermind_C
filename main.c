#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void generCode(int x[4]);
void test(int joueur[4]);
void chek(int x[4], int joueur[4]);

int main()
{
    srand(time(NULL));      //Permet de générer des nombres aléatoires
    int x[4];
    int joueur[4];
    int r;

    generCode(x);

    for(r=0;r<12;r++)       //Détermine le nombre de tentatives possibles
    {
        test(joueur);

        //system("cls");

        chek(x, joueur);

    }


    return 0;
}

void generCode(int x[4])
{
    int i, z, rep;


    for(i=0; i<4;i++)           //génération des nombres aléatoires dans le tableau
    {
        do
        {
            x[i]=rand()%10;

            rep=0;

            for(z=0; z<i;z++)
            {
                if(x[z]==x[i])
                {
                    rep=1;
                }
            }

        }while(rep==1);

        printf("%d\n",x[i]);

    }
}

void test(int joueur[4])
{

    int j;

    for(j=0; j<4;j++)           //Demande au joueur de remplir son tableau
    {
        printf("Indiquez quatres valeures");
        scanf("%d", &joueur[j]);
    }
}

void chek(int x[4], int joueur[4])
{
    int v,m, r, b, count;

    count=0;

        for(v=0;v<4;v++)                    //Vérification des valeures
            {
                for(m=0;m<4;m++)
                    {
                    if(x[m]==joueur[v])
                        {
                            if(v==m)
                            {
                                printf("La %d e valeur donnee est correcte et bien placer !\n", v+1);
                            }else{
                                printf("La %d e valeur donnee est correcte mais mal placer \n", v+1);
                            }

                        }

                    for(r=0;r<4;r++)
                        {
                            if(x[r]==joueur[r])         //Tentative de vérification des tableau pour insérer un message de victoire
                            {
                                count++;
                            }

                            /*if (count==4)
                            {
                                printf("VOUS AVEZ TROUVE LE CODE");
                            }*/
                        }


                    }



            }


}

