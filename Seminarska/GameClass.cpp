#include "stdafx.h"
#include "Seminarska.h"
#include "GameClass.h"
#include "Entity.h"
#include "PlayerMissile.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include <time.h>
#include "Explosion.h"
#include "EnemyMissile.h"
#include "PowerUp.h"
#include "PiercingMissile.h"
#include "Background.h"
#include "UserHUD.h"
#include "FloatingScore.h"
#include "FloatingPowerUp.h"
#include "List.h"
#include "Entry.h"
#include "ListEnemyShip.h"
#include "GameOver.h"
#define BOMB 84
#define FIRE 32
#define UP 87
#define DOWN 83
#define LEFT 65
#define RIGHT 68
#define AUTO_FIRE 16
#define QUIT 81
#define EXIT 88
#define PAUSE(x) ( x == 19 || x == 80 ) ? true : false


int GameClass::MAX_ENEMY_MISILE = 15;
int GameClass::DIFFICULTY = 10;



IMPLEMENT_DYNAMIC(GameClass, CDialog)

GameClass::GameClass(CWnd* pParent /*=NULL*/)
: CDialog(IDD_DIALOG1, pParent)
{

}

GameClass::~GameClass() {
}

void GameClass::OnOK() {
	deleteInGameData();
	CDialog::OnOK();
}
void GameClass::OnCalncel() {
	deleteInGameData();
	CDialog::OnCancel();
}

void GameClass::powerUp() {	
	srand(time(NULL));
	CString power_up;
	int decision = rand()%6;
	if ( decision == 0 ) {
		slowTime();
		power_up = "Slow Time";
	}
	if ( decision == 1 ) {
		ship->raiseShield();
		hud->showShieldBar(ship->shield_duration);
		power_up = "Shield";
	}
	if ( decision == 2 ) {
		doubleShot();
		power_up = "Double Shot";
	}
	if ( decision == 3 ) {
		piercingMissile();
		power_up = "Piercing Missiles";
	}
	if ( decision == 4 ) {
		heal();
		power_up = "Ship Repaired";
	}
	if ( decision == 5 ) {
		hud->storeBomb();
		if ( num_bombs < hud->MAX_BOMBS ) num_bombs++;
		power_up = "Nuke";
	}
	attachFloatingPowerUp(ship->x,ship->y-20,power_up);
}

void GameClass::doubleShot() {
	double_shot_counter = 0;
	double_shot = true;
}


void GameClass::deleteInGameData() {
	delete ship;
	delete enemies;
	delete everything;
	delete background;
	delete hud;
	delete menu;
}
void GameClass::singleShot() {
	double_shot = false;
}

void GameClass::slowTime() {
	EnemyShip::velocity_multiplier = 0.2;
	EnemyMissile::velocity_multiplier = 0.2;
	background->velocity_mutiplier = 1;
	MAX_ENEMY_MISILE = 50;
	slow_time_counter = 0;
	slow_time = true;
}

void GameClass::refreshTime() {
	EnemyShip::velocity_multiplier = 1;
	EnemyMissile::velocity_multiplier = 1;
	background->velocity_mutiplier = 2;
	MAX_ENEMY_MISILE = 15;
	slow_time = false;
}

void GameClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void GameClass::draw(  ) {
	
}


void GameClass::OnPaint() {
		CClientDC clientDC(this);
		CDC memDC;
		memDC.CreateCompatibleDC(&clientDC);
		CRect rcClient;
		GetClientRect(&rcClient);
		CBitmap memBitmap;
		memBitmap.CreateCompatibleBitmap(&clientDC,rcClient.Width(),rcClient.Height());
		memDC.SelectObject(&memBitmap);
		CBrush brush(RGB(255,255,255));
		memDC.SelectObject(brush);
		memDC.Rectangle(-10,-10,1200,600);
		background->draw(&memDC);
		everything->draw(&memDC);
		if ( ship->game_over ) game_over->draw(&memDC);
		hud->draw(&memDC);
		everything->draw(&memDC);
		ship->draw(&memDC);
		menu->draw(&memDC);
		clientDC.BitBlt(0,0,rcClient.Width(),rcClient.Height(),&memDC,0,0,SRCCOPY);
	CDialog::OnPaint();
}

