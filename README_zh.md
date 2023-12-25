# OMNeT_TSNkit

## 介绍

针对时间敏感网络（Time Sensitive Network, [TSN](https://en.wikipedia.org/wiki/Time-Sensitive_Networking)）调度与仿真问题，本项目利用[TSNkit](https://github.com/ChuanyuXue/tsnkit)生成网络调度方案，并利用NeSTiNg框架搭建仿真网络，对调度方案进行仿真与验证。[视频](https://space.bilibili.com/35942145)

本项目旨在推广TSNkit工具与OMNeT++仿真软件，帮助大家快速入门TSN，并轻松复现TSN经典论文中的算法。

> 对于TSN仿真有多种不同仿真框架，本项目仅以NeSTiNg框架进行示例
>
> TSNkit支持多种算法，包括路由与调度算法等。本项目仅选用SMT-NW（[No-wait Packet Scheduling for IEEE Time-sensitive Networks (TSN)](https://dl.acm.org/doi/10.1145/2997465.2997494)）算法进行演示

## 项目所需要环境
+ [Ubuntu 18.04](https://releases.ubuntu.com/18.04/)
+ [OMNeT++ 5.6.1](https://github.com/omnetpp/omnetpp/releases/tag/omnetpp-5.6.1)
+ [INET Framework 4.1.2](https://github.com/inet-framework/inet/releases/tag/v4.1.2)
+ [NeSTiNg](https://gitlab.com/ipvs/nesting)![Commit](https://img.shields.io/badge/commit-b7f1df09-blue)
+ [TSNkit](https://github.com/ChuanyuXue/tsnkit)![Commit](https://img.shields.io/badge/commit-1ae494b-blue)
+ 其他依赖包参考各项目Readme

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

| FlowID | Src | Dst | Size | Period | Deadline | Jitter |
|--------|-----|-----|------|--------|----------|--------|
|    x    |  x   |  x   |   x   |    x    |    x      |  x      |
|     x   |     |     |      |        |          |        |

3.  网络配置信息位于TSNkit/data/input文件夹下,其中XX_task.csv中存有流信息，XX_net.csv中有网络的拓扑信息
4.  TSNkit生成的调度信息默认位于TSNkit/src文件夹下,也就是调用tsnkit.models.smt_nw的当前目录
5.  OMNeT++仿真文件位于xxx/xxx文件夹下


## 使用方式

1. 下载安装Ubuntu 18.04，并安装OMNeT++ 5.6.1
2. cd [path to your OMNeT++]
3. git clone https://gitee.com/deepsea52418/omnet_tsnkit.git 
4. cd TSNkit
5. python setup.py install

## 使用调度算法进行求解（以 _smt_nw_ 为例）
1. 所有的求解模型都位于 TSNkit/src/tsnkit/models目录下
2. cd TSNkit/src
3. 调用smt-nw的格式为 smt_nw.py [-h] [name] task net [output] [workers]， task，net分别为对应的流信息和拓扑信息文件的路径,必须配置,  
output为TSNkit生成的调度信息存放的路径，默认为`./`,也即当前目录
4. 使用`python -m  tsnkit.models.smt_nw  task.csv  net.csv  `进行求解，，一般位于data/input下
5. 求解完成后可以在src目录下（或配置的output目录下）看到生成的GCL.csv,OFFSET.csv,ROUTE.csv等调度信息文件

## 参与贡献

欢迎通过github与我们联系 

## 感谢

1.  xxxx
2.  xxxx


