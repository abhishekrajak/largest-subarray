#include <iostream>
#include <vector>

using namespace std;

/*
 * Kadane's Algorithm
 * does not work when all elements are (-)ve
 **/
int largest_subarrayX(vector<int>& data){
    int max_so_far = 0, max_ends_here = 0;
    for(int i : data){
        max_ends_here += i;
        max_ends_here = max_ends_here<0?0:max_ends_here;
        max_so_far = max_ends_here>max_so_far?max_ends_here:max_so_far;
    }
    return max_so_far;
}

int largest_subarrayY(vector<int>& data){
    int max_so_far = data[0], max_ends_here = data[0];
    for(int i=1; i<data.size(); i++){
        max_ends_here = max(max_ends_here, max_ends_here + data[i]);
        max_so_far = max(max_so_far, max_ends_here);
    }
    return max_so_far;
}

int main(){

    vector<int> data = {-2,1,-3,4,-1,2,1,-5,4};

    cout << largest_subarrayX(data) << endl;

    data.clear();

    data = {-1, -2, -3, -4};

    cout << largest_subarrayY(data) << endl;

    return 0;
}
