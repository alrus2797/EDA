import pygame as pg

M = 5

class Object:
    def __init__(self,p1,p2,value):
        self.p1     = p1
        self.p2     = p2
        self.value  = value

    def isIn(self, BB):
        if  self.p1[0] > BB[0][0] and self.p2[0] < BB[1][0] and \
            self.p1[1] > BB[0][1] and self.p2[1] < BB[1][1]:
            return True
        return False

class RNode:
    def __init__(self,leaf):
        self.M          = M
        self.objects    = [None] * M
        self.leaf       = leaf
        

class RTree:
    def __init__(self):
        self.root = RNode(False)
    
    def insert(self, object, node ):
        if node.leaf:
            for object in node.objects:
                pass


BB = [
    [1,1],
    [4,4]
]

a = RTree


