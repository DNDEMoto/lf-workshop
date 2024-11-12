## ros2 foxy (for ubuntu 20.04)
## https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html

locale  # check for UTF-8

sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

locale  # verify settings


sudo apt install software-properties-common
sudo add-apt-repository universe

sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt upgrade

sudo apt install ros-foxy-ros-base python3-argcomplete

## 毎ターミナルで実行
source /opt/ros/foxy/setup.bash

# 初期化
sudo rosdep init
rosdep update

## colcon
sudo apt install python3-colcon-common-extensions
# おそらくこれも必要
python3 -m pip install --user catkin_pkg
