#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int NilaiX;
    int NilaiY;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(head==NULL)return 1;
    else return 0;
}

void insertDepan(int x, int y)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = x;
    baru->NilaiY = y;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void insertTengah(int x, int y){
    system("cls");
    int pilih;
    cout<<" ============================"<<endl;
    cout<<" =     Pilih Mode Insert    ="<<endl;
    cout<<" =  1. Insert Before        ="<<endl;
    cout<<" =  2. Insert After         ="<<endl;
    cout<<" ============================"<<endl;
    cin >> pilih;
    switch (pilih){
        case 1: system("cls");{
            TNode *baru;
            TNode *bantu;
            TNode *prebantu;
            baru = new TNode;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int before;
                cout << "Memasukkan sebelum data : ";
                cin >> before;
                bantu = head;
                prebantu = bantu;
                baru->NilaiX = x;
                baru->NilaiY = y;
                bool find = false;
                do{
                    if (before == bantu->NilaiX){
                        baru->next = prebantu->next;
                        prebantu->next = baru;
                        find = true;
                        cout << "Data Masuk\n";
                    }
                    
                    prebantu = bantu;
                    bantu = bantu->next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data yang dicari tidak ada!";
                }
            }
        
            break;
        }
        case 2: system("cls");{
            TNode *baru;
            TNode *bantu;
            baru = new TNode;
            baru->NilaiX = x;
            baru->NilaiY = y;
            baru->next = NULL;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int after;
                cout << "Memasukkan setelah data : ";
                cin >> after;
                bantu = head;
                bool find = false;
                do{
                    if (after == bantu->NilaiY){
                        baru->next = bantu->next;
                        bantu->next = baru;
                        find = true;
                        cout << "Data Masuk\n";
                    }
                    
                    bantu = bantu->next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data yang dicari tidak ada!";
                }
            }
            break;
        }
        default: system("cls");{
            cout << "\nMaaf pilihan tidak ada!";
            break;
        }
    }
}

void insertBelakang(int x, int y){
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = x;
    baru->NilaiY = y;
    baru->next = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->NilaiX<<" ";
                cout<<bantu->NilaiY<<" \n";
                bantu=bantu->next;
            }
        }else{ 
            cout <<"Masih kosong\n";
        }
}

void cariData(){
    if (head == NULL){
        cout << "Sorry Data Kosong";
    } else {
        TNode *bantu;
        int cari;
        cout << "Masukkan isi data : ";
        cin >> cari;
        bool find = false;
        bantu = head;

        do{
            if (cari == bantu->NilaiX){
                cout << "Data " << bantu->NilaiX << " " << bantu->NilaiY << " Ketemu!";
                find = true;
            }
            if (cari == bantu->NilaiY){
                cout << "Data " << bantu->NilaiX << " " << bantu->NilaiY << " Ketemu!";
                find = true;
            }
            
            bantu = bantu->next;
        } while (bantu != NULL);

        if (find == false){
            cout << "Sorry Data tidak ada";
        }
    }
}

void hapusDepan()
{

    TNode *hapus;
    int d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->NilaiX;
            head=head->next;
            delete hapus;
        }else
        {
            d=tail->NilaiX;
            head=tail=NULL;
        }
    cout<<d<<"terhapus";
    }else cout<<"Masih kosong\n";
}

void hapusTengah(int x){
    TNode *hapus;
    TNode *prehapus;
    TNode *temp;
    hapus = head;
    prehapus = hapus;
    bool success = false;

    do{
        if (hapus->NilaiX == x || hapus->NilaiY == x){
            prehapus->next = hapus->next;
            temp = hapus;
            temp->next = NULL;
            success = true;
            cout << "Data " << temp->NilaiX << " " << temp->NilaiY << " berhasil dihapus!\n";
            free(temp);
        }
        prehapus = hapus;
        hapus = hapus->next;
    } while (hapus != NULL);
    
    
    if (success == false){
        cout << "Data tidak ditemukan!";
    }
    
}

void hapusBelakang(){
    TNode *hapus;
    TNode *temp;
    hapus = head;
    while (hapus->next != NULL){
        temp = hapus;
        hapus = hapus->next;
    }

    temp->next = NULL;
    cout << "Data " << hapus->NilaiX << " " << hapus->NilaiY << " telah terhapus!";
    free(hapus);
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    do{
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    } while (bantu != NULL);
    
    head = NULL;
    cout << "Data Clear\n";
}

main()
{
    int pil, dataX, dataY;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Tengah         ="<<endl;
        cout<<" = 3. Insert Belakang       ="<<endl;
        cout<<" = 4. Delete Depan          ="<<endl;
        cout<<" = 5. Delete Tengah         ="<<endl;
        cout<<" = 6. Delete Belakang       ="<<endl;
        cout<<" = 7. Cari Data             ="<<endl;
        cout<<" = 8. Tampil Data           ="<<endl;
        cout<<" = 9. Clear                 ="<<endl;
        cout<<" = 10. Exit                 ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout<<"Masukan Data X = ";cin>>dataX;
                cout<<"Masukan Data Y = ";cin>>dataY;
                insertDepan(dataX, dataY);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data X = ";cin>>dataX;
                cout<<"Masukan Data Y = ";cin>>dataY;
                insertTengah(dataX, dataY);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data X = ";cin>>dataX;
                cout<<"Masukan Data Y = ";cin>>dataY;
                insertBelakang(dataX, dataY);
                break;
            }
            case 4: system("cls");{
                hapusDepan();
                break;
            }
            case 5: system("cls");{
                cout << "Masukkan Data : ";cin>>dataX;
                hapusTengah(dataX);
                break;
            }
            case 6: system("cls");{
                hapusBelakang();
                break;
            }
            case 7: system("cls");{
                cariData();
                break;
            }
            case 8: system("cls");{
                tampil();
                break;
            }
            case 9: system("cls");{
                clear();
                break;
            }
            case 10: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    } while (pil!=11);
}