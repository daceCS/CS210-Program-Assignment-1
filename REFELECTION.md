# Reflection

Answer each question in 2-4 sentences, in your own words, referring to your own code.

## 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

`concat` has to reach into the other list's private data: the `data_` array for an 
`ArrayList`, or `head_` for a `LinkedList`. It receives a `List<T>*`, so I use `dynamic_cast` 
to check that `other` is the same concrete type as `this`, and if it comes back `nullptr` 
I print a message and return without touching either list. Mixing the two would mean copying 
every pointer from an array into new nodes (or the reverse), which defeats the "move, don't 
copy" idea. It would also need extra handling for the array's fixed capacity.

## 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

The three pointers are `prev` (the node I just finished, initially `nullptr`), `curr` (the node I'm working on), and `next` (the rest of the list, saved before I change anything). In each pass I save `next = curr->next`, point `curr->next` back at `prev`, then move `prev` and `curr` forward. If I overwrite `curr->next` without saving `next` first, nothing points at the rest of the list anymore and everything after `curr` is lost. If I lose `prev`, the node I just reversed has nothing to link back to, and the new head can't be set at the end.

## 3. addAnywhere and deleteAnywhere both need a bounds check. What's the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

`addAnywhere` accepts `0` to `size`, inclusive, because inserting at `size` means appending after the last element. `deleteAnywhere` accepts `0` to `size - 1`, because there has to be an existing element at that position, so an empty list or `position == size` can't be deleted. In both, if the position is out of range I print an "invalid position" message and return without changing the list or crashing.

## 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat's performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

Without a tail pointer, the only way to find the last node is to walk from `head_` to the end, which takes O(n). `addFront` and `deleteFront` only touch the head, so they never needed that. My `LinkedList` does still have `tail_`, so my `concat` just sets `tail_->next = o->head_`, which is O(1). The cost is that every method that changes the end of the list has to keep `tail_` correct: `addFront` on an empty list, `deleteFront` when it removes the last node, `deleteAnywhere` on the last node, `reverse` (the old head becomes the tail), and `concat` itself.

## 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

To insert at `position` in `ArrayList::addAnywhere`, everything from `position` onward has to move one slot to the right to make room. I loop from the end (`i = size_` down to `position + 1`) and copy `data_[i - 1]` into `data_[i]`. If I shifted from the front instead, `data_[position + 1] = data_[position]` would overwrite the next element before I'd copied it, and I'd end up with the same value repeated down the array and the original elements lost.

## 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

The line is **line 45 of `main.cpp`**: `table->reverse();`. It reverses the turn order in place. Without it, the "After" print would show the same order as "Before", so the Reverse card would do nothing and play would keep going the same direction. The later steps would also be wrong: `deleteAnywhere(2)` would remove a different player, and the second table would be attached to a different list order.