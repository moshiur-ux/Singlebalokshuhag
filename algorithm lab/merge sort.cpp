#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int l_arr[n1];
    int r_arr[n2];
    //create left subarray
    for(int i=0;i<n1;i++){
        l_arr[i]=arr[i+l];
    }
    //create right subarray
    for(int i=0;i<n2;i++){
        r_arr[i]=arr[i+mid+1];
    }
    int i=0,j=0,k=l;
    //merge two sub array in accending order
    while(i<n1&&j<n2){
        if(l_arr[i]<r_arr[j])
        {
            arr[k]=l_arr[i];
            i++,k++;
        }
        else{
            arr[k]=r_arr[j];
            j++;k++;
        }
    }
    while(i<n1){

            arr[k]=l_arr[i];
            i++,k++;
    }
    while(j<n2){

            arr[k]=r_arr[j];
            j++,k++;
    }

}


void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={2,5,1,6,8,7,9,4,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
