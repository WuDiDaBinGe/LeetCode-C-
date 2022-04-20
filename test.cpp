#include <bits/stdc++.h>
using namespace std;

int num[10];

void randinit(){
	unsigned seed=time(0);
	srand(seed);
}
int quicksort(int f,int l){
	int i=f,j=l;
	if(f>=l){
		return 0;
	}
	int base=rand()%(l-f + 1)+f;
	int numbase=num[base];
	while(i<j){
		while(num[j]>numbase&&i<j) j--;
		while(num[i]<numbase&&i<j) i++;
		if(i<j){
			int temp=num[i];
			num[i]=num[j];
			num[j]=temp;
//			swap(num[i],num[j]);//"swap(a,b)"is the same as to"temp=a;a=b;b=temp" 
		}

	}
	quicksort(f,i-1);
	quicksort(j+1,l);
	return 0;
}

int main(){
	randinit;
	for(int i=0; i<10; i++){
		cin>>num[i];
	}
	quicksort(0, 9);
	for(int i=0;i<10;i++){
		cout<<num[i]<<" ";
	}
}