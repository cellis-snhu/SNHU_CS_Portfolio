# CS360 Event Tracking App

## Briefly summarize the requirements and goals of the app you developed. What user needs was this app designed to address?
The app being developed was chosen from 3 options, and I chose to work on an event tracking app. The app was meant to
fulfill a users scheduling needs by allowing them to create events, modify them, delete them, and present a page where
a user can view all of their upcoming events. In addition it would also notify users of events using SMS notifications. The app
needed a user login page that was tied into a database to store user credentials as well.

## What screens and features were necessary to support user needs and produce a user-centered UI for the app? How did your UI designs keep users in mind? Why were your designs successful?
I tried to keep the number of screens to a minimum, and worked with a sign-in page for the user credentials, and a 'single page app' style setup where a main page displayed
all of a users events. A separate page would pop up for creating new events or modifying existing events, all of which navigated to this page via the main events page. The UI kept the user's needs in mind by providing a single place for them to locate all of their events, without complicated menus and pages they'd have to dig through. Everything is accessed through the main page, or you are taken to a separate page that always returns you to the main page when you are done there. This design was successful as it limited the amount of pages and navigation I needed, it is also simple to teach someone to use as the navigation is circular, you can't end up at a dead-end since everything redirects back to the main page or the login if you are not logged in yet.

## How did you approach the process of coding your app? What techniques or strategies did you use? How could those techniques or strategies be applied in the future?
I used the MVC or model-view-controller design pattern to separate my views from application logic and database access code. There is a model object of an event (called Event) that has access methods to read/write from the database. By using this object to access the db, there is no db code called outside the object which means any application changes only need to reference the object layer and don't worry about the underlying database implementation, only that the object returns the data needed.

As for a strategy I worked in small chunks using version control to save changes after testing if I was satisfied it was working as intended. This was extremely useful as I could throw together a small change, but abandon it if it was the wrong approach without having to search through all of the files. It also helped as the codebase grew larger as I could see only what had changed since the last commit instead of trying to track every line I wrote for that feature, which may have included say, a single line in a database method that I might forget about later leading to dead code paths.

## How did you test to ensure your code was functional? Why is this process important, and what did it reveal?
I tested the code was functional piece by piece, acting as a user would. I wrote some methods to quickly generate events so I could test functionality like deleting many events,
adding a lot of events, modifying things, and notifications. This process is extremely important as you need to try to think of things users might do beside the normal happy path in your code, such as changing notification status, then changing the date of an event, then changing notification status back to on. While this might happen infrequently you need to make sure it behaves the way it is supposed to, not just when a user makes a new event and enables a notification at that time.

## Consider the full app design and development process from initial planning to finalization. Where did you have to innovate to overcome a challenge?
One place I found challenging to innovate was very late in development when I needed to add a field to a UI component that was an event. Since this event is displayed on the main page, and needed to be stored in the DB, it required changing code in multiple files and across multiple domains including the UI, app logic, model, and database code. Since I knew this change would be clunky to test (creating a new event, changing options, etc.), I wrote a small method that generated the test data I would need so I didn't have to keep re-doing it manually in the app, and since the testing to make sure it worked correctly took many iterations I was glad I spent the time on this beforehand.

## In what specific component of your mobile app were you particularly successful in demonstrating your knowledge, skills, and experience?
I believe I did a successful job in implementing my plan of a single-page style app, as I was ultimately able to make it work, although I had some
issues during development that required some redesign of interfaces and refactoring. I think my ability to refactor well let me make this design work,
and the result is a very simple app that has some powerful features, and is also very easily editable to add new features and functionality without reworking the 
entire UI design or adding many new pages. I had a family member test the app and they are not a technical person but they were able to quickly and easily understand the user interface because it is really just one page, and everything external to that page always brings you back to it. In addition there is not a complex menu full of settings that is confusing to work through.
