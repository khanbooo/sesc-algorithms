import random
import os
if 'input' not in os.listdir('.'): os.mkdir('input')
if 'output' not in os.listdir('.'): os.mkdir('output')
for i in range(1, 101):
    chislo = random.randint(100, 10000)
    massiv = list(str(i) for i in range(1, chislo))
    random.shuffle(massiv)
    test = open(f'input/test{i}.txt', 'w')
    test.write(f"{len(massiv)}\n")
    test.write(' '.join(massiv))
    test.close()