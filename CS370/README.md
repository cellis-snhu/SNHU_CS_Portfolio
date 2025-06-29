# CS370: Current and Emerging Trends in Computer Science

### Briefly explain the work that you did on this project: What code were you given? What code did you create yourself?

For this project I was required to write the code for implementing a deep learning algorithm in order to create a 'pirate intelligent agent',
that traverses a game grid in order to make it from its starting point in the grid to the 'treasure' spot where it will win the game, avoiding traps along
the way. The algorithm implemented was deep Q-Learning using Keras for the neural network with an input, output, and 2 hidden layers. In addition
some code for the game structure was provided including a TreasureMaze.py and GameExperience.py which provided the board layout and some code for
performing actions in the game, along with experience replay tracking respectively. The section of code I worked on was the implementation of
the deep Q-Learning algorithm itself, in which I used an epsilon-greedy strategy to decay the algorithms exploration value over time as it learned
more of the game.

### What do computer scientists do and why does it matter?

Computer scientists are concerned with solving problems using computers, from the theoretical mathematical ideas to the concrete implementation
of those ideas as software programs, computer scientists cover a large field. Computers have likely been the single largest technology for the human
race in regards to gains in efficiency for problem solving that we have, enabling not only the creation of automatic programs that can perform tasks over and over
for us, but tying into machinery and robots, dissemination of information, and countless other fields and areas where programs are used to aid humans. Computer science matters
because the researchers in the field work on improving the theoretical and practial basis of the field in order for people to apply the science to different technologies
and advance humans in many different domains.

### How do I approach a problem as a computer scientist?

I approach problems as a computer scientist by examining the problem from it's first mathematical principles, or employing known good solutions built on those
principles where necessary. One of the major strengths of programm as a field is that code is reusable, and a simple library that does a complex task can be reused
by an unlimited number of people, meaning the gains in efficiency from it can be astronomical. Personally I look at what the problem is that I'm trying to solve, and break it down into
the simplest atomic pieces that I can in order to understand the system or process that I'm working on. Looking at this level I can then implement code to solve automating those
individual atomic tasks or tying them together by writing a program to pass data between them. In the best case the entire overall system can be automated in a way that there is
little to no manual intervention in executing it.

### What are my ethical responsibilities to the end user and the organization?

I take ethics very seriously, and working in a security related position I always aim to protect the user and their data even if it means a solution might take
longer to implement. Avoiding misuse or leaking of user data is a difficult task and the security process must be built into every level of the software
development lifecycle in order to adequately protect the user's data. In addition to securing data, not misusing a user's data is important as well, which means
also examining how that data is used from the product perspective, ensuring that we aren't writing programs that are exploiting people or using their data in some
other nefarious way that they wouldn't like. I think being open and transparent about collecting minimal user data, outlining what data is collected and what it is used for,
is paramount when it comes to being an ethical programmer and computer scientist.
