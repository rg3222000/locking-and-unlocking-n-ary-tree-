# locking-and-unlocking-n-ary-tree\
n-ary tree that takes in number of children that is n from the user alongside the number of nodes.\
# The functions defined on this tree are as follows.\
islock()- returns true if a given node is locked and false if it is not. A node is locked if lock() has successfully executed for the node.\
Lock()- locks the given node if possible and updates lock information. Lock is possible only if ancestors and descendants of current node are not locked.\
unLock()- unlocks the node and updates information.
