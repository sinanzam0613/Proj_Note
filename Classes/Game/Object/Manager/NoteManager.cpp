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
	mNoteLine = NoteLine::create();

	mNoteLine->retain();

	layer->addChild(mNoteLine);

	noteCreator(layer);

	return true;
}

NoteManager::NoteManager():mNote(nullptr){



}

void NoteManager::noteCreator(cocos2d::Layer* layer) {
	for (int i = 0; i < 8; ++i) {
		auto note = Note::createObject(Vec2(100 + i * 160, rand() % 500 + 300));
		note->setTag(i);
		note->retain();
		mNoteLine->notePushBack(note);
		mNoteLine->addChild(note, 5);
	}
}

void NoteManager::onTouchBegan(cocos2d::Point pos) {
	
	for (unsigned int i = 0; i < mNoteLine->noteSize(); ++i) {
		auto pNote = mNoteLine->getNote(i);
		if (!pNote) {
			return;
		}
		Rect noteRect = pNote->getBoundingBox();
		if (noteRect.containsPoint(pos)) {
			mNote = pNote;
			return;
		}
	}
}

void NoteManager::onTouchMove(cocos2d::Point pos) {
	
	if (pos.y <= 300) return;

	mNote->setPositionY(pos.y + 180);
}

void NoteManager::onTouchEnd(cocos2d::Point pos) {

	int setLinePos = 0;
	setLinePos = ((int)mNote->getPositionY() - START_NOTE) / NOTE_SPACE;

	mNote->soundPlay(setLinePos);

	setLinePos = START_NOTE + (setLinePos * NOTE_SPACE);

	mNote->setPositionY(setLinePos);

	mNote = nullptr;

}

Note* NoteManager::getNote(int value){
	return mNoteLine->getNote(value);
}