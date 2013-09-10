


#my_array = ['....o.', '...o..', '..o...', '.o....', 'o.....', '......']

#my_array = ['oooo.', '.oooo', 'oooo.', '.oooo', '.....']


my_array = ['.....', '.....', '.....', '.....', '.....']


col = len(my_array[0])
row = len(my_array)

def determine(i, j):

    len1 = 1
    len2 = 1
    len3 = 1
    len4 = 1

    for x in xrange(1,5):
        if (x+i < row and my_array[x+i][j] == 'o'):
            len1 = len1 + 1
        if (x+j < col and my_array[i][x+j] == 'o'):
            len2 = len2 + 1
        if (x+i < row and x+j < col and my_array[x+i][x+j] == 'o'):
            len3 = len3 + 1
        if (x+i < row and j-x >= 0 and my_array[i+x][j-x] == 'o'):
            len4 = len4 + 1

    if (len1 == 5 or len2 == 5 or len3 == 5 or len4 == 5):
        return True

    return False

found = False
for i in range(row):
    for j in range(col):
        if (my_array[i][j] == 'o' and determine(i,j)):
            found = True
            break
    else:
        if (found):
            break

if (found):
    print 'found'
else:
    print 'not found'
