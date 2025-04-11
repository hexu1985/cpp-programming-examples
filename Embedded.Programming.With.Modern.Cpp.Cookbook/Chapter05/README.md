### ubuntu上查看syslog

```bash
$ tail -f /var/log/syslog
```

### 树莓派上查看syslog

```bash
$ sudo journalctl -xe
```

### 使用gdbserver进行调试

树莓派端aarch64

```bash
$ gdbserver 0.0.0.0:9090 ./hello
```

ubuntu端x64，需要提前安装gdb-multiarch

```bash
$ sudo apt install gdb-multiarch
```

ubuntu端x64，运行gdb-multiarch

```bash
$ gdb-multiarch ./hello
$ (gdb) target remote X.X.X.X:9090
$ continue
```

