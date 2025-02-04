#include<bits/stdc++.h>
using namespace std;

void bazi();
void start();
void setting();
void record();
ofstream fout;
ifstream fin;

class game{
	public:
		double grade[2]={0,0};
		string players[2]={"player1","player2"};
		char a[100][100];
		int n=6,m=7;
		int p[2]={0,0};
		char index[2]={'X','O'};
		int need=4;
		void del(){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)a[i][j]=' ';
			}
			p[0]=0,p[1]=0;
		}
		void print(){
			for(int i=0;i<m;i++){
				cout<<' '<<i;
			}
			cout<<endl;
			for(int i=n-1;i>=0;i--){
				for(int j=0;j<m;j++){
					cout<<'|'<<a[i][j];
				}
				cout<<'|'<<endl;
			}
		}
		void play(int player,int row){
			p[player]++;
			for(int i=0;i<n;i++){
				if(a[i][row]==' '){
					a[i][row]=index[player];
					return;
				}
			}
		}
		int check(){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(a[i][j]==' ')continue;                 
					if(i+need-1<n){
						bool ch=true;
						for(int k=1;k<need;k++){
							if(a[i][j]!=a[i+k][j]){
								ch=false;
								break;
							} 
						}
						if(ch){
							return a[i][j]==index[0]?0:1;
						}
					}
					if(j+need-1<m){
						bool ch=true;
						for(int k=1;k<need;k++){
							if(a[i][j]!=a[i][j+k]){
								ch=false;
								break;
							} 
						}
						if(ch){
							return a[i][j]==index[0]?0:1;
						}
					}
					if(i+need-1<n && j+need-1<m){
						bool ch=true;
						for(int k=1;k<need;k++){
							if(a[i][j]!=a[i+k][j+k]){
								ch=false;
								break;
							} 
						}
						if(ch){
							return a[i][j]==index[0]?0:1;
						}
					}
					if(i+need-1<n && j-need+1>=0){
						bool ch=true;
						for(int k=1;k<need;k++){
							if(a[i][j]!=a[i+k][j-k]){
								ch=false;
								break;
							} 
						}
						if(ch){
							return a[i][j]==index[0]?0:1;
						}
					}
				}
			}
			return -1;
		}
		double point(int player){
			double q=pow(m,n);
			return q/double(p[player]);
		}
};
game a;
void bazi(){
	system("CLS");
	cout<<"1.start\n2.setting\n3.records\n4.exit\n";
	int a;
	cin>>a;
	switch (a){
		case 1: start();break;
		case 2: setting();break;
		case 3: record();break;
		case 4: exit(0);
	}
}
void start(){
	a.del();
	for(int i=0;true;i==0?i=1:i=0){
		system("CLS");
		a.print();
		cout<<a.players[i]<<"'s turn:"<<endl;
		int x;
		cin>>x;
		a.play(i,x);
		int r=a.check();
		if(r!=-1){
			system("CLS");
			a.print();
			cout<<a.players[r]<<" win";
			double h=a.point(r);
			a.grade[r]+=h;
			fout<<a.players[r]<<" win with point "<<h<<endl;
			for(int i=0;i<1e9;i++){}
			return;
		}
	}
}

void setting(){
	system("CLS");
	cout<<"1."<<a.n<<'*'<<a.m<<" CHANGE?"<<endl;
	cout<<"2. need to win "<<a.need<<" CHANGE?"<<endl;
	cout<<"3. BACK"<<endl;
	int x;
	cin>>x;
	if(x==1){
		system("CLS");
		cout<<"Enter N:";
		cin>>a.n;
		cout<<endl<<"Enter M:";
		cin>>a.m;
		setting();
	}
	if(x==2){
		system("CLS");
		cout<<"Enter number we need to win:";
		cin>>a.need;
		setting();
	}
}

void record(){
	system("CLS");
	fout.close();
	fin.open("records.txt");
	string q;
	while(getline(fin,q)){
		cout<<q<<endl;
	}
	fout.open("records.txt",fstream::app);
	fin.close();
	string gh;
	cout<<"Enter Any key to go Back:";
	cin>>gh;
	return;
}

int main(){
	fout.open("records.txt");
	while(true)bazi();


}
