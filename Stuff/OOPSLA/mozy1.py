f = open("mozy1.dat")
for line in f:
    nums = map(eval, line.split()) # get list of numbers
    size = len(nums)
    if size == 1:
        print "match"
    elif size > 0:
        diffs = [abs(nums[i+1] - nums[i]) for i in range(size-1)]
        themin = min(diffs)
        themax = max(diffs)
        if themin > 0 and themax < size:
            print "match"
        else:
            print "not a match"

f.close()
