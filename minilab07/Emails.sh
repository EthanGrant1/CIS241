#! /bin/bash

for val in $@
do
grep -E -v '^[[:alnum:]]([[:alnum:]]|([.][[:alnum:]]))*@[[:alnum:]]([[:alnum:]]|([.-][[:alnum:]]))*[.][[:alpha:]]{2,}$' $val >> non-valid.txt
done

