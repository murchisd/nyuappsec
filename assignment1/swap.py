s="01 0D 00 00 47 AA 1D 31 01 20 01 80 00 00 0D 00 34 31 64 72 41 74 72 61 7A 64 FF 20 6E 00 73 65 45 3E 47 74 00 31 00 20 00 00 00 02 1D 80 01 01 01 80 00 20 00 10 00 00 00 00 6F 7F 20 73 74 53 00 64 00 00 43 21 20 83 6E 65 70 45 53 20 2F 74 02 72 47 35 20 31 00 00 0A 9F 00 01 20 03 5E 1D 73 45 53 20 6F 74 47 72 20 31 00 00 0A 85 07 00 01 80 E7 01 01 00 01 1D 80 01 00 01 00 04 00 00 0A 85 07 00 04 80 E7 00 85 00 FF F4 7F FF 01 01 00 E7 1D 01 01 01 73 80 45 3E 47 74 6F 31 47 72 20 31 00 00 0A 85 07 00 01 80 E7 01 01 00"

tmp = s.split(" ")
i=0
result=[]
while i < len(tmp):
    result.append(tmp[i+1])
    result.append(tmp[i])
    i+=2

print(' '.join(result))
