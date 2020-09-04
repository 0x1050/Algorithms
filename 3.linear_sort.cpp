/* Linear Sort
 * --------------------------------------------------------
 *  Linear sort is an algorithm that sorts in place.
 *  -------------------------------------------------------
 *
 *  Input: A sequence of numbers A=(a₁, a₂,..,aₙ) where
 *  each element is unique
 *
 *  Output: A permutation A'=(a'₁,a'₂,...,a'ₙ) of the input
 *  sequence such that ----------------> a'₁≤a'₂≤...≤a'ₙ
 *
 *  -------------------------------------------------------
 *
 *  The index i separates the array into two subarrays, the
 *  left being sorted. Unlike insertion sort, the left
 *  subarray does not contain the same elements with which
 *  it began.
 *
 *  Initialization: A[0] is the boundary that separates the
 *  two subarrays. Since the current position is zero, there
 *  are no elements to the left that need to be sorted.
 *
 *  Maintenance: Each iteration finds the lowest value from
 *  A[i] to a[length-1]. It then swaps the lowest value
 *  with the value in position A[i] if A[i] is higher.
 *  This ensures that any values to the from A[0] to A[i]
 *  are not only sorted, but also less than A[i].
 *
 *  Termination: Since each iteration incremented i by one,
 *  the maintenance of the algorithm ensures that the array
 *  is now in the order of (a'₁≤ a'₂≤...≤a'ₙ).
 *
 *  The for loop when no swaps are made or at i=n-2. In the
 *  first case, if there are no swaps to be made, then the
 *  array is already sorted. In the second case, the loop
 *  stops at n-2 because the sorting of numbers at positions
 *  lower left of A.length-2 only leaves one element, which
 *  due to the maintenance is larger than the rest. Because
 *  these two suppositions hold true, we can say that the 
 *  algorithm is correct.
 *
 *  --------------------------------------------------------
 *
 *                      In Action
 *                      ---------
 *  Iteration | array   | work done
 *  -------------------------------------------------------
 *  i=0=n-2   | 3 1 2   |
 *            | i       | i=0
 *            | j       | j=i
 *            | k       | k=i=0
 *            ---------------------------------------------
 *            | 3 1 2   |
 *            | i j     | increment j
 *            |   k     | a[j]<a[key_index],  key_index=j
 *            ---------------------------------------------
 *            | i   j   | increment j
 *            |     k   | a[j]>a[key_index], do nothing
 *            ---------------------------------------------
 *            | 3 1 2   | increment j, j=n, terminate loop
 *            | i k   j |
 *            ---------------------------------------------
 *            | 1 3 2   | swap a[i], a[key_index]
 *  -------------------------------------------------------
 *  i=n-1=1   | 1 3 2   |
 *            |   i     | i=1
 *            |   j     | j=i
 *            |   k     | key_index=i
 *            ---------------------------------------------
 *            | 1 3 2   |
 *            |   i j   | increment j
 *            |     k   | a[j]>a[key_index], key_index=j
 *            ---------------------------------------------
 *            | 1 3 2   |
 *            |   i k j | increment j, j=n-1, terminate loop
 *            ---------------------------------------------
 *            | 1 2 3   | swap a[i], a[key_index]
 *  -------------------------------------------------------
 *                      Best case
 *                      ---------
 *  teration | array   | work done
 *  -------------------------------------------------------
 *  i=1      | 1 2 3   |
 *           | i       | i=0
 *           | j       | j=i
 *           | k       | k=i
 *           ----------------------------------------------
 *           |   j     | increment j, a[j]>a[key_index]
 *           |     j   | increment j, a[j]>a[key_index]
 *           |       j | increment j, j=n-1, terminate loop
 *           ----------------------------------------------
 *           | 1 2 3   |
 *           | i     j |
 *           | k       | a==key_index, return
 *  -------------------------------------------------------
 *
 *  Runtime: As you can see, this algorithm scans the right
 *  subarray every iteration. This means it would perform
 *  n+c operations for the first iteration and n-1+c for
 *  each subsequent operation with c being the constant for
 *  swapping two elements. This time also applies to any
 *  sequence that is comprised of any number repeated n
 *  times. This gives us a worst case running time of
 *  T(n)=(n*n-1)/2+nc or more simply: O(n²), making this a
 *  highly inneficient algorithm to use in most cases.
 *
 *  -----------------------------------------------------*/
#include <iostream>

void linear_sort(int *a,int n) {
   int key_index;
   int j;
   for (int i=0;i<n-1;i++) {
        key_index = i;
        for (j=i;j<n;j++) {
            if (a[j] <= a[key_index])
                key_index = j;
        }
        std::swap(a[i], a[key_index]);
    }
}

int main() {
    int n;
    std::cin >> n;

    int a[n];

    int m;
    for (int i=0;i<n;i++) {
        std::cin >> m;
        a[i] = m;
    }

    linear_sort(a, n);

    for (int i=0;i<n;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}
