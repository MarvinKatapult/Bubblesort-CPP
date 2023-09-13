#include <iostream>


void sort(int * list, int listLength);
void fillListRandom(int * list, int listLength);
void printList(int * list, int listLength, std::string text);

int main() {
    const int listLength = 10;
    int list[listLength];

    fillListRandom(list, listLength);

    printList(list, listLength, "Unsortierte Liste");

    sort(list, listLength);

    printList(list, listLength, "Sortierte Liste");
}

void fillListRandom(int * list, int listLength) {
    // seed random generator
    srand(time(NULL));

    for (int i = 0; i < listLength; i++) {
        list[i] = rand() % listLength;
    }
}


void sort(int * list, int listLength) {
    bool sorted = true;
    for (int i = 0; i < listLength-1; i++) {
        if (list[i] > list[i+1]) {
            sorted = false;
            int temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
        }
    }
    if (sorted == false) {
        sort(list, listLength);
    }
}

void printList(int * list, int listLength, std::string text) {
    std::cout << text << std::endl;
    for (int i = 0; i < listLength; i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}