BOOL GameClass::OnInitDialog() {
	exit = false;
	menu = new GameMenu();
	ship = new PlayerShip();
	everything = new List();
	enemies = new ListEnemyShip();
	background = new Background();
	hud = new UserHUD();
	game_over = new GameOver();
	singleShot();
	regularMissile();
	SetTimer(ID_TIMER,20,NULL);
	num_bombs = 3;
	current_enemy = 5;
	enemy_counter = 150;
	auto_fire = false;
	enemy_missile_counter = 0;
	pause = false;
	return true;
}

void GameClass::piercingMissile() {
	piercing_shot = true;
	piercing_shot_counter = 0;
}
void GameClass::regularMissile() {
	piercing_shot = false;
}

void GameClass::heal() {
	ship->updateHealth(HEAL_AMOUNT);
}

BEGIN_MESSAGE_MAP(GameClass, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()


void GameClass::fire() {
	bool to_fire = false;
	if ( ship->fire_missile ) {		
				to_fire = true;
				ship->fire_missile = false;
		}

	if ( auto_fire ) {
		if ( ship->missile_counter > ship->fire_rate )  {
			to_fire = true;
			
			ship->missile_counter = 0;
		}
	}
	if ( to_fire ) {
		if ( double_shot ) {
			if ( piercing_shot ) {
				attachPiercingMissile(ship->x,ship->y+10);
				attachPiercingMissile(ship->x,ship->y-20);
			}
			else {
				attachMissile(ship->x,ship->y+10);
				attachMissile(ship->x,ship->y-20);
			}
		}
		else {
			if ( piercing_shot ) {
				attachPiercingMissile(ship->x,ship->y);
			}
			else {
				attachMissile(ship->x,ship->y);
			}
		}
	}
}

void GameClass::hitTest( ) {
		PlayerMissile m1(ship->x,ship->y,this);
		PlayerMissile m2(ship->x+50,ship->y,this);
		PlayerMissile m3(ship->x,ship->y+50,this);
		PlayerMissile m4(ship->x+50,ship->y+50,this);

		Entry *temp1 = enemies->checkMissile(m1);
		if ( temp1 ) {
			EnemyShip *enemy_hit1 = dynamic_cast<EnemyShip*> (temp1->data);
			ship->updateHealth(-HIT_DAMAGE);
			explodeEnemy(enemy_hit1);
			enemy_hit1->updateHealth(-1000);
			enemies->deleteEntry(temp1);
			Entry *temp2 = enemies->checkMissile(m1);
			if ( temp2 ) {
				EnemyShip *enemy_hit2 = dynamic_cast<EnemyShip*> (temp2->data);
				ship->updateHealth(-HIT_DAMAGE);
				explodeEnemy(enemy_hit2);
				enemy_hit2->updateHealth(-1000);
				enemies->deleteEntry(temp2);
				Entry *temp3 = enemies->checkMissile(m1);
				if ( temp3 ) {
					EnemyShip *enemy_hit3 = dynamic_cast<EnemyShip*> (temp3->data);
					ship->updateHealth(-HIT_DAMAGE);
					explodeEnemy(enemy_hit3);
					enemy_hit3->updateHealth(-1000);
					enemies->deleteEntry(temp3);
				}	
			}	
		}

		temp1 = enemies->checkMissile(m2);
		if ( temp1 ) {
			EnemyShip *enemy_hit1 = dynamic_cast<EnemyShip*> (temp1->data);
			ship->updateHealth(-HIT_DAMAGE);
			explodeEnemy(enemy_hit1);
			enemy_hit1->updateHealth(-1000);
			enemies->deleteEntry(temp1);
			Entry *temp2 = enemies->checkMissile(m2);
			if ( temp2 ) {
				EnemyShip *enemy_hit2 = dynamic_cast<EnemyShip*> (temp2->data);
				ship->updateHealth(-HIT_DAMAGE);
				explodeEnemy(enemy_hit2);
				enemy_hit2->updateHealth(-1000);
				enemies->deleteEntry(temp2);
				Entry *temp3 = enemies->checkMissile(m2);
				if ( temp3 ) {
					EnemyShip *enemy_hit3 = dynamic_cast<EnemyShip*> (temp3->data);
					ship->updateHealth(-HIT_DAMAGE);
					explodeEnemy(enemy_hit3);
					enemy_hit3->updateHealth(-1000);
					enemies->deleteEntry(temp3);
				}	
			}	
		}
		temp1 = enemies->checkMissile(m3);
		if ( temp1 ) {
			EnemyShip *enemy_hit1 = dynamic_cast<EnemyShip*> (temp1->data);
			ship->updateHealth(-HIT_DAMAGE);
			explodeEnemy(enemy_hit1);
			enemy_hit1->updateHealth(-1000);
			enemies->deleteEntry(temp1);
			Entry *temp2 = enemies->checkMissile(m3);
			if ( temp2 ) {
				EnemyShip *enemy_hit2 = dynamic_cast<EnemyShip*> (temp2->data);
				ship->updateHealth(-HIT_DAMAGE);
				explodeEnemy(enemy_hit2);
				enemy_hit2->updateHealth(-1000);
				enemies->deleteEntry(temp2);
				Entry *temp3 = enemies->checkMissile(m3);
				if ( temp3 ) {
					EnemyShip *enemy_hit3 = dynamic_cast<EnemyShip*> (temp3->data);
					ship->updateHealth(-HIT_DAMAGE);
					explodeEnemy(enemy_hit3);
					enemy_hit3->updateHealth(-1000);
					enemies->deleteEntry(temp3);
				}	
			}	
		}
		temp1 = enemies->checkMissile(m4);
		if ( temp1 ) {
			EnemyShip *enemy_hit1 = dynamic_cast<EnemyShip*> (temp1->data);
			ship->updateHealth(-HIT_DAMAGE);
			explodeEnemy(enemy_hit1);
			enemy_hit1->updateHealth(-1000);
			enemies->deleteEntry(temp1);
			Entry *temp2 = enemies->checkMissile(m4);
			if ( temp2 ) {
				EnemyShip *enemy_hit2 = dynamic_cast<EnemyShip*> (temp2->data);
				ship->updateHealth(-HIT_DAMAGE);
				explodeEnemy(enemy_hit2);
				enemy_hit2->updateHealth(-1000);
				enemies->deleteEntry(temp2);
				Entry *temp3 = enemies->checkMissile(m4);
				if ( temp3 ) {
					EnemyShip *enemy_hit3 = dynamic_cast<EnemyShip*> (temp3->data);
					ship->updateHealth(-HIT_DAMAGE);
					explodeEnemy(enemy_hit3);
					enemy_hit3->updateHealth(-1000);
					enemies->deleteEntry(temp3);
				}	
			}	
		}
}

void GameClass::enemyFire() {
			enemy_missile_counter++;
			srand(time(NULL));
			if ( rand() % (10-2*GameClass::DIFFICULTY) == 0 ) {//one of the enemies randomly chosen will shoot a missile , or several
				if ( enemy_missile_counter > GameClass::MAX_ENEMY_MISILE ) {
					if ( ! enemies->isEmpty() ) {
						attachEnemyMissile(rand()%enemies->count_enemy);
						enemy_missile_counter = 0;
					}
				}
			}	
}

void GameClass::addMoreEnemies() {
	if ( enemy_counter > current_enemy ) {
		enemy_counter = 0;
		current_enemy = 215-(GameClass::DIFFICULTY*15);
		int ypos = (rand() % (ENEMY_TOP_BOUND-ENEMY_BOTTOM_BOUND)) + ENEMY_TOP_BOUND;
		attachEnemyShip(RIGHT_BOUND-100+ENEMY_OFFSET,ypos);	  
	}
	else {
		enemy_counter++;
	}
}

void GameClass::checkPowerUps() {
			if ( ship->shield_on ) hud->updateShieldBar(ship->shield_strength);
			if ( double_shot ) {
				if ( double_shot_counter > DOUBLE_SHOT_DURATION ) {
					singleShot();
				}
				double_shot_counter++;
			}
			if ( piercing_shot ) {
				if ( piercing_shot_counter > PIERCING_SHOT_DURATION ) {
					regularMissile();
				}
				piercing_shot_counter++;
			}

			if ( slow_time ) {
				if ( slow_time_counter > SLOW_TIME_DURATION ) {
					refreshTime();
				}
				slow_time_counter++;
			}	
}

void GameClass::OnTimer(UINT_PTR nIDEvent) {
	OnPaint();
	if ( ! pause ) {
		if ( ship->game_over ) {
			game_over->total_score = hud->score->score;
			hud->updateHealthBar(-1);	
			pause = true;
		}
		else {
			background->update();
			hud->updateHealthBar(ship->health);
			
			checkPowerUps();
			enemyFire();
			addMoreEnemies();
			
			hitTest();
			ship->update();
			fire();
	
			everything->update();
			everything->check();

			if ( ship->score_multiplier != hud->score_multiplier  ) {
				hud->updateMultiplier(ship->score_multiplier);
				attachFloatingScoreMultiplier(hud->MULTIPLIER_X,hud->MULTIPLIER_Y-10,ship->score_multiplier);
			}
			
		}
	}
	else  {

	}
}

void GameClass::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ( nChar == RIGHT ) ship->key_pressed_right = true;
	if ( nChar == LEFT  ) ship->key_pressed_left = true;
	if ( nChar == UP ) ship->key_pressed_up = true;
	if ( nChar == DOWN  ) ship->key_pressed_down = true;
	if ( nChar == FIRE ) ship->key_pressed_fire = true;
}

