/*
 * File:   listaDuplaEncadeada.h
 * Author:
 *
 * Created
 */
#ifndef LISTADUPLAENCADEADA_H
#define LISTADUPLAENCADEADA_H

  typedef struct noDupla TipoNDE;
  typedef struct listaDupla TipoLDE;

   TipoLDE *LDECria();
   void LDEInsereInicio(TipoLDE *lde, int valor);
   void LDEInsereFinal(TipoLDE *lde, int valor);
   void LDEInsereOrdenado(TipoLDE *lde, int valor);
   void LDEImprimeInicio(TipoLDE *lde);
   void LDEImprimeFim(TipoLDE *lde);
   TipoNDE *LDERetornaInicio(TipoLDE *lde);
   TipoNDE *LDERetornaFim(TipoLDE *lde);
   int  LDETamanho(TipoLDE *lde);
   void NDEDisplay(TipoNDE *nde);
   int  LDEConsultaElemento(TipoLDE *lde, int valor);
   void LDERemoveElemento(TipoLDE *lde, int valor);
   void LDESubValor(TipoLDE *lde, int valori, int valorf);
   void FLDEVazia(TipoLDE *lde);
   int  LDEVazia(TipoLDE *lde);
   int  LDESoma(TipoNDE *nde);
#endif /* LISTADUPLAENCADEADA_H */

