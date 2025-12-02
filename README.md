------------------My report - Isaac Coddington--------------------

Me and my wife had a baby halfway through the semester project, so I couldn’t help much during the planning and set up process. During the week of Thanksgiving while we had family here to help, I was able to sit down and create the project.

I started by creating the GUI window and all the UI elements in QT Widgets. After that I started the process of creating all the slots then connecting all the UI signals to those slots. Once I had all Ui elements connected to the desired slots I started working on the code within the slot function. 

The first one I worked on was the raceSelect() as I wanted to figure out how to display pictures in the graphics view. After reading the documentation and some stack overflow discussion I found out about the resources folder to put my pictures. This allows you to not have to worry about file paths when loading pictures into your program, otherwise it was easy to display a picture. 
The biggest hurdle the first day was tying all the race buttons to a single function I found the connect() function in the documentation but had to look through several online discussions to see the actually working syntax.

The second day most of it was spend working on the stat sliders. I initially used the scroll bars and spent a few hours trying to work out how to increment them by 1, after getting frustrated. I looked through the other widgets and decided to use the spinbox which was a lot easier. 

My second big issue, and my biggest hurdle overall was keeping the user from going past the 15 points allowed to distribute between the stats. To keep this short in summary, my function was doing recursive calls which was causing bad behavior. More info is above the sliderChanged() function in the program. The rest of the day was spent finishing the rest of the functions for the slots and creating the second window, I kept the rest of the functions simple.

The character stat screen window also gave me some trouble. I was trying to display the picture the same way the main window did when you selected the race. I was running into a bug that the picture was really tiny within the graphics view. I found my answer on stack overflow, I was calling the function within the constructor, so the window size wasn’t set or drawn yet so it was messing with the size of the picture. The answer is built into QT, there is a showEvent() function you can override and this is the function QT automatically calls after the window is initialized, size is set and drawn on screen.

I did a little work on the third day, which was more manual testing to try to catch any small bugs I might have missed on the first two days. Most of my testing was during the first two days as I built things. I also went through and cleaned up my code and comments, then finally I created this report of my work.

----------------Running the program----------------------

* Using the program is pretty easy just run the program and a window will pop up
  
* You can enter your name in the text box below the name label

* You select which race you want to play and it will display a picture as well as give you 10 free stat points in certain stats depending on which class you select

* You select which class you want and it will display the class trait for that class below the buttons

* You can use the arrow or type in the box to distribute your 15 stat points in whatever stat combo you want. You can't go over 15 and it will update to show how many points you have left.

* Once you are done you can click create and it will display an second screen with all your selections as a character stat sheet.
