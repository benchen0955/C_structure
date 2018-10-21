# C_structure
int a[3][4];
          0 columm   1columm   2       3   
0 row    a[0][0]    a[0][1]  a[0][2]  a[0][3]  
1 row    a[1][0]    a[1][1]  a[1][2]  a[1][3]
2 row    a[2][0]    a[2][1]  a[2][2]  a[2][3]

for (i=0;i<3;i++)
 for (j=0;j<4;j++)
    a[i][j]
	
void fun(int a[][4])
void fun(int a[][4][5])

http://www.pythontutor.com/c.html#mode=edit


int i=10,k;
int *ptr;
ptr=&i;//結構可用
k=*ptr;

int *ptr,n=4;
ptr=(int *)malloc(sizeof(int)*n);(not set over 1 Mbyte);
//結構可用
if (ptr==NULL)
{
   printf("run out of memory");
   exit(0);
}
else
{
   free(ptr);
}
//第一週2016_10_02_14_06_59_636.mp4  51:42介紹VC++


//結構
Person p1;
Person *p2;
p2=&p1;//相同空間
p1.name="abc";
p1.h=20;
p2->name="bcd";
p2->h=100;

LINK LIST轉成FUNCTION功能
數字串列轉成通訊錄改變資料結構即可
VC++ LINK LIST開題在03 LinkList.pdf決解

LINK LIST 排序與搜尋 04 Sort and Search.PDF 第22頁
插入排序可用於不定長度的排序 可以一個一個輸入
快速排序Qsort 
第四週2016_10_29_13_12_59_776.mp4 00:46:24 在stdlib.H 有函式可用
visualize 可以C遂步執行
迷宫及發卡 HW9&HW10
第五週資料結構 HW11
C++
類別class是C++中用來封裝(Encapsulation)資料的關鍵字，當您使用類別
來定義一個物件(Object)時，您考慮這個物件可能擁有的
「屬性」(Property)與「方法」(Method)成員
•屬性是物件的靜態描述,屬性(參數)
•方法是可施加於物件上的動態操作,方法(行為,函數)

使用類別定義出這個物件的規格書，之後就可依這個規格書製作出一個個的
物件實例，並在製作過程中設定個別物件的專屬特性資料。
要訣：
•屬性(該類別的變數)-->要存放的資料 (每個物件有自己的屬性)
•方法(該類別的函式)-->寫要執行的程式 (用方法控制屬性)
屬性修改需要用方法修改,可避免錯誤修改
如何設計類別?

思考 (以功能角度)
•每個物件需要什麼資料?
•每個物件需要什麼方法來操作資料?
進階思考 (以使用者角度)
•如何讓使用類別的人方便簡單使用
•如何避免使用類別的人因資料操作不當而產生錯誤

類別（Class）
宣告一個類別 (類似定義一個結構struct)
語法：

class 類別名稱 
{ 
     public: 
      類別名稱(); //建構式, 用來做物件的初始化 
      ~類別名稱(); //解構式, 用來做物件的善後工作 
      公開的方法或屬性; //可打點使用

     protected: // 只有在同一繼承架構中可以使用的資料 
       受保護的方法或屬性;  //不打可點使用
     
     private: // 只有在此類別中可以使用的資料 
       私有的方法或屬性;   //不打可點使用
};

資料的權限//不加權限 dev c預設 private
最重要的是別忘了在最後加上分號，初學C++的新手很常犯這個錯誤
public這個關鍵字，它表示以下所定義的成員"可以"使用物件名稱"直接被呼叫"，稱之為「"公開成員"」
private關鍵字下的則是「"私有成員"」，不可以透過物件名稱直接呼叫
在類別封裝時，有一個基本原則是：資訊的最小化公開。如果屬性"可以不公開就不公開"，如果要取得或
設定物件的某些屬性，也是儘量透過方法成員來進行

建構式與解構式 (無回傳值)
在定義類別時，您可以使用建構函式(Constructor)來進行物件的"初始化"
ex:  
"::"範疇
LinkedList::LinkedList()
{
head = NULL;
}
而在物件釋放資源之前，您也可以使用「"解構函式"」(Destructor)來進行一些"善後"的工作

WIN10 不能用DEV C

Friend類別
使用friend函式通常是基於"效率的考量"，以直接存取私用成員而不透過函式呼叫的方式，來省去函式呼叫的負擔
您也可以將某個類別宣告為friend類別，被宣告為friend的類別可以直接存取私用成員

p01_tissue.cpp基本物件使用
p02_tissue.cpp使用範疇::
p02_compare.cpp使用Friend類別 僅用於實體 不可繼承
c++_linked_list.cpp 使用c++資料結構
#include <conio.h>//僅window有 linux mac 沒有


繼承（Inheritance）使用:
「繼承」（Inheritance）是物件導向程式設計的一種進階觀念
"繼承就是物件的再利用"，當定義好一個類別後
其他類別可以繼承這個類別的成員資料和函數
語法:
class '子'類別"名稱": 繼承權限 '父'類別"名稱"
{
…
};
在繼承的關係中
•被繼承的類別：
•「"父類別"」（Parent class）或「"基礎類別"」（Base class）
•繼承父類別的類別：
•「"子類別"」（Child class）或「"衍生類別"」（Derived class）

