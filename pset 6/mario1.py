height = int(input("Height: "))

#prompt the user for a positive number.
while height <= 0 or height > 8:
    height = int(input("Height: "))

for i in range(1, height + 1):
    j = height - i
    #To avoid printing empty line at the end.
    if i == height:
        print(" " * j + "#" * i + "  " + "#" * i , end = '')
        continue
    print(" " * j + "#" * i + "  " + "#" * i)