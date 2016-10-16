#!/usr/bin/env python
#encoding: utf-8

class Node(object):
	def __init__(self,data,adjacentes=None):
		self.data=data
		self.cor='W'
		self.adj=adjacentes
		if(adjacentes==None): self.adj=[]

	def __str__(self):
		return str(self.data)
	def __repr__(self):
		return str(self.data)

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
	def addNodes(self,*lista):
		if(lista!=None):
			for no in lista:
				self.nodes.append(no)

def invert(grafo):
	for no in grafo.nodes:
		no.cor='W'
	for no in grafo.nodes:
		no.cor='B'
		for adjacente in no.adj:
			if(adjacente.cor!='B'):
				adjacente.adj.append(no)
				
		no.adj=[node for node in no.adj if node.cor=='B']

def quadrado(grafo):
	for no in grafo.nodes:
		no.cor='W'
	for no in grafo.nodes:
		lista=[]
		for adjNo in no.adj:
			if(adjNo.cor!='B'):
				for adjAdj in adjNo.adj:
					if(not no.adj.__contains__(adjAdj)):
						adjAdj.cor='B'
						lista.append(adjAdj)
		no.adj+=lista
		


teste=Graph()
n1=Node(12)
n2=Node(13)
n3=Node(14)
n4=Node(15)
n1.adj.append(n2)
n1.adj.append(n3)
n2.adj.append(n3)
n3.adj.append(n4)
n4.adj.append(n1)

teste.addNodes(n1,n2,n3,n4)
#teste.nodes.append(Node(14))
print str(teste)+'\n\n'
quadrado(teste)
print teste
