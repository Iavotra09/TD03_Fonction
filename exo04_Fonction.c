#include<stdio.h>
#include<stdlib.h>

int taille_tableau(char nom_tableau);
void elements_tableau(int taille, int tableau[], char nom_tableau);
void affichage(int taille, int tableau[], char nom_tableau);
int verification_T1_T2(int taille1, int taille2, int tab1[], int tab2[]);

int main()
{
    int x, y;
    int T1[100], T2[50];
    x=taille_tableau("T1");
    elements_tableau(x, T1, "T1");
    y=taille_tableau(T2);
    elements_tableau(y, T2, "T2");
    affichage(x, T1, "T1");
    affichage(y, T2, "T2");
    x=verification_T1_T2(x, y, T1, T2);
    affichage(x, T1, "T1");
    return(0);
}

int taille_tableau(char nom_tableau)
{
    int r, taille, tnt=0;
    printf("Vérifions si des éléments de T2 existent dans T1 et supprimons ces éléments de T1 si ils existent:\n");
    do
    {
        printf("Entrez la dimension de %c: ", nom_tableau);
        r=scanf("%d", &taille);

        if(r!=0)
        {
            while(getchar()!='\n');
        }
        if(r!=1 || taille<1 || taille>100)
        {
            printf("La dimension doit être entre 1 et 100!\n");
            tnt++;
        }
        if(tnt==3 && (r!=1 || taille<1 || taille>100))
        {
            printf("Trop de tentatives!\n\n");
            exit(0);
        }
    }
    while(r!=1 || taille<1 || taille>100);
    return taille;
}

void elements_tableau(int taille, int tableau[], char nom_tableau)
{
    int i;
    printf("Veuillez entrer les éléments de %s:\n", nom_tableau);
    for(i=0; i<taille; i++)
    {
        printf("%s[%d]=", nom_tableau, i);
        scanf("%d", &tableau[i]);
    }
    printf("\n");
}

void affichage(int taille, int tableau[], char nom_tableau)
{
    printf("%c: ", nom_tableau);
    for(i=0; i<taille; i++)
    {
        printf("%d  ", tableau[i]);
    }
    printf("\n");
}

int verification_T1_T2(int taille1, int taille2, int tab1[], int tab2[])
{
    int i, j, m=0, compt=0,
    for(i=0; i<taille1; i++)
    {
        if(tab1[i]==tab2[0])
        {
            if((i+taille2)<=taille1)
            {
                for(j=i; j<taille2+i; j++)
                {
                    if(tab1[j]==tab2[k])
                    {
                        compt++;
                        k++;
                    }
                    if(compt==taille2)
                    {
                        for(m=i; m<taille1-taille2; m++)
                        {
                            tab1[m]=tab1[m+taille2];
                        }
                        taille1=taille1-taille2;
                    }

                }
            }
        }
        k=0;
        
    }
    printf("Après l'analyse des éléments de T1 et T2:\nT1: ");
    return taille1;
}

