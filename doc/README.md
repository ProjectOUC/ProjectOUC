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

### button.h

#### Button

- 功能：按钮，点击后触发事件

- 成员：

  ```C++
  
  Button(); //默认构造函数
  
  static void quitButton(); //退出按钮，将Button::isShown置为0
  
  void tradeButton(Character** player); //交易按钮，可以触发绑定交易事件
  
  static void foodButton(Character** player); //购买食物按钮
  
  void battleButton(Character** player); //战斗按钮，触发战斗
  
  //以下用于判断按钮类型
  bool isQuit() const;
  bool isTrade() const;
  bool isFood() const;
  bool isBattle() const;
  
  buttonType getType() const;
  
  //按钮文字说明
  std::string getDescription() const;
  
  //触发按钮
  void onClick(ExMessage& msg, Character** player);
  //判断玩家是否有条件点击该按钮
  bool checkCondition(Character* player);
  //为1时，绘制按钮，否则不绘制
  static int isShown;
  
  ~Button();
  ```

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

### event.h

#### Event

- 功能：触发事件，包括随机事件(Trap)和固定事件(NPC)

- 成员：

  ```c++
  public:
  	Event();
  /*
  *根据path生成一个event。
  *所有event都在event文件夹中，格式见其中的template文件
  */
  	Event(std::string path);
  
  /*
  判断Event类型
  */
  	bool isNPC() const;
  	bool isTrap() const;
  
  	eventType getType() const;
  	
  /*
  *获取event中button的数量
  *要用来判断buttons的layout
  */
  	int getButtonCount() const;
  
  	std::string getEventName() const;
  	std::string getEventDescription() const;
  	std::string getEventPath() const;
  	std::string getImgPath() const;
  
  	void setType(const eventType& _type);
  	void setButtonCount(const int& _buttonCount);
  
  /*
  *触发事件
  *其中包括Event loop
  *绘制代码写在这个函数中
  */
  	void occurEvent(Character** player);
  
  /*
  *Trap不用考虑img，但配置文件还是要随便加一行。NPC的img在配置文件中
  */
  	IMAGE img;
  
  	~Event();
  private:
  	eventType type;
  	int buttonCount;
  	std::vector<Button*> buttons;
  	std::string eventName;
  	std::string eventDescription;
  	std::string eventPath;
  	std::string imgPath;
  };
  
  
  ```

  

### gaming.h

- 功能：这个头文件用来处理一些game loop中发生的情况

- 函数：

  ```C++
  //检测player在当前格触发的事件（战斗、无法进入等）
  void checkTile(std::vector<Scene*>& scenes, Player* player);
  
  //保存，game loop中每1000帧保存1次
  void saveGame(std::vector<Scene*>& scenes, Player* player, bool autoSave = true);
  
  //加载游戏，可以选择存档
  void loadGame(int saveIndex, std::vector<Scene*>& scenes, Player** player);
  
  //判断两个格子是否相互可见
  bool canSee(int x1, int y1, int x2, int y2, Scene* scene);
  
  /*
  * 加载player附近区域的光照
  * 光照数值存储在scene->light中
  */
  void updateLight(std::vector<Scene*>& scenes, Player* player);
  
  /*
  * 随机事件，玩家平均每走20格触发一次。
  */
  void randomEvent(Player** player);
  ```

  

### PCG.h

#### Room

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

  - ```C++
    std::vector<std::vector<int>> mazeGenerate(
    	int height, 
    	int width,
    	int maxRoomNum, //最大房间个数
        int minRoomSize, //房间最小体积
        int maxRoomSize, //房间最大体积
        int maxIter, //最大迭代次数
        int windingPercent, //弯曲系数
        double keepDeadEndRate, //保留死胡同的个数
        bool paint);
    ```
  

### random.h

- 提供了一些生成随机数的函数

- 函数：

- ```C++
  int random(): 返回一个随机数，大小不超过32768*32768
      
  int random(int l, int r): 返回一个随机数，大小为[l, r]
      
  std::vector<int> random(int l, int r, int k, bool re): 生成k个[l, r]间的随机数
  	[l, r]: 结果的可能范围
  	k: 生成次数
  	re: true时，生成的数可以重复，否则不可以。
          
  int random(std::vector<int>& vec): 随机返回vec中的一个数
          
  int randInt(std::vector<int>& vec): 随机返回vec的一个下标
          
  int randIndByWeights(std::vector<int>& weights): 随机返回weights的一个下标k。k的概率与weights[k]成正比。
          
  bool oneIn(int x): 1/x概率返回true。生成一个不超过x的随机数。如果为1，返回true，否则返回false
          
  bool aInb(int a, int b): a/b概率返回true。生成一个不超过b的随机数。如果不超过a，返回true，否则返回false。
          
  int roll(int diceNum, int facet): 掷diceNum个facet面骰，并返回点数之和
  ```

## 五、参考文献

### 地图生成 

1. [房间和迷宫：一个地牢生成算法 | indienova 独立游戏](https://indienova.com/indie-game-development/rooms-and-mazes-a-procedural-dungeon-generator/)

### 随机数

1. PRD算法：https://gaming.stackexchange.com/questions/161430/calculating-the-constant-c-in-dota-2-pseudo-random-distribution

### 图形库

使用easyx完成