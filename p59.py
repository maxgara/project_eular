import os
import re

fp = open("common_words.txt","r")
words = fp.read().split('\n')
fp.close()
fp = open("p059_cipher.txt","r")
cxtext=list(map(int, fp.read().split(',')))
minkey = ord('a')
keys = [minkey,minkey,minkey]
maxkey = ord('z')
done = False
besthits = 0
bestkey = []
beststr = ""
while not done:
    #make cleartext str for each key
    cltextstrs = []
    i=0
    while(i<len(cxtext)):
        key = keys[i%3]
        cltextint = (cxtext[i] ^ key)
        cltextstrs.append(chr(cltextint))
        i=i+1
    cltext = "".join(cltextstrs);

    #count number of word hits
    hits = 0
    for word in words:
        wordmatches = re.findall(word,cltext)
        hits = hits + len(wordmatches)
    if hits > besthits:
        keystr = "".join(map(lambda key: chr(key),keys))
        print(f"{hits} - {keystr} - {cltext}")
        besthits = hits
        bestkey = keys
        beststr = cltext
    #increment keys
    keys[0] = keys[0]+1
    for i in range(0,len(keys)):
        if keys[i]>maxkey:
            keys[i] = minkey
            keys[i+1] = keys[i+1]+1
        elif keys==[maxkey,maxkey,maxkey]:
            done=True


print(beststr)
sum = 0
for c in beststr:
    sum = sum + ord(c)
print(f"sum of ascii vals:{sum}")
