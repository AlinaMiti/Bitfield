#include <iostream>
#include <stdio.h>

struct Kortezh{
    double num;
    int count;
};

bool contein(double num, Kortezh* arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i].num == num)
            return true;
    }
    return false;
}

double Moda(int size, double*array){
    Kortezh* arr1 = new Kortezh[size];
    for(int i = 0; i < size; i++){
        if(contein(array[i], arr1, size)){
            arr1[i].count+=1;
        }
        else{
            arr1[i].num = array[i];
            arr1[i].count = 1;
        }
    }
    int max_cout = arr1[0].count;
    for (int i = 1; i < size; i++){
        if(arr1[i].count > max_cout)
            max_cout = arr1[i].count;
    }

    return max_cout;
}

int main(){
    int size = 100;
    double* array = new double[size];
    for (int i = 0; i < size; i++){
        array[i] = rand()%100 + (rand()%100)/1000;  
    }

    
    return 0;
}