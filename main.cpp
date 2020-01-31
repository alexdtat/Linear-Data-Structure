#include <iostream>

using namespace std;

struct Simple_vector{
    int vec_size;
    int vec_capacity;
    int* data;

    Simple_vector (int x){
        vec_size = x;
        vec_capacity = x;
        data = new int[vec_capacity];
    }

    ~Simple_vector(){
        delete [] data;
    }


    Simple_vector (const Simple_vector &V){
        if (this != &V){
            vec_size = V.vec_size;
            vec_capacity = V.vec_capacity;
            data = new int[vec_capacity];
            for (int i = 0; i < vec_size; i++){
                data[i] = V.data[i];
            }
        }
    }

    const Simple_vector& operator= (const Simple_vector& V){
        if (this == &V) return *this;
        delete [] data;
        vec_size = V.vec_size;
        vec_capacity = V.vec_capacity;
        data = new int[vec_capacity];
        for (int i = 0; i < vec_size; i++) data[i] = V.data[i];
        return *this;
    }

    int &operator [] (int i){
        if ((i < 0) || (i >= vec_size)){
            cout << "Err\n";
            return data[0];
        };
        return data[i];
    }

    void push_back_vec (int x){
        if (vec_size == vec_capacity){
            vec_capacity *= 2;
            int* temp = new int [vec_capacity];
            for (int i = 0; i < vec_size; i++) temp[i] = data[i];
            delete [] data;
            data = temp;
        }
        data [vec_size] = x;
        vec_size++;
    }

    void resize_vec (int s){
        if (s > vec_capacity) vec_capacity += s - vec_capacity;
        vec_size = s;
    }
};

int main()
{
    int test_size = 0;
    int usnum = 0;
    int usel = 0;
    int ussize = 0;
    cout << "Vector size input:\n";
    cin >> test_size;
    Simple_vector test_vec(test_size);
    cout << "The test vector is created.\n";
    Simple_vector second_vec = test_vec;
    cout << "The identical vector is created.\n";
    cout << "Input a number:\n";
    cin >> usnum;
    cout << "The " << usnum << " element of the vector: " << test_vec [usnum] << '\n';
    cout << "Input a number for new element creation:\n";
    cin >> usel;
    test_vec.push_back_vec (usel);
    cout << "The vector has been updated.\n";
    cout << "Input the new size of vector:\n";
    cin >> ussize;
    test_vec.resize_vec(ussize);
    cout << "The size has been updated.\n";
    return 0;
}