c++_stack_queue.cpp使用繼承
protected:可cpp使用繼承給"子"用但不能給"外" 實體不可用
private:不可cpp使用繼承
第五週 錄製_2016_11_06_13_07_40_568 00:25:12 有繼承權限說明


樣板（ TemplateTemplate Template ）
C++ 的Template 是種將資料型態參數化的功能。將資料型態訊自程式
碼中抽離，代之以簡化的符號 (T, T1, T2, ...)。再由編譯器透過類
似巨集"代換"的方式，根據樣板內容產生實際的程式碼

• Function Template(函式樣板 )
• Class Template(類別樣板 )。

思考 :
• 如果今天我們想要設計一些函式來列印出"不同型態的陣列內容"，
這些函式的參數列定義"資料型態"必須設為"不同的型態"，
該如何設計這些函式？
描述上函式的三種方：
• 一般函式 (Function)：
• 描述"各種可能用到的型態"，每個函式都取"不同的名稱"
• 函式重載 (Function Overloading)：
• 描述"各種可能用到的型態"，每個函式都取"相同的名稱"
• 函式樣板 (Function Template) ：
• 描述"一個型態"，"一個函式名稱"

c++_bubblesort.cpp 一般函式

函式重載 (Function Overloading)
作法 :
• 描述各個函式，每都取"相同的名稱"，將可能用到的型態對應各個函式中。
優點：
• 程式設計師不需記一堆函名稱。"編譯器自動會把呼叫的函式對應到同參數型態中"。
缺點：
• 雖比起一般函式的做法方便，但差不多程碼還是要"寫很多遍 "。
c++_bubblesort_overloading.cpp 函式重載

函式樣板 (Function Template)
作法 :
• 描述一個函式，只需"一個名稱"，使用樣板參數取替資料型態。
優點：
• 程式設計師除了不需記一堆函名稱之外， 也不需要寫一 堆類似的程式碼。編譯器
"自動產生"需要的程式碼 (重載函式 )， 然後把呼叫的函式對應到同參數型態中。
• 程式碼一般"較小"(用到的型態才會產生程式 )
缺點：
• 程式功能 缺乏彈性 (只能描述類似的程式行為 )。
列印時用cout (可載typeof函式試試)

以關鍵字"template"起始一個樣板宣告，後接參數。  C/C++ 的程式語法，是以 ( )括起參數。
而 Template語法，則以< >括起參數。

樣板所用參數之完整稱呼是「樣板所用參數 (template parameters)」，慣例以 T, T1, T2 
等作為樣板參數名稱。
接著再寫上函式的程碼樣板，又稱原型 接著再寫上函式的程碼樣板，又稱原型 (prototype)。
函式原型的函式名稱即為函式樣板的名稱


#############################################

Hw3:
定義一個鏈結串列反序列印(ex06 build-4 reverse.c)
Hw4:
鏈結串列-會員資料表 (ex08 member data.c)
Hw5:
字元排序 (chap03_ex2_sort_char.c)
Hw6:
搜尋法(字串) (chap03_ex4_search_char.c
Hw7:
河內塔-計算各圓盤被搬動多少次 (ex04_Hanoi Tower.c)
Hw8:
二元搜尋樹-電話簿 (Addressbook_Tree.c)
Hw9:
撲克牌發牌程式進階版(stack_card.c)
Hw10:
迷宮問題-自行設計一15x10迷宮(stack_maze_ex2.c)
Hw11:
二元搜尋樹C++改寫版(tree.c)

Ex3:
結構陣列印出各科平均 (chap01_ex1.c)	
結構陣列 新增 查詢 修改 列出 計算平均 (chap01_ex2.c) 
建立鏈結串列節點 )(ex01 build-1.c)
Ex4:
定義一個鏈結串列順序列印 (ex03 build-2 add 1.c) 
定義一個鏈結串列反序列印(ex06 build-4 reverse.c)
Ex5:
插入鏈結串列節點	(ex07 interface i.c) 
尋找鏈結串列節點 (ex07 interface i.c) 
刪除鏈結串列節點 (ex07 interface i.c)
Ex6:
排序法與介面 (chap03_ex1_sort_num.c)	
搜尋法(數字) (chap03_ex3_search_num.c)

Ex7:
遞迴,印出n~1 與 1~n (ex01_1-n.c) 
遞迴,算出n!之值 (1*2*3*…*n) (ex03_n!.c) 
河內塔-練習
Ex8:
建立一個基本二元樹 (Binarry_Tree.c) 
前/中/後序走訪 (Binarry_Tree.c) 
二元樹的搜尋 (Tree_LinearSearch.c) 
二元搜尋樹 (BinarySearchTree.c)
Ex9:
撲克牌(stack_card.c) 
迷宮問題-印出路徑座標(stack_maze_ex1.c)
Ex10:
導入C++
Ex11:
Template
Ex12:




template<樣板參數型態 樣板參數名 ,…其他樣板參數 >
原型回傳態 函式名稱 (參數型態 原型參數名 ,...)
{
程式碼 ;
}

c++_bubblesort_template. 函式樣板

類別樣板(Function Template)

part1&2 pdf內有
可make dll
檔案格式
stl
mfc 視窗
佈置安裝 setup檔

