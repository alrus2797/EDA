
class Nodo:
	def __init__(self,valor):
		self.valor = valor
		self.izq = None
		self.der = None

class Arbol:
	def __init__(self):
		self.raiz = None
	def find(self, nodo,valor):		
		if not nodo: return 
		if nodo.valor == valor: return nodo
		if valor < nodo.valor: find(nodo.izq,valor)
		else: find(nodo.der,valor)

	
	def push(self,val):
		if not self.raiz: self.raiz = Nodo(val)
		else:
			self._push(val,self.raiz)

	def _push(self,val, nodo):
		if val < nodo.valor:
			if nodo.izq: self._push(val,nodo.izq)
			else: nodo.izq = Nodo(val) 
		else:
			if nodo.der : self._push(val, nodo.der)
			else: nodo.der = Nodo(val)

	def showr(self,nodo, i):
		if not nodo: return
		i+=3
		self.showr(nodo.der,i)
		print " " * i, nodo.valor
		self.showr(nodo.izq,i)
	
	def show(self):
		a = 0
		self.showr(self.raiz,a)
			
	def inorden(self):
		nStack = [self.raiz]
		rStack = []
		while nStack != []:
			actual = nStack.pop()
			if actual.izq or actual.der:
				rStack.append(actual)
				if actual.der : nStack.append(actual.der)
				if actual.izq : nStack.append(actual.izq)

			else:
				print actual.valor,
				try: print rStack.pop().valor,
				except:
					pass

	def ref(self,nodo):
		if not nodo: return
		temp = nodo.izq
		nodo.izq = nodo.der
		nodo.der = temp
		self.ref(nodo.izq)
		self.ref(nodo.der)
arbol = Arbol()
l = [11,6,8,19,4,17,43]
for i in l:
	arbol.push(i)

arbol.show()
print("---------")
arbol.ref(arbol.raiz)
arbol.show()

