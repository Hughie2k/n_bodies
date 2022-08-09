# **What is this?**
This is a 2d simulation of the [n-body problem](https://en.wikipedia.org/wiki/N-body_problem). The camera can be moved with the arrow keys and zoomed in and out with '=' and '-' respectively. Planets can be selected by clicking on them, which will give them a green outline and have the camera track them. Planets can be deselected by selecting a different planet, by clicking on the same planet again, or by deleting them, with the delete key. Planets can be created by holding right-click, and given an initial velocity by moving the mouse from the original position where right-click was first pressed. Pressing 'n' selects the next planet. *Please* feel free to suggest improvements to the code or interesting features by emailing me (<hughodonnell13@gmail.com>). I am pretty new to programming, and I am all too aware that I am likely to be doing many things in a sub-optimal fashion.

# **Dependencies:**
This project depends on [SFML-2.5.1](https://www.sfml-dev.org/download/sfml/2.5.1/), which I used to render the planets as circles in a window, and to get user input. Here is the SFML [source code](https://github.com/SFML/SFML).