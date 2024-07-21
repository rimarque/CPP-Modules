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

# **The Ford Johnson Algorithm**
The Ford-Johnson algorithm, also known as merge-insertion sort is a sorting algorithm designed to perform as few comparisons as possible to sort a collection.

From what I was able to gather, this algorithm isn't widely used and is not considered to be that fast or efficient. But it's interesting in what concerns the minimum number of comparisons possible.

I will do my best to explain the algorithm regarding my interpretation of the information I was able to find on it.
All the links that helped me understand the the algorithm are shown in the **Resources Section**.

I will do a step by step of the algorithm while relating them to the functions in my code. My implematation can be found in CPP09/ex02. I implemented the algorithm in the template class PmergeMe<Container>, so it can use both deque and vector and compare the containers time performace.

If you clone the repository, in the main function, when calling the fordJohnsonAlgorithm(**bollean**) you can change the argument to true:
```
line 72 std::vector<int> sorted_vec = sortvec.fordJohnsonAlgorithm(false); ==> std::vector<int> sorted_vec = sortvec.fordJohnsonAlgorithm(true);
```
It activates a flag that prints all the steps of the algorithm, so you can better understand how it works.

My program only takes positive intergers: n > 0 && n < INT_MAX

Consider N the number of elements to sort.

Input {20, 30, 2, 109, 40, 8, 3, 55, 99}

Step 1. Make pairs (PmergeMe<Container>::makePairs()) - take the unsorted input sequence and pair the numbers, forming a collection of N/2 pairs of numbers. This can be done randomly. If N is odd, the last number of the collection will be unpaired.

Pair Collection:
(20, 30)
(2, 109)
(40, 8)
(3, 55)
( , 99)

Step 2. Sort pairs (PmergeMe<Container>::sortPairs()) - perform pairwise comparisons so that the first number of each pair is also the highest. As N is odd, in our example, 99 in unpaired.

Pair Collection:

(30, 20)

(109, 2)

(40, 8)

(55, 3)

( , 99)


Step 3. Sort Pair Collection (quicksort_pair()) - recursively sort Pair Collection by the highest value of each pair (in our case, the first). Every article I read about this algorithm mentioned that this sorting step needed to be done recursively. I found no more information about how it should be done. So I researched a few recursive sorting algorithms and implemented quicksort, adapting it to sort a pair collection by the first of each pair. 
The important thing here is that the pairs remain connected, but ordered by their highest value.

Example:

Pair Collection:

(30, 20)

(40, 8)

(55, 3)

(109, 2)

( , 99)


Step 4. Highest numbers of each pair form a sorted sequence (S) and lowest numbers of each pair form a unsorted sequence (pend). (PmergeMe<Container>::Insertion()).

S: 30 40 55 109

pend: 20 8 3 2 99


Step 5: Insert the numbers in the unsorted sequence (pend) into the sorted sequence (S) (PmergeMe<Container>::Insertion())

5.1: Insert the fisrt number of pend in the begining of S. The first number of pend is smaller then the first number of S (it's pair), and because S is sorted, the first number of pend is smaller then every number in S).

S: 20 30 40 55 109


5.2. Going forward, there is a specific order in which we insert the numbers from pend into S.
We use the jacobstal sequence to find the next index to insert. The goal is to insert the number in a subsequence of S with size (2^x)-1. This example assumes the index starts at 1 and instead of zero.


5.2.1. Index to insert: 3; insertion area: 3 => (2^2)-1

Insert index 3: S {3 20 30 40 55 109}

Insert index 2: S {3 8 20 30 40 55 109}


5.2.2. Index to insert: 5; insertion area: 7 => (2^3)-1

Insert index 5: S {3 8 20 30 40 55 99 109}

Insert index 4: S {2 3 8 20 30 40 55 99 109}

Has you can see in the example, we choose the index of pend we want do insert and then we go backwards in the pend sequence until we find a number that was already inserted.

## **Detailed insertion explanation**

If you are still confused I will try my best to explain step 5.1 at a deeper level.
