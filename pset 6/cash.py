#Ask user for a valid input.
while True:
    try:
        change = float(input("change owed: "))
    except ValueError:
        #if the input is not a number.
        print("Sorry,invalid input")
        #return to the start of the loop.
        continue
    if change < 0:
        #if the input number is negative.
        print("Sorry, your response must not be negative.")
        continue
    else:
        break

#convert the input(dollars) into cents.
cents = int(change * 100)
#variable to count the minimum number of coins
coins_num = 0

while cents != 0:
   if cents >= 25:
       cents = cents - 25
       coins_num =  coins_num + 1

   if cents >= 10 and cents < 25: 
       cents = cents - 10
       coins_num = coins_num + 1
   
   if cents >= 5 and cents < 10:
       cents = cents - 5
       coins_num = coins_num + 1

   if cents >= 1 and cents < 5:
      cents = cents - 1
      coins_num = coins_num + 1

# Print the minimum number of coins.
print(coins_num)      