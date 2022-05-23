## Classical queue

The implementation of a circular queue using arrays uses this format:

1. Enqueue adds an element and shifts our rear
2. Dequeue removes an element **from the front alone** and shifts our front to the next element
> Note that no shifting happens when we dequeue, the sizing is done logically via front/end.
3. Once the queue is completely empty, we execute a reset. THe idea here is that a queue's ops are all in constant time as we only modify these variables.

Keeping with that, resizing is in linear time and defeats the purpose so we only reset when we get to an empty state after enqueing.

Qns I have:
* How do you know that the queue is full if we do not store a fixed size?

## Circular queue.

The circular queue solves this wastage by moving the rear automatically when we want to enqueue as long as it isn't full (This requires a rethink of our `isFull` algo).