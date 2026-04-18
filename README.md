# UE5 GAS Combat Demo Portfolio

> 基于 Unreal Engine 5 与 Gameplay Ability System（GAS）实现的动作战斗演示项目，重点展示技能系统、属性系统、护盾机制、投射物逻辑、UI 联动以及 Blueprint / C++ 混合开发实践。

---

## 项目简介

这是一个基于 **Unreal Engine 5** 开发的个人战斗系统练习项目，核心目标是围绕 **Gameplay Ability System（GAS）** 搭建一个可扩展的基础战斗框架，并完成以下关键能力的实现：

- 技能释放与冷却管理
- 资源消耗与伤害生效
- HP / MP / 护盾（ExHP）属性系统
- 投射物与命中逻辑
- UI 与属性状态同步
- Blueprint 与 C++ 混合开发与调试

本仓库为 **作品集展示版仓库**，重点展示项目效果、核心功能、系统设计思路以及个人实现内容。

---

## 项目预览

### 演示视频

其余不便通过单张截图完整展示的动态内容，如技能完整释放流程、战斗反馈、角色移动、UI 变化等，统一放在演示视频中展示。

- Demo Video: 见 [Media/demo-video-link.md](Media/demo-video-link.md)

---

### 项目截图

#### 1. 进入游戏后的整体界面
该截图用于展示项目的整体运行状态，包括角色、敌人、场景以及底部技能栏 UI。  
主要体现：**项目已具备完整的基础战斗 Demo 形态，而不仅仅是单独功能测试。**

![进入游戏界面](Docs/screenshots/scene_overview.png)

---

#### 2. 激光技能释放界面
该截图用于展示角色技能释放时的实际战斗表现。  
主要体现：**项目中已实现可触发的技能系统，并具备技能动作、特效与战斗反馈表现。**

![激光技能释放](Docs/screenshots/skill_laser.png)

---

#### 3. 拾取护盾效果
该截图用于展示角色拾取护盾后的视觉反馈与状态表现。  
主要体现：**项目中除基础战斗外，还实现了护盾 / 额外生命值机制，并具备对应的表现效果。**

![拾取护盾效果](Docs/screenshots/shield_pickup.png)

---

#### 4. 技能选取范围状态
该截图用于展示技能释放前的范围选择与目标指示状态。  
主要体现：**部分技能具备施法前选区与范围预览机制，技能交互流程更加完整。**

![技能选取范围状态](Docs/screenshots/skill_targeting.png)

---

## 核心功能

### 1. 基于 GAS 的技能系统
- 使用 Gameplay Ability System 组织角色技能逻辑
- 支持技能激活、冷却、消耗、伤害生效等基础流程
- 技能结构具备一定扩展性，便于后续增加新技能

### 2. 角色属性系统
- 实现角色 **HP / MP / 护盾（ExHP）** 等属性逻辑
- 支持属性变化驱动 UI 更新
- 支持技能消耗、生命恢复、护盾替换与重置等机制

### 3. 战斗与伤害结算
- 实现近战 / 远程技能的基础战斗流程
- 支持投射物攻击、命中检测、伤害应用与受击反馈
- 通过 Gameplay Effect 驱动部分伤害与资源变化逻辑

### 4. UI 联动
- 实现主界面属性条、技能槽、护盾显示等功能
- 将角色属性变化同步到 UMG 界面
- 支持技能图标、状态表现与基础交互反馈

### 5. 技能选区与目标选择
- 部分技能支持施法前范围预览
- 支持目标选择 / 落点选取类交互逻辑
- 提升技能系统的完整度与可玩性表现

---

## 技术栈

- **Engine**: Unreal Engine 5
- **Language**: C++
- **Gameplay Logic**: Blueprint
- **Framework**: Gameplay Ability System (GAS)
- **UI**: UMG
- **Version Control**: Git / GitHub

---

## 系统结构

```mermaid
flowchart LR
    Player[Player Character]
    ASC[Ability System Component]
    Attr[Attribute Set<br/>HP / MP / Shield]
    Ability[Gameplay Ability]
    GE[Gameplay Effect]
    Projectile[Projectile / Hit Logic]
    UI[UMG UI]
    Enemy[Enemy]

    Player --> ASC
    ASC --> Ability
    ASC --> Attr
    Ability --> GE
    Ability --> Projectile
    GE --> Attr
    Attr --> UI
    Projectile --> Enemy
    Projectile --> GE