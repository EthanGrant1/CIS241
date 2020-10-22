# sed Script

# Replaces ("make) with ('make')
s/["]([[:alnum:]]+)/\'\1\' /

# Replaces (model") with ('model')
s/' +([^"]+)["]/\' \'\1\'/

# Replaces year in two number format (i.e. 72) with decades (i.e. 70s)
s/(.* {3})(([0-9])([0-9]))( {2}.*)/\1\30s\5/

# Removes all lines with missing data
/(.*\?.*)/d
