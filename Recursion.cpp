/*#include <iostream>
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
        return binarySearch(arr,mid,key,start,mid-1);
    }
    {
        return binarySearch(arr,size-(mid+1),key,mid+1,end);
    }
}

//STRINGGGG USING RECURSION



void reverseREc(string &str, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(str[start], str[end]);
    reverseREc(str, start + 1, end - 1);
}


bool checkpalindrome(string &str, int start, int end){
    if(start>=end){
        return false;
    }
    if(str[start]==str[end]){
        return true;
    }
    return checkpalindrome(str,start+1,end-1);
}





//int main(){


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


    // int arr[5]={1,2,3,4,5};
    // int size=5;
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

    //string str="malayalam";
    // reverseREc(str,0,str.length()-1);
    // cout<<str;


    // if(checkpalindrome(str,0,str.length()-1)){
    //     cout<<"Palindrome";
    // }else{
    //     cout<<"Not Palindrome";
    // }



//     return 0;
// }

*/


// #include <iostream>
// using namespace std;

// int bpowerofa(int a,int b){
//     if(a==0){
//         return 0;
//     }
//     if(b==0){
//         return 1;
//     }
//     int ans=bpowerofa(a,b/2);
//     if(b%2==0){
//         return ans*ans;
//     }else{
//         return ans*ans*a;
//     }
// }


// int main(){
//     int num1;    
//     int num2;
//     cout<<"Enter the first number: "<<endl;
//     cin>>num1;
//     cout<<"Enter the second number: "<<endl;
//     cin>>num2;
//     cout<<bpowerofa(num1,num2);


//     return 0;
// }



//Merge Sort using Recursion


#include <iostream>
#include <vector>
using namespace std;


vector <int> mergeSort(vector <int> &arr){
    
}


int main(){
    vector<int> arr={9,5,2,3,7,11,17};

}