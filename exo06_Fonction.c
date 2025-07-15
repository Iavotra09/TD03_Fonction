#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int prendre_mot(char mot_palindrome[]);
void verification_palindrome(int taille, char mot_palindrome[]);

int main()
{
    int N;
    char mot[51];
    N=prendre_mot(mot);
    verification_palindrome(N, mot);
    return(0);    
}

int prendre_mot(char mot_palindrome[])
{
    int taille, tnt=0;   
    printf("Savoir si une chaîne de caractères est un palindrome ou non: \n");
    do
    {
        printf("Entrez le mot: ");
        scanf("%s", mot_palindrome);
        
        taille=strlen(mot_palindrome);
        if(taille>=50)
        {
            printf("Entrez un mot ayant au plus 50 caractères!\n");
            tnt++;
        }
        if(tnt==3 && taille>=50)
        {
            printf("Trop de tentatives!\n");
            exit(0);
        }
    }while(taille>=50);
    return taille;
}

void verification_palindrome(int taille, char mot_palindrome[])
{
    int i, compt=0;
    for(i=0; i<taille/2; i++)
    {
        if(mot_palindrome[i]!=mot_palindrome[taille-1-i]) //comparer le premier caractère avec le dernier, le deuxième avec le dernier,... si il rencontre un qui n'est pas identique à son image, il arrête la boucle pour dire que ce n'est pas un palindrome
        {
            printf("Le mot \"%s\" n'est pas un palindrome.\n", mot_palindrome); 
            break;
        }
        else
        {
            compt++;
        }
    }
    if(compt==taille/2)
    {
        printf("Le mot \"%s\" est un palindrome.\n", mot_palindrome); //si jusqu'à N/2, les caractères sont tous identiques à leurs images, c'est un palindrome
    }
}