# Tiles-to-word
# Question
“You are given a dictionary (dictionary.txt), containing a list of words, one per line. Imagine you have seven tiles. Each tile is either blank or contains a single lowercase letter (a-z).  Please list all the words from the dictionary that can be produced by using some or all of the seven tiles, in any order. A blank tile is a wildcard, and can be used in place of any letter.  

1. Find all of the words that can be formed if you don't have to deal with blank tiles. 
2. Find all of the words that can be formed, including those where blank tiles are used as wildcards.
3. Please bear in mind you will need to process several hundred of 7-tile sets with the same dictionary.
 
Expectations:
 
a) Please write down the reasoning or the explanation behind your solution in plain English or pseudo-code. Please do a big O analysis of your solution, need not be overtly mathematical, an informal big O analysis will do.
b) Please provide the source code of your implementation.
c) Please include instructions on how to compile and run your code.
d) Bonus points for source code in C/C++/C#. “

# Solution: 
As no tile information was provided, I made a general algorithm that can rum with whatever tiles provided. Loop for each word in the dictionary, and for each word, check the characters in the word if it is in the tiles provided. The only difference between q1 and q2 is if we treat blank tile as wildcard. Following is the pseudo-code. 
```
For(word in dictionary)
{
	If(word.size() < tiles.size())
	{
		For(character in word)
{
	For(tile in tilelist)
	{
		If(character == tile || tile == ‘ ‘)
		{
			Record that tile
		}
If(didn’t found that tile) return false;
}
}
	}
}
```
The source code is written in C++. It is in the file “main.cpp”. You can compile and run it with the following command:
## Windows:
```
g++ main.cpp -o main.exe
```
And then run it by:
### without wildcard
```
main -wo “your tiles”
```
### with wildcard
```
main -w “your tiles”
```
## Linux:
```
g++ main.cpp -o main
```
And then run it by:
### without wildcard
```
./main -wo “your tiles”
```
### with wildcard
```
./main -w “your tiles”
```
