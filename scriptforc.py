import os
import subprocess
import time
start_time = time.time()
counter = 0
print("Press:\n1 to sort by heapsort\n2 to sort by quicksort\n3 to sort by shellsort\n4 to sort by introsort")
chosen_sort = int(input())
if chosen_sort == 1:
    chosen_sort = 'heap_sort'
elif chosen_sort == 2:
    chosen_sort = 'quick_sort'
elif chosen_sort == 3:
    chosen_sort = 'shell_sort'
elif chosen_sort == 4:
    chosen_sort = 'intro_sort'

os.system(f'gcc {chosen_sort}.c -o {chosen_sort}.exe')


for i in range(1, 101):
    res = subprocess.run([f"{chosen_sort}.exe", f"input/test{i}.txt", f"output/sorted{i}.txt"], stdout=subprocess.PIPE)
    test = open(f"input/test{i}.txt", 'r')
    n = int(test.readline())
    arr = list(map(int, test.readline().split()))
    test.close()
    output = open(f"output/sorted{i}.txt", 'r')
    output_list = list(map(int, output.readline().split()))
    output.close()
    if sorted(arr) == output_list:
        print(f'Test {i}: Accepted')
        counter += 1
    else:
        print(f'Test {i}: Wrong answer')
print(f'\nTotal result: {counter}/100')
print("Duration %s seconds" % (time.time() - start_time))

