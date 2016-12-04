#include <iostream>

#include "reserv.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

List_parent LP;
List_child LC;
address_child AC;
address_parent AP;
infotype_parent XP;
infotype_child XC;

void mainMenu();
void clrscr();
void daftar();
void login();
void admin();
void menuUser(List_parent &L,address_parent &P);
void menuAdmin();
void tambahtiket();
void deluser();
void viewall();
void sortharga();

int main()
{
    createListParent(LP);
    createListChild(LC);
    mainMenu();
    return 0;
}

void clrscr()
{
    system("cls");
}

void mainMenu()
{
    clrscr();
    int pil;
    cout<<"----------MAIN MENU----------"<<endl;



    cout<<"   1. Daftar "<<endl;

    cout<<"   2. Login"<<endl;

    cout<<"   3. Admin"<<endl;

    cout<<"---------------------------------------------------------------"<<endl;

    cout<<"   99. Exit"<<endl;

    cout<<"   Pilih: ";
    cin>>pil;

    switch (pil)
    {
    case 1:
        daftar();
        break;
    case 2:
        login();
        break;
    case 3:
        admin();
        break;
    case 99:
        exit(99);
        cout<<"TERIMA KASIH"<<endl;
        break;
    }
    if (pil != 99)
    {

        mainMenu();

    }

}

void daftar()
{
   clrscr();
    cout<<"---------REGISTER---------"<<endl;
    cout<<"ID         : ";cin>>XP.id_User;
    cout<<"Nama         : ";cin>>XP.nama;
    cout<<"Password     : ";cin>>XP.password;
    cout<<"Email      : ";cin>>XP.email;
    cout<<"No.HP      : ";cin>>XP.no_hp;
    if (findElmParent(LP,XP) == NULL) {
        AP = alokasiParent(XP);
        address_parent Q = first(LP);
        address_parent tempP = first(LP);
        if(first(LP) == NULL){
            insertFirstParent(LP, AP);
        }
        else {
            while (next(Q) != first(LP)){
                if (info(next(Q)).id_User < XP.id_User){
                    tempP = next(tempP);
                }
                Q = next(Q);
            }
            insertAfterParent(LP,tempP,AP);
        }
        cout<<"--------User telah terdaftarr--------"<<endl;
        getch();
        mainMenu();
    }
    else {
        cout<<"--------Id telah ada. Silahkan input ID yang lain--------"<<endl;
        getch();
        mainMenu();
    }
}

void login()
{
    clrscr();
    infotype_parent x;
    address_parent P;
    cout<<"--------LOGIN---------"<<endl;
    cout<<"    ID  : ";
    cin>>x.id_User;
    cout<<"   Password  : ";
    cin>>x.password;
    P = findElmParent(LP,x);
    if (P != NULL)
    {
        if (info(P).password == x.password)
        {
            menuUser(LP,P);
        }
        else
        {
            cout<<"Salah Password"<<endl;
            getch();
            login();
        }
    }
    else
    {
        cout<<"Id Tidak Terdaftar"<<endl;
        getch();
        mainMenu();
    }
}

void admin()
{
    clrscr();
    string username,pass;
    cout<<"---------ADMIN--------"<<endl;
    cout<<"   Username  : ";
    cin>>username;
    cout<<"   Password  : ";
    cin>>pass;
    if (username == "admin")
    {
        if (pass == "admin123")
        {
            menuAdmin();
        }
    }
    else
    {
        cout<<"Slah Salah Salah"<<endl;
        getch();
        mainMenu();
    }
}

