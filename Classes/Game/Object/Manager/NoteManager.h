#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include "cocos2d.h"

class NoteLine;
class Note;

enum LineType{
	Red = 0,
	Bule
};

class NoteManager : public cocos2d::Ref{

protected:
	NoteManager();

	~NoteManager();

public:

	static NoteManager* create(cocos2d::Layer* layer);

	bool init(cocos2d::Layer* layer);

	void noteCreator(cocos2d::Layer* layer);

	Note* getNote(LineType type, int value);
	
	void onTouchBegan(cocos2d::Point pos);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

private:
	Note* mNote;
	NoteLine* mRedNoteLine;
	NoteLine* mBuleNoteLine;
	NoteLine* Lines;
};
#endif