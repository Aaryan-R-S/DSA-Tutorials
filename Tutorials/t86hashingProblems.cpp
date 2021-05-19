#include<bits/stdc++.h>
using namespace std;

// given an array find count freq of each elem
void countFreq(){
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    map<int, int> myMap;

    for (int i = 0; i < n; i++)
    {
        myMap[v[i]]++;
    }
    
    for (auto &i : myMap)
    {
        cout<<i.first<<": "<<i.second<<endl;;
    }
    
}

// print vertical order traversal of a binary tree
class Node{
    public:
        Node* left;
        int data;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        };

        void setPtr(Node* l, Node* r){
            this->left = l;
            this->right = r;
        };
};

void inOrder(Node* n){
    if (n!=NULL)
    {
        inOrder(n->left);
        cout<<n->data<<" ";
        inOrder(n->right);
    }
};

void setMap(Node* n, int dist, map<int, vector<int>> &m){
    if(n!=NULL){
        m[dist].push_back(n->data);
        setMap(n->left, dist-1, m);
        setMap(n->right, dist+1, m);
    }
    return;
}

void verticalOrderPrint(){

/*
         7
     4      5
   1   2    0   3
      9    8
*/

    //Preorder - 7 4 1 2 9 5 0 8 3
    //Inorder - 1 4 9 2 7 8 0 5 3
    //Postorder - 1 9 2 4 8 0 3 5 7
    
    Node* Root = new Node(7);
    Node* N1 = new Node(4);
    Node* N2 = new Node(5);
    Node* N3 = new Node(1);
    Node* N4 = new Node(2);
    Node* N5 = new Node(9);
    Node* N6 = new Node(0);
    Node* N7 = new Node(3);
    Node* N8 = new Node(8);

    Root->setPtr(N1, N2);
    N1->setPtr(N3, N4);
    N4->setPtr(N5, NULL);
    N2->setPtr(N6, N7);
    N6->setPtr(N8, NULL); 

    // inOrder(Root);
    // cout<<endl;

    map<int, vector<int>> m;
    setMap(Root, 0, m);

    for (auto &&i : m)
    {
        cout<<i.first<<" -> ";
        for (auto &&j : i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

}

// Count no of subarrays with sum zero
void sumZero(){
    int n;cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    map<int,int> myMap;

    int preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += v[i];
        myMap[preSum]++;
    }
    
    int ans = 0;
    for (auto &i : myMap)
    {
        int c = i.second;
        ans += (c*(c-1))/2;

        if(i.first==0){
            ans += c;
        }
    }

    cout<<ans<<endl;
    
}

int main(){
    // countFreq();

    // verticalOrderPrint();

    // sumZero();

    return 0;
}