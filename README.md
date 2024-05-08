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
      - 计算damage，数值为进攻方atk-防御方def，防御方丢失health
        - 第一轮怪物会锁血
      - 判断是否有Character死亡
      - 交换双方，重复一次上述过程
  - winnerGetGadgets：player获得道具和金币

### button.h

- 功能：检测鼠标点击实现的一个按钮
- 成员：Todo
- 函数：Todo

### character.h

- enum char_type：枚举单位类型

#### Character

- 功能：Monster, Chest, Player的基类。
  - 不同的Character之间可以触发事件，如战斗、陷阱
  - 可以获得其它Character的物品
- 成员
  - health, attack, defense：基础属性 生命值/攻击力/防御力
  - character_type：单位类型，有PLAYER，CHEST，MONSTER
  - name：单位名称
  - coin：角色携带的金钱数
- 函数
  - modify_health(int x)：将health设为health+x，
  - modify_attack(int x)：将attack设为attack+x
  - modify_defense(int x)：将defense设为defense+x
  - modify_type(char_type t)：将character_type设为t

### chest.h

- getChest()：返回一个测试用Chest

#### Chest

- 功能：Character的子类，Player可以从中获得道具，金币等
- 成员：Todo
- 函数：

### gadget.h

- gadgetList：所有gadget的清单

  > Todo: 移到配置文件中，打开游戏读取

#### Gadget

- 功能：道具类，可以在某些场合(如战斗)中发生作用
- 成员：Todo
- 函数：Todo

### monster.h

- getMonster：返回一个用于测试的Monster

#### Monster

- 功能：Character的子类，与Player发生战斗
- 成员：Todo
- 函数：
  - getMonster：返回一个用于测试的Monster

### player.h

- 功能：Character的子类，玩家操控的单位，负责探索场景，击败怪物，发现宝箱，完成任务。
- 成员：Todo
- 函数：Todo

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
  - initSceneByNum：初始化场景，通过数组num控制每种tile的数量
    - 输入一个数组num，代表types中每个type的tile的数量
    - 保证均匀采样