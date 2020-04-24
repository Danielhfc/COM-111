//MENSAGENS SEM ACENTO
// Uso do tipo char
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
// declarando ponteiro para arquivo
FILE *fp;
// declarando as variáveis
int qdemsgs, tammsg, c, i, j, k, lq;
float raiz;
char pmo[100], pmd[100];
/* abre arquivo para leitura */
fp = fopen("mensagens_SA.txt","rt");
if (fp==NULL) {
printf("Nao foi possivel abrir arquivo.\n");
exit(1);
}
/* Le do arquivo a quantidade de mensagens */
fscanf(fp,"%d",&qdemsgs);
for(i=0;i<qdemsgs;i++){
fscanf(fp,"%d", &tammsg);
fscanf(fp," %[^\n]", pmo);
printf("%d",sizeof(pmo));
raiz = sqrt(tammsg);
lq = (int)raiz;
c = -1;
for(j=0; j < lq; j++){
for(k=j; k<tammsg; k=k+lq){
c++;
memcpy(pmd+c, pmo+k, 1 );
}
}
memcpy(pmd + c + 1, "\0", 1);
printf("\nOriginal: \n ");
printf(" >> tm: %d \n >> lq: %d \n >> msg: %s", tammsg, lq, pmo);
printf("\nDescripto: %s\n\n", pmd);
}
return 0;
}
