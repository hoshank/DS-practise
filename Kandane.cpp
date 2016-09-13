#include <iostream>
using namespace std;


int Kandane(int a[], int size , int * start, int * end){		//returns max of sum of all possible contigous sub array 
	int max_global=a[0],max_local=a[0];			// max global gives the max globally while max local is used to find the max sum in the present subarray so far
	*start=0;
	*end=0;
	for(int i=0;i<size;i++){
		max_local=max(a[i],max_local+a[i]);
		if(a[i]>max_local){				//this helps in handling cases where the first few numbers are non-positive or all the numbers in the array are non-positive
			max_local=a[i];
			*start=i;
			*end=i;
		}
		else{
			max_local+=a[i];
			*end=i;
		}
		if(max_local>max_global){
			max_global=max_local;
			*end+=1;
		}
		cout<<a[*start]<<" "<<a[*end]<<endl;
	}
	return max_global;
}

int main(){

	int s=0,e=0;
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int sum=max(a,8,&s,&e);
	cout<<sum<<endl;
	for(int i=s;i<=e;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}