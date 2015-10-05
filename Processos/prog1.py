#
# Lab1 - Criacao de subprocessos usando Python
#
#		A
# 	   /
#	  B
#
# Rubem Kalebe (2015.2)
#
# python prog1.py

import sys
import os
import time

print "PID: " + str(os.getpid())

pid = os.fork()

if pid == 0:
	# Processo filho
	m = 5
	print "Processo filho"
	pid = os.getpid();
	print "PID filho: " + str(pid)
	for j in range(0, m):
		print "Sou o Filho, meu PID eh: " + str(pid) + " e J = " + str(j)
		#time.sleep(5)
	print "Sou o Filho, meu PID eh: " + str(pid) + " -- vou encerrar"
	os._exit(0) # encerra execucao
elif pid > 1:
	# Processo pai
	m = 2
	print "Processo pai"
	pid = os.getpid();
	print "PID pai: " + str(pid)
	for j in range(0, m):
		print "Sou o Pai, meu PID eh: " + str(pid) + " e J = " + str(j)

	print "---Vou executar o filho!"
	os.wait()
	print "O filho encerrou, agora irei encerrar!"
else:
	# Falha -- o subprocesso nao foi criado
	print "Falha ao criar novo subprocesso!!!"
	os.exit(1)

sys.exit(0)
