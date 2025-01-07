#include "../include/BinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

// 构造函数的实现，初始化左右孩子为 nullptr
BinaryTreeNode::BinaryTreeNode() : left(nullptr), right(nullptr) {}

// 先序遍历的实现：访问根节点，然后先序遍历左子树，再先序遍历右子树
void BinaryTreeNode::PreOrderTraverse(BinaryTreeNode* root) {
    // 使用getValue()函数获得节点的值
    if (root != nullptr) {
        cout << root->getValue() << " ";
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
    else{
        return;
    }
    // DONE
}

// 中序遍历的实现：先中序遍历左子树，再访问根节点，最后中序遍历右子树
void BinaryTreeNode::InOrderTraverse(BinaryTreeNode* root) {
    if (root != nullptr) {
        InOrderTraverse(root->left);
        cout << root->getValue() << " ";
        InOrderTraverse(root->right);
    }
    else{
        return;
    }
    // DONE
}

// 后序遍历的实现：先后序遍历左子树，再后序遍历右子树，最后访问根节点
void BinaryTreeNode::PostOrderTraverse(BinaryTreeNode* root) {
    if (root != nullptr) {
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        cout << root->getValue() << " ";
    }
    else{
        return;
    }
    //DONE
}

// 层次遍历的实现：使用队列，按层级从上到下、从左到右遍历树
void BinaryTreeNode::LevelOrderTraverse(BinaryTreeNode* root) {
    std::queue<BinaryTreeNode> nq;
    nq.push(*root);
    while (!nq.empty()) {
        BinaryTreeNode node = nq.front();
        cout << node.getValue() << " ";
        nq.pop();
        if (node.left != nullptr) {
            nq.push(*node.left);
        }
        if (node.right != nullptr) {
            nq.push(*node.right);
        }
    }
    // DONE
}

// 辅助函数：通过中序和后序遍历构建树（递归实现）
BinaryTreeNode* BinaryTreeNode::buildTreeFromInorderPostorderHelper(const std::vector<std::string>& inorder, int inStart, int inEnd,
                                                                    const std::vector<std::string>& postorder, int postStart, int postEnd,
                                                                    std::unordered_map<std::string, int>& inorderMap) {
    // 递归终止条件
    if(inStart > inEnd || postStart > postEnd){
        return nullptr;
    }
    // DONE

    // 后序遍历的最后一个元素是根节点
    auto rootval=postorder[postEnd];
    // DONE

    // 获取根节点在中序遍历中的位置并计算左子树的大小
    int rootIndex=inorderMap[rootval];
    int leftSize=rootIndex-inStart;
    // DONE

    // 递归构建左子树和右子树
    auto node=new BinaryTreeNode();
    node->name=rootval;
    node->left=buildTreeFromInorderPostorderHelper(inorder,inStart,rootIndex-1,postorder,postStart,postStart+leftSize-1,inorderMap);
    node->right=buildTreeFromInorderPostorderHelper(inorder,rootIndex+1,inEnd,postorder,postStart+leftSize,postEnd-1,inorderMap);
    // DONE
    return node;
}

// 构建树的函数，调用辅助函数来构建二叉树
BinaryTreeNode* BinaryTreeNode::buildTreeFromInorderPostorder(const std::vector<std::string>& inorder, const std::vector<std::string>& postorder) {
    std::unordered_map<std::string, int> inorderMap;
    // 构建中序遍历值到索引的映射，方便快速查找
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    // 调用辅助函数开始构建树
    return buildTreeFromInorderPostorderHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
}

// 辅助函数：通过中序和前序遍历构建树（递归实现）
BinaryTreeNode* BinaryTreeNode::buildTreeFromInorderPreorderHelper(const vector<string>& inorder, int inStart, int inEnd, 
                                                                     const vector<string>& preorder, int preStart, int preEnd, 
                                                                     unordered_map<string, int>& inorderMap) {
    // 递归终止条件
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }
    // DONE

    // 前序遍历的第一个元素是根节点
    string rootVal = preorder[preStart];
    // DONE

    // 获取根节点在中序遍历中的位置并计算左子树的大小
    int rootIndex = inorderMap[rootVal];
    int leftSize = rootIndex - inStart;
    // DONE

    // 递归构建左子树和右子树
    BinaryTreeNode* root = new BinaryTreeNode();
    root->name = rootVal;
    root->left = buildTreeFromInorderPreorderHelper(inorder, inStart, rootIndex - 1, preorder, preStart + 1, preStart + leftSize, inorderMap);
    root->right = buildTreeFromInorderPreorderHelper(inorder, rootIndex + 1, inEnd, preorder, preStart + leftSize + 1, preEnd, inorderMap);
    // DONE
    return root;
}

// 构建树的函数，调用辅助函数来构建二叉树
BinaryTreeNode* BinaryTreeNode::buildTreeFromInorderPreorder(const vector<string>& inorder, const vector<string>& preorder) {
    unordered_map<string, int> inorderMap;
    // 构建中序遍历值到索引的映射
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    // 调用辅助函数开始构建树
    return buildTreeFromInorderPreorderHelper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inorderMap);
}

// getValue 虚函数的实现，返回当前节点的名字
string BinaryTreeNode::getValue() {
    return this->name;
}
