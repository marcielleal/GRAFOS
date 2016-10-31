#!/usr/bin/env python
#encoding: utf-8

import copy

class Node(object):
	def __init__(self,data,adjacentes=None):
		self.data=data
		self.cor='W'
		self.adj=adjacentes
		if(adjacentes==None): 
			self.adj=[]
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
	def addNodes(self,*lista):
		if(lista!=None):
			for no in lista:
				self.nodes.append(no)
	def getNode(self,key):
		for no in self.nodes:
			if(no==key):
				return no

def invert(grafo):
	novoGrafo=copy.deepcopy(grafo)
	for no in grafo.nodes:
		novoGrafo.getNode(no).adj=[]

	for no in grafo.nodes:
		for adjacente in no.adj:
			#if(not adjacente.adj.__contains__(no)):
			novoGrafo.getNode(adjacente).adj.append(novoGrafo.getNode(no))
	return novoGrafo

def quadrado(grafo):
	novoGrafo=copy.deepcopy(grafo)
	
	index=0
	for no in grafo.nodes:
		lista=[]
		for adjNo in no.adj:
			for adjAdj in adjNo.adj:
				if(not no.adj.__contains__(adjAdj) and no.data!=adjAdj.data):
					lista.append(adjAdj)
		
		novoGrafo.nodes[index].adj+=lista
		index+=1
	return novoGrafo

teste=Graph()
n1=Node(12)
n2=Node(13)
n3=Node(14)
n4=Node(15)
n1.adj.append(n2)
#n1.adj.append(n3)
#n1.adj.append(n4)
n2.adj.append(n3)
n3.adj.append(n1)
#n4.adj.append(n1)
#n2.adj.append(n1)

teste.addNodes(n1,n2,n3,n4)
#teste.nodes.append(Node(14))
print str(teste)+'\n\n'
print str(quadrado(teste))+'\n\n'
print str(invert(teste))+'\n\n'
print str(teste)

