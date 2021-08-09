from cs50 import get_string

get = get_string("Input: \n")
periods = 0
sentences = 0
words = 0

for i in range(len(get)):
    if (get[i] == '.') or (get[i] == ',') or (get[i] == '?') or (get[i] == ';') or (get[i] == '!') or (get[i] == "'"):
        periods += 1
    if get[i] == ' ':
        words += 1
    if (get[i] == '.') or (get[i] == '?') or (get[i] == '!'):
        sentences += 1

f = (len(get) - (words + periods))
words += 1
f /= words
f *= 100
sentences /= words
sentences *= 100
index = (0.0588 * f - 0.296 * sentences - 15.8)

if index < 1:
    print("Before Grade 1")
elif index <= 15:
    print(f"Grade {(round(index))}")
elif index > 16:
    print("Grade 16+")