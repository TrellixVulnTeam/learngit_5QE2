L1=['Hello','world',18,'Apple',None]
L2=[s.lower()  for s in L1 if isinstance(s,str)==True ]
print(L2)
if L2==['hello','world','apple']:
    print('测试通过!')
else:
    print('测试失败!')
