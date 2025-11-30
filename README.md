# 資料結構 HW2
---
## Contents
- [Library Explanation](#LE) 
    - [Map](#Map)
    - [Unordered Map](#UnorderedMap)
- [Code Explanation](#CE)
    - [Binary Search Tree](#BST)
    - [Hash Table](#HT)
- [Experiment](#experiment)
    - [Insertion Time](#InsertionTime)
    - [Average Search Time](#AverageSearchTime) 

## Library Explanation<a id=LE></a>
1. ##### Map<a id=Map></a>
   ![Map](https://github.com/antyee87/DataStructureHW3/blob/main/map.png?raw=true)
   <br>
   C++的map是以紅黑樹(red-black tree)實作的，而紅黑樹是一種自平衡二元搜尋樹，也屬於BST。
2. ##### Unordered Map<a id=UnorderedMap></a>
   ![Unordered_Map](https://github.com/antyee87/DataStructureHW3/blob/main/unordered_map.png?raw=true)
   <br>
   C++的unordered map在注解說明了是基於hash table實作的，C++規範也限制了無序容器需要以hash table實現。

## Code Explanation<a id=CE></a>
Code : https://github.com/antyee87/DataStructureHW3
1. ##### Binary Search Tree<a id=BST></a>
```c++
void BST::insert(int id, int score)
{
    bst.try_emplace(id, StudentProfile(id)).first->second.add_score(score);
    // 如果元素存在，直接增加分數，如果元素不存在，新增元素再增加分數
}

double BST::search_average(int id)
{
    auto it = bst.find(id); // 尋找元素
    if (it == bst.end()) // 元素不存在
        return -1; 
    return it->second.get_scores_average(); // 計算平均
}
```
<br>

2. ##### Hash Table<a id=HT></a>
```c++
void HT::insert(int id, int score)
{
    ht.try_emplace(id, StudentProfile(id)).first->second.add_score(score);
    // 如果元素存在，直接增加分數，如果元素不存在，新增元素再增加分數
}

double HT::search_average(int id)
{
    auto it = ht.find(id); // 尋找元素
    if (it == ht.end()) // 元素不存在
        return -1;
    return it->second.get_scores_average(); // 計算平均
}
```
<br>

## Experiment<a id=Experiment></a>
* ### Environment
    - CPU: 12th Gen Intel(R) Core(TM) i7-12700 (2.10 GHz)
    - RAM: 24GB
    - OS: Windows 11 家用版 25H2 (Build 26200.6899)
    - Compiler: Visual Studio 2022 (MSVC)
  
* ### Result
    1. ##### Insertion time<a id=InsertionTime></a>
    ![Insertion Time](https://github.com/antyee87/DataStructureHW3/blob/main/experiment1.png?raw=true)
    <br>
    Binary Search Tree單次插入複雜度是O(log n)，插入n個數據的複雜度是O(n log n)，而Hash Table單次插入複雜度是O(1)，插入n個數據的複雜度是O(n)，但神奇的是兩者時間差異只有約1.5倍，看起來都像O(n)，應該是hash table的運作開銷較大的緣故。<br>


    2. ##### Average Search Time<a id=AverageSearchTime></a>
    ![Average Search Time](https://github.com/antyee87/DataStructureHW3/blob/main/experiment2.png?raw=true)
    <br>
    在不同資料量下進行2^20次搜尋後得到平均搜尋時間，每個數據都是10組實驗數據取平均。Binary Search Tree複雜度是O(log n)，Hash Table複雜度是O(1)，但可能由於有分數的學生增加或其他額外開銷，Hash Table搜尋時間仍會增長。<br>
