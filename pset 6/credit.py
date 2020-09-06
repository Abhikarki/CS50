import sys

#Ask user for a valid input.
while True:
    num = (input("Number: "))
    #calculate the length of the input.
    number_of_digits = len(num)
    try:
        card_number = int(num)
    except ValueError:
        #if the input is not a number.
        print("Sorry,invalid input")
        #return to the start of the loop.
        continue
    if card_number < 0:
        print("Sorry, your response must not be negative.")
        continue
    else:
        break 

#exit the code if user enters card number of invalid length.
if number_of_digits != 13 and number_of_digits != 15 and number_of_digits != 16:
    print("INVALID")
    sys.exit(1)
 

 #To calculate the sum of digits as per Luhn's algorithm
sum = 0 

#store card_number in a temporary variable
tmp_num = card_number

while tmp_num >= 10:
    #arithmetic to find every other digits starting
    #with second to last digit and add digits of 2
    #times the digit to sum as per Luhn's algorithm.
    m = tmp_num % 100                       
    n = m % 10                        
    o = (m - n) / 10
    p = 2 * o

    if p >= 10:
        q = p % 10
        #add the products' digits together if it is >= 10
        sum = sum + q + 1         

    if p < 10:
        #add the products' digit if it is less than 10
        sum = sum + p
    #update tmp_num.
    tmp_num = (tmp_num - m) / 100 


#store card_number in a temporary variable
tmp_num1 = card_number

while tmp_num1 != 0:
    #arithmetic to find the sum of remaining digits
    b = tmp_num1 % 100                       
    c = b % 10                      
    sum = sum + c
    tmp_num1 = (tmp_num1 - b) / 100


#Exit the code if the card number is invalid as per Luhn's algorithm
if sum % 10 != 0:
    print("INVALID")
    #exit the code(failure)
    sys.exit(1)

 
#To check if it is American express card number
if number_of_digits == 15:       
    g = 10000000000000
    h = card_number % g
    #To find the first two digits of the number
    i = (card_number - h) / g               

    #check the first two digits.
    if i == 34 or i == 37:
        print("American Express")
        #exit the code(success)
        sys.exit(0)
    else:
        print("INVALID")
        #exit the code(failure)
        sys.exit(1)


#To check if it is VISA card number
if number_of_digits == 13:       
    ab = 1000000000000
    bc = card_number % ab
    #To find the first digit of the number
    cd = (card_number - bc) / ab                
             
    #check the first digit.
    if cd == 4:
        print("VISA")
        #exit the code(success)
        sys.exit(0)
    else:
        print("INVALID")
        #exit the code(failure)
        sys.exit(1) 


#To check if it is VISA or a Master card
if number_of_digits == 16:            
    mn = 100000000000000
    no = card_number % mn
    #To find the first two digits of the number
    op = (card_number - no) / mn             

    #To check for VISA card 
    if op >= 40 and op <= 49:            
        print("VISA")
        #exit the code(success)
        sys.exit(0)

    #To check for Master card
    elif op >= 51 and op <= 55:       
        print("MASTER CARD")
        #exit the code(success)
        sys.exit(0)

    else:   
        print("INVALID")
        #exit the code(failure)
        sys.exit(1) 

