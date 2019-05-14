/*	
Nama program    : Tree
Nama	        : Difa Bagasputra Maulana
NPM	            : 140810180057 
Tanggal buat	: 14 Mei 2019 
********************************************************************/ 
#include<iostream>
using namespace std;

struct Simpul {
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout << "Masukkan simpul : ";cin >> pBaru->info;
    pBaru->left = 0;
    pBaru->right = 0;
}

void insertBST(Tree& root,pointer pBaru){
	if(root==NULL){
		root=pBaru;
	}
	else if(pBaru->info<root->info){
		insertBST(root->left,pBaru);
	}
	else if(pBaru->info>root->info){
		insertBST(root->right,pBaru);
	}
	else{
		cout<<"sudah ada"<<endl;
	}
}

void notasiKurung (Tree Root) {
    if (Root != NULL){
        cout<<"(";
        cout<< Root->info <<" ";
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout<<")";
    }
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<" ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info<<" ";
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<" ";
    }
}

int main(){
	pointer pb;
	Tree t;
    int n,pil;
    t=NULL;

    cout<<"Masukkan Banyak Simpul : ";cin>>n;
    for(int i=0;i<n;i++){
        CreateSimpul(pb);
        insertBST(t,pb);
    }
    cout<<"Tree : ";notasiKurung(t);
    cout<<endl;
    
    do
    {
        cout<<"\n==========MENU=========\n";
        cout<<"1. Pre Order\n";
        cout<<"2. In Order\n";
        cout<<"3. Post Order\n";
        cout<<"\n=======================\n";
        cout<<"0. Exit\n";
        cout<<"\n=======================\n";
        cout<<"Pilihan : ";cin>>pil;
        switch (pil)
        {
        case 1:
            cout<<"=====Pre Order=====\n";
            preOrder(t);
            cout<<endl;
            break;
        
        case 2:
            cout<<"=====In Order=====\n";
            inOrder(t);
            cout<<endl;
            break;

        case 3:
            cout<<"=====Post Order=====\n";
            postOrder(t);
            cout<<endl;
            break;

        case 0:
            break;

        default:
            cout<<"Input Salah! coba lagi..\n";
            break;
        }
    } while (pil!=0);
    
}