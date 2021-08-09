from cs50 import get_string

while True:
    try:
        s = (int(get_string("Input: \n")))
    except ValueError:
        continue
    if s in (1, 2, 3, 4, 5, 6, 7, 8):
        break
    
for i in range(s):
    print(" " * (s - (i + 1)) + "#" * (i + 1),"", "#" * (i + 1))