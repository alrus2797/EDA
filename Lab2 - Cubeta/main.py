def getLenNumber(number):
    res=0
    number=abs(number)
    while number > 0:
        number=number//10
        res+=1
    return res

def getSubNumber(number,position):
    #tam=getLenNumber(number)
    if position < 0:
        return -2
    
    modulo=10**(position)
    return int((number//(modulo))%10)


def showStructure(s):
    t = max([len(i) for i in s])
    c=80
    print("\t|"+"-"*(c-1)+"|")
    for i in range(10):
        print("\t|",i,end="")
    print("\t|")
    print("\t|"+"-"*(c-1)+"|")
    for i in range(t):
        for j in range(10):
            #print(j,i)
            try:
                print("\t|",s[j][i], end="")
            except Exception:
                print("\t| ",end ="")
        print("\t|")
    print("\t|"+"-"*(c-1)+"|")
    print()


numeros = []
# a = int(input("Ingrese tamano: "))

# for i in range(a):
#     numeros.append(int(input("Ingrese un numero: ")))

#print (getLenNumber(0))

numeros = [0,1,512,343,64,125,218,27,8,729]
tam = getLenNumber(numeros[0])
for numero in numeros:
    #print(numero)
    t = getLenNumber(numero)
    if  t > tam:
        tam = t

for iteracion in range(tam):
    estructura = [[] for i in range(10)]
    for numero in numeros:
        pos = getSubNumber(numero,iteracion)
        estructura[pos].append(numero)
    print ("\t Iteración: ",iteracion)
    showStructure (estructura)
    print()
