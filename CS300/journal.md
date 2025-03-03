# CS 300 DSA: Analysis and Design

## What was the problem you were solving in the projects for this course?
The main problem being solved for in the projects in this course were selecting appropriate data structures
to fit a specific business use-case, and implementing those data structure(s) along with supporting code
needed to run them, ingest and process data, etc.

## How did you approach the problem? Consider why data structures are important to understand.
My approach to the problem was to consider the pros and cons of each different data structure, and compare it to
the use-case that the target users would most likely run into. For instance in the selection of a data structure
for the final project, for which a major component was providing a sorted list of all of the data, I had chosen
to use a hash table. The hash table cannot store sorted data so there is a major cost to extracting and sorting it,
however, this operation would likely only happen once or minimal times relative to the amount of times users would
need to search for a piece of data by its ID. In this case the hash table can provide O(1) lookup assuming no collisions,
while a sorted vector for instance would only provide at best the runtime of a binary search.

## How did you overcome any roadblocks you encountered while going through the activities or project?
Most of the roadblocks I encountered were small debugging issues or parts where I was unclear how to
implement something based on the instructions. I was able to resolve everything on my own or by asking the
instructor for clarifying information.

## How has your work on this project expanded your approach to designing software and developing programs?
This project has given me a greater appreciation really looking at what a user needs the software to do, and implementing
that specific functionality only in the best way possible. I always consider the use-case the user presents, but this
course specifically made me quanitfy that use-case in a way that I did not have to previously, and thinking about
what the most computationally efficient methods were for implementing the user's feature requests was a dimension
I learned can have many different pieces to interpret and is not always straightforward.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Since things like data structures are used at the most fundamental level in programming libraries, and they are expected
to produce certain performance results, I had to do a much deeper dive into how the data structure would be used in order
to write a concise and simple implementation that also met the predicted spec of how it would be used. Many of the APIs
were provided, which I later revisited in order to investigate whether I would have implemented the public API in the
same manner and how I might go about modifying it were I to write my own libraries that might be used across dozens of
pieces of software of all different types.
