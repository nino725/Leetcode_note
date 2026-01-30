/*
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
*/
1.定义树的结构
struct node{
    node* son[26]{}; //大括号全都初始化为空指针
    bool end = false;
};

class Trie {
public:
    //创建根节点
    node* root = new node();

    //查找函数
    int find(string word){
        node* cur = root;
        for(char& a : word){
            a -= 'a';
            if(cur->son[a] == nullptr){
                return 0;
            }
            cur = cur->son[a];
        }
        return cur->end ? 2 : 1;
    }

    //销毁树
    void destory(node* Node) {
        if(Node == nullptr){
            return;
        }
        for(node* cur : Node->son){
            destory(cur);
        }
        delete Node;
    }

    ~Trie(){
        destory(root);
    }
    
    void insert(string word) {
        node* cur = root;
        for(auto& w : word){
            w -= 'a';
            if(cur->son[w] == nullptr){
                cur->son[w] = new node();
            }
            cur = cur->son[w];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        int a = find(word);
        return a == 2;
    }
    
    bool startsWith(string prefix) {
        int a = find(prefix);
        return a != 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */