BEGIN {
FS = ","
totalscore = 0
totalsoccergames = 0
homegameswon = 0
}

NR > 1 && ($2 == "soccer(W)") {
        totalscore += $4
        totalsoccergames++
}

NR > 1 && ($7 == "yes") && ($3 == "W") {
        homegameswon++
}

END {
        print "Avg GVSU soccer score = " totalscore/totalsoccergames
        print "Count GVSU home wins = " homegameswon }
