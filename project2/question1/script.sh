#! /bin/bash

# Array of problem sizes
problemsizes=(8 16 32)
# Program file names
filename=""

# Arguments are program names
for args in $@
do
for val in ${!problemsizes[@]}
do
filename=${args/.py/}
python3 $args.py ${problemsizes[$val]} >> $filename.out
done
done
