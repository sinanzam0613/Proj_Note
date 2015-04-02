#include "NoteLine.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
 /--------------------------*/
NoteLine::NoteLine():mNoteList(0){
    //Excelからの音符読み込み
    
}


/*--------------------------/
 インスタンス生成
 /--------------------------*/
NoteLine* NoteLine::create(){
    auto inst = new NoteLine();
    
    if(inst && inst->init()){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE(inst);
    return nullptr;
}

/*--------------------------/
 初期化
 /--------------------------*/
bool NoteLine::init(){
    return true;
}

/*--------------------------/
 末尾への要素の追加
 /--------------------------*/
void NoteLine::notePushBack(NoteLineMember nlm){
    mNoteList.push_back(nlm);
}

/*--------------------------/
 指定位置への要素の追加
 /--------------------------*/
void NoteLine::noteInsert(int number,NoteLineMember nlm){
    mNoteList.insert(mNoteList.begin() + number, nlm);
}

/*--------------------------/
 要素数の確認
 /--------------------------*/
size_t NoteLine::noteSize(){
    return mNoteList.size();
}

/*--------------------------/
 位置の取得
 /--------------------------*/
cocos2d::Point NoteLine::noteGetPosition(int number){
    
    
    cocos2d::Point mNotePosition;
    
    
    mNotePosition  = cocos2d::Point( number * mNoteValue.notesSpaceX + mNoteValue.startPosX ,
                                    mNoteList[number] * mNoteValue.notesSpaceY + mNoteValue.startPosY );
    
    return mNotePosition;
}







