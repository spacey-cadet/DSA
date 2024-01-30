#include <iostream>
#include <vector>

using namespace std;
 pair<int , int> findMaxSubArray(const vector<int>& inputarray){
    int max_sum = inputarray[0];
    int current_sum = inputarray[0];
    int start_index = 0;
    int end_index = 0;
    int temp_start_index = 0;
    for(int i=1; i< inputarray.size(); ++i){
        if(inputarray[i] > current_sum + inputarray[i]){
            current_sum = inputarray[i];
            temp_start_index= i;
        } else{
            current_sum += inputarray[i];
        }

        if(current_sum > max_sum){
            max_sum = current_sum;
            start_index = temp_start_index;
            end_index = i;
        }
    }
    return make_pair(start_index, end_index);
 }

 int main(){
    vector <int> inputarray = {-2, 3 , 5 ,-3 ,0 , 3, -5, 8};
    pair<int, int>  result = findMaxSubArray(inputarray);
    cout << "Maximum subarray is: (" << result.first << result.second << ")" << endl ;
    return 0;
 }

