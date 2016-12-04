#ifndef RESERV_H_INCLUDED
#define RESERV_H_INCLUDED

#include <iostream>
using namespace std;



#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define next(P) P->next
#define prev(P) P->prev




typedef struct elmlist_parent *address_parent;
typedef struct Tiket infotype_child;
typedef struct elmlist_child *address_child;
typedef struct User infotype_parent;
struct User
{
string id_User;
string password;
string nama;
string email;
int no_hp;
};

struct Tiket

{
    string id_Tiket;
    int harga_Tiket;
    string kota_asal;
    string kota_tujuan;

};

struct List_parent {
    address_parent first;
};


struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};
struct elmlist_parent {
    infotype_parent info;
    address_parent next,prev;
    List_child child;

};




void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
address_parent alokasiParent(infotype_parent x);
void dealokasiParent(address_parent &P);
address_parent findElmParent(List_parent L, infotype_parent x);
void printInfoParent(List_parent L);

void createListChild(List_child &L);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(List_child &L,address_child Prec, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(List_child &L,address_child Prec, address_child &P);
address_child alokasiChild(infotype_child x);
void dealokasiChild(address_child &P);
address_child findElmChild(List_child L, infotype_child x);
void printInfoChild(List_child L);

#endif // RESERV_H_INCLUDED
