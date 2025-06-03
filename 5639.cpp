#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d\n", node->val);
}

int main() {
    int val;
    vector<int> preorder;

    // 전위 순회 입력 받기
    while (scanf("%d", &val) != EOF) {
        preorder.push_back(val);
    }

    if (preorder.empty()) return 0;

    // 첫 번째 값을 루트로 생성
    Node* root = new Node(preorder[0]);
    stack<Node*> stk;
    stk.push(root);

    for (size_t i = 1; i < preorder.size(); ++i) {
        Node* node = new Node(preorder[i]);

        if (preorder[i] < stk.top()->val) {
            // 왼쪽 자식
            stk.top()->left = node;
            stk.push(node);
        } else {
            // 오른쪽 자식을 붙일 부모 찾기
            Node* parent = nullptr;
            while (!stk.empty() && stk.top()->val < preorder[i]) {
                parent = stk.top();
                stk.pop();
            }
            parent->right = node;
            stk.push(node);
        }
    }

    postorder(root);
    return 0;
}