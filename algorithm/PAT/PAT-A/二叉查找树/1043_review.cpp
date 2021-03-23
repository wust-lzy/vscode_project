#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val;
    node *l, *r;
};
void ins(node *&root,int data)
{
    if(root==nullptr)
    {
        root = new node();
        root->val = data;
        root->l = root->r = nullptr;
        return;
    }
    if(data<root->val)
        ins(root->l, data);
    else
        ins(root->r, data);
}
node* buildTree(vector<int>&v)
{
    node *root = nullptr;
    for (int i = 0; i < v.size();i++)
        ins(root, v[i]);
    return root;
}
void preBuild(node *root,vector<int>&vi)
{
    vi.push_back(root->val);
    if(root->l!=nullptr)
        preBuild(root->l, vi);
    if(root->r!=nullptr)
        preBuild(root->r, vi);
}
void pre_mirrorBuild(node *root,vector<int>&vi)
{
    vi.push_back(root->val);
    if(root->r!=nullptr)
        pre_mirrorBuild(root->r, vi);
    if(root->l!=nullptr)
        pre_mirrorBuild(root->l, vi);
}
void postBuild(node *root,vector<int>&vi)
{
    if(root->l!=nullptr)
        postBuild(root->l, vi);
    if(root->r!=nullptr)
        postBuild(root->r, vi);
    vi.push_back(root->val);
}
void post_mirrorBuild(node *root,vector<int>&vi)
{
    if(root->r!=nullptr)
        post_mirrorBuild(root->r, vi);
    if(root->l!=nullptr)
        post_mirrorBuild(root->l, vi);
    vi.push_back(root->val);
}
int main()
{
    int n;
    cin >> n;
    vector<int> origin, pre, prem;
    for (int i = 0; i < n;i++)
    {
        int t;
        scanf("%d", &t);
        origin.push_back(t);
    }
    node *root = buildTree(origin);
    preBuild(root, pre);
    pre_mirrorBuild(root, prem);
    if((origin!=pre)&&(origin!=prem))
    {
        cout << "NO\n";
        return 0;
    }
    vector<int> ans;
    printf("YES\n");
    if(origin==pre)
        postBuild(root, ans);
    else if(origin==prem)
        post_mirrorBuild(root, ans);
    for (int i = 0; i < n;i++)
    {
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
    return 0;
}