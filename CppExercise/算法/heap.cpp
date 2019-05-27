#include <iostream>
#include <algorithm>
using namespace std;
void HeapAdjust(int A[],int i,int size ){
	int l = 2*i;
	int r = 2*i+1;
	int tmp ;
	while(l<=size){
		tmp = l;
		if(r<=size && A[r]>A[l]){  //���ҽڵ�Ƚ�
			tmp = r;
		}
		if(A[tmp]>A[i]){            //�븸�ڵ�Ƚ� 
			swap(A[i],A[tmp]);
		}
		else break;
	}
}
void MakeHeap(int A[],int size){
	int i;
	for(i = size/2 ;i >= 0; i--){   //�����һ����Ҷ�ӽڵ㿪ʼ�����ڵ� 
		HeapAdjust(A,i,size);
	}
}
void HeapSort(int A[], int size){
	int i;
	MakeHeap(A,size);
	for(i = size;i >= 1;i--){
			swap(A[0],A[i]); //�㷨 
			for(int j = i/2 ;j >= 0; j--)
        	HeapAdjust(A,j,i-1);
	}
}
int main(){
	int a[8] = {9,4,5,2,1,7,4,6};
 	HeapSort(a,8);
	for(int i=0;i<8;i++){
		cout<<i<<":"<<a[i]<<endl;
	}
	getch();
	return 0;

}



