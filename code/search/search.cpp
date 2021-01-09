#include <iostream>
using namespace std;
int BinarySearch(int arr[],int n,int key){
    int l = 0,r = n-1;
    while(l < r){
        int mid = (l+r)/2;
        if(arr[mid] >= key)
            r = mid;
        else
            l = mid+1;
    }
    if(arr[l] == key)
        return l;
    else
        return -1;
}
/*int BinarySearch(int arr[],int n,int key){
    int l = 0,r = n-1;
    while(l < r){
        int mid = (l+r+1)/2;
        if(arr[mid] <= key)
            l = mid;
        else
            r = mid-1;
    }
    if(arr[l] == key)
        return l;
    else
        return -1;
}
*/
int main(){
    int arr[] = {2,4,5,6,6,6,7,8,8,10};
    cout<<BinarySearch(arr,sizeof(arr)/sizeof(arr[0]),6)<<endl;
    
    return 0;
}
