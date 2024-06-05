hexu1985/The.Art.Of.Writing.Efficient.Programs### Ubuntu 18/20 安装qume+respberry+crossbuild

1. 安装qemu

```
$ sudo apt-get install qemu-system
```

2. 下载树梅派相关文件
    - 访问<http://downloads.raspberrypi.org/raspbian_lite/images/raspbian_lite-2019-07-12/2019-07-10-raspbian-buster-lite.zip>并下载
    - 访问<https://github.com/dhruvvyas90/qemu-rpi-kernel/blob/master/kernel-qemu-4.14.79-stretch>并下载
    - 访问<https://github.com/dhruvvyas90/qemu-rpi-kernel/blob/master/versatile-pb.dtb>并下载

3. 创建测试目录并解压复制文件

```
$ mkdir -p $HOME/raspberry
# cp files
$ unzip 2019-07-10-raspbian-buster-lite.zip
```

4. 打开终端并运行QEMU

```
$ qemu-system-arm -M versatilepb -dtb versatile-pb.dtb -cpu arm1176 -kernel kernel-qemu-4.14.79-stretch -m 256 -drive file=2019-07-10-raspbian-buster-lite.img,format=raw -append "rw console=ttyAMA0 rootfstype=ext4 root=/dev/sda2 loglevel=8" -net user,hostfwd=tcp::22023-:22,hostfwd=tcp::9090-:9090 -net nic -serial stdio
# 用户名和秘密为：pi/raspberry
# 退出grab快捷键：Ctrl+Alt+g
```

5. 打开终端并安装crossbuild

```
$ sudo apt-get install crossbuild-essential-armel
```

6. 交叉编译hello-world程序

```
$ cd hello
# 去掉交叉编译设置的注释
$ cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
$ cmake --build build
```

7. 上传文件到虚拟机
    - 在虚拟机上启动ssh server
        ```
        pi@raspberrypi:~ $ sudo systemctl start ssh
        ```
    - 在终端执行scp
        ```
        $ scp -P 22023 hello/build/hello pi@127.0.0.1:~
        ```

8. 在虚拟机上运行hello-world程序

在虚拟机的命令行执行：

```
pi@raspberrypi:~ $ ./hello
Hello, world!
```

9. gdb远程调试

    - 虚拟机上安装并运行gdbserver
        ```
        pi@raspberrypi:~ $ sudo apt-get install gdbserver
        pi@raspberrypi:~ $ gdbserver 0.0.0.0:9090 ./hello
        ```
    - 在终端执行gdb
        ```
        $ gdb-multiarch -q ./hello 
        Reading symbols from ./hello...
        (gdb) target remote 127.0.0.1:9090 
        $ continue
        ```

