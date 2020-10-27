# CptS-223, Test Space to Practice Hashing

---

The point of hashing is to provide a way to catalogue data (especially very large set of data) efficiently.

For small datasets, array is without a doubt king in tasks that require extremely fast access and
retrieval of information. However, the deadly weakness of array is that it is too rigid for scaling,
which defeats the purpose of storing large and growing datasets.

So, is there a way to meet between the very fast index-based access time of array while also allow
data to scale indefinitely?

This is where *Hashing* really shines. Hashing is basically a method to organized data into ordered
indexes, which called **keys** to avoid confusion. The **keys** are created via a hash function which
basically accept a passed element of the data unit and returns a sufficiently unique 'tag' for that
data unit. How unique the key is all depends on how good the hash function is. The **keys** then can be
organized and mapped into a BST tree (usually a more efficient variation such as AVLT or RBT). Due to
the highly efficient nature of BST trees (Big-Oh: logN), access time for any particular data with a
provided key is very fast. Although not instantaneous like array index, it is still extremely fast and
efficient while also allowing data to scale indefinitely without an a cumbersome algorithm to resize
and update the array.
