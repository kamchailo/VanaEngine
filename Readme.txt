Setup :
- Sometimes the solution can not find proper Startup project.
    - Setup VanaApp project as Startup Project.

Control :
- Arrow-keys for direction
- Spacebar for rotate clockwise

// 12 nov 22
Serializer :
- VanaApp now create scene from JSON file

// 11 nov 22
Physics Body :
- Add Physics Body which support SetVelocity() SetAcceleration() AddForce()
Event System :
- CollisionManager can now boardcast collision event 
- Each components in the root can response to message in HandleEvent(Event*)

// 3 nov 22
GameObject

- Moved Transform, Render and Collision Update from Node to components
and make class Node support Components.

// 23 oct 22
Collision Design :
- User use CollisionManager to spawnCollider and return an address to a new collider
and the manager also keep as a list (std::vector). 
- CollisionManager will have their own update (not sync with gameplay update).
- By design, I intend for user to atttach AABB to any object as a board collision phrase 
which also contain OOBB as narrow phrase collider.
- Every frame, CollisionManager will check every board phrase collider together.
    - If the there any collider hit each other in board phrase, both of them will be added to std::vector<NarrowMessage> narrowColliders
        - If each pair of narrowColliders with their narrow colliders (OOBB by design)
            - Add each collided collider to their personal list of collideds.

    
