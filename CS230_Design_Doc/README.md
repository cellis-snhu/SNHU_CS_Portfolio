# CS 230

## Briefly summarize The Gaming Room client and their software requirements. Who was the client? What type of software did they want you to design?

The Gaming Room asked for assistance taking their existing game Draw It or Lose It, from being available only on Android to a web-based game that can be accessed from multiple platforms.

The game itself involves rendering drawings over the course of 30 seconds while teams attempt to guess what the picture is before the time expires, if the pictures hasn’t been guessed, other teams have a 15 seconds window to enter one guess of what it might be.

They presented specific requirements for the game platform and how it should operate and manage game instances, but left a lot of the implementation and platform decisions open.

## What did you do particularly well in developing this documentation##?

I believe I did a particularly good job  with attention to the small details for developing the design documentation. I have some experience in this already and was able to dig into the details of a lot of the topics needed for the design.

## What about the process of working through a design document did you find helpful when developing the code?

Specific requirements were the most helpful, like the requirements around the game instance management. These requirements being extremely specific helps reduce the cognitive load of making choices around ambiguous design requests.

## If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?

I would work on revising the domain model. When writing the original write-up of the domain model I believe the language I used was too complex and dove into too much detail that the object diagam itself actually covers, and should have spent more time describing the interactions between the objects and possible edge cases within them.

## How did you interpret the user’s needs and implement them into your software design? Why is it so important to consider the user’s needs when designing?

I try to take into consideration all of the possible dimensions the user is asking about, and try to make compromises only in the areas where they are ok with it. In this case The Gaming Room did not express a concern with a small budget, only staying within the budget, so it allowed for things like more leeway in choices in the platform.

I think another largely overlooked consideration, especially in cases like this operating as a contractor for a larger company, is looking at the long term maintainability and operational cost related to something. It doesn't make sense to pay for niche expertise for something that may be slightly better than the alternative if the alternative is widely used and easier to learn, as it is the client company that will usually end up maintaining and performing maintenance once the contract piece is finished.

## How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?

My approach was to prototype the specific initial requests to understand their functionality, mainly the initial tying together of the class objects with empty or test functions, then look at the how the interactions are described and develop the detailed pieces.

I think this approach is helpful as you work from the outside in and only have to understand a piece of the requirements at a time to do so. If you make mistakes, the prototype is simple enough to scrap and start over as well.