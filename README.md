# 3DOF Stewart Platform 
 A stewart platform moving in 3 axes was designed and coded.Stewart Platform are parallel manipulators created for movement and positioning. The platform includes 6 adjustable legs to provide movement and control of the plates between the 2 plates. The main purpose of the platform is to create a test environment for specific purposes.
These purposes are:
1.Flight simulations
2.Animatronik
3.Crane technology
4.Underwater research
5.Earthquake simulations
6.Robotic etc.

![image](https://user-images.githubusercontent.com/66810191/170566531-6cf9c466-d72b-48c8-8d9f-929fe52a0162.png)

It first appeared in 1949 as a parallel mechanism produced by V. Eric Gough to test different loads. Then in 1965 D. Stewart started using a variant of the hexapod for flight simulators. And under the name of the Gough-Stewart platform, it began to be called the Stewart platform. This platform was developed over time by Klaus Cappel, H. McCallion etc. It has survived to the present day by trying to be developed and improved by many engineers.

![image](https://user-images.githubusercontent.com/66810191/170566605-4447188a-4844-4cb6-b166-51a75327fe82.png)

## Kinematics of the Stewart Platform
The Stewart platform is connected to 2 parts. These parts are base and platform parts. These parts are connected to each other by 6 calculated legs. With this setup, the platform can move in 3 translational and rotational dimensions. 
The base piece is considered as the x y z orthogonal axes and reference work.
The platform has its own x', y', z' orthogonal axes.
The origin of the coordinates of the platform is defined by 3 translational movements, 1 time with respect to each axis of the base.
The 3 angular displacements define the direction with respect to the base platform. A number of Euler angles are used in the following order:
1. Rotate angle ψ around the z-axis.
2. Rotate the angle θ around the y-axis.
3. Rotate the angle φ around the x-axis.

![image](https://user-images.githubusercontent.com/66810191/170566726-efe7919c-3f49-4f4b-a191-bf95a074fff0.png)

P = i’x’ + j’y’ + k’z’ = ix + jy + kz
x = OA – BC = x’cos ψ – y’sin ψ 
y = AB + PC = x’sin ψ + y’cos ψ
z = z’

### The full rotation matrix of the platform relative to the base:
![image](https://user-images.githubusercontent.com/66810191/170566882-5a39b6c2-62e3-4a66-b0dd-612048d01f7c.png)

# Latest version of the platform : 

![image](https://user-images.githubusercontent.com/66810191/170566992-c665df26-7007-42f3-a0ce-fc319bc9459d.png)


																																																	

																																																	

