#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//brute force
int maxsumsubarr(vector<int> &arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        int data=0;
        int res=0;
        for(int j=i;j<arr.size();j++){
            data+=arr[j];
            res=max(res,data);
        }
        sum=max(sum,res);
    }
    return sum;
}


//  kadanes algorithm

int maxsum(vector<int>&arr){
    int maxsum=INT16_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxsum=max(maxsum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}


//  Rearrange array sign

vector <int> arrrearrange(vector<int>&arr){
    int n=arr.size();
    vector<int>po(n/2);
    vector<int>ne(n/2);
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            po.push_back(arr[i]);
        }
        if(arr[i]<0){
            ne.push_back(arr[i]);
        }
    }
    int j=0;
    for(int i=0;i<po.size()&&i<ne.size();i++){
        arr[j++]=po[i];
        arr[j++]=ne[i];
    }
    return arr;
}


void reArrange(vector<int>&arr){
    vector<int> res(arr.size());
    int j=0;
    int k=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            res[j]=arr[i];
            j=j+2;
        }
        if(arr[i]<0){
            res[k]=arr[i];
            k=k+2;
        }

    }
    arr=res;
}

void reArrange2(vector<int>& arr) {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> res;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            arr1.push_back(arr[i]);
        } else if (arr[i] < 0) {
            arr2.push_back(arr[i]);
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && k < arr2.size()) {
        res.push_back(arr1[i++]);
        res.push_back(arr2[k++]);
    }

    while (i < arr1.size()) {
        res.push_back(arr1[i++]);
    }
    
    while (k < arr2.size()) {
        res.push_back(arr2[k++]);
    }

    arr = res;
}

vector <int> nextpermu(vector<int> &arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

vector<int> palindrome(vector<int>&arr){
    int s=0;
    int e=arr.size()-1;
    int sum=0;
    vector<int> res1;
    stack<int> st;
    while(s<e){
        sum+=arr[s];
        if(sum==arr[e]){
            res1.push_back(sum);
            st.push(arr[e]);
            e--;
            sum=0;
        }
        s++;
    }
    res1.push_back(arr[s]);
    while(!st.empty()){
        res1.push_back(st.top());
        st.pop();
    }
    
    return res1;

}


void roated(vector<int>& arr,int n){

    vector<int>res;
    for(int i=0;i<n;i++){
        res[((n-1)+i)%n]=arr[i];
    }
    arr=res;
}

int search(vector<int>& nums, int target) {
    int i=1;
    int count=0;
    while(i!=nums.size()){
        if(nums[0]==target){
            return count;
        }
        roated(nums,nums.size());
        count++;
        i++;
    }
    return count;
}


int searchNinsert(vector<int> &arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}


int main(){
    //vector <int> arr={2,3,5};   //-2,-3,4,-1,-2,1,5,-3
    // cout<<"Sum is: " <<maxsumsubarr(arr)<<endl;
    // cout<<"Sum is: " <<maxsum(arr)<<endl;
    // reArrange2(arr);

    //vector <int> aa=nextpermu(arr);

    // for(int i=0;i<aa.size();i++){
    //     cout<<aa[i]<<" ";
    // }





    //vector <int> arr={10,5,8,6,9,14,15};


    // vector<int> result=palindrome(arr);
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<" ";
    // }

    //cout<<search(arr,5)<<endl;
    //return 0;



    vector <int> arr={1,3,5,6};
    cout<<searchNinsert(arr,7)<<endl;
    return 0;
}