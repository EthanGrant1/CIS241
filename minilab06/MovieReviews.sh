#! /bin/bash

# Variables

# When writing the directory, include train or test, but not pos or neg directories
directory="$1"

# Determines the subdirectory to cd into using the rating number
rating="$2"

# If conditional to check if whether or not to go into pos or neg

if ((${rating}>6)); then
	directory="${directory}pos"
	cd "${directory}"
elif (($rating<5)); then
	directory="${directory}neg"
	cd "${directory}"
else
	echo "Please use a number that is 1, 2, 3, 4, 7, 8, 9, or 10"
fi

minilab6dir='/mnt/c/Users/Golden'\ 'Gamer/Desktop/CIS241Files/CIS241/minilab6'

cd "${directory}"
cat "${directory}/"*_"${rating}.txt" > "${minilab6dir}/interfiles/Reviews.txt"
tr -d "'" < "${minilab6dir}/interfiles/Reviews.txt" > "${minilab6dir}/interfiles/ReviewsNoApostrophe.txt"
tr -c [:alpha:] '\n' < "${minilab6dir}/interfiles/ReviewsNoApostrophe.txt" > "${minilab6dir}/interfiles/WordList.txt"
tr [:upper:] [:lower:] < "${minilab6dir}/interfiles/WordList.txt" > "${minilab6dir}/interfiles/WordListIgnoreCase.txt"
sort "${minilab6dir}/interfiles/WordListIgnoreCase.txt" > "${minilab6dir}/interfiles/WordListSorted.txt"
uniq -c "${minilab6dir}/interfiles/WordListSorted.txt" > "${minilab6dir}/interfiles/WordListCount.txt"
sort "${minilab6dir}/interfiles/WordListCount.txt" > "${minilab6dir}/interfiles/WordListSmallBig.txt"
grep -v 'br$\| $\|[0-9]$' "${minilab6dir}/interfiles/WordListSmallBig.txt" > "${minilab6dir}/interfiles/WordListGrep.txt"
grep -vwf "${minilab6dir}/stopwords.txt" "${minilab6dir}/interfiles/WordListGrep.txt" > "${minilab6dir}/interfiles/WordListStopWords.txt"
sort -r "${minilab6dir}/interfiles/WordListStopWords.txt" > "${minilab6dir}/interfiles/WordListBigSmall.txt"
head --lines=12 "${minilab6dir}/interfiles/WordListBigSmall.txt" >> "${minilab6dir}/interfiles/FinalWordList.txt"
cat "${minilab6dir}/interfiles/FinalWordList.txt"
