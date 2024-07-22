# **CPP-Modules**

## :speech_balloon: **About**
10 Modules to learn the basics of Object Oriented Programming. Coded in C++.

## 🙋‍♀️ **Authorship**
- [Rita Marques](https://github.com/rimarque)

## :inbox_tray: **Cloning the repository**

```shell
git clone git@github.com:rimarque/CPP-Modules.git
```

## 💎 **Modules concluded**
### **Module** 0️⃣0️⃣
```
- Namespaces
- Classes
- Member functions
- Stdio streams
- Initialization lists
- Static
- Const
```
### **Module** 0️⃣1️⃣
```
- Memory allocation
- Pointers to members
- References
- Switch statement
```

### **Module** 0️⃣2️⃣
```
- Ad-hoc polymorphism
- Operator overloading
- Orthodox Canonical class form
```

### **Module** 0️⃣3️⃣
```
- Inheritance
```
### **Module** 0️⃣4️⃣
```
- Polymorphism
```

### **Module** 0️⃣5️⃣
```
- Exceptions
```

### **Module** 0️⃣6️⃣
```
- Type casting
```

### **Module** 0️⃣7️⃣
```
- Templates
```
### **Module** 0️⃣8️⃣
```
- Templated containers
- Iterators
- Algorithms
```
### **Module** 0️⃣9️⃣
```
- STL (Standard Template Library)
- Bitcoin value calculator
- Reverse Polish Notation
- Ford-Johnson algorithm
```

## 🌐 **Resources**
[Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)

[Virtual functions and runtime polymorphism](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/)

[Abstract Class vs Interface Equivalence in C++](https://blog.devgenius.io/what-is-the-difference-between-interface-and-abstract-class-1b76277f2659)

[Type casting](https://cplusplus.com/doc/oldtutorial/typecasting/)

[Reverse Polish Notation Calculator](https://paodayag.dev/reverse-polish-notation-js-parser/)

[Reverse Polish Notation](https://www.wallstreetmojo.com/reverse-polish-notation/#h-frequently-asked-questions-faqs)

[Stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/?ref=lbp)

[Queue](https://www.geeksforgeeks.org/queue-cpp-stl/)

[Ford-Johnson merge-insertion sort - codereview](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)

[Ford-Johnson merge-insertion sort - figma](https://www.figma.com/board/JW5jFeoD6fbSnu2K2XXfKV/Ford-Johnson-(merge-insertion-sort)-algorithm?node-id=0-1&t=JN6OEvVyCySPm7fN-0)

[Ford-Johnson merge-insertion sort - github.com/PunkChameleon](https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort)

[Ford-Johnson merge-insertion sort - wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)

## :link: **Compilation**

Choose the module and the exercise you want to compile, for example:

```sh
$ cd ./CPP00/ex00
```

To compile the program you should run `make`.

This rule will generate an executable file. To launch the executable you should follow this syntax:

```sh
$ ./executable
```

## ➿ **The Ford Johnson Algorithm**

The Ford-Johnson algorithm, also known as merge-insertion sort is a sorting algorithm designed to perform as few comparisons as possible to sort a collection.

From what I was able to gather, this algorithm isn't widely used and is not considered to be that fast or efficient. But it's interesting in what concerns the minimum number of comparisons possible.

I will do my best to explain the algorithm regarding my interpretation of the information I was able to find on it.
All the links that helped me understand the the algorithm are shown in the **Resources Section**.

I will do a step by step of the algorithm while relating them to the functions in my code. My implematation can be found in CPP09/ex02. I implemented the algorithm in the template class PmergeMe, so it can use both deque and vector and compare the containers time performace.

You can run `make` in the CPP09/ex02 folder to compile the program. Then launch it:

```sh
$ ./PmergeMe 20 30 2 109 40 8 3 55 99
```

In the main function, when calling the fordJohnsonAlgorithm(
`
bollean
`
) you can change the argument to ***true***:
```
std::vector<int> sorted_vec = sortvec.fordJohnsonAlgorithm(true);
```
It activates a flag that prints all the steps of the algorithm, so you can better understand how it works.

My program only takes positive intergers as input: 0 < n < INT MAX

Consider N the number of elements to sort.

### Next there is a step by step of the algorithm with examples:

```
Input {20, 30, 2, 109, 40, 8, 3, 55, 99}
```
### Step 1. Make pairs
Take the unsorted input sequence and pair the numbers, forming a collection of N/2 pairs of numbers. This can be done randomly. If N is odd, the last number of the collection will be unpaired. (PmergeMe<Container>::makePairs()).
```
Pair Collection:
(20, 30)
(2, 109)
(40, 8)
(3, 55)
( , 99)
```

### Step 2. Sort pairs 
Perform pairwise comparisons so that the first number of each pair is also the highest. As N is odd, in our example, 99 in unpaired. (PmergeMe<Container>::sortPairs()).
```
Pair Collection:
(30, 20)
(109, 2)
(40, 8)
(55, 3)
( , 99)
```

### Step 3. Sort Pair Collection
Recursively sort Pair Collection by the highest value of each pair (in our case, the first). Every article I read about this algorithm mentioned that this sorting step needed to be done recursively. I found no more information about how it should be done. So I researched a few recursive sorting algorithms and implemented quicksort, adapting it to sort a pair collection by the first of each pair. 
The important thing here is that the pairs remain connected, but ordered by their highest value. (quicksort_pair()) 

```
Pair Collection:
(30, 20)
(40, 8)
(55, 3)
(109, 2)
( , 99)
```


### Step 4. Create S and pend sequences
Highest numbers of each pair form a sorted sequence (S) and lowest numbers of each pair form a unsorted sequence (pend). (PmergeMe<Container>::Insertion()).
```
S: 30 40 55 109
pend: 20 8 3 2 99
```

### Step 5: Insertion 
Insert the numbers in the unsorted sequence (pend) into the sorted sequence (S), using binnary search. 
(PmergeMe<Container>::Insertion())

5.1: Insert the fisrt number of pend in the begining of S. The first number of pend is smaller then the first number of S (it's pair), and because S is sorted, the first number of pend is smaller then every number in S).
```
S: 20 30 40 55 109
```

5.2. Going forward, there is a specific order in which we insert the numbers from pend into S.
We use the jacobstal sequence to find the next index to insert, and use binnary search to find the correct place of insertion. The goal is to search in a subsequence of S with size (2^x)-1. This example assumes the index starts at 1 and instead of zero.


5.2.1. Index to insert: 3; insertion area: 3 => (2^2)-1
```
Insert index 3: S {3 20 30 40 55 109}
Insert index 2: S {3 8 20 30 40 55 109}
```

5.2.2. Index to insert: 5; insertion area: 7 => (2^3)-1
```
Insert index 5: S {3 8 20 30 40 55 99 109}
Insert index 4: S {2 3 8 20 30 40 55 99 109}
```
Has you can see in the example, we choose the index of pend we want do insert and then we go backwards in the pend sequence inserting the numbers one by one into the first (2^x)-1 numbers of S.

### 🔍  **Detailed insertion explanation**

If you are still confused I will try my best to explain step 5.2 at a deeper level.

We will use notation like p1, p2, p3 to describe the numbers in pend, and s1, s2... to describe the numbers in S (where p1 and s1 are the first numbers of each sequence).

After step 4 we have two sequences: S (witch is sorted, and contains the highest numbers of each pair) and pend (witch is unsorted, and contains the smallest numbers of each pair). Such as: p1 < s1; p2 < s2; p3 < s3; p4 < s4; and so on...

Now we have to insert, one by one, the numbers in pend into S, until S contains all N numbers in ascending order.

The goal of the algorithm is to do the least number of comparisons. For the worst case scenario we get the least number of comparisons if we try to insert a number into a sequence with size (2^x) - 1 (insertion area).

The ford johnson algorithm uses binary search to find the correct place in S in which to insert each element of pend. The key for this algorithm is in the size of the subsequence of S in witch we are searching (insertion area = (2^x) - 1). 

In my code, I removed 1 from the selected indexes because in c++ indexes start at 0 instead of 1.

We know the first number of pend is smaller then the first number of S (p1 < s1), so the first step is to insert p1 in the begining of S.

Going forward, there is a specific order in which we insert the numbers from the pend sequence into S. The goal of this insertion order is to insert the number into a sequence with size (2^x) - 1 (insertion area):

1. Choose the next index to insert: use the jacobstal sequence (...3, 5, 11, 21, 43, 85...), starting at number 3, to choose the index of the next number to insert
2. Choose the next insertion area: (2^x)-1, starting at x = 2
3. Insert the choosen index into the first (2^x)-1 numbers of sorted

``` 
     The first time we will insert p3 into the first 3 numbers of sorted (insertion area = 3)
``` 

4. Go backwards in the pend sequence inserting the numbers one by one into the the first (2^x)-1 numbers of sorted

```
     The first time we will insert p2, and then stop, because p1 was already inserted
``` 

When it finds an index that has already been inserted, it repeats steps 1, 2, 3 and 4. Next time, the index will be 5, the insertion area will be 7, and we will insert p5 and p4. Then the index will be 11, the insertion area will be 15, and we will insert p11, p10, p9, p8, p7, p6.

### **Example until jacobstal number 1️⃣1️⃣**
NOTE: First we insert p1 in the begining of S

#### **Jacobstal number 3️⃣**
1. The first index to insert is 3
2. The first insertion area is 3
3. Insert p3 into the first 3 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p3 is 3 ((2^2) - 1), why?
We know p3 is smaller then s3, so we only need to look in {p1, s1, s2}
```
4. Insert p2 into the first 3 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p2 is only 3 ((2^2) - 1), why?
We know p2 is smaller then s2, so we only need to look in {p1, s1, p3}, {p1, p3, s1} or {p1, s1, s2}, depending where p3 was inserted
```

#### **Jacobstal number 5️⃣**
1. The second index to insert is 5
2. The second insertion area is 7
3. Insert p5 into the first 7 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p5 is 7 ((2^3) - 1), why?
We know p5 is smaller then s5, so we only need to look in {p1, s1, p2, p3, s2, s3, s4}
```
4. Insert p4 into the first 7 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p4 is only 7 or less ((2^3) - 1), why?
We know p4 is smaller then s4, so we only need to look in {p1, s1, p2, p3, s2, s3, p5}
```

#### **Jacobstal number 1️⃣1️⃣**
1. The thirth index to insert is 11
2. The thirth insertion area is 15
3. Insert p11 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p11 is 15 ((2^4) - 1), why?
We know p11 is smaller then s11, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, s9, s10}
```
4.1 Insert p10 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p10 is only 15 ((2^4) - 1), why?
We know p10 is smaller then s10, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, s9, p11}
```
4.2 Insert p9 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p9 is only 15 ((2^4) - 1), why?
We know p9 is smaller then s9, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, p11, p10}
```
4.3 Insert p8 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p8 is only 15 ((2^4) - 1), why?
We know p8 is smaller then s8, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, p11, p10, p9}
```
4.4 Insert p7 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p7 is only 15 ((2^4) - 1), why?
We know p7 is smaller then s7, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, p11, p10, p9, p8}
```
4.4 Insert p6 into the first 15 numbers of sorted
```
The size of the insertion area in wicth we need to search to insert p6 is only 15 ((2^4) - 1), why?
We know p6 is smaller then s6, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, p11, p10, p9, p8, p7}
```


#### **Jacobstal number 2️⃣1️⃣**
1. The fourth index to insert is 21
2. The fourth insertion area is 31
3. ...

We go on like this until all numbers from the pend sequence are inserted into S
