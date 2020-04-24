//MENSAGENS COM ACENTO
// Uso do tipo wchar_t
//
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <math.h>
#include <locale.h>
int main()
{
    // declarando ponteiro  para arquivo
    FILE *fp;
    // declarando as variáveis
    int qdemsgs, tammsg,c,i,j,k,lq;
    float raiz;
    wchar_t* pmo;
    wchar_t* pmd;
    setlocale(LC_ALL,"");
    printf ("Locale is: %s\n", setlocale(LC_ALL,NULL) );
    /* abre arquivo para leitura */
    fp = fopen("mensagens_CA.txt","rt");
    if (fp==NULL) {
           printf("Não foi possivel abrir arquivo.\n");
           exit(1);
    }
    fwscanf(fp,L"%d",&qdemsgs);
    i=0;
    while (i < qdemsgs){
      fwscanf(fp,L"%d",&tammsg);
      pmo = (wchar_t *)malloc((tammsg+1)*sizeof(wchar_t));
      pmd = (wchar_t *)malloc((tammsg+1)*sizeof(wchar_t));
      fwscanf(fp,L"%ls",pmo);
      raiz = sqrt(tammsg);
      lq = (int)raiz;

      c=-1;
      for(j=0;j < lq; j++){
         for(k=j;k<tammsg;k=k+lq){
            c++;
            wmemcpy(pmd+c, pmo+k, 1 );
         }
      }
      wmemcpy(pmd+c+1,L"\0",1);
      printf("\nOriginal: \n >> tm: %d  \n >> lq: %d \n >> msg: %ls",tammsg,lq, pmo);
      printf("\nDescripto: %ls\n\n", pmd);
      free(pmd);
      free(pmo);
      i++;
    }
     // fim while
    return 0;
}

