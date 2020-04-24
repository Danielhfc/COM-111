//MENSAGENS SEM ACENTO
// Uso do tipo char
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    // declarando ponteiro  para arquivo
    FILE *fp;
    // declarando as variáveis
    int qdemsgs, tammsg,c,i,j,k,lq;
    float raiz;
    char* pmo;
    char* pmd;
    /* abre arquivo para leitura */
    fp = fopen("mensagens_SA.txt","rt");
    if (fp==NULL) {
           printf("Não foi possivel abrir arquivo.\n");
           exit(1);
    }
    /* Le do arquivo a quantidade de mensagens */
    fscanf(fp,"%d",&qdemsgs);
    i=0;
    while (i < qdemsgs){
            printf("%d",sizeof(pmo));
      fscanf(fp,"%d",&tammsg);
      pmo = (char *)malloc(tammsg+1*sizeof(char));
      pmd = (char *)malloc(tammsg+1*sizeof(char));
      fscanf(fp," %[^\n]",pmo);
      raiz = sqrt(tammsg);
      lq = (int)raiz;
      c=-1;
      for(j=0;j < lq; j++){
         for(k=j;k<tammsg;k=k+lq){
            c++;
            memcpy(pmd+c, pmo+k, 1 );
         }
      }
      memcpy(pmd+c+1,"\0",1);
      printf("\nOriginal: \n >> tm: %d  \n >> lq: %d \n >> msg: %s",tammsg,lq, pmo);
      printf("\nDescripto: %s\n\n", pmd);
      free(pmd);
      free(pmo);
      i++;
    } // fim while
    return 0;
}
