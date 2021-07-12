#include <bits/stdc++.h>
using namespace std;
#define MAX 5

class CircularQueue
{
public:
    int front, rear;
    int a[MAX];
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int data);
    int dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};

bool CircularQueue::isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    return false;
}

bool CircularQueue::isFull()
{
    if (front == 0 && rear == MAX - 1)
    {
        return true;
    }
    if (front == rear + 1)
    {
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        a[rear] = data;
    }
}

int CircularQueue::dequeue()
{
    int val = 0;
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return 0;
    }
    else
    {
        val = a[front];
        front = (front + 1) % MAX;
    }
    return val;
}

void CircularQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    CircularQueue q;
    q.display();
    q.enqueue(14);
    q.display();
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    q.display();
    q.enqueue(20);
    return 0;
}