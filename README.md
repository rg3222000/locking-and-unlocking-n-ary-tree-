# locking-and-unlocking-n-ary-tree
n-ary tree that takes in number of children that is n from the user alongside the number of nodes.
# The functions defined on this tree are as follows.
islock(X)- returns true if a given node is locked and false if it is not. A node is locked if lock() has successfully executed for the node.\
Lock(X,uid)- user with user id as uid locks the given node X if it is not already locked by some user or has a locked ancestor or descendent and updates lock information...Lock is possible only if ancestors and descendants of current node are not locked.\
unLock(X,uid)- user with user id as uid can unlock the node if the node was previously locked by the user with user id as uid otherwise it returns false and updates information regarding it's ancestors and descendents.