void GameClass::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if ( nChar == RIGHT ) ship->key_pressed_right = false;
	if ( nChar == LEFT  ) ship->key_pressed_left = false;
	if ( nChar == UP ) ship->key_pressed_up = false;
	if ( nChar == DOWN  ) ship->key_pressed_down = false;
	if ( nChar == FIRE ) ship->key_pressed_fire = false;
	if ( nChar == AUTO_FIRE ) auto_fire = !auto_fire;
	if ( PAUSE(nChar) ) {
		pause = !pause;
		if ( pause ) menu->show();
		else menu->hide() ;
	}
	if ( nChar == QUIT ) {
		if ( pause ) 
		    OnOK();
		else {
			menu->show();
			pause = true;
		}
	}
	if ( nChar == EXIT ) {
		if ( pause ) {
				exit = true;
				OnCancel();
		}
		else {
			menu->show();
			pause = true;
		}
	}
	if ( nChar == BOMB ) clearScreen();
}

void GameClass::attachMissile( int xpos , int ypos ) {
	PlayerMissile* to_add = new PlayerMissile(xpos+ship->missile_xoffset,ypos+ship->missile_yoffset,this);
	everything->addEntry(to_add);
}

void GameClass::attachEnemyMissile( int enemy_index ) {
	EnemyShip *temp = enemies->fireMissile(enemy_index);
	EnemyMissile* to_add = new EnemyMissile(temp->x+EnemyShip::MISSILE_XOFFSET,temp->y+EnemyShip::MISSILE_YOFFSET,ship);
	everything->addEntry(to_add);
}

