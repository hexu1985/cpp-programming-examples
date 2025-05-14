### Ubuntu24.04 上 apt install Google Performance Tools

```
# 更新软件包列表
sudo apt update

# 安装 gperftools 和 pprof 工具
sudo apt install -y google-perftools libgoogle-perftools-dev

# 检查关键文件
ls /usr/lib/x86_64-linux-gnu/libprofiler.so  # 动态库路径

pprof --version                             # 检查 pprof 工具
# pprof-symbolize
```


---

### **gperftools (Google Performance Tools)** 在 Linux 系统上从源码编译安装的详细步骤：

---

### **1. 安装依赖项**
确保系统已安装必要的编译工具和库：
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install -y autoconf automake libtool g++ make git curl

# CentOS/RHEL
sudo yum install -y autoconf automake libtool gcc-c++ make git curl
```

---

### **2. 下载源码**
从官方仓库克隆最新代码：
```bash
git clone https://github.com/gperftools/gperftools.git
cd gperftools
```

（或下载稳定版压缩包：`curl -OL https://github.com/gperftools/gperftools/releases/download/gperftools-<version>/gperftools-<version>.tar.gz`）

---

### **3. 生成配置脚本**
运行自动生成配置脚本：
```bash
./autogen.sh
```

> 如果 `autogen.sh` 报错，可能是缺少依赖（如 `libunwind`），需先安装：  
> ```bash
> sudo apt install libunwind-dev  # Ubuntu
> sudo yum install libunwind-devel  # CentOS
> ```

---

### **4. 配置编译选项**
```bash
./configure --prefix=/usr/local  # 默认安装到 /usr/local
```
常用选项：
- `--enable-frame-pointers`：优化栈追踪（建议开启）。
- `--disable-heap-checker`：禁用堆检查器（按需选择）。

---

### **5. 编译和安装**
```bash
make -j$(nproc)       # 并行编译，加快速度
sudo make install     # 安装到系统
```

---

### **6. 更新动态库缓存**
确保系统能找到新安装的库：
```bash
sudo ldconfig
```

---

### **7. 验证安装**
检查是否安装成功：
```bash
# 查看 pprof 工具
pprof --version

# 验证 libprofiler.so
ls /usr/local/lib/libprofiler.so
```

---

### **8. 使用示例**
#### **CPU 性能分析**
```bash
# 运行程序并生成 profile 文件
LD_PRELOAD=/usr/local/lib/libprofiler.so CPUPROFILE=output.prof ./your_program

# 生成火焰图
pprof --web output.prof  # 交互式查看
pprof --flame output.prof > flame.svg  # 导出 SVG
```

#### **内存分析**
```bash
HEAPPROFILE=output_heap ./your_program  # 生成堆分析文件
pprof --web output_heap.0001.heap      # 查看内存分配
```

---

### **常见问题解决**
1. **`libunwind` 报错**：  
   - 安装开发版 `libunwind`（见步骤1）。  
   - 若仍失败，配置时添加 `--disable-libunwind`（不推荐，可能影响栈追踪）。

2. **权限问题**：  
   - 如果无法写入 `/usr/local`，改用 `--prefix=$HOME/.local` 并配置 `LD_LIBRARY_PATH`：
     ```bash
     export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH
     ```

3. **旧版本冲突**：  
   - 卸载系统自带版本（如 `apt remove google-perftools`）。

---

### **卸载方法**
```bash
sudo make uninstall  # 在源码目录执行
sudo rm -rf /usr/local/lib/libprofiler* /usr/local/bin/pprof
```

