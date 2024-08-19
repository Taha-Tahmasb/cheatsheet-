string = input()
tmp = []
for i in string:
    tmp.append(i)
cnt1 = tmp.count("A")
cnt2 = tmp.count("C")
cnt3 = tmp.count("B")
if cnt3 == cnt2 + cnt1 :
    print("YES")
elif cnt3 == cnt2 :
    print("YES")
elif cnt3 == cnt1 :
    print("YES")
else :
    print("NO")
