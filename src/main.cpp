#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int input_array_size, input_queries;

    cin >> input_array_size;
    cin >> input_queries;

    int **a = new int *[input_array_size];

    for(int i = 0; i < input_array_size; i++){
        int k;
        cin >> k;
        a[i] = new int [k];

        for (int j = 0; j < k; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < input_queries; i++){
        int input_query_x, input_query_y;

        cin >> input_query_x;
        cin >> input_query_y;

        cout << a[input_query_x][input_query_y] << endl;
    }

}
