#include "reserv.h"
void createListParent(List_parent &L)
{

    first(L) = NULL;
}

address_parent alokasiParent(infotype_parent x)
{


    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createListChild(child(P));
    return P;
}

void insertFirstParent(List_parent &L, address_parent P)
{

    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLastParent(List_parent &L, address_parent P)

{
    address_parent Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }

}
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P)
{
    if (first(L) == NULL)
    {
        insertFirstParent(L,P);
    }
    else if (next(Prec) == first(L))
    {
        insertLastParent(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstParent(List_parent &L, address_parent &P)
{
    address_parent Q = first(L);
    if(next(P)==  first(L)) {
        first(L) = NULL;
    }
    else {
        while (next(Q) != first(L)){
            Q=next(Q);
        }
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        next(Q) = first(L);
    }
    }


void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P)
{
    if (next(Prec) == first(L))
    {
        P = first(L);
        first(L) = next(P);
        next(Prec) = first(L);
        next(P) = NULL;
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void deleteLastParent(List_parent &L, address_parent &P)
{
    address_parent Q;
    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            Q = first(L);
            while (next(next(Q)) != first(L))
            {
                Q =next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
            next(P) = NULL;
//dealokasi(P);
        }
    }
}


void printInfoParent(List_parent L)
{
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL)
    {
        do
        {
            cout<<"ID : "<<info(P).id_User<<endl;
            cout<<"Password : "<<info(P).password<<endl;
            cout<<"Nama : "<<info(P).nama<<endl;
            cout<<"Email : "<<info(P).email<<endl;
            cout<<"No.Hp : "<<info(P).no_hp<<endl;
            printInfoChild(child(P));
            P = next(P);
        }
        while(info(P).id_User !=info(first(L)).id_User);
    }
}

address_parent findElmParent(List_parent L, infotype_parent x)
{

       address_parent P = first(L);
    if ( first(L) == NULL){
        return NULL;
    }
    else{
        do {
            if(info(P).id_User == x.id_User) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
}




void createListChild(List_child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasiChild(infotype_child x)
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstChild(List_child &L, address_child P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastChild(List_child &L, address_child P)
{
    if(first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}
void insertAfterChild(List_child &L,address_child Prec,address_child P){
    if (first(L) == NULL){
        insertFirstChild(L,P);
    }
    else if (Prec == last(L)){
        insertLastChild(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void printInfoChild(List_child L)
{
    address_child P = first(L);
    while(P !=NULL)
    {
        cout<<"ID Tiket : "<<info(P).id_Tiket<<endl;
        cout<<"Harga Tiket : "<<info(P).harga_Tiket<<endl;
        cout<<"Kota Asal : "<<info(P).kota_asal<<endl;
        cout<<"Kota Tujuan : "<<info(P).kota_tujuan<<endl;
        P = next(P);
    }
}

void deleteFirstChild(List_child &L, address_child &P)
{
    if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLastChild(List_child &L, address_child &P)
{
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
}
void deleteAfterChild(List_child &L,address_child Prec, address_child &P)
{
    if (Prec == last(L))
    {
        deleteLastChild(L,P);
    }
    else{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}
}

address_child findElmChild(List_child L, infotype_child x)
{
    address_child P = first(L);
    while(P != NULL)
    {
        if(info(P).id_Tiket ==x.id_Tiket)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
