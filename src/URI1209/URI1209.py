#!/usr/bin/env python
#encoding: utf-8
from time import time
class Node(object):
	def __init__(self,data,adjacentes=None):
		self.data=data
		self.cor='W'
		self.adj=adjacentes
		if(adjacentes==None): 
			self.adj=[]
		self.len=len(self.adj)
	def __str__(self):
		return str(self.data)
	def __repr__(self):
		return str(self.data)
	def __eq__(self,other):
		return (other.data==self.data)

class Graph(object):
	def __init__(self):
		self.nodes=[]
	def __str__(self):
		string=""
		for no in self.nodes:
			string+=no.__str__()+'-->'+str(len(no.adj))+' '
			string+=no.adj.__str__()+'\n'
		return string[:len(string)-1]	#Tirar o ultimo \n
	def __repr__(self):
		return self.__str__()
	def getNode(self,key):
		for no in self.nodes:
			if(no.data==key):
				return no

def colore(grafo,string):
	for no in grafo.nodes:
		grafo.cor=string

def calculaQuemVai(grafo,k):
	t1=time()
	colore(grafo,'W')
	for no in grafo.nodes:
		if(len(no.adj)<k):
			no.cor='B'
	houveMud=True
	while(houveMud):
		houveMud=False
		for no in grafo.nodes:
			if(no.cor=="W"):
				tamSemRetB=len(no.adj)
				for adjac in no.adj:
					if(adjac.cor=='B'):
						tamSemRetB-=1
				if(tamSemRetB<k):
					no.cor='B'
					houveMud=True
	t2=time()
	print "TIME CALCULA "+str(t2-t1)
	return [no for no in grafo.nodes if no.cor=='W']

def ler():
	l1=time()
	entrada=raw_input()+" "
	nova=""
	lista=[]
	for ch in entrada:
		if(ch!=" "):
			nova+=ch
		else:
			lista.append(nova)
			nova=""
	l2=time()
	print "TIME LER "+str(l2-l1)
	return [int(num) for num in lista]

grafo=Graph()
k=0
while(True):
	try:
		numeros=ler()
		n=numeros[0]
		m=numeros[1]
		k=numeros[2]
		print n,m,k
		for i in range(1,n+1):
			grafo.nodes.append(Node(i))
		
		while(m!=0):
			ns=ler()
			na=ns[0]
			nb=ns[1]
			
			grafo.getNode(na).adj.append(grafo.getNode(nb))
			grafo.getNode(nb).adj.append(grafo.getNode(na))
			m-=1
	except EOFError:
		break

for no in grafo.nodes:
	no.len=len(no.adj)

saida=""
for no in calculaQuemVai(grafo,k):
	saida+=str(no.data)+" "
if(len(saida)>1):
	print saida[:len(saida)-1]
elif(len(saida)):
	print saida[0]
else:
	print 0