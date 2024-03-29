# D3D9-hook-3D
 A proof of concept made for drawing 3d shapes in a d3d9 hook
 
 
 
## What is this?

Imagine you are playing the game Garry's Mod, for example. What if you wanted to edit pixels being draw at the screen, geometry models, shaders, preferences of the renderer? This has many and many uses, you could edit the games shaders to make super realistic graphics, create GUIs (Graphical User Interface), run another game inside, change how the game appears to the local user and even use it for less honorable reasons such as creating a game cheat and implement a ESP (Extra Sensory Perception).
For all that, you would need to edit change the D3D9 hook that runs commands for the application, and that is indeed, **not a easy task.**


## What is D3D9 (Direct3D 9)?

Many graphics softwares make use of Microsoft's graphics API Direct3D 9, specially games for computers. There is big list of famous games that use that, such as Half Life 2, Garry's Mod, Grand Theft Auto San Andreas, Call of Duty, Call of Duty 2, Swat 4, World of Warcraft, and much more. This API can render 2D and also 3d models, using advanced different options. Also, it introduced the concept of geometry instancing, which means using multiple copies of the same geometry, improving the runtime performance.


## How its done?

To inject code or modify the D3D9 hook, you would need to find the desired software task window, create a valid code for Direct3D, get the desired hook, compile all to a DLL, inject the DLL in the game. To be compatible with uses that need **to be more undetectable, I wrote this code so as it uses the EndScene Hook**, that means that its very likely that it will get some problems because it is configured to support GUI objects, as its a common use in that hook. But this also means that if someone took a print of your game using lua commands in that game, it would not get your DLL inserted modifications, because it does not catch the EndScene hook. Finally, there are preferences set at the beggining of the modified hook call so we can finally **draw working 3D geometry shapes and not only 2D GUI stuff**.


![qo8TiOflEe](https://user-images.githubusercontent.com/38440423/168485960-893f513f-7c20-42d0-9ddd-179487d42cae.png)
