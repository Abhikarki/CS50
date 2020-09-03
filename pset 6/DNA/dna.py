import csv
import sys

#exit the program if number of command line arguments!=3
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

#function to count and return the max STR repetitions
def find_num_of_occurrence(seq, s):
    tmp_num, i, num = 0, 0, 0
    #length of the STR passed as argument.
    length = len(s)

    #find() returns the index of the first occurrrence of substring
    #find() returns -1 if substring doesn't exist inside the string.
    while seq.find(s, i, len(seq)) != -1:
        a = seq.find(s, i, len(seq))
        if i == 0 or a == i:
            tmp_num += 1
            if tmp_num > num:
                num = tmp_num        
            i = a + length
        else:
            i = a + length
            tmp_num = 1
    return num

#gets the name of the sequence file from command line arguments.
sequence_name = sys.argv[2]

with open(sequence_name, 'r') as sequence_file:
    #reads a line of the file and stores in form of a string
    seq = sequence_file.readline()
    sequence_file.close()
    
    n1 = find_num_of_occurrence(seq, "AGATC")
    n2 = find_num_of_occurrence(seq, "TTTTTTCT")
    n3 = find_num_of_occurrence(seq, "AATG")
    n4 = find_num_of_occurrence(seq, "TCTAG")
    n5 = find_num_of_occurrence(seq, "GATA")
    n6 = find_num_of_occurrence(seq, "TATC")
    n7 = find_num_of_occurrence(seq, "GAAA")
    n8 = find_num_of_occurrence(seq, "TCTG")
    
    

#gets the name of the csv file from command line arguments.
database_name = sys.argv[1]
#to check if finding was success or a 'No match'
success = 0
with open(database_name, 'r') as database_file:
    #read csv data into a dictionary.
    database_reader = csv.DictReader(database_file, delimiter =',')
    for row in database_reader:
        #convert the values to integers and store in variables.
        m1, m2, m3, m4 = int(row['AGATC']), int(row['TTTTTTCT']), int(row['AATG']), int(row['TCTAG'])
        m5, m6, m7, m8 = int(row['GATA']), int(row['TATC']), int(row['GAAA']), int(row['TCTG'])
        
        if m1==n1 and m2==n2 and m3==n3 and m4==n4 and m5==n5 and m6==n6 and m7==n7 and m8==n8:
           print(row['name'])
           success = 1
    database_file.close()    
    if success == 0:
        print("No match")
