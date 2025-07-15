#include<stdio.h>
#include<string.h>

int prendre_phrase(char sentence[]);
void decryptage(int nbr_caracteres, char sentence[]);
void affichage(int nbr_caracteres, char sentence[]);

int main()
{
    int N;
    char phrase[1000];
    N=prendre_phrase(phrase);
    decryptage(N, phrase);
    affichage(N, phrase);
    return(0);
}

int prendre_phrase(char sentence[])
{
    int nbr_caracteres;
    printf("Décryptage:\n");
    printf("Phrase cryptée: ");
    fgets(sentence, nbr_caracteres, stdin);
    nbr_caracteres=strlen(sentence);
    return nbr_caracteres;
}

void decryptage(int nbr_caracteres, char sentence[])
{
    int i, j;
    for(i=0; i<nbr_caracteres; i++)  //analyser chaque lettre
    {
        if(sentence[i]=='I' && sentence[i+1]=='T')
        {
            nbr_caracteres=nbr_caracteres-2;
            for(j=i; j<nbr_caracteres; j++)
            {
                sentence[j]=sentence[j+2];
            }
        }
    }
}

void affichage(int nbr_caracteres, char sentence[])
{
    int i;
    printf("Phrase en français: ");
    for(i=0; i<nbr_caracteres; i++)
    {
        printf("%c", sentence[i]);
    }
    printf("\n");
}