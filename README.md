**Make sure that you have read the copyright and license in the LICENSE.md file.**

###About:
This maths library is to provide a common set of maths classes (i.e. vectors) used for graphics which can be used for any graphics API (i.e. OpenGL or DirectX).
When I wrote this I was targeting OpenGL so the Martix class uses column-major matrices as used in the OpenGL Specification, so if your API uses row-major you may need to convert.

###Install/Setup:
As the library is a small collection of .h and .cpp files all you will need to do is include them into your project. To get the whole library to be included just do:

``` C++
#include "Maths.h" 
```

If you would rather use a part of the library you can do, for example you only want Vectors and Martix classes, you can just include the parts you would like:
``` C++ 
#include "AABB.h" // includes AABB class
#include "Mat4.h" // includes Mat4, Mat3, Vec3, Vec2 classes
```

###How to use:
Once included it's easy, for example:

``` C++
    math::Vec3 a(10.0f, 10.0f, 10.0f);
    math::Vec3 b(10.0f, 10.0f, 10.0f);
    float result = math::dot(a, b); // dot product
```

###Bugs, issues and features:
I do my best to make sure that all the code works correctly as it should.
If you find any bugs or issues with the code contact me or raise a issue, as I am busy I will do my best to get round to fixing it although I make no promises.

The same applies for suggestions, ideas or new features, I will do my best to get around to adding them (if I feel that they should be added) but again I make no promises.

For more information see the wiki
