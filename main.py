al = ['a', 'b', 'c', 'd']
accepting_states = ['q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q6', 'q7', 'q8', 'q9', 'q10', 'q11', 'q12']
slovo = input()


# s0 = -
# s1 = a+b+c+d
# aa*(a+b+c+d)
# xx*(a++c+d)
# xx*(a+b+x+d)
# xx*(a+b+c+x)
# xxx

def check(slovo):
    s = 'q0'
    for i in slovo:
        if i not in al:
            return False

        if s != 'q9' and s != 'q10' and s != 'q11' and s != 'q12':
            if s != 'q1' and s != 'q5' and i == 'a':
                s = 'q1'
            elif s != 'q2' and s != 'q6' and i == 'b':
                s = 'q2'
            elif s != 'q3' and s != 'q7' and i == 'c':
                s = 'q3'
            elif s != 'q4' and s != 'q8' and i == 'd':
                s = 'q4'
            elif s == 'q1' and i == 'a':
                s = 'q5'
            elif s == 'q2' and i == 'b':
                s = 'q6'
            elif s == 'q3' and i == 'c':
                s = 'q7'
            elif s == 'q4' and i == 'd':
                s = 'q8'
            elif s == 'q5' and i == 'a':
                s = 'q9'
            elif s == 'q6' and i == 'b':
                s = 'q10'
            elif s == 'q7' and i == 'c':
                s = 'q11'
            elif s == 'q8' and i == 'd':
                s = 'q12'

    if s != 'q9' and s != 'q10' and s != 'q11' and s != 'q12':
        print("Слово", slovo, "принадлежит языку")
    else:
        print("Слово", slovo, "не принадлежит языку")


check(slovo)
