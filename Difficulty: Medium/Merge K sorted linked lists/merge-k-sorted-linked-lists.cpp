//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if (arr.empty()) return nullptr;
        return merge(arr, 0, arr.size() - 1);
    }
    
    private:
    Node* merge(vector<Node*>& arr, int l, int r) {
        if (l == r) return arr[l];
        int mid = l + (r - l) / 2;
        Node* l1 = merge(arr, l, mid);
        Node* l2 = merge(arr, mid + 1, r);
        return mergeTwoLists(l1, l2);
    }
    
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node x(0);
        Node* y = &x;
        while (l1 && l2) {
            if (l1->data < l2->data) {
                y->next = l1;
                l1 = l1->next;
            } else {
                y->next = l2;
                l2 = l2->next;
            }
            y = y->next;
        }
        if (l1) y->next = l1;
        if (l2) y->next = l2;
        return x.next;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends