import csv
from sys import argv
from pathlib import Path


if (len(argv) > 3) or (Path(f'{argv[1]}').suffix != '.csv') or (Path(f'{argv[2]}').suffix != '.txt'):
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

txtfile = argv[2]
csvfile = argv[1]

def check_repetitions(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)

def print_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match")

def main():
    with open(csvfile, "r") as csv_file:
        reader = csv.reader(csv_file)
        all_sequences = next(reader)[1:]
        with open(txtfile, "r") as filename:
            s = filename.read()
            actual = [check_repetitions(s, seq) for seq in all_sequences]
        print_match(reader, actual)
    
if __name__== "__main__":
    main()