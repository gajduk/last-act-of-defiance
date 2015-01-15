#pragma once
#include "Entity.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "GameMenu.h"
#include "Background.h"
#include "UserHUD.h"
#include "Entry.h"
#include "List.h"
#include "ListEnemyShip.h"
#include "GameOver.h"

// GameClass dialog

class GameClass : public CDialog {
	DECLARE_DYNAMIC(GameClass)

private:
	int enemy_missile_counter;
	int current_enemy;
	int enemy_counter;
	int slow_time_counter;
	bool slow_time;
	int num_bombs;
	bool auto_fire;
	bool pause;
	bool double_shot;
	bool piercing_shot;
	int piercing_shot_counter;
	int double_shot_counter;
	UserHUD *hud;
	List *everything;
	GameMenu *menu;
	PlayerShip *ship;
	Background *background;
	GameOver *game_over;

	void draw();
	void attachMissile( int xpos , int ypos );
	void attachEnemyShip( int xpos , int ypos );
	void attachExlposion( int xpos , int ypos );
	void attachEnemyMissile( int enemy_index );
	void attachPowerUp( int xpos , int ypos );
	void attachPiercingMissile( int xpos , int ypos );
	void attachFloatingScore( int xpos, int ypos);
	void attachFloatingPowerUp( int xpos, int ypos, CString power_up);
	void attachFloatingScoreMultiplier( int xpos, int ypos , int value );
	void deleteInGameData();
	void OnOK();
	void OnCalncel();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
		
	DECLARE_MESSAGE_MAP()

public:
	static int MAX_ENEMY_MISILE;
	static const int GAME_SPEED = 30;
	static const int MAX_HEIGHT = 1510;
	static const int MIN_HEIGHT = -150;
	static const int RIGHT_BOUND = 1150;
	static const int LEFT_BOUND = -50;
	static const int ENEMY_OFFSET = 100;
	static const int ENEMY_TOP_BOUND = 50;
	static const int ENEMY_BOTTOM_BOUND = 460;
	static const int HEAL_AMOUNT = 100;
	static const int DOUBLE_SHOT_DURATION = 600;
	static const int PIERCING_SHOT_DURATION = 600;
	static const int SLOW_TIME_DURATION = 100;
	static const int HIT_DAMAGE = 100;

	static int DIFFICULTY;

	ListEnemyShip *enemies;
	bool exit;

	
	GameClass(CWnd* pParent = NULL); 
	virtual ~GameClass();

	void hitTest();
	void explodeEnemy(EnemyShip *enemy_hit);
	void heal();
	void powerUp();
	void slowTime();
	void refreshTime();
	void doubleShot();
	void singleShot();
	void fire();
	void piercingMissile();
	void regularMissile();
	void clearScreen();
	void enemyFire();
	void addMoreEnemies();
	void checkPowerUps();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
 	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};
