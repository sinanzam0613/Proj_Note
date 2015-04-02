#ifndef _NOTELINE_H_
#define _NOTELINE_H_

#include "cocos2d.h"


#include <vector>
#include <string>


/**
 *	@enum	：	NoteLineMember
 *	@brief	：	音階、休符列挙
 *	@author	：	新井椋汰
 */
enum NoteLineMember{
    LINE_DO_LOW = 0,
    LINE_RE,
    LINE_MI,
    LINE_FA,
    LINE_SOL,
    LINE_LA,
    LINE_SI,
    LINE_DO_HIGH,
    LENGTH,
};

/**
 *	@struct	：	constNoteValue
 *	@brief	：	音符「開始位置」及び「間隔」の値　の構造体
 *	@author	：	新井椋汰
 */
struct constNoteValue{
    const int startPosX = 0;
    const int startPosY = 0;
    const int notesSpaceX = 0;
    const int notesSpaceY = 0;
};


/**
 *	@class	：	NoteLine
 *	@brief	：	五線譜基礎
 *	@author	：	新井椋汰
 */

class NoteLine : public cocos2d::Node {
protected:
    
    /**
     *  @brief  コンストラクタ
     */
    NoteLine();
    
    /**
     *  @brief  デストラクタ
     */
    ~NoteLine() = default;
    
public:
    
    /**
     *  @brief  インスタンスの生成
     * @return	NoteLine    インスタンス
     */
    static NoteLine* create();
    
    /**
     *  @brief  初期化
     *  @return bool    初期化が完了したか否か
     */
    virtual bool init() override;
    
    /**
     *  @brief  末尾への要素の追加
     *  @param NoteLineMember 追加したい音階または休符
     */
    void notePushBack( NoteLineMember nlm);
    
    /**
     *  @brief  指定位置への要素の追加
     *  @param int 追加したい箇所
     *  @param NoteLineMember 追加したい音階または休符
     */
    void noteInsert(int number, NoteLineMember nlm);
    
    /**
     *  @brief  要素数の確認
     */
    size_t noteSize();
    
    /**
     *  @brief  位置の取得
     *  @param int　取得したい音符の番数
     */
    cocos2d::Point noteGetPosition(int number);
    
    
private:
    //音符格納用配列
    typedef std::vector<NoteLineMember> NoteList;
    NoteList mNoteList;
    //音符各種値構造体
    constNoteValue mNoteValue;
    
};


#endif