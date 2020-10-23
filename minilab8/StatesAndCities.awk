# AWK Script

# Beginning initializations
BEGIN {

# Initializing the variables
Change = 0
State = ""

# Field Seperator
FS = ","
}

# Loops over every line and calculates the total
# Change for each State
{

# Specific field numbers for each variable
Change = $5
State = $2

# An associative array which holds the total Change
# for each State
ChangeArray[State] += Change
}

# Ending statements
END {

print "State, Overall Change"
print "----------------------"
# For loop that rints the State and ChangeArray line-by-line
for (key in ChangeArray)
print key", "ChangeArray[key]
}
