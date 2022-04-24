m->pattern length
n->text length
1<=m<=n
---------------------------------------------------------------------------------
NO PREPROCESSING
Naive
O{(n-m+1)(m)}

Naive when all characters are distinct O(n)
---------------------------------------------------------------------------------
PREPROCESSING Pattern
Rabin Karp
O{(n-m+1)(m)}
but better than Naive on avg 
KMP
O(n)
---------------------------------------------------------------------------------
Preprocesses TEXT
SUffix Tree:O(m)