void menuUser(List_parent &L,address_parent &P)
{
    int pil;
    //int j = 0;
    infotype_parent x;
    infotype_child XC;
    clrscr();
    cout<<"--------Menu User-------"<<endl;
    cout<<"   Welcome  "<<info(P).nama<<" ("<<info(P).nama<<")"<<endl;
    cout<<"   1. Lihat Tiket Tersedia"<<endl;
    cout<<"   2. Beli Tiket"<<endl;
    cout<<"   3. Lihat Transaksi"<<endl;
    cout<<"   4. Edit Profile"<<endl;
    cout<<"   5. Back"<<endl;
    cout<<"   Select: ";
    cin>>pil;
    switch (pil)
    {
    case 1 :
    {
        printInfoChild(LC);
        getch();
        menuUser(L,P);
        break;
    }
    case 2:
    {
        printInfoChild(LC);
        if (first(LC) == NULL)
        {
            cout<<"Tiket Tidak Tersedia";
            getch();
            menuUser(LP,P);
        }
        else
        {
            cout<<"Masukkan ID Tiket yg dibeli: ";
            cin>>XC.id_Tiket;
            address_child C = findElmChild(LC,XC);
            address_child tempC = first(LC);
            address_child findC;
            address_child delC = C;
            insertFirstChild(child(P),C);
            if (C == first(LC))
            {

                deleteFirstChild(LC,delC);
            }
            else if (C == last(LC)){
                deleteLastChild(LC,C);
            }
            else {
                while (tempC != last(LC)) {
                    if (next(tempC) == C ) {
                        deleteAfterChild(LC,tempC,C);
                    }
                    tempC = next(tempC);
                }
            }
        getch();
        menuUser(L,P);
        break;
    }
    case 3:
    {
        printInfoChild(child(P));
        getch();
        menuUser(L,P);
        break;
    }
    case 4:
        cout<<"Name: ";
        cin>>info(P).nama;
        cout<<"Password: ";
        cin>>info(P).password;
        cout<<"Email: ";
        cin>>info(P).email;
        cout<<"Phone Number: ";
        cin>>info(P).no_hp;
        cout<<"Edit Profile successful!"<<endl;
        getch();
        menuUser(L,P);
        break;
    case 5:
        mainMenu();
        break;
    }

}
}
void menuAdmin()
{
    clrscr();
    int pil;
    cout<<"-------MENU ADMIN--------"<<endl;
    cout<<"   1. View User"<<endl;
    cout<<"   2. Delete User"<<endl;
    cout<<"   3. Tambah Tiket"<<endl;
    cout<<"   4. View All"<<endl;
    cout<<"   5. Sort Harga"<<endl;
    cout<<"   Pilih: ";
    cin>>pil;
    switch(pil)
    {
    case 1:
        printInfoParent(LP);
        getch();
        menuAdmin();
        break;
    case 2:
        deluser();
        getch();
        menuAdmin();
        break;

    case 3:
        tambahtiket();
        break;
    case 4:
        viewall();
        break;
    case 5:
        void sortharga();
        break;
    }

}
void tambahtiket()
{
    clrscr();
    infotype_child P;
    infotype_child x;
    cout<<"--------Tambah Tiket--------"<<endl;
    cout<<"  ID Tiket         : ";
    cin>>x.id_Tiket;
    if (findElmChild(LC,x) != NULL)
        {
        cout<<"ID already exist."<<endl;
        getch();

    }
    else
    {
        cout<<"   Harga Tiket : ";
        cin>>x.harga_Tiket;
        cout<<"   Kota asal : ";
        cin>>x.kota_asal;
        cout<<"   Kota Tujuan :";
        cin>>x.kota_tujuan;
        //cout<<info(P).id_User;

        address_child Q = first(LC);
        address_child tempC = first(LC);
        address_child C = alokasiChild(x);
        if (first(LC) == NULL)
        {
            insertFirstChild(LC,C);

        }

        else
        {

            while (Q != last(LC))
            {

                if (first(LC) == last(LC))
                {

                    if (info(first(LC)).id_Tiket > x.id_Tiket)
                    {
                        insertLastChild(LC,C);
                    }
                    else if (info(first(LC)).id_Tiket < x.id_Tiket)
                    {
                        insertFirstChild(LC,C);
                    }
                }

                else if(info(next(Q)).id_Tiket < x.id_Tiket)
                {
                    tempC = next(tempC);

                }
                Q = next(Q);
            }
            insertAfterChild(LC,tempC,C);
        }
        getch();
        menuAdmin();
    }
}

void deluser(){
    printInfoParent(LP);
    infotype_parent x;
if (first(LP) == NULL){
        cout<<"   Tidak ada user "<<endl;
        getch();
        menuAdmin();
    }

    cout<<"Masukkan Id: "; cin>>x.id_User;
    address_parent tempP = first(LP);
    if (findElmParent(LP,x) == NULL){
        cout<<"ID Tidak ada"<<endl;
        getch();
        menuAdmin();
    }
    else{
        address_parent P = findElmParent(LP,x);
        if (P == first(LP)){
            deleteFirstParent(LP,P);
        }
        else if (next(P) == first(LP)){
            deleteLastParent(LP,P);
        }
        else{
            do{
                if (next(tempP) == P){
                    deleteAfterParent(LP,tempP,P);
                }
                tempP = next(tempP);
            }while (P != first(LP));
        }
        cout<<"ID telah didelete"<<endl;
        getch();
        menuAdmin();
    }
}

void viewall ()
{
    clrscr();
    address_parent P = first(LP);
    if (P != NULL)
    {
        while (P != NULL)
        {
            cout << "ID User : " << info(P).id_User << endl;
            cout << "Nama : "<<info(P).nama<<endl;
            cout<<"Transaksi : "<<endl;
            printInfoChild(child(P));
            P = next(P);
        }
    }
    else
    {
        cout << "Tidak Ada Transaksi" << endl;
        cout<<endl;
    }
    mainMenu();
}



