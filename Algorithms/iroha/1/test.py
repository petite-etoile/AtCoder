from subprocess import*
n, k = map(int, input().split())
*a, = map(int, Popen(['wsl', 'factor', str(n)],
                     stdout=PIPE).communicate()[0].split()[1:])
print(a)
