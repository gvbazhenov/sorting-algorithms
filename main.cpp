#include <iostream>
#include <vector>
#include <iterator>
#include <random>

void insertionSort(std::vector<int> &);
void sinkingSort(std::vector<int> &);
void printSequence(std::vector<int> &);

int main()
{
    size_t defaultSize = 10;
    std::vector<int> vector = {};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t iter = 0; iter != defaultSize; iter++) // random writing
        vector.push_back(distribution(generator));

    printSequence(vector); // printing the original sequence
    insertionSort(vector); // proceeding the sorting
    printSequence(vector); // printing the sorted sequence

    return 0;
}

void printSequence(std::vector<int> &vector)
{
    for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
}

void insertionSort(std::vector<int> &vector)
{
    int key = 0, inIter = 0;

    for (size_t outIter = 2; outIter < vector.size(); outIter++)
    {
        key = vector[outIter];
        inIter = outIter - 1;

        while (inIter > -1 && vector[inIter] > key) // checking the opportunity to shift elements
        {
            vector[inIter + 1] = vector[inIter];
            inIter--;
        }
        vector[inIter + 1] = key; // inserting
    }
}
