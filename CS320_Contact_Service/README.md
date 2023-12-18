# CS 320

## How can I ensure that my code, program, or software is functional and secure?

There are multiple methods for ensuring that software is both functional and secure. I think the best approach is to determine first what level of confidence you need to have in the software you're writing, and proceed to design a thorough set of testing features that can prove that the pieces you need to check all work at the given level of confidence you need.

This might be writing unit tests for simple scripts or small libraries, static analysis with open source and paid tools for programs that have specific security needs, or a full suite of checks on everything from the planning, design, code, and live operational environment for things that are critical.

## How do I interpret user needs and incorporate them into a program?

What a user requests and what they actually need are often two slightly different things. It's a balance of art and science to determine what a user is actually asking for and figuring out the best way to reproduce that in code.

I try to begin this process by looking at what the user actually wants to accomplish, determining what they are really trying to do without considering the implementation let's them freely ask for things and you can pare down the request to what is feasible at a later point if it is necessary.

## How do I approach designing software?

After determining what the user is actually looking for, like receiving a piece of data like an article or picture, collating information to make a decision for something like a vacation, determining what they want and figuring out how to present it often means you can implement the underlying functionality in a way that is opaque to the user so they don't need to worry about the complexity of what they're asking you to provide.