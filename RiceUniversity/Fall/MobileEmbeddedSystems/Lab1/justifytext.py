#! /usr/bin/python
import sys

 #Mobile and Embedded Systems - Lab1 - Part 1 - Python
 #Student: Juarez Aires Sampaio Filho
 #Rice ID: S01217136
 #email: js100@rice.edu


# 
# INSERT DESCRIPTION HERE
# Justify input text to the length informed.
#If the line's size is less than the number of length then the algorithm try to
#make the spaces between words equal in that line. If the size is grater, then
#we add the extra words to the beginning of the next line.
#
#This was the idea, but the program doesn't work well with big lines.
#Sometimes it works, sometimes don't. I'm sure it works if the line
#are all less than length, but there are bugs for the general case
#

def justify(file_name, justify_length):
    text_file = open(file_name, 'r')
    #print some useful information and the original text
    print "Filename:", file_name
    print "Justify length:", justify_length
    print justify_length*'-'
    print "Original text:"
    print justify_length*'-'
    lines = text_file.readlines()
    for line in lines:
    	print line,
    print justify_length*'-'
 	
    new_text = []
    
    for line_number,line in enumerate(lines):
    	words = line.split()	

        #count number of characters used inside words
    	n_nonempty_caracteres = 0 
    	for word in words:
    		n_nonempty_caracteres += len(word)
    	
        #find the minimal number of characters required for that line
        #(we subtract one because we don't add a space to the last word)
        required_caracteres = n_nonempty_caracteres + len(words) - 1   

    	new_line = []

        n_first_nonempty_caracteres = 0
        if required_caracteres > justify_length:        
            for word_number, word in enumerate(words):
                n_first_nonempty_caracteres += len(word)
                if len(word)>justify_length:
                    print "Error! I found a word longer than the justify length"
                    return -1
                if n_first_nonempty_caracteres < justify_length:
                    n_first_nonempty_caracteres += 1 #count the space added
                elif n_first_nonempty_caracteres > justify_length:
                    #subtract the extra word added
                    n_first_nonempty_caracteres -= len(word) 
                    if(line_number == len(lines) - 1):
                        lines.append(" ")
                    #now we add every extra word to the next line
                    next_line_list = lines[line_number+1].split()
                    next_line_list_copy = next_line_list[0:len(next_line_list)]
                    #add spaces to the list
                    for n,w2 in enumerate(next_line_list_copy):
                        if n == (len(next_line_list_copy)-1):
                            continue
                        next_line_list.insert(1+2*n, " ")

                    lines[line_number+1] = words[word_number:len(words)]+ [" "] + next_line_list
                    lines[line_number+1] = "".join(lines[line_number+1])
                    #remove every extra word on the current line
                    for i in range(word_number, len(words)):                
                        words.pop(word_number)
                    #get out of the loop
                    break


    	if 0==0: 
            number_of_spaces = max((justify_length - n_nonempty_caracteres)/max(len(words)-1,1),1)
            n_caracteres_in_new_line = 0
            for i,word in enumerate(words[0:(len(words)-1)]):
                new_line.append(word)
                if(i != len(words)-2):
                    new_line.append(number_of_spaces*" ")
                    n_caracteres_in_new_line += + len(word) + number_of_spaces
                else:
                    n_caracteres_in_new_line +=  len(word)
            last_word = words[len(words)-1]
            number_of_spaces_left = justify_length - n_caracteres_in_new_line - len(last_word)
            if(len(words)>1):
                new_line.append(number_of_spaces_left*" ")
            new_line.append(last_word)
            new_line.append('\n')
            new_line = "".join(new_line)
            new_text.append(new_line)
    new_text = "".join(new_text)
    print "\tJustified text:"
    print justify_length*'-'
    print new_text
    print justify_length*'-'



# Program justifies text contents of a given file
# This is the actual code that gets run when the
# program is run. 
#
# DO NOT EDIT BELOW HERE.
if __name__ == "__main__":

    file_name = ''
    length = -1

    # Parse command line arguments
    try:
        for i in range(len(sys.argv)):
            if sys.argv[i] == '-f':
                file_name = sys.argv[i+1]
            elif sys.argv[i] == '-l':
                length = int(sys.argv[i+1])
    except:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')

    if file_name == '' or length < 1:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')
        
    justify(file_name, length)
