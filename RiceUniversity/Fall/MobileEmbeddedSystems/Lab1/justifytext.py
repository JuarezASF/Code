import sys

# 
# INSERT DESCRIPTION HERE
#
def justify(file_name, justify_length):
    # COMPLETE ME
    text_file = open(file_name, 'r')
    print 'Mobile and Embedded Systems - Lab1 - Part 1 - Python'
    print 'Student: Juarez Aires Sampaio Filho'
    print 'Rice ID: S01217136'
    print 5*'\n'
    print "\tFilename:", file_name
    print "\tJustify length:", justify_length
    print "\tOriginal text:"
        #print original text between two dashed lines
    print justify_length*'-'
    lines = text_file.readlines()
    for line in lines:
    	print line,
    print justify_length*'-'

    line_number = 0 	
    new_text = []
    
    for line in lines:
    	words = line.split()	
    	n_nonempty_caracteres = 0 #number of caracteres used inside words
    	for word in words:
    		n_nonempty_caracteres += len(word)
    	required_caracteres = n_nonempty_caracteres + len(words) - 1    	
    	new_line = []
    	if required_caracteres < justify_length:
            number_of_spaces = (justify_length - n_nonempty_caracteres)/max(len(words)-1,1)
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
        line_number = line_number + 1
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
