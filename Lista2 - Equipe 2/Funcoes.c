TipoLista *Copia(TipoLista *le){
    int i;
    TipoLista *le2 = lcria();
    Tipono *aux = le->inicio;

    for(i=0;i<le->tamanho;i++){
        InsereFinal(*le2,aux->valor);
        aux = aux->prox;
    }
    return le2;
}

TipoLista  *LEConcatena( TipoLista *Le1, TipoLista *Le2){
    int i;
    Tipono *aux = le2->inicio
    for  (i = 0; i < le2->tamanho; i++)
    {
        InsereFinal(*le1,aux->valor);
        aux = aux->prox;
    }
    return le2;
    
} 