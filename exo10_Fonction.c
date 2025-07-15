#include<stdio.h>
#include<string.h>

int entrer_phrase(char tableau[]);
void cryptage(int taille, char tableau[]);
void phrase_crypte(int taille, char tableau[]);

int main()
{
    int N=0, i, j, k,l;
    char phrase[1000];
    N=entrer_phrase(phrase);
    cryptage(N, phrase);
    phrase_crypte(N, phrase);
    return(0);
}

int entrer_phrase(char tableau[])
{
    int i, taille;
    printf("Cryptage:\n");
    printf("Phrase en français: ");
    for(i=0; i<1000; i++)
    {
        scanf("%c", &tableau[i]);
        taille++;    
        if(tableau[i]=='\n')
        {
            tableau[i]='\0';
            break;
        }
    }
    return taille;
}

void cryptage(int taille, char tableau[])
{
    int i, j, k, l;
    char voyelle[]={'a','e','u','i','o','y','A','E','U','I','O','Y'};
    char consonne[]={' ','b','c','d','f','g','h','j','k','l','m','n','p', 'q','r','s','t','v','w','x','z','B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
    
    for(i=0; i<taille; i++)  //analyser chaque lettre
    {
        for(j=0; j<40; j++)  //analyser si la lettre appartient à consonne
        {
            for(k=0; k<12; k++)  //analyser si la lettre qui la suit appartient à voyelle
            {
                if(tableau[i]==consonne[j] && tableau[i+1]==voyelle[k])
                {
                    taille=taille+2;
                    for(l=taille-1; l>=i+2; l--)
                    {
                        tableau[l]=tableau[l-2];
                    }
                    tableau[i+1]='I';
                    tableau[i+2]='T';
                    i=i+3;
                }
            }
        } 
    }
}

void phrase_crypte(int taille, char tableau[])
{
    int i;
    printf("Phrase cryptée: ");
    for(i=0; i<taille; i++)
    {
        printf("%c", tableau[i]);
    }
    printf("\n");
}