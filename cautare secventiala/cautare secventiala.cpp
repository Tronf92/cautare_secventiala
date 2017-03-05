#include <iostream>
using namespace std;

void cautSecv(int a,int n,int k[100]);
void cautSucc(int a,int n,int k[100]);

void cautSecv(int a,int n,int k[100]){
	int i,p;
	p=0;
	if(a<k[0])
		cout << "Elementul cautat nu exista si ar trebui sa se afle pe pozitia " << p << endl;
	if(a==k[0]){
		p=1;
		cout << "Elementul cautat se afla pe pozitia " << p << endl;
	}
	else{
		if(a>k[n-1]){
			cout << "Elementul cautat nu exista si ar trebui sa se afle pe pozitia " << n+1 << endl;
			p=n+1;
		}
		else{
			for(i=0;i<n;i++){
				if ((p==0) && (a==k[i])){
					p=i;
					cout << "Elementul cautat este al " << (p+1) <<"element" <<  endl;
				}				
			}
		}
	}
}
	
void cautSucc(int a,int n,int k[100]){
	int p=1;
	if(a==k[0]){
		p=0;
	}
	else{
		if (a>k[0]){
			while ( (p<=n) && a>k[p]){
				p=p+1;
			}
		}
	}
	cout << "Elementul se afla pe pozitia " << p+1 << endl;
}

int BinarySearch(int a,int n,int k[100],int st,int dr);

void cautBin_rec(int a,int n,int k[100]){
	int p;
	if(a<k[0]){
		cout << "Elementul nu exista si ar trebui sa se afle pe prima pozitie" << endl;
	}
	else{
		if(a>k[n-1]){
			cout << "Elementul nu exista si ar trebui sa se afle pe pozitia" << n << endl;
		}
		else{
			p=BinarySearch(a,n,k,0,n-1);
		}
	}
	cout << "Elementul se afla pe pozitia " << p+1 << endl;
}

int BinarySearch(int a,int n,int k[100],int st, int dr){
	int m;
	if(st>=dr-1){
		return dr;
	}
	else{
		m=(st+dr)/2;
		if(a<=k[m]){
			return BinarySearch(a,n,k,st,m);
		}
		else{
			return BinarySearch(a,n,k,m,dr);
		}
	}
}

int Binarysearch_nerec(int a,int n,int k[100],int st,int dr);

void cautBin_nerec(int a,int n,int k[100]){
	int p;
	if(a<k[0]){
		cout << "Elementul nu exista si ar trebui sa se afle pe prima pozitie" << endl;
	}
	else{
		if(a>k[n-1]){
			cout << "Elementul nu exista si ar trebui sa se afle pe pozitia" << n << endl;
		}
		else{
			p=Binarysearch_nerec(a,n,k,0,n-1);
		}
	}
	cout << "Elementul se afla pe pozitia " << p << endl;
}

int Binarysearch_nerec(int a,int n,int k[100],int st,int dr){
	int m;
	while(st-dr>1){
		m=(st+dr)/2;
		if(a<=k[m]){
			dr=m;
		}
		else{
			st=m;
		}
	}
	return dr;
}

int main(){
	int a,n,sir[100],i;
	cout << "Introduceti nr de elemente" << endl;
	cin >> n;

	for(i=0;i<n;i++){
		cout << "sir[" << i << "]= ";
		cin >> sir[i];
	}
	cout << "Introduceti elementul cautat:" << endl;
	cin >> a;
	//Cautare secventiala
	cout << "incepe cautarea secventiala:" << endl;
	cout << endl;
	cautSecv(a,n,sir);
	cout << endl;
	cout << "Cautarea secventiala s-a terminat" << endl;
	cout << "--------------------------------------------------" << endl;
	//End
	//Cautarea succesiva
	cout << "Cautarea succesiva incepe: " << endl;
	cout << endl;
	cautSucc(a,n,sir);
	cout << endl;
	cout << "Cautarea succesiva s-a terminat!"<< endl;
	cout << "--------------------------------------------------" << endl;
	//End
	//Cautare binara recursiva
	cout << "Cautarea binara recursiv a inceput!" << endl;
	cout << endl;
	cautBin_rec(a,n,sir);
	cout << endl;
	cout << "Cautarea binara recursiv s-a terminat!" << endl;
	cout << "--------------------------------------------------" << endl;
	//End
	//Cautare binara nerecursiv
	cout << "Cautarea binara nerecursiv a inceput!" << endl;
	cout << endl;
	cautBin_nerec(a,n,sir);
	cout << endl;
	cout << "Cautarea binara nerecursiv s-a terminat!" << endl;
	cout << "--------------------------------------------------" << endl;
	//End

	system("pause");
	return 0;

}