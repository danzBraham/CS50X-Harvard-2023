from sys import argv

# Method 1
# for i in range(len(argv)):
#     print(argv[i])

# Method 2
# for arg in argv:
#     print(arg)

# Method 3 starting at index 1 to the end
for arg in argv[1:]:
    print(arg)

# if len(argv) == 2:
#     print(f"hello, {argv[1]}")
# else:
#     print("hello, world")