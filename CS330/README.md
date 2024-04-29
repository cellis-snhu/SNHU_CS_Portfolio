# CS330

## How do I approach designing software?
My approach to designing software is to write simple software that accomplishes the task, and only engineer more complexity when it is explicitly called for and nececssary. This hopefully means my code is easier to read and avoids premature optimization.

### What new design skills has your work on the project helped you to craft?
An important new design skill I picked up working on this project was definitely organization of a large project. There is a lot of base code provided in this project, and I was also required to write a larger amount of code than a normal class as this was essentially a single project that spanned the entire length of the course.

Using the base code as an example for how to structure my work along with reading some other projects in C++ and looking at OpenGL function signatures helped me decide how to layout my code.

### What design process did you follow for your project work?
I began with prototyping any new code and keeping it as small as possible until I had a working example of what I needed to do that week for the project milestone. I then expanded my code into the proper functions and added new functions where needed. After that I cleaned up my comments so I understood what I had done. Using git for this was indispensible as being able to view the diff of a large file helps me see only the changes I made and I could layer my change commits in ways that were easy to revert if needed.

### How could tactics from your design approach be applied in future work?
I think the prototyping-interation process is very applicable to almost all types of software except the few specific cases that truly rely on a specific upfront design where all the constraints are known beforehand.

## How do I approach developing programs?
I approach programs by starting out with the bare minimum working functionality I can come up with, generally the core feature I'm looking to build, and work outwards implementing things like better error handling, adding convenience functions, and trying to make the code more useful while keeping it as simple as possible.

### What new development strategies did you use while working on your 3D scene?
A new development strategy I tried but ultimately did not use much due to knowledge constraints was stubbing out functions I thought I would need. I think this strategy can work when you are much more familiar with what you're working on, but as this was my first graphics class I was simultaneously learning how the code works along with the mathematical concepts and stubbing out what I thought would work seemed to be more overhead than needed versus doing extremely minimal prototype functions one at a time.

### How did iteration factor into your development?
As mentioned previously, I followed a pattern of minimal prototype to start, and then iterated by adding one 'feature' or new functionality at a time. This was crucial to do in this project as it is very easy to misconfigured any single object or shader and break compilation without an easy way to revert large changes across the whole project. Iteration helps keep changes small and limits them to a few steps that can be worked backwards or tracked with git.

### How has your approach to developing code evolved throughout the milestones, which led you to the project’s completion?
As I got more comfortable with the base graphics code and understanding how openGL functions were wrapped, I was able to more easily understand the new pieces of code each weel. Towards the end of the project I found it easy to read a functions name and understand likely what it was doing, and was able to write my own work without reading the entire underlying functions I was calling, but using the built-in intellisense tools in Visual Studio to figure out parameters and return values.

## How can computer science help me in reaching my goals?
Computer Science is very instrumental to my goals, which are now to advance my career as an SRE into a more development focused role like platform engineering, with the goal to be to attend grad school and eventually specialize in something security related like cryptography, or possibly a more mathematics based programming field like graphics work.

### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future educational pathway?
I think graphics was one of the more unique applications of code I worked on, where the resulting artifacts feel a bit less academically contrived and more like something that I would create in the real world.

### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future professional pathway?
The heavy math overlap with graphics programming, in my opinion, is a huge boost to my skills as many of the most sought after programming jobs are mostly implementing math and algorithms in low level code.