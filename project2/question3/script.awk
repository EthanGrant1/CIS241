# AWK script

# Beginning initialization statements

BEGIN {

       # The total number of drunk drivers and the proportion
       # of all accidents that included at least 1 drunk driver

       DrunkDriverTotal = 0
       CurrentLineDrunkDrivers = 0
       DrunkDriverAccidents = 0
       MichDrunkDriverAccidents = 0
       DrunkDriverProportion = 0
       MichDrunkDriverProportion = 0
       MichDarkAccidentProportion = 0

       # Various other figures
       FridaySaturdayAccidents = 0
       LightCondition = 0
       DarkAccidents = 0
       FridaySaturdayProportion = 0

       # The total number of accidents overall
       AccidentCount = 0
       MichAccidenCount = 0

       # Number used as a code for each state
       StateCode = 0

       # The total number of people involved in the accidents
       PeopleInvolved = 0
       
       # The number of the day of the week
       DayOfWeek = 0

       # Field Seperator
       FS = ","
       }
       
       # If the number in Field 52 (Number of Drunk Drivers) is greater than 0,
       # then include it in the proportion of accidents with drunk drivers
       NR > 1 { AccidentCount = NR-1
         CurrentLineDrunkDrivers = $52 }
       CurrentLineDrunkDrivers > 0 { DrunkDriverAccidents++ }

       # Checks if the day of the week is Friday or Saturday and determines
       # the proportion of all accidents that occured on those days
      NR > 1 { DayOfWeek = $15 }
       (DayOfWeek == 6 || DayOfWeek == 7) { FridaySaturdayAccidents++ }

       # Checks if the state code is 26 (Michigan) and determines the proportion
       # of drunk driving accidents
       NR > 1 { StateCode = $1 
         CurrentLineDrunkDrivers = $52 }
       StateCode == 26 { MichAccidentCount++ }
       (StateCode == 26 && CurrentLineDrunkDrivers > 0) { MichDrunkDriverAccidents++ }

       # Checks if the light condition is 2, 3, or 6 and determines the proportion
       # of Michigan accidents that occurred in the dark
       NR > 1 { LightCondition = $36
         StateCode = $1 }
       NR > 1 && (LightCondition == 2 || LightCondition == 3 || LightCondition == 6) && StateCode == 26 { DarkAccidents++ }

       # Summarizes the data by state by determining the number of people involved
       # in each accident by state
      
       # Loops through every line and assigns each state
       # a value for how many people were involved in an accident
       NR > 1 {
       StateCode = $1
       PeopleInvolved = $9
       PeopleArray[StateCode] += PeopleInvolved
       }


# Ending finalization statements
END {

    # Calculation of various proportions
    DrunkDriverProportion = DrunkDriverAccidents/AccidentCount
    print "DD Proportion: "DrunkDriverProportion

    FridaySaturdayProportion = FridaySaturdayAccidents/AccidentCount
    print "Friday/Saturday Proportion: "FridaySaturdayProportion
    
    MichDrunkDriverProportion = MichDrunkDriverAccidents/MichAccidentCount
    print "MI DD Proportion: "MichDrunkDriverProportion
    
    MichiganDarkAccidentProportion = DarkAccidents/MichAccidentCount
    print "MI Dark Proportion: "MichiganDarkAccidentProportion
    
    PROCINFO["sorted_in"] = "@ind_num_asc"
    
    # For loop to print the values in the array of PeopleInvolved
    print "State Code,# People"
    {

    for (key in PeopleArray)
    
    # Includes only if there are people involved 
    if (PeopleArray[key] > 0)
        print key","PeopleArray[key]
    }

    }
