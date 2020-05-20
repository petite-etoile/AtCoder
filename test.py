for i in range(1,104):
    direc = "ARC"+str(i).zfill(3)
    print("mkdir "+direc)
    print("mv {}* {}/".format(direc,direc))