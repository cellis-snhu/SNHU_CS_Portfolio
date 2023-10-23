# SNHU_CS

# CS250 Essential Questions

## How do I interpret user needs and implement them into a program? How does creating “user stories” help with this?

Often users attempt to ask for what they *think* they want, but they are not usually intimately familiar with the underlying pieces of technology that they are asking in relation to. In response to this, developers and other techincal staff must learn to interpret what users are actually asking for, and determine how to take that request and implement it in a reasonable way inside the system or program they are working on. 

Computational operations at their base are actually very simple, programs generally being a larger abstraction of this idea, but functionally all take some data, transform it, and output it. Outputs can be text, or units of work performed on another data, or interaction with systems and people in the real world. Taking this idea, we can work backwards by determining what output is the user looking to receive, determining what input interaction the user can do with what they know, and then having the function or program translate input to output.

User stories help codify this into simple questions or prompts a non-technical person can answer, those generally being translated to some formulation of:

As a $user, I want to $do_something, so that I can $see_result.

As you can see, user stories map very closely to the formulation of a program, where the action a user wants to perform is the 'input', and the why of that being the output or result. The transformation of that input to desired output is generally the domain of the developer to implement how they see fit with the guidelines their oganization has for software development.


## How do I approach developing programs? What agile processes do I hope to incorporate into my future development work?

I personally, when possible, prefer to approach writing programs with a method similar to test driven development (TDD). My background in infrastructure often leads me down a similar path to designing anything, as I often know what the end result should be doing, in which case it only makes sense to *prove* that outcome with things like tests, automated policy checks, or security scans.

I often chase simplicity, and I understand that sometimes you need a big hunk of marble before you can carve it down into the perfect sculpture. In this vein, also very well aligned with TDD, I attempt to approach most of my work by making small changes, or in the case of greenfield projects making tiny prototypes to prove the concept can work before delving into the work of building a large program.

## What does it mean to be a good team member in software development?

I think the most important trait in a team member is a strangely self-evident one that many people haven't actually considered when they look at how they interact with others, that being that you understand that the point of teamwork is to do things a single person can't, and everything you're doing is really in service of that goal.

I believe looking at teamwork with this lens helps get rid of some of the ego around working in a team, and organizations should praise and incentivize this behavior when they see it.


# CS210 Project 3: Grocery Item List Discussion

## Summarize the project and what problem it was solving.
Project 3 for CS210 involved writing a program to read in data from a text file, optionally into a class using a map<> in order to store the frequency of words that appear in the file, and offer methods to print various samples and information about that data, along with functionality to store backups.

## What did you do particularly well?
I believe on this project I did a good job implementing the functionality as simply as possible. Using a map and a simple algorithm that adds the words while adjusting frequency, I was able to accomplish all of the requirements with very little code, while having code that is particularly extensible for adding more processing down the road. A map makes the most sense to store this data as it allows O(1) access for the primary functionality asked in the prompt, to search for a specific word's frequency in the data.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I think the first enhancement I would add to the existing code would be writing a small library to store most of the printing functionality in the main driver file, allowing someone to re-implement my code much easier as an ADT or library as it would not have any extraneous pieces.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I'm new to working with C++ outside of some prototypes, with most of my experience being in C, Go, and Python. C is extremely limited relative to the C++ standard library which makes a lot of functionality easier to implement than from scratch, but I found the syntax of C++ to feel a little verbose relative to languages I'm used to using. Thankfully due to the widespread adoption of C++ there are many resources available online. I found the ISO cpp standard to be helpful when trying to determine if my approach was using modern C++ features, as many of the online resources use approaches that existed in older C++ standards that have since been replaced with newer modern features. A particular example of this is the methods of using iterators for traversing maps.

## What skills from this project will be particularly transferable to other projects or course work?
I think the basic grasp of C++ will serve me a lot in other course work, especially the graphics programming class CS majors are required to take, as it has given me a solid foundation to build on, enough that I can work on small projects related to topics I'm interested in and enough information to traverse documentation without feeling lost.

## How did you make this program maintainable, readable, and adaptable?
I made this program maintainable, readable, and adaptable by keeping it simple. It is a single class that stores the grocery item list with a private map data member to store the word frequencies. I think you could have a GroceryItem class to store objects with more information or metadata later on, but it would be premature to build this functionality in from the start.
