class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, TreeNode*> parentMap;
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode->val == destValue)
                return backtrackPath(currentNode, pathTracker);
            if (parentMap.find(currentNode->val) != parentMap.end()) {
                TreeNode* parentNode = parentMap[currentNode->val];
                if (visitedNodes.find(parentNode) == visitedNodes.end()) {
                    q.push(parentNode);
                    pathTracker[parentNode] = {currentNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }
            if (currentNode->left != nullptr &&
                visitedNodes.find(currentNode->left) == visitedNodes.end()) {
                q.push(currentNode->left);
                pathTracker[currentNode->left] = {currentNode, "L"};
                visitedNodes.insert(currentNode->left);
            }
            if (currentNode->right != nullptr &&
                visitedNodes.find(currentNode->right) == visitedNodes.end()) {
                q.push(currentNode->right);
                pathTracker[currentNode->right] = {currentNode, "R"};
                visitedNodes.insert(currentNode->right);
            }
        }
        return "";
    }

private:
    string backtrackPath(
        TreeNode* node,
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker) {
        string path;
        while (pathTracker.count(node)) {
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void populateParentMap(TreeNode* node, unordered_map<int, TreeNode*>& parentMap) {
        if (node == nullptr) return;
        if (node->left != nullptr) {
            parentMap[node->left->val] = node;
            populateParentMap(node->left, parentMap);
        }

        if (node->right != nullptr) {
            parentMap[node->right->val] = node;
            populateParentMap(node->right, parentMap);
        }
    }

    TreeNode* findStartNode(TreeNode* node, int startValue) {
        if (node == nullptr) return nullptr;
        if (node->val == startValue) return node;
        TreeNode* leftResult = findStartNode(node->left, startValue);
        if (leftResult != nullptr) return leftResult;
        return findStartNode(node->right, startValue);
    }
};