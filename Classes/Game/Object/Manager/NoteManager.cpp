#include "NoteManager.h"
#include "Game/Object/StageObject/Note/NoteLine.h"
#include "Game/Object/StageObject/Note/Note.h"

USING_NS_CC;

NoteManager* NoteManager::create(cocos2d::Layer* layer){

	auto obj = new NoteManager();

	if (obj && obj->init(layer)){
		obj->autorelease();

		return obj;
	}
	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool NoteManager::init(cocos2d::Layer* layer){
	mRedNoteLine = NoteLine::create();

	mRedNoteLine->retain();

	layer->addChild(mRedNoteLine);

	mBuleNoteLine = NoteLine::create();

	mBuleNoteLine->retain();


	layer->addChild(mBuleNoteLine);

	noteCreator(layer);

	return true;
}

NoteManager::NoteManager():mNote(nullptr){


}

NoteManager::~NoteManager(){
	mRedNoteLine->release();
	mBuleNoteLine->release();
}

void NoteManager::noteCreator(cocos2d::Layer* layer) {
	for (int i = 0; i < 5; ++i) {  //Vec2(100 + i * 160, rand() % 500 + 300) Vec2(100 , 400)
		auto note = Note::createObject(Vec2(350 + i * 180, rand() % 300 + 300));
		note->setName("Note" + std::to_string(i));
		note->retain();
		mRedNoteLine->notePushBack(note);
		mRedNoteLine->addChild(note, 5);
	}

	for (int i = 0; i < 5; ++i) {  //Vec2(100 + i * 160, rand() % 500 + 300) Vec2(100 , 400)
		auto note = Note::createObject(Vec2(350 + i * 180, rand() % 300 ));
		note->setName("Note" + std::to_string(i));
		note->retain();
		mBuleNoteLine->notePushBack(note);
		mBuleNoteLine->addChild(note, 5);
	}

}

void NoteManager::onTouchBegan(cocos2d::Point pos) {
	
	for (unsigned int i = 0; i < mRedNoteLine->noteSize(); ++i) {
		auto pNote = mRedNoteLine->getNote(i);
		if (!pNote) {
			return;
		}
		auto noteRect = pNote->getBoundingBox();
		if (noteRect.containsPoint(pos)) {
			mNote = pNote;
			return;
		}
	}
}

void NoteManager::onTouchMove(cocos2d::Point pos) {
	
	if (mNote == nullptr) return;

	float Yvalue;

	Yvalue = pos.y + ADJUST_VALUE;

	if (pos.y > MAX_NOTE - ADJUST_VALUE)  Yvalue = MAX_NOTE;

	if (pos.y < START_NOTE - ADJUST_VALUE) Yvalue = START_NOTE;

	mNote->setPositionY(Yvalue);
}

void NoteManager::onTouchEnd(cocos2d::Point pos) {

	if (mNote == nullptr) return;

	int setLinePos = 0;
	setLinePos = ((int)mNote->getPositionY() - START_NOTE) / NOTE_SPACE;

	mNote->soundPlay(setLinePos);

	setLinePos = START_NOTE + (setLinePos * NOTE_SPACE);

	mNote->setPositionY(setLinePos);

	mNote = nullptr;

}

Note* NoteManager::getNote(LineType type, int value){

	if (type == Red){
		if (value >= mRedNoteLine->noteSize()) return mRedNoteLine->getNote(0);
		return mRedNoteLine->getNote(value);
	}
	if (value >= mBuleNoteLine->noteSize()) return mBuleNoteLine->getNote(0);
	return mBuleNoteLine->getNote(value);
}