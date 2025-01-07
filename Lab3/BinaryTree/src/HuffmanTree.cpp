#include "../include/HuffmanTree.h"

// 构造函数
HuffmanTreeNode::HuffmanTreeNode(char ch, int freq) : character(ch), frequency(freq) {
    left = right = nullptr;
}

// 重写 getValue 方法，返回字符
string HuffmanTreeNode::getValue() {
    return string(1, character);  // 返回字符
}

// 获取节点频率
int HuffmanTreeNode::getFrequency() const {
    return frequency;
}

// 构建哈夫曼树
HuffmanTreeNode* HuffmanTreeNode::buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    // 创建最小堆
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, freq_cmp> minHeap;

    // 将所有字符和频率加入堆中
    // DONE
    for(auto pair: freqMap){
        minHeap.push(new HuffmanTreeNode(pair.first, pair.second));
    }
    
    // 合并最小的两个节点，直到堆中只剩下一个节点
    // DONE
    while(minHeap.size() > 1){
        HuffmanTreeNode* left = minHeap.top();
        minHeap.pop();
        HuffmanTreeNode* right = minHeap.top();
        minHeap.pop();
        HuffmanTreeNode* parent = new HuffmanTreeNode('\0', left->getFrequency() + right->getFrequency());
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    // 返回哈夫曼树的根节点
    return minHeap.top();
}

// 打印哈夫曼树的编码（先序遍历）
void HuffmanTreeNode::printHuffmanCodes(HuffmanTreeNode* root, string code) {
    // TODO
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        cout<<root->getValue()<<": "<<code<<endl;
        return;
    }
    auto hufleft=dynamic_cast<HuffmanTreeNode*>(root->left);
    auto hufright=dynamic_cast<HuffmanTreeNode*>(root->right);
    printHuffmanCodes(hufleft, code + "0");
    printHuffmanCodes(hufright, code + "1");
}
