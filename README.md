# mm6chupchangekey：魔法门6中文完美升级版的键位修改器

## 注意

仅对魔法门6中文完美升级版有效，请勿用于其他版本！

执行changekey_wsad.bat文件可以使用wsad作方向键时的推荐键位；执行changekey.bat文件可以还原中文完美升级版默认键位

该工具会自动备份原来的mm6.exe至mm6.exe.backup

如果您想自定义键位，请阅读以下详细用法

## 命令行用法

这是一个简易的命令行工具，其用法为：

```
mm6chupchangekey.exe 文件路径及名称 功能1 按键1 功能2 按键2 ...
```

其中，功能可以是以下之一（以下括号中是注释，请不要在命令行中输入括号和其中的内容）：

* alwaysrun（是否总是奔跑）
* fliponexit（离开房屋时是否转身）
* forward（前进）
* back（后退）
* "turn left"（左转）
* "turn right"（右转）
* yell（呐喊）
* jump（跳跃）
* "toggle turnbase"（切换回合制/即时制）
* inspect（调查前方事物）
* "skip character"（切换到下一个队员）
* "cast quick spell"（施展备用魔法）
* attack（使用武器攻击）
* "fly up"（向上飞）
* "fly down"（向下飞）
* land（降落）

（本工具暂无法改变仰视俯视平视、打开任务地图摘要休息魔法书等的键位）

对于alwaysrun和fliponexit，“按键”可以是1或0（即是或否）；对于其他，按键可以是以下之一：

* backspace
* enter
* space
* "page up"
* "page down"
* end
* home
* left
* up
* right
* down
* insert
* delete
* 0 至 9
* a 至 z
* =
* ,
* -
* .
* /
* `
* \
* '

也可以使用（但不建议使用）：

* f1 至 f12
* tab
* shift
* ctrl
* alt
* capslock

不区分大小写；有空格的请用英文双引号（""）包裹起来

## 范例

您可以双击执行魔法门6目录下的changekey_wsad.bat文件，它是wsad作方向键时的推荐键位，它的内容是：

```
mm6chupchangekey.exe "mm6.exe" alwaysrun 1 fliponexit 0 forward w back s "turn left" a "turn right" d attack e "cast quick spell" c "fly up" f "fly down" g land v
```

这意味着：

* 总是奔跑：是（1）
* 离开房屋时转身：否（0）
* 前进、后退、左转、右转：WSAD
* 武器攻击：E
* （打开魔法书：C）
* 施展备用魔法：CTRL+C或ALT+C
* 向上飞：F
* 向下飞：G
* 降落：V
（一个特殊的键位是：施展备用魔法的C键和打开魔法书冲突，所以打开魔法书还是C键，施展备用魔法变为CTRL+C或ALT+C）

您也可以双击执行changekey.bat文件，它可以还原为中文完美升级版默认键位（总是奔跑，离开房屋时不转身，其他键位和原版一致）

或者，使用文本编辑器打开changekey.bat，修改成您想要的，保存，双击执行

## 附：魔法门6原版键位表

* ↑↓←→：前进、后退、左转、右转
* Shift + ↑↓：跑步移动
* Ctrl + ←→：侧移
* Page Down：仰视
* End：平视
* Delete：俯视
* Page Up：向上飞（当施展了空气魔法中的飞行奇术后）
* Home：降落（着陆）
* Insert：向下飞
* Enter：切换回合制/即时制
* 空格：调查前方事物（拾起地上的物品、打开箱子等）
* A：使用武器攻击（如敌人距离远，则使用弓箭）
* S：施展备用魔法（如无，则使用使用武器攻击）
* X：跳跃
* R：休息
* Z：打开队伍属性
* C：打开魔法书
* B：切换到下一个队员（跳过当前队员）
* 1、2、3、4：选中某队员（第二次按打开该队员的属性栏）
* 5、6：与雇佣的NPC谈话
* M：打开地图
* Q：打开当前任务
* N：打开自动摘要
* T：打开日历
* Y：呐喊（驱赶挡路的NPC）

（原版不按Shift为行走状态，较慢，离开房屋时会转身。中文完美升级版开启了总是奔跑，离开房屋时不会转身，没有更改其他键位）
