This is Epsilon (Advanced method to compare two different number with close precision)

Epislon - the most common method of doing floating point equality involves using a function that looks to see if two numbers are almost the same. 
If they are “close enough”, then we call them equal. The value used to represent “close enough” is traditionally called epsilon number. 
Epsilon is generally defined as a small positive number (e.g. 0.00000001, sometimes written 1e-8).

If we say any number that is within 0.00001 of another number should be treated as the same number, then:

+ Case 1: 1 and 1.0001 would be different, but 1 and 1.00001 would be the same. That’s not unreasonable.
+ Case 2: 0.0000001 and 0.00001 would be the same. That doesn’t seem good, as those numbers are two orders of magnitude apart.
+ Case 3: 10000 and 10000.00001 would be different. That also doesn’t seem good, as those numbers are barely different given the magnitude of the number.
