# わからんわからん
"""
偉い人が書いたやつ
import numpy as np

N = int(input())
n0 = 2**int(np.ceil(np.log2(2*N - 1)))

A = np.zeros(n0)
B = np.zeros(n0)
for i in range(N):
    A[i], B[i] = map(int, input().split())

C = np.fft.ifft( np.fft.fft(A)*np.fft.fft(B) )

print("\n".join(["0"] + ["{}".format(int(ci)) for ci in np.real(C[:2*N - 1] + 0.5)]))
"""
