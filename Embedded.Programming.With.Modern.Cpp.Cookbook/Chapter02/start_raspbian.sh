qemu-system-arm -M versatilepb -dtb ${HOME}/raspberry/versatile-pb.dtb -cpu arm1176 \
    -kernel ${HOME}/raspberry/kernel-qemu-4.14.79-stretch -m 256 \
    -drive file=${HOME}/raspberry/2019-07-10-raspbian-buster-lite.img,format=raw \
    -append "rw console=ttyAMA0 rootfstype=ext4 root=/dev/sda2 loglevel=8" \
    -net user,hostfwd=tcp::22023-:22,hostfwd=tcp::9090-:9090 -net nic -serial stdio
