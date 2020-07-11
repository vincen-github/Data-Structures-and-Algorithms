# -*- coding: utf-8 -*-
"""
Created on Sat Feb 23 22:24:01 2019

@author: vincen
"""
class Stack(object):
    """基于顺序表(list)实现栈"""
    def __init__(self):
        self.__list = []
    
    def push(self,item):
        """压栈"""
        self.__list.append(item)
        #self.__list.insert(0,item)
        """尾部添加的原因为顺序表中，尾部添加的时间复杂度为O(1),头部添加的时间复杂度为O(n)"""
        """若使用链表,则应该将头部作为栈底,因链表头部添加时间复杂度为O(1),尾部添加的时间复杂度为O(n)"""
    
    def pop(self):
        """出栈"""
        return self.__list.pop(-1)
        #self.__list.pop(0)
    
    def peek(self):
        """返回栈顶元素"""
        if self.is_empty():
            #若为空，返回None,代表栈中无元素
            return None
        return self.__list[-1]
    
    def is_empty(self):
        """判断栈是否为空"""
        return self.__list == []
            
    
    def size(self):
        """栈的大小"""
        return len(self.__list)
    
if __name__ == '__main__':
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    print(s.pop())
    print(s.pop())
    print(s.pop())
    print(s.pop())
    print(not(s.is_empty()))