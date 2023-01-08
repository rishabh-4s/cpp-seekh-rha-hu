#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{

    vector<int> pq;

public:
    PriorityQueue()
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
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    // check later
    /*
    int removeMin()
    {

        int res = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;

        while (parentIndex < pq.size())
        {
            int lci = 2 * parentIndex + 1;
            int rci = 2 * parentIndex + 2;
            int mini = 0;
            // checking ki index out of range na ho jaaye
            if (lci < pq.size() && rci < pq.size())
                mini = min(pq[lci], pq[rci]);
            else if (lci < pq.size() && rci >= pq.size())
                mini = pq[lci];
            else
                break;
            // swapping
            if (pq[lci] == mini)
            {
                pq[lci] == pq[parentIndex];
                pq[parentIndex] = mini;
                parentIndex = lci;
            }
            else if (pq[rci] == mini)
            {
                pq[rci] == pq[parentIndex];
                pq[parentIndex] = mini;
                parentIndex = rci;
            }
        }
        return res;
    }
    */

    int removeMin()
    {

        int res = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int lci = 2 * parentIndex + 1;
        int rci = 2 * parentIndex + 2;

        while (lci < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[lci])
                minIndex = lci;

            if (rci < pq.size() && pq[rci] < pq[minIndex])
                minIndex = rci;

            if (minIndex == parentIndex)
                break;

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }

        return res;
    }

    void printer()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(0);
    p.insert(10);
    p.insert(20);
    p.insert(30);
    p.insert(40);
    p.insert(100);

    /*
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    cout << p.removeMin() << endl;
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    */

    p.printer();
    cout << p.removeMin() << endl;
    