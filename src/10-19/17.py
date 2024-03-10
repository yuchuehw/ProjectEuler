ONES = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen']

TENS = ['', '', 'twen', 'thir', 'for', 'fif']

BIGS = ['','','m', 'b', 'tr', 'quadr', 'quint', 'sext', 'sept', 'oct', 'non', 'dec', 'undec', 'duodec', 'tredec', 'quattuordec', 'quindec', 'sexdec', 'septendec', 'octodec', 'novemdec', 'vigint']

def spell_small(i):
    s = ""
    x,y=divmod(i,100)
    s+=f"{ONES[x]} hundred{' and 'if y else''}"if x else''
    s+=ONES[y]if y<16 else f"{ONES[y-10]}teen"if y<20 else''
    x,y=divmod(y,10)

    s+=f"{TENS[x] if x<6 else ONES[x]}ty{'-'if y else''}{ONES[y] if y else''}"if x>1 else''
    return s.replace('tt','t')

def num_builder(i,big,result):
    n,i = divmod(i,1000)
    s = spell_small(i)
    if not i:0
    elif big == 1:s += BIGS[big]+" thousand"
    elif big:s += " "+BIGS[big]+"illion"
    if s:result.insert(0,s)
    if n:num_builder(n,big+1,result)

def spelling_number(i):
    result = []
    if i == 0:result += ["zero"]
    big_counter = 0
    num_builder(i,0,result)
    return ", ".join(result)

S=''
for i in range(1,1001):
	S+=spelling_number(i)
print(len(S)-S.count(' ')-S.count(',')-S.count('-'))
