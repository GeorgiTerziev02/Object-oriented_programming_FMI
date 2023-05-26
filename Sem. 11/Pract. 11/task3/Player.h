#pragma once

enum class Stars {
	oneStar,
	twoStar,
	threeStar,
	fourStar,
	fiveStar
};

class Player
{
	int ID;
	int points;
	Stars stars=Stars::oneStar;
public:
	void missionCompleted(int points);
	void sedID(int ID);
	void setPoints(int points);
	void setStars(Stars newStar);
	virtual int getID()const ;
	virtual int getPoints()const ;
	virtual Stars getStars()const ;
	virtual bool levelUp() = 0;
	virtual ~Player()=default;
};

