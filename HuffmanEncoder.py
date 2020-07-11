import HuffmanTree
from stack_based_on_list import Stack

#传入huffman_tree,以字典形式返回哈夫曼编码
def huffman_encoder(huffman_tree):
    '''
    默认左0右1
    '''
    #首先将所有叶子结点存入一个list中
    def search_leaf(root,leaf_list = []):
        if root.leftchild == None and root.rightchild == None:
            leaf_list.append(root)
        else:
            if root.leftchild != None:
                search_leaf(root.leftchild)
            if root.rightchild != None: 
                search_leaf(root.rightchild)
        return leaf_list
    leaf_list = search_leaf(huffman_tree)
    #构建编码字典
    coding_dic = {}
    #从每一个叶子结点出发,不断向上左右移动，直到找到根结点停止，将其存入字典中
    for leaf in leaf_list:
        #构建一个栈
        stack = Stack()
        #保存leaf,其weight域在最后要作为coding_dic的key
        leaf_copy = leaf
        #向上左右移动到根结点是终止循环条件
        while(leaf_copy != huffman_tree):
            #若leaf是左孩子
            if(leaf_copy.parent.leftchild == leaf_copy):
                stack.push('0')
            #若leaf是右孩子
            elif(leaf_copy.parent.rightchild == leaf_copy):
                stack.push('1')
            #置leaf为其父结点
            leaf_copy = leaf_copy.parent
        #出栈,得到编码
        coding = ''
        while(not stack.is_empty()):
            coding += stack.pop()
        #将编码放入字典中
        coding_dic[leaf.data] = coding
    #返回coding_dic
    return coding_dic

if __name__ == "__main__":
    # 声明带权值的结点列表
    weight_node_list = [HuffmanTree.TreeNode(weight,data) for data,weight in zip([chr(i) for i in range(65,72)],range(1,7))]
    huffman_tree = HuffmanTree.HaffmanTree(weight_node_list)
    haffman_coding_dic = huffman_encoder(huffman_tree)
    print(haffman_coding_dic)


