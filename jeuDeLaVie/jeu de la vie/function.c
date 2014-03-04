#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define maxY 5
#define maxX 5


void affMat(int **tab)//affichage de la matrice
{
int i, j;

for (i=0; i<maxX; i++)
    {
     for (j=0; j<maxY; j++)
          printf("%d", tab[i][j]);
     printf("\n");
    }
}

int   **initMat() //allocation de la matrice
{
   int i,j;
   
   int   **tab;
   
    tab = (int**)malloc(sizeof(int*) * maxX);

        for(i=0 ; i<maxX ; i++)
            tab[i] = (int*)calloc(maxY, sizeof(int));
   
   return (tab);
}

//tableau d'origine de 0 et 1
int   **CreerpremierTableau()
{
   int   i,j;
   int   **tab;
   
   tab = initMat();  
   
   for (i =0;i< maxX;i++)
   {
      for (j=0;j<maxY;j++)
         tab[i][j] = rand()%2;
   }
   
   return(tab);

}

int CompterVoisin(int colonne, int ligne, int **matrice)
{
   int i,j,compte;
   
     
    for (i=ligne-1;i<ligne+1;i++)
      for(j=colonne-1;j<colonne+1;j++)
        if ((i>0) && (i<maxX) && (j>0) && (j<maxY))
            if (matrice[i][j] == 1)
               compte++;
               
       return compte;
   
}



void  evolutionGrille(int c, int l,int **tab)
{
   int   cpt;
   
   cpt = 0;
   
   cpt = CompterVoisin(c,l, tab);
     
 
  //printf("compteur %d\n", cpt);
 
         if (tab[c-1][l-1] ==0) //si la cellule est morte  
            {
            printf("la2\n");
            printf("  \n");
            printf("%d, %d\n", c,l);
               if (cpt == 3) // si elle a 3 voisins
                  tab[c-1][l-1] = 9; //dead = alive
               else
                  tab[c-1][l-1] = 2; // dead stay dead
            }
         else
            {//si alive
               cpt--;
               // printf("compteur %d\n", cpt);
               if ((cpt == 2) || (cpt == 3))
                  { // si alive a 3  ou 2 voisins
                    tab[c-1][l-1] = 5; //alive stay alive
                    //printf("here");
                  }
               else
                  {
                  tab[c-1][l-1] = 8; // alive die
                // printf("la\n");
                  }
            }
         // printf("modif %d\n", tab[c-1][l-1]);
    
   
    affMat(tab);
}



int main()
{
   int **tab;
   int   **tab2;
   
   char  d;
   int i,j;
   int l,c,cycle;
   
   srand((unsigned int) time(NULL));
   
   
   l=3;
   c=4;
   cycle = 5;
   tab2 = initMat();
   tab = CreerpremierTableau(tab);
   affMat(tab);
   printf(".................\n");
   
     for(i=1;i<maxX;i++){
      for(j=1;j<maxY;j++){
           evolutionGrille(i,j,tab);
            printf(".............\n");
            }
          }
            
  
      
  
}
