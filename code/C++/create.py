import os

def folder(problem):
	os.makedirs(problem, exist_ok=True)
	with open(os.path.join(problem, "main.cpp"), "w") as f:
		f.write("")
	with open(os.path.join(problem, "in.txt"), "w") as f:
		f.write("")

with open("plantilla.cpp", "w") as f:
	f.write("")
with open("out.txt", "w") as f:
	f.write("")

for i in range(ord('A'), ord('P') + 1):
	folder(chr(i))