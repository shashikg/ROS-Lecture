# Add dependencies in package.xml
Almost all dependecies automatically gets added when you create your package with specifying it's dependencies. Well let's understand it for the example codes.
```xml
<buildtool_depend>catkin</buildtool_depend><!--This one is added to tell about the build tool in our case it is catkin-->
<!--other dependencies which we added during creating the package-->
<build_depend>roscpp</build_depend>
<build_depend>rospy</build_depend>
<build_depend>std_msgs</build_depend>
<run_depend>roscpp</run_depend>
<run_depend>rospy</run_depend>
<run_depend>std_msgs</run_depend>
```
** Two important lines to be added when you use custom message and srv **
```xml
<build_depend>message_generation</build_depend>
<run_depend>message_runtime</run_depend>
```
