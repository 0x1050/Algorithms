/* --------------------------------------------------------
 *
 * Insertion sort is an algorithm that sorts in place.
 * The numbers to be sorted are called keys.
 *
 * --------------------------------------------------------
 *
 * Input: A sequence of n numbers (a₁,a₂,..aₙ).
 *
 * Output: A permutation (a'₁, a'₂,..., a'ₙ) of the
 * input sequence such that -----> a'₁≤ a'₂≤ ... ≤ a'ₙ
 *
 * --------------------------------------------------------
 *
 * The index i indicates the current key being inserted
 * At the beginning of each iteration, the subarray
 * A[0..i-1] is considered sorted while a[i+1..n] is
 * unsorted.
 *
 * The sorted side contains the same elements that it began
 * with, the only difference being that they are now sorted.
 * This is formally called a loop invariant.
 *
 *                      ---------
 *
 * Loop invariants are useful to understand whether or not
 * an algorithm is correct. to do this, we need to show
 * three things about a loop invariant:
 *
 * Initialization: It is true prior to the first iteration
 * of the loop.
 *
 * Maintenance: If it is true before the first iteration of
 * the loop, it remains true before the next iteration.
 *
 * Termination: When the loop terminates, the invariant
 * gives us a useful property that helps show that the
 * algorithm is correct.
 *
 *                      ---------
 *
 * If the first two properties are valid, the invariant
 * becomes true before each iteration of the loop. This is
 * similar to the concept of mathematical induction.
 *
 * The termination phase is different from mathematical
 * induction in the sense that there is in fact a final
 * iteration, whereas in mathematics, we go onto infinity.
 *
 * Let's observe the properties:
 *
 * Initialization: We need to show that the first invariant
 * is true. This is done by observing that A[0..a-1] is
 * comprised of exactly one element. By it's very nature,
 * a list of one element is sorted.
 *
 * Maintenance: Does each iteration maintain the loop
 * invariant? Looking at the operations conducted, we can
 * observe that every iteration pushes all of the numbers
 * smaller than the current key one to the right. This makes
 * room for the key to be placed properly while keeping
 * the lesser element to the left and the larger elements
 * to the right, preserving the sorted state.
 *
 * Termination: The for loop terminates a i>A.length=n.
 * Since each iteration increases i by 1, we have j=n+1
 * at each iteration. Substituting n+1 for i in the wording
 * of loop invariant, we see that the subarray A[1..n]
 * consist of the elements originally in A[1..n], but in
 * sorted order. Seeing that A[1..n] represents the entire
 * array, we can say that the array is sorted when the
 * program is finished. Hence, the algorithm is correct.
 *
 * ---------------------------------------------------------
 *
 *                      In Action
 *                      ---------
 *
 * Iteration |  array       | work
 * ----------|--------------|-------------------------------
 * i=1       |  3 5 4 6 2 1 | key = a[i] = 5
 *           |  j i         | key>j, continue
 * ----------|--------------|-------------------------------
 * i=2       |  3 5 4 6 2 1 | key = a[i] = 4;
 *           |    j i       | key>j
 *           |  3 5 5 6 2 1 | copy j to j+1
 *           |  j   i       | decrement j, key>j, continue
 * ----------|--------------|-------------------------------
 * i=3       |  3 4 5 6 2 1 | key = a[i] = 6
 *           |      j i     | key>j, continue
 * ----------|--------------|-------------------------------
 * i=4       |  3 4 5 6 2 1 | key = a[i] = 2
 *           |        j i   | key<j
 *           |  3 4 5 6 6 1 | copy j to j+1
 *           |      j   i   | decrement j, key<j
 *           |  3 4 5 5 6 1 | copy j to j+1
 *           |    j     i   | decrement j, key<j
 *           |  3 4 4 5 6 1 | copy j to j+1
 *           |  j       i   | decrement j, key<j
 *           |  3 3 4 5 6 1 | copy j to j+1
 *           |j         i   | decrement j, j<0, continue
 *           |  2 3 4 5 6 1 | copy key to j+1
 * -------------------------|------------------------------
 * i=5       |  2 3 4 5 6 1 | key = a[i] = 1
 *           |          j i | key<j
 *           |  2 3 4 5 6 6 | copy j to j+1
 *           |        j   i | decrement j, key<j
 *           |  2 3 4 5 5 6 | copy j to j+1
 *           |      j     i | decrement j, key<j
 *           |  2 3 4 4 5 6 | copy j to j+1
 *           |    j       i | decrement j, key<j
 *           |  2 3 3 4 5 6 | copy j to j+1
 *           |  j         i | decrement j, key<j
 *           |  2 2 3 4 5 6 | copy j to j+1
 *           |j           i | decrement j, j<0
 *           |  1 2 3 4 5 6 | copy key to j+1
 * -------------------------|----------------------------*/
#include <iostream>

void insertion_sort(int *a, int n) {
    int key;
    int j;
    for (int i=1; i<n;i++) {
        key = a[i];
        j = i-1;
        while (j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


int main() {
    int n;
    std::cout << "How many numbers to sort? ";
    std::cin >> n;

    int a[n];
    int m;
    for (int i=0; i<n;i++) {
        std::cin >> m;
        a[i] = m;
    }

    insertion_sort(a, n);

    for (int i=0; i<n;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}
