import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv)!= 3:
        print("Number of arguments is incorrect")
        return

    # TODO: Read database file into a variable
    persons = []
    with open(argv[1]) as file:
        database = csv.reader(file)
        for reader in database:
            dict = {}
            dict["name"]= reader[0]
            for i in range(1,len(reader)):
                dict[i]= reader[i]
            persons.append(dict)

    # TODO: Read DNA sequence file into a variable
    f= open(argv[2], "r")
    sequence= f.read()

    # TODO: Find longest match of each STR in DNA sequence
    match= []
    for i in range(1, len(persons[0])):
        match.append(int(longest_match(sequence, persons[0][i])))

    persons.pop(0)
    # TODO: Check database for matching profiles
    for i in persons:
        for j in range(1, len(i)):
            if int(i[j]) != match[j-1]:
                break
            elif j==len(i)-1:
                print(i["name"])
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
