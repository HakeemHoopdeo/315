# Comp315-Project
Upload all relevant documents (Abstracts, Proposals, Code, etc.)
Changes to original idea:

- Generating a finite number of mines with random numbers on all but 1 mine which is the correct answer
- Shoot the mine that is the correct answer to open the portal (a cool swirling animation will happen once it's open)
- Think of the mine as a key to the portal door in a sense
- There will be only 1 portal but it'll look like a majestic portal scaled appropriately at the back of each room
- We'll work on two main rooms to loop through just to get a feel of movement and resetting the room
- Once the heavy lifting is done we will have to focus on the aesthetic a bit more in terms of having different themes
- E.g. of different kinds of themes we can choose from: light, dark, forest, dirty swamp, relaxing lakeside, beach, 
  lava volcano, ashen land (like Dragonborn DLC: Skyrim), snow area, sky temple, etc
- When we get there we should see if we can choose a minimum of 5 themes after every 10 levels
- In terms of difficulty, i don't think we should have the difficulty increase as we play but rather have it increase
  based on the choice: Easy, medium and hard. 
- Easy will be just one and at most 2 operators (we need to see the ratio of how we wanna generate operators) 
- What i mean is we can decide on a system that we think will be complex for example, in Easy mode if we generate 2 operators
  and both happen to be division then it's more like medium if you think about it.
- So maybe division must appear only once in easy mode, like we should have restrictions on how many times an operator is allowed 
  to appear in each mode maybe by using a parallel array to say for example, OpAppearance = [2, 2, 1, 1] where 2 and 2 is for 
  + and - and 1 and 1 is for the * and /. And each time one is generated then it must be decremented.
- Say we generate / once then the remaining number of / for easy mode is now 0, and say if we generate a / again then it must be 
  regenderated. So like while not something, generateOp()
- So for easy mode i think we can keep it to 1 operand to make life easy, medium can have 3 and hard can have 5. 
- So each mode will have like 10 levels for example (probably 20) but all of it will be strictly easy, medium or hard cause 
  then if it's progressive then it becomes boring to play if you know how to do the easy and medium 
- If we have the free time to account for variables then we can just add it as a MasterMode difficulty.
- I was thinking of a name like MasterMath or MathMaster or MonsterMath but like if we go that route than the difficulty
  involving variables and stuff can be called the nameOfTheGame difficulty eg MasterMath Mode instead of MasterMode
- If we have difficulty increase as we play then we can probably use a switch case statement and be like Obj.getLevelNo() and
  work with that in ranges so if the level number is in one range then call generateEasy() or something to that effect
- Back to the health system, Nikiel and i were thinking in terms of having 3 hearts and if you get it wrong then the place blows 
  up and you lose a heart which results in you having to answer the same question or a new one 
- Nikiel suggested if you get it wrong you just lose a heart and the room blows up only when you lose all hearts.
- But i think it works better that you lose a heart with the room blowing up cause for example, if you run out of time the the room
  must blow up as well. You can get less time for the higher difficulty levels if need be but we'll work on that
- We can use a system of badges or trophees (idfk how to spell this) or something for the milestone if we get there which we should       based on the time like small milestones will be with badges and big ones will be with trophies
- For generating math equations, we have to use the answer for one and the others can be randomized within a range of the answer
- Remember how we have chewable looking mentos mines? Maybe the red mines can be an indicator of positive numbers and blue chewable
  looking mentos mines can indicate negative numbers so it'd look cooler but we'll see about that one as well
- Half of these are still WIP

