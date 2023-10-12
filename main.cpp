#include <iostream>

void fillListRandom(int * list, int listLength) {
    // Get Seed
    srand(time(NULL));

    // Fill List with random values
    for (int i = 0; i < listLength; i++) {
        list[i] = rand() % listLength;
    }

}

void sort(int * list, int listLength) {
    bool sorted = true;

    for (int i = 0; i < listLength-1; i++) {
        if (list[i] > list[i+1]) {
            sorted = false;
            // swap
            int temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
        }
    }
    if (sorted == false) sort(list, listLength);
}

void printList(int * list, int listLength, std::string text) {
    std::cout << text << std::endl;
    for (int i = 0; i < listLength; i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    const int listLength = 10;
    int list[listLength] = { 0L };

    printList(list, listLength, "unsorted list");

    fillListRandom(list, listLength);

    printList(list, listLength, "unsorted list");

    sort(list, listLength);

    printList(list, listLength, "sorted Liste");
}
