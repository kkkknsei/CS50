from cs50 import get_string

VISA = ["4"]
MASTER = ["51", "52", "53", "54", "55"]
AMEX = ["34", "37"]

s = get_string("CC NUMBER: \n")

def check(s):
    
    first = 0
    second = 0

    if len(s) == 15:
        for i in reversed(range(len(s))):
            if (i % 2) != 0:
                first = ((str(int(s[i]) * 2)))
                if ((int(first)) >= 10):
                    second += (int(first[0])) + (int(first[1]))
                else:
                    second += (int(first))
            elif (i % 2) == 0:
                second += (int(s[i]))
    elif len(s) == 13 or 16:
        for i in reversed(range(len(s))):
            if (i % 2) == 0:
                first = ((str(int(s[i]) * 2)))
                if ((int(first)) >= 10):
                    second += (int(first[0])) + (int(first[1]))
                else:
                    second += (int(first))
            elif (i % 2) != 0:
                second += (int(s[i]))

    second = (str(second))

    if (int(second[1])) == 0:
        return True
    else:
        return False

check(s)

if (check(s) == True) and (s[:1] in VISA) and (len(s) == 13 or 16):
    print("VISA")
elif (check(s) == True) and (s[:2] in MASTER) and (len(s) == 16):
    print("MASTERCARD")
elif (check(s) == True) and (s[:2] in AMEX) and (len(s) == 15):
    print("AMEX")
else:
    print("INVALID")