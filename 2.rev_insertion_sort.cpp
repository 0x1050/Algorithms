#include <iostream>

void rev_ISort(int *a, int n) {
    int key;
    int j;
    for (int i=n-2;i>=0;i--) {
        key = a[i];
        j = i+1;
        while (j<n && a[j]>key) {
            a[j-1] = a[j];
            j++;
        }
        a[j-1] = key;
    }
}

int main() {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;

    int a[n];
    int m;
    std::cout << "What numbers? ";
    for (int i=0;i<n;i++) {
        std::cin >> m;
        a[i] = m;
    }

    rev_ISort(a, n);

    for (int i=0; i<n;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}

