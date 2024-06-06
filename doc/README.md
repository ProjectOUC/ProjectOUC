<center>
    <font size=6>
        游戏设计与开发 项目文档
    </font>
</center>

[toc]

## 一、开发环境

- IDE：Visual Studio 2022
- 语言：C++
- 其它：EasyX图形库

## 二、功能描述

​		一个游戏，流程图如下 [图片]（没有图片）

## 三、代码规范

- 尽量保证单个文件内代码风格一致

- 在每个文件开头加上以下语句，保证中文输出正常

  ```c++
  #pragma execution_character_set("utf-8")
  ```


## 四、类和文件说明

该条目格式如下：

```
### <文件名>
- <全局变量，函数等>: <对应含义>
#### <类名>
// 可以简写较为简单的函数
- 功能: <具体功能>
- 变量
	- <成员n>: <成员n含义>
- 函数(可不包括常函数)
	- <函数n>: <函数n含义>
		-(可选) <输入含义>
		-(可选) <返回值含义>
		-(可选) <详细过程解释>
```

### attribute.h

#### Attr

- 功能：所有基础属性，包括生命、攻击、防御、闪避、暴击率等。重载了+、-、*运算符。
- 变量
  - attackFirstLevel：先攻值，确定双方攻击顺序
  - strength：力量值，暂时没用
  - agility：敏捷值，暂时没用
  - wisdom：智力值，暂时没用
  - criticalAttackRate：暴击概率，最高100
  - missRate：被闪避概率，最高100

### battle.h

#### Battle

- 功能：由两个Character触发。双方health逐渐降低，health归零一方失败，胜利者可获得其携带的物品、金币等
- 变量
  - attacker：主动发起攻击的Character，通常优先攻击。(有些道具可以改变攻击顺序)
  - defenser：受到攻击的Character，通常晚于attacker攻击。
  - turn：战斗轮数
- 函数
  - battle：attacker和defenser轮流攻击，直至一方生命归零
    - 返回值：
      - True：战斗结束，且player存活
      - False：战斗结束且player死亡，或战斗无法结束
  - battleStep：一轮攻击
    - 返回值：
      - True：有Character死亡
      - False：回合结束，无Character死亡
    - 详细过程：
      - 计算damage
      - 判断是否有Character死亡
      - 交换双方，重复一次上述过程
  - attack：攻击，计算过程见代码
    - 返回值：
      - True：有一方死亡
      - False：双方存活
  - winnerGetGadgets：player获得道具和金币

### character.h

- enum char_type：枚举单位类型

#### Character

- 功能：Monster, Chest, Player的基类。
  - 不同的Character之间可以触发事件，如战斗、陷阱
  - 可以获得其它Character的物品
- 成员
  - attr：属性值
  - character_type：单位类型，有PLAYER，CHEST，MONSTER
  - name：单位名称
  - coin：角色携带的金钱数
  - gadgets：角色携带的每种道具的数量
- 函数
  - take_gadget：获取一定数量的道具，并获得属性
  - lose_gadget：丢失一定数量的道具，并失去属性
  - use_gadget：使用当前手持的道具，并改变属性

### chest.h

- getChest()：返回一个测试用Chest

#### Chest

- 功能：Character的子类，Player可以从中获得道具，金币等

### gadget.h

- max_gadget_index：道具总种类数
- gadgetList：所有gadget的清单
- usefulGadgetSet：所有可使用的道具的集合
- gadgetVisited：记录某道具是否曾获得

#### Gadget

- 功能：道具类，可以在某些场合(如战斗)中发生作用
- 成员：
  - gadgetIndex：唯一标识Gadget的数字。
  - name
- 函数：
  - get_gadget()：获得gadget时触发效果
    - 返回值：Attr类型，代表获得道具时提升的属性。
  - lose_gadget()：丢弃gadget时触发的效果
  - initGadgetList：初始化上述全局变量，并将Gadget的每个子类创建一个对象，放入gadgetList中
  - destroyGadgetList：释放内存

#### 其余子类

- 功能：Gadget的子类，具体的一种道具

### monster.h

- getMonster：返回一个用于测试的Monster

#### Monster

- 功能：Character的子类，与Player发生战斗
- 成员：Todo
- 函数：
  - getMonster：返回一个用于测试的Monster

### PCG.h

### Room

- 功能：用于生成迷宫地形的房间，以及在洞穴地形中生成一些事件。
- 成员：左下和右上的坐标；重载了赋值运算符
- 函数：
  - intersect(const Room& other)：判断两个Room是否相交
  - include(const Room& other)：判断两个Room是否存在包含关系

- 提供了两个算法，分别用于生成迷宫地形和洞穴地形

- 洞穴地形生成接口如下，具体过程见代码注释

  - ```c++
    std::vector<std::vector<int>> caveGenerate(
    	int height, 
    	int width,
    	int maxIter, //细胞自动机迭代轮数，通常不超过10，建议为5
    	int wallWeight, //初始化时，wall在地图中的占比，通常为45%-50%，建议为45%
    	float fillIter); //用于控制细胞自动机迭代过程中，填充大片空地的轮数，建议为0.5以上
    ```

- 迷宫地形生成接口如下，具体过程见代码注释

  - 



### player.h

- 功能：Character的子类，玩家操控的单位，负责探索场景，击败怪物，发现宝箱，完成任务。
- 成员：Todo
- 函数：Todo

### random.h

- 提供了一些生成随机数的函数

### scene.h

- SwitchToWindow：切换窗口，可视化界面使用

  > 未完成

#### Scene

- 功能：游戏的场景，包含每个格子中的信息
- 成员：Todo
- 函数：
  - checkTile：检测当前tile是否存在Monster/Event/Chest等，并触发
  - move：向一个方向移动，并checkTile
  - initScene：初始化场景，包括确定场景大小，分配每个tile的类型，确定起点和终点等。
  - initSceneByNum：通过一个num向量初始化场景，num向量用于控制每种格子的个数。

## 五、参考文献

### 地图生成 

1. [房间和迷宫：一个地牢生成算法 | indienova 独立游戏](https://indienova.com/indie-game-development/rooms-and-mazes-a-procedural-dungeon-generator/)

### 图形库

