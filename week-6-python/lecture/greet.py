import sys

if len(sys.argv) != 2:
    print("Missing comnand-line argument")
    sys.exit(1)

print(f"Hello {sys.argv[1].capitalize()}")
sys.exit(0)
