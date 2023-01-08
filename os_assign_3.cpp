#include <iostream>
#include <vector>
using namespace std;
int32_t2 main()
{
    FIO int customer_count;
    cin >> customer_count;
    vector<trio> v(customer_count);
    vector<int> v1(customer_count);
    loop(i, 0, customer_count)
    {
        cin >> v[i].arrival_time;
        v[i].position = i;
    }
    loop(i, 0, customer_count)
    {
        cin >> v[i].burst_time;
    }
    loop(i, 0, customer_count)
    {
        cin >> v[i].cost;
    }
    priority_queue<trio, vector<trio>, com> pq;
    int time = 0;
    int count = 0;
    sort(v.begin(), v.end(), vecom);
    pq.push(v[0]);
    int i = 1;
    cout << "Billing Sequence is: ";
    while (!pq.empty())
    {
        trio top = pq.top();
        pq.pop();
        if (time - top.arrival_time >= 0)
        {
            v1[top.position] = time - top.arrival_time;
        }
        else
        {
            time += time - top.arrival_time;
            v1[top.position] = 0;
        }
        time += top.burst_time;
        cout << "C" << top.position + 1 << " ";
        v[top.position].turnAround = time - top.arrival_time;
        while (i < customer_count And
                       v[i]
                           .arrival_time <= time)
        {
            pq.push(v[i]);
            i++;
        }
    }
    cout << endl;
    cout << "Waiting time for each Customer is:-" << endl;
    int avgWaiting = 0;
    int avgTurnAround = 0;
    loop(i, 0, customer_count)
    {
        cout << "C" << i + 1 << ":" << v1[i] << endl;
        avgWaiting += v1[i];
    }
    cout << "Average waiting time is: " << (avgWaiting * 1.0) / customer_count << endl;
    cout << "TurnAround time for each Customer is:-" << endl;
    loop(i, 0, customer_count)
    {
        cout << "C" << i + 1 << ":" << v[i].turnAround << endl;
        avgTurnAround += v[i].turnAround;
    }
    cout << "Average waiting time is: " << (avgTurnAround * 1.0) / customer_count << endl