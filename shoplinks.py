import webbrowser
import time
import os

abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

BASE = "http://shopalphacomm.com/"
#new = 2
#webbrowser.open_new_tab(BASE)
#time.sleep(2)
text = open("items.txt",'r')
items=text.readlines()



for i in range(len(items)):
    #webbrowser.open(BASE + items[i],new=new)
    ''' if (i+1) % 10 == 0:
        print "Press Any Key To Continue: "
        raw_input() '''

    webbrowser.open_new_tab(BASE + items[i])
    print i + 1, ": Opening", items[i]
    time.sleep(1)
    
    