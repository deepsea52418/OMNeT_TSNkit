# OMNeT_TSNkit

## 介绍

针对时间敏感网络（Time Sensitive Network, [TSN](https://en.wikipedia.org/wiki/Time-Sensitive_Networking)）调度与仿真问题，本项目利用[TSNkit](https://github.com/ChuanyuXue/tsnkit)生成网络调度方案，并利用NeSTiNg框架搭建仿真网络，对调度方案进行仿真与验证。项目[视频链接](https://space.bilibili.com/35942145)。

本项目旨在推广TSNkit工具与OMNeT++仿真软件，帮助大家快速入门TSN，并轻松复现TSN经典论文中的算法。

> OMNeT++支持多种不同仿真框架，建议根据仿真目标不同选择合适的仿真框架，本项目以NeSTiNg框架进行示例
> 
> TSNkit支持多种算法，本项目仅选用SMT-NW（[No-wait Packet Scheduling for IEEE Time-sensitive Networks (TSN)](https://dl.acm.org/doi/10.1145/2997465.2997494)）算法进行演示。更多算法，请参照[此链接](https://tsnkit.readthedocs.io/en/latest/schedule.html)

## 项目所需要环境
+ [Ubuntu 18.04](https://releases.ubuntu.com/18.04/)
+ [OMNeT++ 5.6.1](https://github.com/omnetpp/omnetpp/releases/tag/omnetpp-5.6.1)
+ [INET Framework 4.1.2](https://github.com/inet-framework/inet/releases/tag/v4.1.2)
+ [NeSTiNg](https://gitlab.com/ipvs/nesting)&nbsp;&nbsp;&nbsp;&nbsp;![Commit](https://img.shields.io/badge/commit-b7f1df09-blue)
+ [TSNkit](https://github.com/ChuanyuXue/tsnkit)&nbsp;&nbsp;&nbsp;&nbsp;![Commit](https://img.shields.io/badge/commit-1ae494b-blue)
+ 其他依赖环境参考各项目Readme

## 代码说明

1.  网络拓扑：
``` mermaid
graph LR
    Client1[Client1]
    Client2[Client2]
    Client3[Client3]
    TSNSwitch1[TSNSwitch1]
    TSNSwitch2[TSNSwitch2]
    Server1[Server1]
    Server2[Server2]
    Server3[Server3]
    Client1 --- TSNSwitch1
    Client2 --- TSNSwitch1
    Client3 --- TSNSwitch1
    TSNSwitch1 --- TSNSwitch2
    TSNSwitch2 --- Server1
    TSNSwitch2 --- Server2
    TSNSwitch2 --- Server3
```
2.  流信息

| FlowID | Src | Dst | Size | Period    | Deadline | Jitter   |
|--------|-----|-----|------|-----------|----------|----------|
| 0      | 1   | 5   | 500B | 500000ns  | 408400ns | 408400ns |
| 1      | 2   | 6   | 1200B| 1000000ns | 408400ns | 408400ns |
| 2      | 3   | 7   | 200B | 200000ns  | 408400ns | 408400ns |

3.  文件目录
```
.
├── omnet
│   └── workspace
│       └── nesting
│           └── teach
│               ├── xml
│               │   ├── teach_gcl.xml (Simulated GCL Information)
│               │   └── teach_Routing.xml (Simulated Routing Information)
│               ├── _example_teach.ini (Simulated Network Configuration)
│               └── teach.ned (Simulated Network Topology)
└── TSNkit
    ├── data
        │  
        ├── input
        │    ├─example
        │       ├─ example_net.csv  (Network Topology)
        │       ├─ example_task.csv (FLOW Information)
        │        
        │          
        └─ output
            ├─example
                 ├─ example-DELAY.csv     (Flow Delay Information)
                 ├─ example-GCL.csv       (GCL Information)
                 ├─ example-OFFSET.csv    (Flow Send Offset)
                 ├─ example-QUEUE.csv     (Flow Priority Information)
                 ├─ example-ROUTE.csv     (Flow Priority Information)

```


## 使用方式

#### 安装
1. 下载安装Ubuntu 18.04，并安装OMNeT++ 5.6.1
2. cd [path to your OMNeT++]
3. `git clone https://gitee.com/deepsea52418/omnet_tsnkit.git`
4. `cd OMNET_TSNKIT`
5. 安装编译INET Framework，具体参考[此链接](https://github.com/inet-framework/inet/blob/master/INSTALL.md)
6. 安装编译NeSTiNg，具体参考[此链接](https://gitlab.com/ipvs/nesting/-/blob/master/README.md)
7. 安装TSNkit,具体参考[此链接](https://github.com/ChuanyuXue/tsnkit/blob/main/README.md)
#### 使用调度算法进行求解
1. `cd TSNkit/src`
2. 使用`python -m  tsnkit.models.smt_nw  ../data/input/example/example_task.csv  ../data/input/example/example_net.csv  ../data/output/example`进行求解，该命令加载input/example中的
3. 求解完成后，可以在当前目录下看到生成的调度结果文件（GCL.csv，OFFSET.csv等）
#### 运行仿真
1. 打开OMNeT++
2. 选择OMNET_TSNKIT\omnet\workspace作为OMNeT++ 的workspace
3. 选择nesting\teach\\_example_teach.ini，右键选择`Run As`运行


## Tips
>
>SMT-NW算法通过指定流发送的偏移时间，实现流的无等待传输。在此过程中，并未涉及到流优先级相关问题，因此将所有流优先级置为0；
>
>根据`nesting\src\nesting\ieee8021q\queue\QueuingFrames.h`代码中的定义，在8个可用队列情况下，优先级为0的流映射至`Queueing`模块的1号队列进行传输;
>
>在NeSTiNg仿真框架中，默认情况下，仿真节点模块所采用的oscillator子模块频率为1Mhz，仿真时间精度为1μs。为了提高仿真精度，在本项目中，将oscillator模块频率指定为1Ghz，即仿真时间精度为1ns；
>
>在NeSTiNg仿真框架中，默认采用802.3协议指定的数据帧格式，即完整数据帧大小 = 应用层数据 + 前导码(8B) + 目的地址(6B) + 源地址(6B) + vlanTag(4B) + 长度(2B) + CRC(4B)
>
>目前在TSNkit中未考虑帧间间隔问题，需要将`\inet\src\inet\linklayer\ethernet\Ethernet.h`文件中的`INTERFRAME_GAP_BITS`参数由96修改至0
>
>TSNKit中对于时延的计算减去了源端的发送时延,并且没有减去offset,而omnet中时延的计算是从源端设备开始发送第一个bit开始的，也就是说tsnkit中时延的输出减去offset，再加上源端的传输时延才是omnet中应该出现的时延；
## 参与贡献

如果您对该项目有任何意见或建议，欢迎在项目页面提交Issue。感谢您的参与与反馈！

## 感谢

+  [Chuang Li](https://github.com/chaungLi)
+  [Callin](https://github.com/lxacc)
+  OMNeT++ , INET Framework , NeSTiNg , TSNkit项目贡献者