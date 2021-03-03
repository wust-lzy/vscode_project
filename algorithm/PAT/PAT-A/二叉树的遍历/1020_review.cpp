#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int post[35],in[35];
vector<int> ans;
struct node
{
    int val;
    node *left, *right;
};
node* pre(int root,int start,int end)
{
    if(start>end)
        return NULL;
    int i = start;
    while(i<end&&post[root]!=in[i])
        i++;
    node *t = new node();
    t->val = post[root];
    t->left = pre(root - (end - i + 1), start, i - 1);
    t->right = pre(root - 1, i + 1, end);
    return t;
}
void bfs(node* root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }  
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> post[i];
    for (int i = 0; i < n;i++)
        cin >> in[i];
    node *root = pre(n - 1, 0, n-1);
    bfs(root);
    for (int i = 0; i < n;i++)
    {
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
        return 0;
}