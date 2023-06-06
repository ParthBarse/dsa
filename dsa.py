# Q1) Implement all the functions of a dictionary (ADT) using hashing and handle collisions using chaining without replacement. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, and Keys must be unique. Standard Operations: Insert(key, value) Find(key) Delete(key)

table = {}

for i in range(0, 10):
    table[i] = [0, -1]

print(table)

def hash_function(value):
    return value % 10

def Insert(key, value):
    if table[key][0] == 0:
        table[key][0] = value
    elif table[key][0] % 10 != key:
        while table[key][0] != 0:
            key = (key + 1) % 10
        table[key][0] = value
    else:
        while table[key][0] != 0:
            key = (key + 1) % 10
        table[key][0] = value

        old_loc = hash_function(value)
        while table[old_loc][1] != -1:
            old_loc = table[old_loc][1]
        table[old_loc][1] = key

def find(key):
    for i in range (0,10):
        if table[i][0]==key:
            return i
    return 0
        

RUNNING = True

while RUNNING:
    print("\n\nWhat do you want to do: \n1.Insert Number\n2.Find Number\n3.Delete number\n4.Print Table")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        number = int(input("Enter a number: "))
        loc = hash_function(number)
        Insert(loc, number)

    elif choice == 2:
        key=int(input("Enter the key to be found: "))
        x=find(key)
        if x!=0:
            print("Key found at loc: ",x)
        else:
            print("Key not present")

    elif choice == 3:
        pass
    elif choice == 4:
        for key,value in table.items():
            print(key,": ",value)

    else:
        print("Invalid Input. Please try again.")

    ch = input("Do you want to continue? (Y/N): ")
    if ch.upper() != 'Y':
        RUNNING = False

# OR


hashTable = {}

for i in range(0,10):
    hashTable[i] = []

def insert(value):
    key = (value%10)
    if key not in hashTable:
        hashTable[key]=[value]
    else:
        print("Collision at - ", value, " and Index - ",key)
        hashTable[key].append(value)
    
def display(hashTable):
    for key, value in hashTable.items():
        print(key, '->', value)
        
def find(key):
    val = hashTable.values()
    f=False
    for i in val:
        if key in i:
            f=True
            break
        else:
            f=False
    if f==True:
        print("Key Found in HashTable")
    else:
        print("Key not found in HashTable")
        
def delete(v):
    f=False
    for key in hashTable:
        val = hashTable.values()
        for i in val:
            if v in i:
                i.remove(v)
                f=True
                break
            else:
                f=False
    print(hashTable)
    
        
        
insert(16)
insert(10)
insert(20)
insert(11)
insert(12)
insert(19)
insert(13)
insert(14)
insert(15)
insert(17)
insert(18)
insert(21)
insert(31)
insert(36)


display(hashTable)

find(36)

display(hashTable)



# Q2) To create ADT that implements the &quot;set&quot; concept.
# a. Add (new Element) - Place a value into the set
# b. Remove (element) Remove the value
# c. Contains (element) Return true if element is in collection
# d. Size () Return number of values in collection Iterator () Return an iterator used
# to loop over collection
# e. Intersection of two sets
# f. Union of two sets
# g. Difference between two sets
# h. Subset

def create_set():
    return []

def add(s, element):
    if element not in s:
        s.append(element)

def remove(s, element):
    if element in s:
        s.remove(element)

def contains(s, element):
    return element in s

def size(s):
    return len(s)

def iterator(s):
    return iter(s)

def intersection(s1, s2):
    intersection_set = []
    for element in s1:
        if element in s2:
            intersection_set.append(element)
    return intersection_set

def union(s1, s2):
    union_set = set(s1 + s2)
    return union_set

def difference(s1, s2):
    difference_set = []
    for element in s1:
        if element not in s2:
            difference_set.append(element)
    return difference_set

def is_subset(s1, s2):
    for element in s1:
        if element not in s2:
            return False
    return True

# Create sets
set1 = create_set()
set2 = create_set()

# Add elements
add(set1, 1)
add(set1, 2)
add(set1, 3)

add(set2, 4)
add(set2, 3)
add(set2, 2)
add(set2, 1)

# Remove element
remove(set1, 2)

# Check if an element is in the set
print(contains(set1, 1))  # Output: True
print(contains(set2, 6))  # Output: False

# Get the size of the set
print(size(set1))  # Output: 2

# Iterate over the set
for element in iterator(set1):
    print(element)

# Perform set operations
intersection = intersection(set1, set2)
union = union(set1, set2)
difference = difference(set1, set2)
is_subset = is_subset(set1, set2)

# Display the results
print("Intersection:", [element for element in iterator(intersection)])
print("Union:", [element for element in iterator(union)])
print("Difference:", [element for element in iterator(difference)])
print("Is Subset:", is_subset)


# Q14) Implement all the functions of a dictionary (ADT) using hashing and handle collisions using chaining with replacement Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, and Keys must be unique. Standard Operations: Insert(key, value) Find(key) Delete(key)

table = {}

for i in range(0, 10):
    table[i] = [0, -1]

print(table)

def hash_function(value):
    return value % 10

def Insert(key, value):
    if table[key][0] == 0:
        table[key][0] = value 
        
    elif table[key][0] % 10 != key:            
        temp1=table[key][0]
        temp2=table[key][1]
        old_loc=key
        table[key][0]=value
        table[key][1]=-1
        while table[key][0] != 0:
            key = (key+ 1) % 10
        table[key][0] = temp1
        table[key][1] = temp2
        
        for i in range(0,10):
            if table[i][1]==old_loc:
                table[i][1]=key
                
    else:
        while table[key][0] != 0:
            key = (key + 1) % 10
        table[key][0] = value

        old_loc = hash_function(value)
        while table[old_loc][1] != -1:
            old_loc = table[old_loc][1]
        table[old_loc][1] = key

def delete(value):
    for i in range (0,10):
        if table[i][0]==value:
            table[i][0]=0
            temp_chain=table[i][1]
            temp_key=i
            table[i][1]=-1
    for i in range(0,10):
        if table[i][1]==temp_key:
            table[i][1]=temp_chain
    
    
def find(key):
    for i in range (0,10):
        if table[i][0]==key:
            return i
    return 0
        
RUNNING = True

while RUNNING:
    print("\n\nWhat do you want to do: \n1.Insert Number\n2.Find Number\n3.Delete number\n4.Print Table")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        number = int(input("Enter a number: "))
        loc = hash_function(number)
        Insert(loc, number)

    elif choice == 2:
        key=int(input("Enter the key to be found: "))
        x=find(key)
        if x!=0:
            print("Key found at loc: ",x)
        else:
            print("Key not present")

    elif choice == 3:
        x=int(input("Enter the number to be deleted"))
        delete(x)
    elif choice == 4:
        for key,value in table.items():
            print(key,": ",value)

    else:
        print("Invalid Input. Please try again.")

    ch = input("Do you want to continue? (Y/N): ")
    if ch.upper() != 'Y':
        RUNNING = False