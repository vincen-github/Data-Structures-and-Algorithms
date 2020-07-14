class TreeNode(object):
    def __init__(self,weight,data = None,leftchild = None,rightchild = None,parent = None):
        self.data = data
        self.weight = weight
        self.leftchild = leftchild
        self.rightchild = rightchild
        self.parent = parent
        if rightchild != None:
            rightchild.parent = self
        if leftchild != None:
            leftchild.parent = self

def wpl(root,layer = 0):
    if root == None:
        return 0
    #若是叶子结点,返回层数*权重
    if root.leftchild == None and root.rightchild == None:
        return layer*root.weight
    #若不是叶子结点，返回左右子树的权重和
    elif root.leftchild != None or root.rightchild != None:
        return wpl(root.leftchild,layer+1) + wpl(root.rightchild,layer+1)
    

def HaffmanTree(weight_node_list):
    if len(weight_node_list) == 0:
        raise Exception("weight_node_list is empty.")
    while(len(weight_node_list) > 1):
        # 存储weight_node_list中每一棵树根节点的权值
        weight_list = [node.weight for node in weight_node_list]
        # 弹出根节点权值最小的那一颗树的根结点
        node1 = weight_node_list.pop(weight_list.index(min(weight_list)))
        # 将上面弹出的根节点的权值从权值列表中删除
        weight_list.pop(weight_list.index(min(weight_list)))
        # 弹出根节点权值最小的那一棵树的根节点
        node2 = weight_node_list.pop(weight_list.index(min(weight_list)))
        # 将上面弹出的根节点的权值从权值列表中删除
        weight_list.pop(weight_list.index(min(weight_list)))
        # 将弹出的两个树的根节点作为左右子树，形成新树
        node_concated = TreeNode(weight = node1.weight + node2.weight,leftchild = node1,rightchild = node2)
        # 将新树的根节点加入至weight_node_list中
        weight_node_list.append(node_concated)
    return weight_node_list[0]


if __name__ == "__main__":
    # 声明带权值的结点列表
    weight_node_list = [TreeNode(weight) for weight in range(1,7)]
    # 生成哈夫曼树
    haffman_tree = HaffmanTree(weight_node_list)
    print(haffman_tree.leftchild.parent.weight)
    print("生成的哈夫曼树的带权路径长度为:",wpl(haffman_tree))
    print("该哈夫曼树根结点的权重为:",haffman_tree.weight)
    