void GameClass::explodeEnemy(EnemyShip *enemy_hit) {
	hud->addScore(100*hud->score_multiplier);
	attachFloatingScore(enemy_hit->x,enemy_hit->y);
	attachExlposion(enemy_hit->x,enemy_hit->y);
	srand(time(NULL));
	if ( rand() % 3 ) {
		attachPowerUp(enemy_hit->x,enemy_hit->y);
	}
}

void GameClass::attachEnemyShip( int xpos , int ypos ) {
	EnemyShip* to_add = new EnemyShip(xpos,ypos);
	enemies->addEntry(to_add);
	everything->addEntry(to_add);
}

void GameClass::attachExlposion( int xpos , int ypos ) {
	Explosion* to_add = new Explosion(xpos,ypos);
	everything->addEntry(to_add);
}

void GameClass::attachPowerUp( int xpos , int ypos ) {
	PowerUp* to_add = new PowerUp(xpos,ypos,ship,this);
	everything->addEntry(to_add);
}
void GameClass::attachFloatingScore( int xpos, int ypos ) {
	FloatingScore* to_add = new FloatingScore(xpos,ypos,100*hud->score_multiplier);
	everything->addEntry(to_add);
}
void GameClass::attachFloatingScoreMultiplier( int xpos, int ypos , int value ) {
	FloatingScore* to_add = new FloatingScore(xpos,ypos,value);
	everything->addEntry(to_add);
}
void GameClass::attachFloatingPowerUp( int xpos, int ypos , CString power_up) {
	FloatingPowerUp* to_add = new FloatingPowerUp(xpos,ypos,power_up);
	everything->addEntry(to_add);
}
void GameClass::attachPiercingMissile( int xpos , int ypos ) {
	PiercingMissile* to_add = new PiercingMissile(xpos+ship->missile_xoffset,ypos+ship->missile_yoffset,this);
	everything->addEntry(to_add);
}
void GameClass::clearScreen() {
//	void (*fptr)(EnemyShip*) = &GameClass::explodeEnemy;
	if ( num_bombs > 0 ) {
		--num_bombs;
		everything->~List();
		everything = new List();
		Entry *walker = enemies->start;
		while ( walker ) {
			explodeEnemy(dynamic_cast<EnemyShip*> (walker->data));
			walker = walker->rlink;
		}
		enemies->~ListEnemyShip();
		enemies = new ListEnemyShip();
		hud->dropBomb();
	}
}

