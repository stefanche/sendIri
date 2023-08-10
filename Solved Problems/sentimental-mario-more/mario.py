# TODO
from cs50 import get_int

while True:
    height = get_int("Give height\n")
    if height>0 and height<9:
        break
    else:
        print("Number not in range")

for i in range(height):
    for y in range(height-i-1):
        print(" ", end="")
    for x in range(i+1):
        print("#", end="")
    print("  ", end="")
    for z in range(i+1):
        print("#", end="")
    print("")


