
#include <bits/stdc++.h>

using namespace std;

struct NodeDetails
{
    int data;
    int min, max;
};
bool levelOrderIsOfBST(int arr[], int n)
{
    if (n == 0)
        return true;

    queue<NodeDetails> q;
    int i = 0;

    NodeDetails newNode;
    newNode.data = arr[i++];
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);

    while (i != n && !q.empty())
    {
        NodeDetails temp = q.front();
        q.pop();

        if (i < n && (arr[i] < temp.data &&
                      arr[i] > temp.min))
        {
            newNode.data = arr[i++];
            newNode.min = temp.min;
            newNode.max = temp.data;
            q.push(newNode);
        }

        if (i < n && (arr[i] > temp.data &&
                      arr[i] < temp.max))
        {
            newNode.data = arr[i++];
            newNode.min = temp.data;
            newNode.max = temp.max;
            q.push(newNode);
        }
    }

    if (i == n)
        return true;

    return false;
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (levelOrderIsOfBST(arr, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
