#include<iostream>
using namespace std;
void Thap_HN(int n , string cotnguon , string cottrunggian , string cotdich){
	if(n==1) cout<<"\n di chuyen dia "<<n<<" tu "<<cotnguon<<" sang "<<cotdich;
	else{ 
	      Thap_HN(n-1 ,cotnguon,cotdich,cottrunggian);
		cout<<"\n di chuyen dia "<<n<<" tu "<<cotnguon<<" sang "<<cotdich;
		Thap_HN(n-1 ,cottrunggian,cotnguon,cotdich);
	}
}
int main(){
	int n;
	cout<<"Nhap so dia n:";
	cin>>n;
	Thap_HN(n,"A","B","C");
	return 0;
}