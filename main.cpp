#include <iostream>

using namespace std;

struct Simple_array{
    int arr_size;
    int* data;

    Simple_array (int x){
        arr_size = x;
        data = new int[arr_size];
    }

    ~Simple_array(){
        delete [] data;
    }


    Simple_array (const Simple_array &A){
        if (this != &A){
            arr_size = A.arr_size;
            data = new int[arr_size];
            for (int i = 0; i < arr_size; i++){
                data[i] = A.data[i];
            }
        }
    }

    const Simple_array& operator= (const Simple_array& A){
        if (this == &A) return *this;
        delete [] data;
        arr_size = A.arr_size;
        data = new int[arr_size];
        for (int i = 0; i < arr_size; i++) data[i] = A.data[i];
        return *this;
    }

    int &operator [] (int i){
        if ((i < 0) || (i >= arr_size)){
            cout << "Err\n";
            return data[0];
        };
        return data[i];
    }
};

int main()
{
    int test_size = 0;
    int usnum = 0;
    cout << "Array size input:\n";
    cin >> test_size;
    Simple_array test_arr(test_size);
    cout << "The test array is created.\n";
    Simple_array second_arr = test_arr;
    cout << "The identical array is created.\n";
    cout << "Input a number:\n";
    cin >> usnum;
    cout << "The " << usnum << " element of the array: " << test_arr [usnum] << '\n';
    return 0;
}
