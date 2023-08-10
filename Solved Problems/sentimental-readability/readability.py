# TODO
from cs50 import get_string
import re

def main():
    text = get_string("give text ")
    sentence = len(re.findall("[.!?]",text))
    words  = len(re.findall(" ", text)) + 1
    letters = len(re.findall("[a-zA-Z]", text))
    L= letters/words* 100
    S= sentence/words* 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    if grade>16:
        print("Grade 16+\n")
    elif grade<1:
        print("Before Grade 1\n")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()



