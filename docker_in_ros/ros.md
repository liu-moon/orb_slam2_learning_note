# ROS2的Docker使用

本文件记录了如何在ubuntu系统中使用docker来运行ROS2，本教程是gui版本的，可以正常调用带gui的程序，摄像头也可以正常使用

windows版本也可以参考，但是如果涉及到图形界面的话，需要额外的配置，而且如果使用摄像头的话，需要更加复杂的配置，目前没有找到优雅的解决办法。

## Dockerfile

下面是一个简单的Dockerfile，可以用来构建一个ROS2的docker镜像，我在镜像中添加了《古月
ROS2入门21讲》的相关代码以及配置，用户通过该文件创建镜像之后，可以直接在工作目录下使用`colcon build`
进行编译，然后记得设置环境变量（`echo "source ~/dev_ws/install/setup.bash" >> ~/.bashrc`），就可以运行相关的demo了。

首先创建docker文件夹，并新建文件`Dockerfile`
，然后将下面的内容复制进去，然后在该文件夹下运行`docker build -t humble_from_file .`即可创建镜像。`humble_from_file`
是镜像的名字，可以自行修改。

```dockerfile
FROM osrf/ros:humble-desktop-full

RUN apt-get update
RUN apt-get install -y git && apt-get install -y python3-pip

# 创建工作空间
RUN mkdir -p ~/dev_ws/src && cd ~/dev_ws/src && git clone https://gitee.com/guyuehome/ros2_21_tutorials.git
# 自动安装依赖
RUN pip3 install rosdepc && rosdepc init && rosdepc update
RUN cd ~/dev_ws && rosdep install -i --from-paths src --rosdistro humble -y
# 编译工作空间
RUN apt install -y python3-colcon-ros
# source
# RUN source /opt/ros/humble/setup.bash
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
# RUN cd ~/dev_ws && colcon build
# 设置环境变量
# RUN source ~/dev_ws/install/setup.bash
# RUN echo "source ~/dev_ws/install/setup.bash" >> ~/.bashrc

RUN echo "ALL DONE!"
```

## 运行镜像

完成上面的步骤之后，就可以运行镜像了，这里我写了一个脚本`run_docker.bash`，可以直接运行，脚本内容如下：

```bash
xhost local:root

XAUTH=/tmp/.docker.xauth

docker run -it \
    --name=<yourname> \
    --env="DISPLAY=$DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --env="XAUTHORITY=$XAUTH" \
    --volume="$XAUTH:$XAUTH" \
    --net=host \
    --privileged \
    humble_from_file:latest \
    bash

echo "Done."
```

文件里面的`<yourname>`是你给容器起的名字，可以自行修改，然后运行`./run_docker.bash`
即可，如果无法运行，可以尝试`chmod +x run_docker.bash`。
