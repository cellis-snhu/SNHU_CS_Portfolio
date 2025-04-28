# CS 305 
## Briefly summarize your client, Artemis Financial, and its software requirements. Who was the client? What issue did the company want you to address?
Artemis Financial is a fictitious company that acts as a financial advisor for its clients. They develop financial plans for clients all over the world. The company
wanted our company Global Rain to help them modernize their software operations and secure their application's REST API.

## What did you do well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall well-being?
I believe I was a very thorough investigator when it came to looking for vulnerabilities in the clients software. I began by employing a manual review
of each type of issue covered in the vulnerability process flow diagram, as well as using automated tools like dependency-check from OWASP to discover vulnerabilities
in dependencices. In addition I thoroughly performed manual testing after the fact to ensure there were no issue with the updates I made.

Software security adds a lot of value to a company as it let's developers feel like they are making a difference and providing a secure product for their users. In addition
it helps the business retain the trust of its users and even attract new business based on a reputation for taking security seriously, especially in the domain
of finance that a company like Artemis Financial operates in.

## Which part of the vulnerability assessment was challenging or helpful to you?
I believe the manual review process is very challenging. It takes a lot of focus and not only going through the list step by step, but considering the
interconnects between different areas as well, where something like incorrectly applying secure error handling may lead to a leak that makes your encryption vulnerable.

## How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?
Layers of security to me mean that we are applying multiple checks or defenses that overlap a specific thing (or multiple things) at different levels. This could be using
something like input sanitization applying at more than one level. We may sanitize user input at the API endpoint where a user passes the data in, but to be truly secure
we should be validating input at every step in our code including within methods on the class objects themselves, in case some input case is not handled correctly at
the API layer, it may get caught by another check at the object layer.

In the future I would start using more advanced tools like static software analysis and dynamic analysis on running programs in order to add more layers of checks beyond 
my static dependency checks and manual review that I had performed already.

## How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities?
In order to ensure changes left the code in at least the same state without making things worse, but preferably in a better state, I performed a lot of manual before/after
testing in order to ensure the behavior remained the same when I made changes, and I kept changes small in scope to ensure any bugs would be caught in that small
segment of code I was working on. In addition I ran the static checks like dependency-check after changes to ensure I was not introducing new vulnerabilities in any new
libraries that I was using.

## What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?
I think static and dynamic security software specifically is a tool that will be very helpful. Another major thing I would like to have in the future would be a comprehensive set
of unit and integration tests. While I manually checked the program behavior after each change since the programs were small, anything larger than a 'hello world' program
is hard to comprehend while changing and running tests to ensure the behavior remains the same even after fixing a security issue is invaluable.

## Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?

I think I would show future employers my manual code review, as reviewing pull requests or changes to code is a daily task for most software engineers and
security expertise is highly valuable. I think showing the depth with which I evaluated the code would be a good thing to present in addition to my actual
software engineering skill.
