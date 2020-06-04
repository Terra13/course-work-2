#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    float arr[10];
    float sum = 0;
    int count = 0, min = 101;

    for(int i = 0; i < 10; i++) {

        arr[i] = 100 - rand() % 201;
        cout << arr[i] << " ";

        if (arr[i] < min) min = arr[i];
        if(arr[i] < 0) {
            sum += arr[i];
            count++;
        }
    }

    cout << endl << "min = " << min;
    cout << endl << sum/count << endl;

    for (int i = 0; i < 10; i++){
        if(arr[i] == min) arr[i] = sum/count;
        cout << arr[i] << " ";
    }

    return 0;
}
