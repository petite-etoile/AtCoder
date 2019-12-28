while 1:
    s = input().replace('"','\\"').replace("\n","\\n")
    print("\""+s+"\",")