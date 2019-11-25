s = input()

n = s.replace('eraser', '').replace('erase', '').replace(
    'dreamer', '').replace('dream', '')

if not n:
    print('YES')
else:
    print('NO')
