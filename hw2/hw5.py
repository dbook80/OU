
#Donovan Booker - counting lines, words, and characters in a directory

import sys

for x in sys.argv[1:]:

        with open(x) as sys.stdin:

                lines = 0
                words = 0
                characters = 0

                for line in sys.stdin:
                        num_words = line.split()
                        lines += 1
                        words += len(num_words)
                        characters += sum(len(words) for words in num_words)

                        print("lines : ")
                        print(lines)
                        print("words : ")
                        print(words)
                        print("characters : ")
                        print(characters)
                        print("")

