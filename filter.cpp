#include<iostream>
#include<vector>
#include<variant>

using Element  = std::variant <int , char>;

void show(std::vector<Element> arr){
    for(int i = 0 ; i < arr.size() ; i++){
        std::visit([](auto&& arg){
            std::cout << arg << std::endl;
        },arr[i]);
    }
}
std::vector<int> fun( std::vector<int>* v , int num){
    int c = 0 ;
    for(auto item : *v){
        (*v)[c] = num;
        c++;
    }
    return *v;
}
// arr.filter( function(currentValue, index, arr) )
std::vector<int> filter( std::vector<int> arr ,bool (*callbackFn)(int curr , int i)){
    std::vector<int> result;
    int c = 0;
    for(auto item : arr){
        bool itemResult = callbackFn(item, c);
        if(itemResult == true){
            result.push_back(item);
        }
        c++;
    }
    return result;
}
bool checkPair(int item ,int i){

    if(item > 3){
        return true;
    }else{
        return false;
    }
}
int main(){

    std::vector<int> arr  = {1,2,3,4,5,6,6};
    std::vector<int> (*funcPtr)(std::vector<int>*,int) = fun; 
    // std::vector<int> returned = funcPtr(&arr , 121);
    std::vector<int> test = filter(arr , [](int item , int i )->bool{return item%2 == 0;});
    // std::vector<int> test = filter(arr ,checkPair);
    for(auto item : test){
        std::cout<<item<<"\n";
    }
    return 0;
}