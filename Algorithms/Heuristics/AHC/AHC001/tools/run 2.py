from subprocess import run,PIPE,CalledProcessError
import sys


input_file = "in/0000.txt"
output_file = "out.txt"

# command_draw = ["cargo","run","--release","-bin", "gen", "<", "tools/seed.txt"]
command_draw = ["cargo","run","--release","--bin","vis", input_file, output_file]
# command_draw = ["./a.out"]

# run(command_draw)
try:
    run(command_draw,check=True)
except CalledProcessError:
    print('外部プログラムの実行に失敗しました [' + " ".join(command_draw) + ']', file=sys.stderr)
    sys.exit(1)

# with open("temp.txt","w") as f:
#     try:
#         res = run(command_measure,stdout=f,stderr=f,check=True)
#     except CalledProcessError:
#         print('外部プログラムの実行に失敗しました [' + "".join(command_measure) + ']', file=sys.stderr)
#         sys.exit(1)

# with open("temp.txt","r") as f:
#     try:
#         run(command_draw,stdin=f,check=True)
#     except CalledProcessError:
#         print('外部プログラムの実行に失敗しました [' + "".join(command_draw) + ']', file=sys.stderr)
#         sys.exit(1)
        
# "p measure_time_1.py 2>&1 | p draw_graph.py"
# command = ["python3","measure_time_1.py","2>&1","|","python3","draw_graph.py"]
