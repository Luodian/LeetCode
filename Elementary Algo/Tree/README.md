# Tree

### Symmetric Tree
A brief thought is to determine whether the right child and left child have the same mid-order sequences?

But actually it's not such easy. But we can simplify this problem from a new perspective

**Comparing this tree with itself in a mirror way.** 

The problem is equal to ask: In what situation can a tree been seen as symmetrical? Well, we can start to traverse this tree from its left and right child. And it should satisfiy these conditions.

1. Mirror root's value should be the same.
2. Root's left child should be symmetrical to its right child.(Recursively)

### Level Order Traverse

Simple question, use `depth` variable to record currrent level. Traverse tree in middle order, push `val` to vector according to current leve.
When `depth > vector.size`, append a new empty vector.