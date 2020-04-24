/*ARVOREBIN _H */
#ifndef ARVOREBIN_H
#define ARVOREBIN_H

typedef struct NO* ArvBin;

ArvBin* ArvBinCriar(); //F01
int ArvBinLiberar(ArvBin *raiz); //F02
int ArvBinVazia(ArvBin *raiz); //F03
int ArvBinAltura(ArvBin *raiz); //F04
int ArvBinTotalNO (ArvBin *raiz); //F05
int ArvBinPreOrdem (ArvBin *raiz); //F06
int ArvBinEmOrdem (ArvBin *raiz); //F07
int ArvBinPosOrdem (ArvBin *raiz); //F08
int ArvBinInsere (ArvBin *raiz, int valor); //F09
int ArvBinRemove (ArvBin *raiz, int valor); //F10
int ArvBinConsulta (ArvBin *raiz, int valor); //F11
int ArvBinTotalFolhas(ArvBin* raiz); //F12
int ArvBinNoUmFilho(ArvBin* raiz); //F13
int ArvBinEstritaBin(ArvBin* raiz); //F14

#endif /* ARVOREBIN _H */
