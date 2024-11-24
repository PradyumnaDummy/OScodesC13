#include<iostream>
using namespace std;

//best fit
void bestfit(int* bl,int m,int* pr,int n){
	int allocation[n];
	for(int i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(int i=0;i<n;i++){
		int best_idx=-1;
		for(int j=0;j<m;j++){
			if(bl[j]>=pr[i]){
				if(best_idx==-1){
					best_idx=j;
				}
				else if(bl[best_idx]>bl[j]){
					best_idx=j;
				}
			}
		}
		if(best_idx!=-1){
			allocation[i]=best_idx;
			bl[best_idx]-=pr[i];
		}
	}
	
	
		//print
	cout<<"\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout<<i+1<<"\t\t"<<pr[i]<<"\t\t";
        	if (allocation[i] != -1) {
            cout<<allocation[i]+1<<endl;
        	}
        	else{
            cout<<"Not Allocated"<<endl; 
        	}
    }
    cout<<endl;
    cout<<endl;
}


int main(){
	int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processSize) / sizeof(processSize[0]); 
	cout<<"best fit is "<<endl;
	bestfit(blockSize,m,processSize,n);
}