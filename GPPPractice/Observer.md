# Flyweight

See: [Observer](https://gameprogrammingpatterns.com/observer.html)

1) [Object oriented] Use the observer pattern to implement a `GameView` class that prints the map to the screen. Call a `notify` method whenever the `CurrentCoordinates` updates.
   - hint: You'll need to have game state inheret from a new class, and game view inherit from an `observer` class.
2) [Functional] Use the observer pattern by moving the `PrintMap` function to GPPPractice. Register this function in a list of `Observers` on the GameState class. Call all `observers` when the `CurrentCoordinates` updates.