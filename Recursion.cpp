#include <iostream>
using namespace std;


//recursive funtion to calculate factorial


int factorial(int n){
    if(n==0) return 1;
    int res=n*factorial(n-1);
    return res;
}

//2^(n) 


int powernof2(int n){
    if(n==0){
        return 1;
    }
    int ans=2* powernof2(n-1);
    return ans;
}

  //printing counting from n to m


void counting(int num2, int num1){
    if(num2>num1){
        return;
    }
    cout<<num2<<" ";
    counting(num2+1, num1);
}


//a^b


int apowerofb(int a, int b){
    if(b==0){
        return 1;
    }
    if(a==1 || a==0){
        return a;
    }

    int ans=a*apowerofb(a,b-1);
    return ans;

}


int fibonacci(int num){
    if(num==0 || num==1){
        return num;
    }
    int ans=fibonacci(num-1)+fibonacci(num-2);
    return ans;

}


void saynprint(int n, string arr[]){
    if(n==0){
        return;
    }
    int digit=n%10;
    n=n/10;
    saynprint(n,arr);
    cout<<arr[digit]<<" ";
}


int sumofarray(int *arr, int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int ans=*arr+sumofarray(arr+1,size-1);
    return ans;
}


bool isSorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }
    if(*arr>*(arr+1)){
        return false;
    }else{
        return isSorted(arr+1,size-1);
    }
}


bool linearSearch(int *arr, int size, int key){
    if(size==0){
        return false;
    }
    if(*arr==key){
        return true;
    }else{
        return linearSearch(arr+1, size-1, key);
    }
}

bool binarySearch(int *arr, int size, int key, int start, int end){
    // int start=0;
    // int end=size-1;


    if(start>end){
        return false;
    }
    int mid=start+(end-start)/2;


    if(arr[mid]==key){
        return true;
    }else if (arr[mid]>key)
    {
        /* code */
        return binarySearch(arr,mid,key,start,mid-1);
    }
    {
        return binarySearch(arr,size-(mid+1),key,mid+1,end);
    }
}


int main(){


    // int num;
    // cout<<"Enter the first number: "<<endl;
    // cin>>num;

    // int num2;
    // cout<<"Enter the second number: "<<endl;
    // cin>>num2;



    //int ans=factorial(num);
    

    // int ans=powernof2(num);


    // counting(num, num2);


    // int res=apowerofb(num, num2);
    // cout<<res;


    // for(int i=0;i<num;i++){
    //     int res=fibonacci(i);
    //     cout<<res<<" ";
    // }




    // string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    // saynprint(num,arr);


    int arr[5]={1,2,3,4,5};
    int size=5;
    // int ans=sumofarray(arr,size);
    // cout<<ans;

    // if(isSorted(arr,size)){
    //     cout<<"Array is Sorted";
    // }else{
    //     cout<<"Arayy is unsorted";
    // }

    // if(linearSearch(arr,size,1)){
    //     cout<<"Element found";
    // }else{
    //     cout<<"Not found";
    // }


    // if(binarySearch(arr,size,8,0,5)){
    //     cout<<"Element found";
    // }else{
    //     cout<<"Not found";
    // }


    return 0;
}