

https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html

ビルド済みのはず。
ROSのパス通し、ターミナル毎に必用
`source /opt/ros/foxy/setup.bash`

環境変数のセットアップ

`source install/setup.bash`

Now run the talker node:

`ros2 run py_pubsub talker`

Open another terminal, source the setup files, and then start the listener node:

`source install/setup.bash`
`ros2 run py_pubsub listener`