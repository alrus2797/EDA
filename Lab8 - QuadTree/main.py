import cv2 as cv
import numpy as np
import sys

#Get picture filename from terminal args
filename = sys.argv[1]

#Choose between adaptative threshold or simple threshold
adaptative = False
if len(sys.argv) == 3:
    adaptative = True


img = cv.imread(filename)
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)   

# cv.namedWindow('lena',cv.WINDOW_NORMAL)
# cv.resizeWindow("lena",1000,440)

#Show original image
cv.imshow("lena",img)
print("Press to binarize...\n")
cv.waitKey(0)

#Binarize the image in thresh1
if adaptative:
    thresh1 = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,cv.THRESH_BINARY,11,2)
    print("Adaptative Threshold selected")
else:
    ret,thresh1 = cv.threshold(gray,127,255,cv.THRESH_BINARY)
    print("Simple Threshold selected")
print()

cv.imwrite('bin.jpg',thresh1)
img1 =  cv.imread('bin.jpg')

#Draw a rectangle in img1 (the binarized picture)
def drawRectangle(p1,p2):
    cv.rectangle(img1,tuple(p1),tuple(p2),(255,0,0),1)

#QuadTree Node:     
# Draws a rectangle when its created
class QNode:
    #In: Two points of a quadrant
    #   p1: Left - Up point
    #   p2: Right- Down point

    def __init__(self,p1,p2):
        self.p1 = p1
        self.p2 = p2
        self.color = 0
        self.hijos = [None] * 4
        self.setColor()
        drawRectangle(self.p1,self.p2)

    #Set a color between -1 (gray), 0 (black) and 1(white) to the node
    def setColor(self):
        # Counts all non-zeros inside the quadrant (between p1 and p2)
        suma = np.count_nonzero(thresh1[ self.p1[1] : self.p2[1] , self.p1[0] : self.p2[0] ])

        #Total of pixels in the quadrant
        total = abs((self.p2[1] - self.p1[1]) * (self.p2[0] - self.p1[0]))

        if   suma == total : self.color = 1     #If all are non-zeros
        elif suma == 0     : self.color = 0     #If all are zeros
        elif suma < total  : self.color = -1    #If there are less non-zeros than zeros

    #Calculate auxiliar points to divide a quadrant
    #and create children nodes
    def dividir(self):
        #Center of quadrant
        centro = self.p1 + (self.p2 - self.p1)//2

        #WASD points (Up - Down, Left - Right)
        arriba = np.array([ centro[0] , self.p1[1] ])
        abajo  = np.array([ centro[0] , self.p2[1] ])

        izquierda = np.array([ self.p1[0] , centro[1] ])
        derecha   = np.array([ self.p2[0] , centro[1] ])

        #Creates children nodes with WASD points  
        self.hijos[0] = QNode(self.p1,centro)
        self.hijos[1] = QNode(arriba,derecha)
        self.hijos[2] = QNode(centro,self.p2)
        self.hijos[3] = QNode(izquierda,abajo)

    #Divide a Quadrant until the lenght of quadrant is 1 pixel
    # If Quadrant color is complete white or black then no divide
    def deepDivide(self):
        #Lenght of quadrant
        if np.array_equal(self.p2-self.p1,(1,1)): return
        #If the color is gray then divide
        if self.color == -1: self.dividir()

        #For progressive visualization
        # cv.imshow("lena",img1)
        # cv.waitKey(1)

        # For each children with gray Color (-1) divide it
        #print("loading...")
        for i in self.hijos:
            if i.color == -1:
                i.deepDivide()

#QuadTree Class
class QTree:    
    def __init__(self): 
        self.imagen = thresh1
        #The root node is on all the picture
        self.root = QNode(np.array((0,0)), np.array(thresh1.shape[1::-1]))
        #Show binarized image
        
        cv.imshow("lena",img1)
        print("Press to start...\n")
        cv.waitKey(0)

        #Execute deepDivide
        self.root.deepDivide()

        #Show after deepDivide

        cv.imshow("lena",img1)
        print("Press to exit...\n")
        cv.waitKey(0)
        cv.destroyAllWindows()


t = QTree()