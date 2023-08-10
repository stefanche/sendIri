# TODO
from cs50 import get_string

def main():

    card = get_string("Give card nr\n")
    nrdig = len(card)
    if nrdig!= 16 and nrdig!= 15 and nrdig!= 13:
        print("INVALID")
    else:
        card = int(card)
        if checksum(card, nrdig)== 0:
            nrdig-=2
            card = card // 10**nrdig
            if amex(card)== 0:
                return 0
            if master(card)== 0:
                return 0
            card//= 10
            if visa(card,nrdig+2)== 0:
                return 0
            print("INVALID")
        else:
            print("INVALID")



def checksum(nr, digits):
    sum, odd, even = 0, 0, 0
    nr = int(nr)
    for i in range(digits):
        if i%2==0:
            odd+= nr%10
            nr//= 10
        else:
            temp= nr%10*2
            if temp>9:
                even+= temp%10
                temp//= 10
                even+= temp%10
            else:
                even+= temp%10
            nr//=10

    print(odd)
    sum= odd+even
    print(sum)
    if sum%10==0:
        return 0
    return 1

def amex(nr):

    if nr==34 or nr==37:
        print("AMEX")
        return 0
    return 1

def master(nr):

    if nr>=51 and nr<=55:
        print("MASTERCARD")
        return 0
    return 1

def visa(nr,digits):

    if nr==4:
        if digits== 13 or digits== 16:
            print("VISA")
            return 0
    return 1

if __name__ == "__main__":
    main()


