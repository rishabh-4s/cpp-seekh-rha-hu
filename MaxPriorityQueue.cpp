#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue
{
    vector<int> pq;

    public:
    MaxPriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // no. of elements in the priority queue
    int getSize()
    {
        return pq.size();
    }

    // min element of pq which is the 0th element of the vector
    int getMaz()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    void printer()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)      
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;

            }
            else break;

            childIndex = parentIndex;
        }
        
    }
};

int main()
{
    MaxPriorityQueue m;
    m.insert(10);
    m.insert(20);
    m.insert(30);
    m.printer();
}