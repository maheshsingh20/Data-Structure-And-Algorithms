#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;


int secondlargest(vector<int> &arr){
    int largest=arr[0];
    int res=0;
    for(int i=1;i<arr.size();i++){
        if(largest<arr[i]){
            res=largest;
            largest=arr[i];
        }
        else{
            if(res<arr[i]){
                res=arr[i];
            }
        }
    }
    return res;
}


bool isArraySorted(vector<int>&arr){
    int curr=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]<curr){
            return false;
        }
        else curr=arr[i];
    }
    return true;
}

//Using Recursion


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


vector <int> removeduplicates(vector <int>& arr){
    vector<bool> freq(*max_element(arr.begin(),arr.end())+1,false);
    vector <int> res;
    for(int num:arr){
        if(!freq[num]){
            res.push_back(num);
            freq[num]=true;
        }
    }
    return res;
}

vector<int> leftrotateBy1(vector<int> &arr, int k) {
    int j = arr.size();
    vector<int> nums(j);  // Initialize nums with the size of arr
    for (int i = 0; i < j; i++) {
        nums[(j - k + i) % j] = arr[i];
    }
    return nums;
}

vector <int> moveZeroesToEnd(vector<int> &arr){
    int firstzero=-1;
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0 && firstzero==-1){
            firstzero=arr[i];
            j=i;
        }
        if(arr[i]!=0 && firstzero==0){
            swap(arr[i],arr[j]);
            firstzero=arr[j+1];
            j=j+1;
        }
    }
    return arr;
}


int majorityelement(vector<int> &arr){
    map<int,int> freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    for(auto i:freq){
        if(i.second>arr.size()/2){
            return i.first;
        }
    }
    return -1;
}

vector<int> unionOfArray(vector<int> arr1, vector<int> arr2){
    int maxx=max(arr1[arr1.size()-1],arr2[arr2.size()-1]);
    vector<int> freq(maxx+1,-1);
    vector<int> result;
    for(int i=0;i<arr1.size();i++){
        if(freq[arr1[i]]==-1){
            freq[arr1[i]]=1;
            result.push_back(arr1[i]);
        }
    }
    for(int i=0;i<arr2.size();i++){
        if(freq[arr2[i]]==-1){
            freq[arr2[i]]=1;
            result.push_back(arr2[i]);
        }
    }
    return result;
}



vector<int> intersectionOfArray(vector<int> arr1, vector<int> arr2){
    int maxx=max(arr1[arr1.size()-1],arr2[arr2.size()-1]);
    vector<int> freq(maxx+1,-1);
    vector<int> result;
    for(int i=0;i<arr1.size();i++){
        if(freq[arr1[i]]==-1){
            freq[arr1[i]]=1;
        }
        else{
            result.push_back(arr1[i]);
        }
    }
    for(int i=0;i<arr2.size();i++){
        if(freq[arr2[i]]==-1){
            freq[arr2[i]]=1;
        }
        else{
            result.push_back(arr2[i]);
        }
    }
    return result;
}


int maxconsecutiveones(vector<int> &arr){
    int count=0;int maxx=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==1){
            count++;
            maxx=max(maxx,count);
        }else{
            count=0;
        }
    }
    return count;
}


int numberthatappearsonesothertwice(vector<int> &arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=res^arr[i];
    }
    return res;
}


int longestsubarraywithsumk(vector<int> &arr,int k){
    int sum=0;int count=0;
    int left=0;
    int right=0;
    while(right<arr.size()){
        sum+=arr[right];
        while(sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            count=max(count,right-left+1);
        }
        right++;
    }
    return count;
}


int longestSubarraywithsumk(vector<int>&arr, int k){
    map <int, int> premap;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        //calculate sum of remaining part
        int rem=sum-k;

        // calculate length and update maxlen

        if(premap.find(rem)!=premap.end()){
            int len=i-premap[rem];
            maxlen=max(maxlen,len);
        }

        if(premap.find(sum)==premap.end()){
            premap[sum]=i;
        }
    }
    return maxlen;
}

vector<int> twosum(vector<int> &num,int target){
    map<int, int> premap;

    for(int i=0;i<num.size();i++){
        int n=num[i];
        int moreneeded=target-n;
        if(premap.find(moreneeded)!=premap.end()){
            return {premap[moreneeded],i};
        }
        premap[n]=i;
    }
    return {-1,-1};
}




// int main(){
    //int arr[5]={1,2,8,4,5};
    // int ans=secondlargest(arr);
    // cout<<ans<<endl;
    // if(isArraySorted(arr)){
    //     cout<<"Sorted";
    // }else{
    //     cout<<"Unsortedd";
    // }
    
    // if(isSorted(arr,5)){
    //     cout<<"Sorted";
    // }else{
    //     cout<<"Unsortedd";
    // }

    // vector <int> arr={1,0,8,0,9,6,0,3};
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // vector <int> res=moveZeroesToEnd(arr);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }


    // vector <int> arr1=leftrotateBy1(arr,4);
    // for(int i=0;i<arr1.size();i++){
    //     cout<<arr1[i]<<" ";
    // }
    

    // vector<int> arr1={1,2,3,4,5};
    // vector<int> arr2={4,5,6,8,7};
    // vector<int> res=unionOfArray(arr1,arr2);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    // vector<int> res1=intersectionOfArray(arr1,arr2);
    // for(int i=0;i<res1.size();i++){
    //     cout<<res1[i]<<" ";
    // }



    // vector<int> arr={1,2,1,1,1,1,3,8,9,1,1,1,1,1,1};
    // cout<<maxconsecutiveones(arr);

    // vector<int>arr={1,2,3,1,2,3,5};
    // cout<<numberthatappearsonesothertwice(arr);



    // vector<int> arr={-1,0,1,-1,3,1,0,0,0,1};
    // cout<<longestSubarraywithsumk(arr,2);


    // vector<int> arr={6,8,4,2,3,7};
    // for (int i = 0; i < twosum(arr,13).size(); i++)
    // {
    //     cout<<twosum(arr,13)[i]<<" ";
    // }
    
    // return 0;

//     vector <int> arr={1,1,1,1,1,2,2,2,2,2,2,2,2,3,4};
//     cout<<majorityelement(arr);
// }


int maximumproductsubarray(vector<int> &arr){
    int product=1;
    int count=0;
    for(int i=0;i<arr.size();i++){
        product*=arr[i];
        if(arr[i]<0){
            count++;
        }
    }
    if(count%2==0) 
    return product;
}

int main(){
    vector<int> arr={1,-2,3,-4,5,-6};
    cout<<maximumproductsubarray(arr);
    return 0;
}