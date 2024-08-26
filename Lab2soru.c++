#include <iostream>
#include <vector>
using namespace std;

// Bağlı liste düğümü yapısı
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(NULL) {}
};

// Heap yapısı
class MaxHeap {
public:
    vector<int> array;

    void maxHeapify(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < array.size() && array[left] > array[largest])
            largest = left;

        if (right < array.size() && array[right] > array[largest])
            largest = right;

        if (largest != idx) {
            swap(array[idx], array[largest]);
            maxHeapify(largest);
        }
    }

    void buildHeap() {
        for (int i = array.size() / 2 - 1; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    void printHeap() {
        for (size_t i = 0; i < array.size(); ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// Bağlı listeyi heap'e dönüştüren fonksiyon
MaxHeap listToMaxHeap(ListNode* head) {
    MaxHeap heap;
    ListNode* current = head;
    while (current != NULL) {
        heap.array.push_back(current->data);
        current = current->next;
    }
    heap.buildHeap();
    return heap;
}

int main() {
    // Bağlı listeyi oluşturma
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(9);

    // Bağlı listeyi max-heap'e dönüştürme
    MaxHeap maxHeap = listToMaxHeap(head);

    // Heap'i yazdırma
    cout << "Max Heap Agac Yapisi: ";
    maxHeap.printHeap();

    return 0;
}