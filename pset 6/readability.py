def main():
    #prompt user for input.
    #assigning space separated inputs to a list.
    text = list(input("Text: ").split())
    
    #Call function to count the number of letters.
    l = count_letters(text)
    #number of words = length of the list.
    w = len(text)
    #Call function to count the number of sentences.
    s = count_sentences(text)

    #L is the average number of letters per 100 words in the text.
    L = (l * 100) / w
    #S is the average number of sentences per 100 words in the text.
    S = (s * 100) / w
    
    #formula to calculate Coleman-Liau index
    index= (0.0588 * L) - (0.296 * S) - 15.8    
    grade = round(index)

    if grade <= 16 and grade >= 1:
        print("Grade:", grade)
  
    elif grade > 16:
        print("Grade 16+")
  
    else:
        print("Before Grade 1")



def count_letters(text):
    #length of the list.
    a = len(text)
    i = 0
    #variable to count letters.
    letters = 0
    #continue loop until the end of the list.
    while i != a:  
        #count the length of the words.
        let = len(text[i])
        #iterate through each letter in the word.
        for j in range(let):
            if text[i][j].isalpha() == True:
                #update the number of letters.
                letters += 1
        i += 1
    return letters   


def count_sentences(text):
    #length of the list.
    a = len(text)
    m = 0
    #variable to count sentences.
    sent = 0
    #continue loop until the end of the list.
    while m != a:  
        #count the length of the words.
        let = len(text[m])
        #iterate through each letter in the word.
        for n in range(let):
            if text[m][n] == "." or text[m][n] == "?" or text[m][n] == "!":
                #update number of sentences.
                sent += 1
        m += 1
    return sent            

#call the main function.
main()    