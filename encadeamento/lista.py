L = []
op = 1

while(op in [1,2,3]):
    op = int(input("\n===MENU===\n[1]Print the list\n[2]Insert an element\n[3]Remove an element\n[4]Leave\n-> "))
    match op:
        case 1:
            print(L)
            continue
        case 2:
            elem = int(input("Type the element to insert: "))
            L.append(elem)
        case 3:
            elem = int(input("Type the element to remove: "))
            L.remove(elem)

print("End of program!")