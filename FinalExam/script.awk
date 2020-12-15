# This script takes a comma separated list
# of house listings and calculates the number
# of houses that have a pool and the average
# price of houses that have 4 or more bedrooms.

# Initialization of variables

BEGIN { HasPool = ""
	PoolHouses = 0
	NumBeds = 0
	CurrentPrice = 0
	BedTotal = 0
	BedPriceTotal = 0
	BedAvg = 0
	FS = ","
}
	# For all houses, check if it has a pool, the number of beds, and the price.
	NR > 1 { HasPool = $3
		 NumBeds = $1 
		 CurrentPrice = $4 }
	
	# Add to the count of pool houses if the house has a pool
	HasPool == "yes" { PoolHouses++ }
	
	# If the number of beds is greater than or equal to 4, add to the count for houses,
	# and add the price to the running total
	NumBeds >= 4 { BedTotal++
		       BedPriceTotal += CurrentPrice }

# Ending statements

END {	# Calculate the average price for houses with 4 or more beds
	BedAvg = BedPriceTotal/BedTotal

	# Print the number of houses that have a pool, and the average price for houses 
	# with 4 or more beds.
	print "Pool count = " PoolHouses
	print "Average 4+ beds = " BedAvg }



